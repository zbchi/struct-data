#pragma once
#include<stdio.h>
#include<stdlib.h>


//初始化栈
typedef void * LinkStack; 
LinkStack init_LinkStack();

//入栈
void push_LinkStack(LinkStack stack,void*data);

//出栈
void pop_LinkStack(LinkStack stack);

//法返回i栈顶
void*top_LinkStack(LinkStack stack);

//返回i栈的大小
int size_LinkStack(LinkStack stack);

//判断栈是否为空
int isEmpty_LinkStack(LinkStack stack);

//销毁栈
void destroy_LinkStack(LinkStack stack); 