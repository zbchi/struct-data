#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BinaryNode
{
    char ch;
    struct BinaryNode*lChild;
    struct BinaryNode*rChild;
};

void recursion(struct BinaryNode*root)
{
    if(root==NULL)
    return;
    printf("%c\n",root->ch);
    recursion(root->lChild);
    recursion(root->rChild);
}

void test01()
{
    struct BinaryNode nodeA={'A',NULL,NULL};
    struct BinaryNode nodeB={'B',NULL,NULL};
    struct BinaryNode nodeC={'C',NULL,NULL};
    struct BinaryNode nodeD={'D',NULL,NULL};
    struct BinaryNode nodeE={'E',NULL,NULL};
    struct BinaryNode nodeF={'F',NULL,NULL};
    struct BinaryNode nodeG={'G',NULL,NULL};
    struct BinaryNode nodeH={'H',NULL,NULL};

    nodeA.lChild=&nodeB;
    nodeA.rChild=&nodeF;

    nodeB.rChild=&nodeC;

    nodeC.lChild=&nodeD;
    nodeC.lChild=&nodeE;

    nodeF.rChild=&nodeG;
    nodeG.lChild=&nodeH;

    //递归先序遍历
    recursion(&nodeA);
}

int main()
{
    test01();
    return 0;
}