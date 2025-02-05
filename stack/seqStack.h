#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//桟的顺序存储
#define MAX 1024
struct SStack
{
    //桟中数组
    void*data[MAX];
    //桟的大小
    int m_Size;
};

typedef void* SeqStack;

//初始化桟
SeqStack init_SeqStack();

//入桟
void push_SeqStack(SeqStack stack,void*data);

//出桟
void pop_SeqStack(SeqStack stack);

//返回桟顶
void * top_SeqStack(SeqStack stack);

//返回桟的大小
int size_SeqStack(SeqStack stack);

//判断桟是否为空
int isEmpty_SeqStack(SeqStack stack);
//销毁
void destroy_SeqStack(SeqStack stack);