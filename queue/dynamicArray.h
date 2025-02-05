#pragma  once 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��̬���ݽṹ��
struct dynamicArray
{
	void ** pAddr; // ά�����ٵ�������ʵ�����ָ��

	int m_Capacity; //��������

	int m_Size; //�����С
};

//��ʼ������ �������� ��ʼ��������
struct dynamicArray * init_dynamicArray(int capacity);

//����Ԫ��
void insert_dynamicArray(struct dynamicArray * arr, int pos, void * data);

//��������
void foreach_dynamicArray(struct dynamicArray * arr, void(*myPrint)(void *));

//ɾ������
void removeByPos_dynamicArray(struct dynamicArray * arr, int pos);

//����ֵ ��ɾ������������
void removeByValue_dynamicArray(struct dynamicArray * arr, void * data, int(*myCompare)(void *, void *));

//��������
void destroy_dynamicArray(struct dynamicArray * arr);

