#include"seqStack.h"

void printError(char*str,char*errorMsg,char *p )
{
    printf("错误信息：%s\n",errorMsg);
    printf("%s\n",str);
    int num=p-str;
    for(int i=0;i<num;i++)
    {
        printf(" ");
    }
    printf("|\n");
}

void test01()
{
    char *str="5+5*(6)+9/3*1-(1+3(";
    char*p=str;

    //初始化栈
    SeqStack mystack=init_SeqStack();
    while(*p!='\0')
    {
        if(*p=='(')
        {
            //入栈
            push_SeqStack(mystack,p);
        }
        if(*p==')')
        {
            //pop
            if(size_SeqStack(mystack)>0)
            {
                //如果栈非空 执行从此和出栈
                pop_SeqStack(mystack);
            }
            else
            {
                printError(str,"右括号没有匹配到对应的左括号",p);
                break;
            }
        }
        p++;
    }
    //都扫描完后，判断栈是否为空
    while(size_SeqStack(mystack)>0)
    {
        printError(str,"左括号没有匹配到右括号",top_SeqStack(mystack));
        //打印一次错误就出一次从栈
        pop_SeqStack(mystack);
    }
}

int main()
{
    test01();
}