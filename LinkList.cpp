// 单链表
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode, * LinkList;

//头插法
LinkList Inserthead(LinkList &L){
    //待头结点的链表 L是head
    int x;LNode* f;
    L=(LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    while(true){
        scanf("%d",&x);
        if(x == -1)
            break;
        f=(LNode*)malloc(sizeof(LNode));
        f->data = x;
        f->next = L->next;
        L->next = f;
    }
    return L;
}

//尾插法
LinkList InsertTail(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
    int x;LNode* tmp,*current = L;
    while(true){
        scanf("%d",&x);
        if(x == -1)
            break;
        tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = x;
        current->next = tmp;
        current = tmp;
    }
    current->next = NULL;
    return L;
}

//按序号查找值
ElemType SearchForPosition(LinkList& L,int pos){
    LNode* current = L->next;
    for(int i=0;i<pos-1;i++){
        current = current->next;
    }
    return current->data;
}

//按data查找 返回结点
LNode* SearchForElement(LinkList& L,ElemType e){
    LNode* current = L->next;
    while(current!=NULL){
        if(current->data == e)
            return current;
        current = current->next;
    }
    return NULL;
}

//新结点插入第i个位置 i为显式位置
LinkList InsertIntoAllocatedPosition(LinkList& L,int pos,ElemType e){
    LNode* tmp1 = L;
    for(int i=0;i<pos;i++){
        tmp1 = tmp1->next;
    }
    LNode* node = (LNode*)malloc(sizeof(LNode));
    node->data = e;
    node->next = tmp1->next;
    tmp1->next = node;

    return L;
}

void PrintList(LinkList &L){
    LNode* tmp = L->next;
    while(tmp != NULL){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
}

//倒置链表
LinkList ReverseLinkList(LinkList &L){
    LNode* cur = L->next; //第一个存储元素
    L->next = NULL; //让原来的链表置为空
    while(cur!=NULL){
        LNode* del = NULL;
        LNode* tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = cur->data;
        tmp->next = L->next;
        L->next = tmp;
        del = cur;
        cur=cur->next;
        free(del);
    }
    return L;

}

int main(){
    LinkList L;
    // L = Inserthead(L);
    L = InsertTail(L);
    PrintList(L);
    printf("\n");
    // int ret = SearchForPosition(L,1);
    // printf("%d",ret);
    // LNode* tmp = SearchForElement(L,5);
    // printf("%d",tmp->data);
    // L = InsertIntoAllocatedPosition(L,3,100);
    // PrintList(L);

    L = ReverseLinkList(L);
    PrintList(L);
}
