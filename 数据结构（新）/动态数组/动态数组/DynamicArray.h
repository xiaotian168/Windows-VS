#pragma once	//防止头文件重复包含

//动态数组的数据结构
struct DArray
{
	void **pArry;	//数组空间首地址
	int capacity;	//容量
	int size;	//大小
};

typedef void(*MYFOREACH)(void*);	//遍历函数指针

typedef int(*DATACOMPARE)(void *, void *);	//比较函数指针

#ifdef __cplusplus
extern "C" {
#endif

	//初始化动态数组
	struct DArray *Init_DynamicArray();

	//指定位置插入函数
	void Insert_DynamicArray(struct DArray *arr, int pos, void* data);

	//尾部插入函数
	void PushBack_DynamicArray(struct DArray *arr, void* data);

	//头部插入函数
	void PushFront_DynamicArray(struct DArray *arr, void* data);

	//删除函数(按指定位置删除)
	void Remove_DynamicArray(struct DArray *arr, int pos);

	//按值删除
	void DeleteByVal_DynamicArray(struct DArray *arr, void* data, DATACOMPARE myCompare);

	//遍历函数，（打印）
	void Foreach_DynamicArray(struct DArray *arr, MYFOREACH myForeach);

	//销毁数组
	void Destroy_DynamicArray(struct DArray *arr);
	

#ifdef __cplusplus
}
#endif
