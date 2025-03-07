
#include<stdio.h>
#define DEFAULT_SIZE 16
typedef struct ListNode
{
    struct ListNode*next;
    int key;
    void *data;
}ListNode;

typedef ListNode*List;
typedef ListNode*Element;

typedef struct HashTable
{
    int TableSize;
    List*Thelists;
}HashTable;


int Hash(int key,int TableSize)
{
    return key%TableSize;
}

HashTable* InitHash(int TableSize)
{
    int i=0;
    HashTable*hTable=NULL;
    if(TableSize<=0)
    {
        TableSize=DEFAULT_SIZE;
    }

    hTable=(HashTable*)malloc(sizeof(HashTable));

    hTable->TableSize=TableSize;

    //为hash桶分配空间，其为一个指针数组
    hTable->Thelists=(List*)malloc(sizeof(List)*TableSize);

    //为hash桶对应的指针数组初始化链表节点
    for(int i=0;i<TableSize;i++)
    {
        hTable->Thelists[i]=(ListNode*)malloc(sizeof(ListNode));
        
        memset(hTable->Thelists[i],0,sizeof(ListNode));
    }
}

Element Find(HashTable*HashTable,int key)
{
    int i=0;
    List L=NULL;
    Element e=NULL;
    i=Hash(key,HashTable->TableSize);
    L=HashTable->Thelists[i];
    e=L->next;
    while(e!=NULL&&e->key!=key)
       e=e->next;

    return e;

}

void Insert(HashTable*HashTable,int key,void *value)
{
    Element e=NULL,tmp=NULL;
    List L=NULL;
    e=Find(HashTable,key);
    if(e==NULL)
    {
        tmp=(Element)malloc(sizeof(ListNode));
        //前插法
        L=HashTable->Thelists[Hash(key,HashTable->TableSize)];
        tmp->data=value;
        tmp->key=key;
        tmp->next=L->next;
        L->next=tmp;
    }
    else 
    printf("the key has exsited\n");  

}


void Delete(HashTable*HashTable,int key)
{
    Element e=NULL,last=NULL;
    List L=NULL;
    int i;
    int i=Hash(key,HashTable->TableSize);
    L=HashTable->Thelists[i];

    last=L;
    e=L->next;
    while(e!=NULL&&key!=key)
    {
        last=e;
        e=e->next;
    }

    if(e)
    {

        last->next=e->next;
        free(e);
    }
}