#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BinaryNode
{
    char ch;
    struct BinaryNode*lChild;
    struct BinaryNode*rChild;
};

void caculateLeafNum(struct BinaryNode*root,int * num)
{
    if(root==NULL)
    return;
    if(root->lChild==NULL&&root->rChild==NULL)
    (*num)++;
    caculateLeafNum(root->lChild,num);
    caculateLeafNum(root->rChild,num);
}

int getTreeHeight(struct BinaryNode *root)
{
    if(root==NULL)
    return 0;

    int lHeight=getTreeHeight(root->lChild);
    int rHeight=getTreeHeight(root->rChild);
    //取大值+1
    return (lHeight>rHeight?lHeight:rHeight)+1;
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
    nodeC.rChild=&nodeE;

    nodeF.rChild=&nodeG;
    nodeG.lChild=&nodeH;

    //统计叶子数量
    int num=0;
    caculateLeafNum(&nodeA,&num);
    printf("LeavesNum:%d\n",num);

    //统计树高度
    int height=getTreeHeight(&nodeA);
    printf("TreeHeight:%d\n",height);
}

int main()
{
    test01();
    return 0;
}