#include<iostream>
#include<string>
using namespace std;
#define STACK_MAX 101
char StackArray[STACK_MAX];
int StackTop = -1;

bool isFull(){
    return StackTop >= STACK_MAX;
}
bool isEmpty(){
    return StackTop == -1;
}
void pushToStack(char element){
    if(isFull()){
        cout << "Stack is Full ";
    }
    else{
        StackTop++;
        StackArray[StackTop] = element;
    }
    return;
}

char popFromStack(){
    if(isEmpty()){
        cout<<"Stack is empty ";
        return -1;
    }
    else{
        char a = StackArray[StackTop];
        StackTop--;
        return a;
    }
}

int main(){
    string word;
    getline(cin, word);
    int size = 0;
    for(char c: word){
        pushToStack(c);
        size++;
    }

    for(int i = 0; i<size; i++){
        char a = popFromStack();
        cout<<a;
    }
    cout<<endl;
    return 0;
}
