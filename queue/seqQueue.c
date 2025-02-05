#include"seqQueue.h"
#include"dynamicArray.h"

//初始化队列
seqQueue init_seqQueue()
{
    struct dynamicArray *array=init_dynamicArray(MAX);
    return array;
}

//入队
void push_seqQueue(seqQueue queue,void*data)
{
    //本质尾插
    if(queue==NULL)
    {
        return;
    }
    if(data==NULL)
    {
        return;
    }
    struct dynamicArray*array=queue;
    if(array->m_Size==MAX)
    return;

    insert_dynamicArray(array,array->m_Size,data);
}

//出队
void pop_seqQueue(seqQueue queue)
{
    //本质头删除
    if(queue==NULL)
    return;
    
    struct dynamicArray*array=queue;
    removeByPos_dynamicArray(array,0);
}

//返回队头
void* front_seqQueue(seqQueue queue)
{
    if(queue==NULL)
    return NULL;
    struct dynamicArray* array=queue;

    return array->pAddr[0];
}

//返回队尾
void* back_seqQueue(seqQueue queue)
{
        if(queue==NULL)
    return NULL;
    struct dynamicArray* array=queue;

    return array->pAddr[array->m_Size-1];
}

//返回队列大小
int size_seqQueue(seqQueue queue)
{
    if(queue==NULL)
    return -1;

    struct dynamicArray *array=queue;
    return array->m_Size;
}

//判断队列是否为空
int isEmpty(seqQueue queue)
{
    if(queue==NULL)
    return -1;

    struct dynamicArray* array=queue;
    if(array->m_Size==0)
    return 1;
    return 0;
}

//销毁队列
void destroy_seqQueue(seqQueue queue)
{
    if(queue==NULL)
    return;
    destroy_dynamicArray(queue);
}