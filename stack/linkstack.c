#include"linkstack.h"
struct LinkNode
{
    //只维护指针域
    struct LinkNode*next;
};

struct lstack
{
    struct LinkNode pHeader;//头节点
    int m_Size;//栈的大小
};

//初始化栈
typedef void * LinkStack; 
LinkStack init_LinkStack()
{
    struct lstack*myStack=(struct lstack*)malloc(sizeof(struct lstack));
    if(myStack==NULL)
    return NULL;

    myStack->pHeader.next=NULL;
    myStack->m_Size=0;

    return myStack;
}

//入栈
void push_LinkStack (LinkStack stack,void*data)
{
    //本质是头插入
    struct lstack*mystack=stack;
    
    //取出用户前四个字节
    struct LinkNode*mynode=data;


    mynode->next=mystack->pHeader.next;
    mystack->pHeader.next=mynode;

    //更新栈的大小
    mystack->m_Size++;
}

//出栈
void pop_LinkStack(LinkStack stack)
{
    struct lstack*mystack=stack;
    mystack->pHeader.next=(mystack->pHeader.next)->next; 
    //
    mystack->m_Size--;
}
//法返回i栈顶
void*top_LinkStack(LinkStack stack)
{
    struct lstack*mystack=stack;
    return mystack->pHeader.next;
}

//返回i栈的大小
int size_LinkStack(LinkStack stack)
{
    struct lstack *mystack=stack;
    return mystack->m_Size;
}

//判断栈是否为空
int isEmpty_LinkStack(LinkStack stack)
{
    struct lstack*mystack=stack;
    if(mystack->m_Size==0)
    return 1;
    return 0;
}

//销毁栈
void destroy_LinkStack(LinkStack stack)
{
    if(stack==NULL)
    return -1;

    free(stack);
    stack==NULL;
} 

