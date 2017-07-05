#pragma once	//防止头文件重复包含

//动态数组的数据结构
struct DArray
{
	void **pArry;	//数组空间首地址
	int capacity;	//容量
	int size;	//大小
};

typedef void(*MYFOREACH)(void*);	//定义一个函数指针类型

#ifdef __cplusplus
extern "C" {
#endif

	//初始化动态数组
	struct DArray *Init_DynamicArray();

	//插入函数
	void Insert_DynamicArray(struct DArray *arr, int pos, void *data);

	//删除函数
	void Remove_DynamicArray(struct DArray *arr, int pos);

	//遍历函数，（打印，修改数据）
	void Foreach_DynamicArray(struct DArray *arr, MYFOREACH myforeach);

	//销毁数组
	void Destroy_DynamicArray(struct DArray *arr);
	

#ifdef __cplusplus
}
#endif
