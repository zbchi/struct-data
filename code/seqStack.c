#include"seqStack.h"
//初始化桟
SeqStack init_SeqStack()
{
    struct SStack *myStack=(struct SStack*)malloc(sizeof(struct SStack));
    if(myStack==NULL)
    return NULL;
    memset(myStack->data,0,sizeof(void*)*MAX);
    myStack->m_Size=0;
    return myStack;
}

//入桟
void push_SeqStack(SeqStack stack,void*data)
{
    //本质是尾插
    if(stack==NULL)return;
    if(data==NULL)return;
    struct SStack *mystack=stack;

    //判断桟是否满了
    if(mystack->m_Size==MAX)
    return;


    mystack->data[mystack->m_Size]=data;
    mystack->m_Size++;
}

//出桟
void pop_SeqStack(SeqStack stack)
{
    //本质是尾删
    if(stack==NULL)
    return;
    struct SStack*mystack=stack;
    
    if(mystack->m_Size==0)
    return;

    mystack->data[mystack->m_Size-1]=NULL;
    mystack->m_Size--;
}

//返回桟顶
void * top_SeqStack(SeqStack stack)
{
    //本质返回数组的最后一个元素
    if(stack==NULL)
    return NULL;

    struct SStack*mystack=stack;

    if(mystack->m_Size==0)
    return NULL;

    return mystack->data[mystack->m_Size-1];
}

//返回桟的大小
int size_SeqStack(SeqStack stack)
{
    if(stack==NULL)
    return -1;

    struct SStack *mystack=stack;
    return mystack->m_Size;

}

//判断桟是否为空
int isEmpty_SeqStack(SeqStack stack)
{
    if(stack==NULL)
    return -1;//返回真也为空

    struct SStack*mystack=stack;

    if(mystack->m_Size==0)
    return 1;

    return 0;


}

//销毁
void destroy_SeqStack(SeqStack stack)
{
    if(stack==NULL)
    return;

    free(stack);
    stack==NULL;
    
}