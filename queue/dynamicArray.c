#include "dynamicArray.h"

// 初始化动态数组结构体，并设置初始容量
struct dynamicArray * init_dynamicArray(int capacity)
{
	struct dynamicArray * array = malloc(sizeof(struct dynamicArray));

	if (array == NULL)
	{
		return NULL;
	}

	// 初始化成员变量
	array->m_Capacity = capacity;
	array->m_Size = 0;
	array->pAddr = malloc(sizeof(void *)* capacity);

	if (array->pAddr == NULL)
	{
		return NULL;
	}

	return array;
}


// 插入元素到指定位置
void insert_dynamicArray(struct dynamicArray * arr, int pos, void * data)
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	if (pos < 0 || pos > arr->m_Size)
	{
		// 如果插入位置无效，则默认插在末尾
		pos = arr->m_Size;
	}

	// 判断是否需要扩展容量，如果当前没有足够空间，则动态扩展
	if (arr->m_Size >= arr->m_Capacity)
	{
		//1. 扩展原容量大小
		int newCapacity = arr->m_Capacity * 2;

		//2. 分配新内存空间
		void ** newSpace = malloc(sizeof (void *)* newCapacity);

		//3. 将原数据复制到新的内存空间中
		memcpy(newSpace, arr->pAddr, sizeof(void*)* arr->m_Capacity);

		//4. 释放原内存空间
		free(arr->pAddr);

		//5. 指针指向新地址
		arr->pAddr = newSpace;

		//6. 更新容量大小
		arr->m_Capacity = newCapacity;
	}


	// 移动元素为新元素腾出位置
	for (int i = arr->m_Size - 1; i >= pos; i--)
	{
		// 向后移动
		arr->pAddr[i + 1] = arr->pAddr[i];
	}
	// 将新元素放置到指定位置
	arr->pAddr[pos] = data;


	// 增加数组的大小
	arr->m_Size++;
}

// 遍历并处理每个元素
void foreach_dynamicArray(struct dynamicArray * arr, void(*myPrint)(void *))
{
	if (arr == NULL)
	{
		return;
	}

	if (myPrint == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->m_Size; i++)
	{
		myPrint(arr->pAddr[i]);
	}
}


// 根据索引位置移除元素
void removeByPos_dynamicArray(struct dynamicArray * arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}

	// 如果位置无效，直接返回
	if (pos < 0 || pos >arr->m_Size - 1)
	{
		return;
	}

	// 移动元素填补空缺
	for (int i = pos; i < arr->m_Size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}

	// 减少数组大小
	arr->m_Size--;

}

// 根据值和比较函数移除元素
void removeByValue_dynamicArray(struct dynamicArray * arr, void * data, int(*myCompare)(void *, void *))
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->m_Size; i++)
	{
		if (myCompare(arr->pAddr[i], data))
		{
			// 如果比较器成功匹配，则需要移除i处的元素
			removeByPos_dynamicArray(arr, i);
			break;
		}
	}


}

// 销毁动态数组
void destroy_dynamicArray(struct dynamicArray * arr)
{

	if (arr == NULL)
	{
		return;
	}

	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
		arr->pAddr = NULL;
	}


	free(arr);
	arr = NULL;

}