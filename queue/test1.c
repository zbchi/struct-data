#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"seqQueue.h"


struct person
{
    char name[64];
    int age;
};

void test01()
{
    seqQueue myQueue=init_seqQueue();
    struct person p1={"aaa",10};
    struct person p2={"bbb",20};
    struct person p3={"ccc",30};
    struct person p4={"ddd",40};
    struct person p5={"eee",50};

    //入队
    push_seqQueue(myQueue,&p1);
    push_seqQueue(myQueue,&p2);
    push_seqQueue(myQueue,&p3);
    push_seqQueue(myQueue,&p4);
    push_seqQueue(myQueue,&p5);

    //通过循环查看队头 队尾 执行出队
    while(!isEmpty(myQueue))
    {
        struct person*personFront=front_seqQueue(myQueue);
        printf("队头name:%s age:%d\n",personFront->name,personFront->age);

        struct person*personBack=back_seqQueue(myQueue);
        printf("队尾name:%s age:%d\n",personBack->name,personBack->age);

        //出队
        pop_seqQueue(myQueue);
    }

    //队列大小
    printf("size:%d\n",size_seqQueue(myQueue));

    destroy_seqQueue(myQueue);
}

int main()
{
    test01();
    return 0;
}
