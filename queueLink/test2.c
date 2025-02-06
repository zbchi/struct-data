#include"linkQueue.h"
struct person
{
    struct LinkNode node;
    char name[64];
    int age;
};

void test02()
{
    LinkQueue myQueue=init_LinkQueue();
    struct person p1={{NULL},"aaa",10};
    struct person p2={{NULL},"bbb",20};
    struct person p3={{NULL},"ccc",30};
    struct person p4={{NULL},"ddd",40};
    struct person p5={{NULL},"eee",50};

    //入队
    push_LinkQueue(myQueue,&p1);
    push_LinkQueue(myQueue,&p2);
    push_LinkQueue(myQueue,&p3);
    push_LinkQueue(myQueue,&p4);
    push_LinkQueue(myQueue,&p5);

    //通过循环查看队头 队尾 执行出队
    while(!isEmpty(myQueue))
    {
        struct person*personFront=front_LinkQueue(myQueue);
        printf("队头name:%s age:%d\n",personFront->name,personFront->age);

        struct person*personBack=back_LinkQueue(myQueue);
        printf("队尾name:%s age:%d\n",personBack->name,personBack->age);


        //出队
        pop_LinkQueue(myQueue);
    }

    //队列大小
    printf("size:%d\n",size_LinkQueue(myQueue));

    destroy_LinkQueue(myQueue);
}

int main()
{
    test02();
    return 0;
}
