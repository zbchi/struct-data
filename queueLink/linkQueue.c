#include"linkQueue.h"
//初始化队列
LinkQueue init_LinkQueue()
{
    struct LQueue*myQueue=malloc(sizeof(struct LQueue));
    if(myQueue==NULL)
    return NULL;

    myQueue->pHeader.next=NULL;
    myQueue->m_size=0;
    myQueue->pTail=&myQueue->pHeader;

    return myQueue;
}


//入队
void push_LinkQueue(LinkQueue queue,void*data)
{
    //本质尾插
    if(queue==NULL||data==NULL)
    return;

    struct LQueue*myQueue=queue;

    //将用户数据前四个字节取出
    struct LinkNode*myNode=data;

    //更新指针指向
    myQueue->pTail->next=myNode;
    myQueue->pTail=myNode;
    myNode->next=NULL;

    //更新大小
    myQueue->m_size++;

    return;
}

//出队
void pop_LinkQueue(LinkQueue queue)
{
    //头删
    if(queue==NULL)
    return;

    struct LQueue*myQueue=queue;
    
    //判断队列是否为空
    if(myQueue->m_size==0)
    return;
    
    //特判只有一个节点处理pTail的指向
    if(myQueue->m_size==1)
    {
        myQueue->pTail=&myQueue->pHeader;
    }

    myQueue->pHeader.next=myQueue->pHeader.next->next;
    return;
}

//返回队头
void* front_LinkQueue(LinkQueue queue)
{
    if(queue==NULL)
    return NULL;

    struct LQueue*myQueue=queue;

    if(myQueue->m_size==0)
    return NULL;

    return myQueue->pHeader.next;
}

//返回队尾
void* back_LinkQueue(LinkQueue queue)
{
    if(queue==NULL)
    return NULL;

    struct LQueue*myQueue=queue;

    if(myQueue->m_size==0)
    return NULL;

    return myQueue->pTail;
}

//返回队列大小
int size_LinkQueue(LinkQueue queue)
{
    if(queue==NULL)
    return -1;

    struct LQueue*myQueue=queue;
    return myQueue->m_size;
}

//判断是否为空
int isEmpty(LinkQueue queue)
{
    if(queue==NULL)
    return -1;

    struct LQueue*myQueue=queue;
    if(myQueue->m_size==0)
    return 1;
    return 0;
}

//销毁队列
void destroy_LinkQueue(LinkQueue queue)
{
    if(queue==NULL)
    return;

    free(queue);
    queue=NULL;
}