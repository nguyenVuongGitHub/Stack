/*
*       Stack
*
*       code by vuong :>/
*/
#include <iostream>
using namespace std;

// khai báo cấu trúc của stack 
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
struct stack{
    node *top;
};
typedef struct stack stack;
//================================================
// khởi tạo stack
void createStack(stack &s){
    s.top = NULL;
}
// khởi tạo một node mới
node *createNode(int data){
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//================================================
// kiểm tra rỗng
bool isEmpty(stack s){
    return s.top == NULL;
}
// thêm phần tử vào stack
void push(stack &s, node *newNode){
    if(isEmpty(s)){
        s.top = newNode;
    }
    else{
        newNode->next = s.top;
        s.top = newNode;
    }
}
// xem phần tử trên cùng
int top(stack s){
   return s.top->data; 
}
// lấy phần tử trên cùng ra
int pop(stack &s){
    int data = s.top->data;
    node *temp = s.top->next;
    s.top = NULL;
    s.top = temp;
    return data;
}
// lấy toàn bộ stack ra
void display(stack &s){
    while(!isEmpty(s)){
        cout << pop(s) << " ";
    }
}
//================================================

int main(){
    int n;cin>>n;
    stack s;
    createStack(s);
    cout << "\nstack rong : " << isEmpty(s);
    for(int i = 0; i <n;i++){
        int data;cin>>data;
        node *newNode = createNode(data);
        push(s,newNode);
    }
    cout << "\nstack rong : " << isEmpty(s);
    cout << "\nphan tu dau tien la (top) : " << top(s);
    
    cout << "\nphan tu dau tien la (pop) : " << pop(s) << endl;
    display(s);
    cout << "\nstack rong : " << isEmpty(s);
    return 0;
}
