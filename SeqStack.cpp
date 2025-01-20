#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50
typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SeqStack;

//初始化栈
void init(SeqStack &S){
    S.top = -1;
}

//判断栈是否已满
bool IsFull(SeqStack &S){
    if(S.top == MAXSIZE-1){
        return true;
    }else{
        return false;
    }
}

//入栈Push
bool Push(SeqStack &S,ElemType e){
    if(!IsFull(S)){
        S.data[S.top+1] = e;
        S.top++;
        return true;
    }else{
        return false;
    }
}

//出栈Pop
bool Pop(SeqStack &S,ElemType &s){
    if(S.top==-1)
        return false;
    s = S.data[S.top];
    S.top--;
    return true;
}

//取栈顶元素
bool GetTop(SeqStack &S,ElemType &s){
    if(S.top == -1){
        return false;
    }else{
        s = S.data[S.top];
        return true;
    }
}

int main(){
    SeqStack S;
    init(S);//初始化栈

    //入栈
    Push(S,1);
    Push(S,2);
    Push(S,5);

    //取栈顶元素
    int x;
    if(GetTop(S,x)){
        printf("取栈顶元素成功 栈顶元素为%d\n",x);
    }else{
        printf("栈空 取不了元素\n");
    }

    //出栈
    int y;
    while(Pop(S,y)){
        printf("出栈成功 出栈元素为%d\n",y);
    }
    printf("===栈空===");



}