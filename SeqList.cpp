//
// Created by 董晓鸥 on 2025/1/12.
顺序表
//

#include <stdio.h>

#define Maxsize 50
typedef int ElemType;

typedef struct{
    ElemType data[Maxsize]; //顺序表开辟空间
    int length; //顺序表实际空间
}SqList;

bool Insert(SqList &L,int pos,ElemType e){
    //pos为插入实际的位置 可以插入的实际位置为1-(length+1) 下标0-length
    if(pos <1 || pos > L.length+1)
        return false;
    //空间不够
    if(L.length >= Maxsize)
        return false;

    L.length++;
    for(int i=L.length-1;i>=pos;i--){
        L.data[i] = L.data[i-1];
    }
    L.data[pos-1] = e;
    return true;
}

bool Delete(SqList &L,int pos,ElemType &e){
    if(pos <1 || pos > L.length)
        return false;
    e = L.data[pos-1];
    for(int i=pos-1;i<L.length-1;i++){
        L.data[i] = L.data[i+1];
    }
    L.length--;
    return true;
}

int Locate(SqList &L,ElemType e,int &loc){
    for(int i=0;i<=L.length-1;i++){
        if(L.data[i] == e){
            loc = i+1;
            return true;
        }
    }
    return false;
}

void printList(SqList L){
    for(int i=0;i<= L.length-1;i++){
        printf("%4d",L.data[i]);
    }
    printf("\n\n");
}

int main(){
    //构建顺序表
    SqList L;
    L.length = 5;
    L.data[0] = 10;
    L.data[1] = 40;
    L.data[2] = 50;
    L.data[3] = 20;
    L.data[4] = 15;

    printf("============初始化顺序表============\n");
    printf("初始化顺序表为:");
    printList(L);

    //插入显式位置为6的元素100
    printf("============插入显式位置为6的元素100============\n");
    int ret1 = Insert(L,6,100);
    printList(L);

    printf("============删除显式位置为2的元素============\n");
    int e = 0;
    int ret2 = Delete(L,2,e);
    printList(L);
    printf("原来的值为%d\n",e);

    printf("============查询元素100的显式位置============\n");
    int loc = -1;
    int ret3 = Locate(L,100,loc);
    printf("%d",loc);

}