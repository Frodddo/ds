//队头front删除 队尾rear插入
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int front;//队尾 删除
    int rear;//队头 插入
}SeqQueue;

void Init(SeqQueue &S){
    S.front = S.rear = 0;
}

//入队列
bool Enqueue(SeqQueue &Q,ElemType e){
    if((Q.rear+1)%MAXSIZE == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXSIZE;
    return true;
}

//出队列
bool Dequeue(SeqQueue &Q,ElemType &e){
    if(Q.front == Q.rear)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front+1)%MAXSIZE;
    return true;
}

int main(){
    SeqQueue Q;
    Init(Q);
    //入队
    Enqueue(Q,1);
    Enqueue(Q,5);
    Enqueue(Q,3);
    Enqueue(Q,2);
    Enqueue(Q,9);

    //出队
    int e;
    while(Dequeue(Q,e)){
        printf("出队列成功 出队列元素为%d\n",e);
    }
    printf("===队列空===");

}

