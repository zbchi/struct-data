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

struct BinaryNode*copyTree(struct BinaryNode*root)
{
    if(root==NULL)
    return NULL;

    //拷贝左子树
    struct BinaryNode*lChild=copyTree(root->lChild);
    //拷贝右子树
    struct BinaryNode*rChild=copyTree(root->rChild);
    //创建新节点
    struct BinaryNode*newNode=malloc(sizeof(struct BinaryNode));
    //子树挂载到新节点上
    newNode->lChild=lChild;
    newNode->rChild=rChild;
    newNode->ch=root->ch;

    return newNode;
}

void freeTree(struct BinaryNode*root)
{
    if(root==NULL)
    return;
    
    //先释放左子树
    freeTree(root->lChild);
    //再释放右子树
    freeTree(root->rChild);
    //再释放根节点
    printf("%c is going to free\n",root->ch);
    free(root);
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
    //拷贝
    struct BinaryNode*newTree=copyTree(&nodeA);
    recursion(newTree);

    //释放树
    freeTree(newTree);
}

int main()
{
    test01();
    return 0;
}