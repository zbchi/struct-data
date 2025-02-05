#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAX 1024   //队列最大大小


typedef void* seqQueue;

//初始化队列
seqQueue init_seqQueue();

//入队
void push_seqQueue(seqQueue queue,void*data);

//出队
void pop_seqQueue(seqQueue queue);

//返回队头
void* front_seqQueue(seqQueue queue);

//返回队尾
void* back_seqQueue(seqQueue queue);

//返回队列大小
int size_seqQueue(seqQueue queue);

//判断队列是否为空
int isEmpty(seqQueue queue);

//销毁队列
void destroy_seqQueue(seqQueue queue);