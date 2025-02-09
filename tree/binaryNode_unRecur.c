#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"seqStack.c"
struct BinaryNode
{
    char ch;
    struct BinaryNode*lChild;
    struct BinaryNode*rChild;

    int flag;//节点标志
};

void nonRecursion(struct BinaryNode*root)
{
    SeqStack myStack=init_SeqStack();
    
    //将根节点入栈
    push_SeqStack(myStack,root);

    //stack元素个数大于0，循环
    while(size_SeqStack(myStack)>0)
    {
        //获取栈顶
        struct BinaryNode*topNode=top_SeqStack(myStack);
        pop_SeqStack(myStack);

        if(topNode->flag==1)
        {
            printf("%c\n",topNode->ch);
            continue;
        }
        //如果为假，将标志改为真
        topNode->flag=1;

        //依次压入右，左，根
        if(topNode->rChild!=NULL)
        push_SeqStack(myStack,topNode->rChild);
        if(topNode->lChild!=NULL)
        push_SeqStack(myStack,topNode->lChild);

        push_SeqStack(myStack,topNode);

    }
    
    destroy_SeqStack(myStack);
}


void test01()
{
    struct BinaryNode nodeA={'A',NULL,NULL,0};
    struct BinaryNode nodeB={'B',NULL,NULL,0};
    struct BinaryNode nodeC={'C',NULL,NULL,0};
    struct BinaryNode nodeD={'D',NULL,NULL,0};
    struct BinaryNode nodeE={'E',NULL,NULL,0};
    struct BinaryNode nodeF={'F',NULL,NULL,0};
    struct BinaryNode nodeG={'G',NULL,NULL,0};
    struct BinaryNode nodeH={'H',NULL,NULL,0};

    nodeA.lChild=&nodeB;
    nodeA.rChild=&nodeF;

    nodeB.rChild=&nodeC;

    nodeC.lChild=&nodeD;
    nodeC.rChild=&nodeE;

    nodeF.rChild=&nodeG;
    nodeG.lChild=&nodeH;


    //非递归遍历
    nonRecursion(&nodeA);
}

int main()
{
    test01();
    return 0;
}