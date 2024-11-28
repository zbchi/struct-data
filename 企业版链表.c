//节点结构体设计
struct LinkNode
{
    //只维护指针域
    struct LinkNode*next;
};

struct LList
{
    struct LinkNode pHeader;//头节点
    int m_Size;
};

typedef void* LinkList;

//从初始化链表
void init_LinkList()
{
    struct LList *mylist=malloc(sizeof(struct LList));
    if(mylist==NULL)
    return;
    mylist->m_Size=0;
    mylist->pHeader.next=NULL;

}

//插入链表
void insert_LinkList(LinkList list,int pos,void*data)
{
    if(list==NULL)
    return;

    struct LList*mylist=list;
    if(pos<0||pos>mylist->m_Size-1)
    {
        pos=mylist->m_Size;
    }

    //取出用户数据的前四个字节空间
    struct LinkNode*myNode=data;
    //找到的等待插入位置的前驱节点
    struct LinkNOde*pCurrent =myNode->pHeader;
    for(int i=0;i<pos;i++)
    {
        pCurrent=pCurrent->next;
    }
    //更改指针指向
    myNode->next=pCurrent->next;
    pCurrent->next=myNode;

    mylist->m_Size++;
}

//用回调函数年遍历
void foreach_LinkList(LinkList list,void(*myPrint)(void*))
{
    if(NULL==list)
    return;

    struct LList*mylist=list;

    //指向第一个有真实数据的节点
    struct LinkNode*pCurrent=mylist->pHeader.next;

    for(int i=0;i<mylist->m_Size;i++)
    {
        //pCurrent就是用户数据的首地址，用首地质访问
        myPrint(pCurrent);
        pCurrent=pCurrent->next;
    }

}



struct person
{
    struct LinkNode node;
    char name[64];
    int age;//节点结构体设计
};
struct LinkNode
{
    //只维护指针域
    struct LinkNode*next;
};

struct LList
{
    struct LinkNode pHeader;//头节点
    int m_Size;
};

typedef void* LinkList;

//从初始化链表
void init_LinkList()
{
    struct LList *mylist=malloc(sizeof(struct LList));
    if(mylist==NULL)
    return;
    mylist->m_Size=0;
    mylist->pHeader.next=NULL;

}

//插入链表
void insert_LinkList(LinkList list,int pos,void*data)
{
    if(list==NULL)
    return;

    struct LList*mylist=list;
    if(pos<0||pos>mylist->m_Size-1)
    {
        pos=mylist->m_Size;
    }

    //取出用户数据的前四个字节空间
    struct LinkNode*myNode=data;
    //找到的等待插入位置的前驱节点
    struct LinkNOde*pCurrent =myNode->pHeader;
    for(int i=0;i<pos;i++)
    {
        pCurrent=pCurrent->next;
    }
    //更改指针指向
    myNode->next=pCurrent->next;
    pCurrent->next=myNode;

    mylist->m_Size++;
}

//用回调函数年遍历
void foreach_LinkList(LinkList list,void(*myPrint)(void*))
{
    if(NULL==list)
    return;

    struct LList*mylist=list;

    //指向第一个有真实数据的节点
    struct LinkNode*pCurrent=mylist->pHeader.next;

    for(int i=0;i<mylist->m_Size;i++)
    {
        //pCurrent就是用户数据的首地址，用首地质访问
        myPrint(pCurrent);
        pCurrent=pCurrent->next;
    }

}



struct person
{
    struct LinkNode node;
    char name[64];
    int age;
}

void myprint(void*data)
{
    struct person*person=data;
    printf("%s  %d\n",person->name,person->age);
}

void myprint(void*data)
{
    struct person*data1=data;
    printf("%s  %d\n",data1->name,data1->age);
}