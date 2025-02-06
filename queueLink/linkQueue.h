#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//节点结构体
struct LinkNode
{
    struct LinkNode*next;
};

//队列结构体
struct LQueue
{
    struct LinkNode pHeader;//头节点
    struct LinkNode* pTail;  //尾节点的指针
    int m_size;//队列大小
};

typedef void* LinkQueue;

//初始化队列
LinkQueue init_LinkQueue();

//入队
void push_LinkQueue(LinkQueue queue,void*data);

//出队
void pop_LinkQueue(LinkQueue queue);

//返回队头
void* front_LinkQueue(LinkQueue queue);

//返回队尾
void* back_LinkQueue(LinkQueue queue);

//返回队列的新大小
int size_LinkQueue(LinkQueue queue);

//判断是否为空
int isEmpty(LinkQueue queue);

//销毁队列
void destroy_LinkQueue(LinkQueue queue);