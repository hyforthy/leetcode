/*
 * 堆的实现
 */
#ifndef __MHEAP__ 
#define __MHEAP__ 
 
#include <stdio.h>
#include <stdlib.h>
 
template <class T>
class MHeap  
{
public:	
	bool Cmp(const T &a, const T &b)
	{
		return IsMaxHeap ? a <= b : a >= b;
	}
	
	// big 为真则创建大堆， 否则小堆
	MHeap(int n, int big);
	~MHeap();
	
	void BuildHeap();
	
	// 删除给定下标的元素
	bool Remove(int pos, T& val);
	
	// 从position向下开始调整
	void ShiftDown(int pos);
	
	// 从position向上开始调整
	void ShiftUp(int pos);
	
	// 压入数据
	bool Push(const T& val);
	inline bool Top(T &val);
	void Pop();
	inline bool Empty();
 
private:
	T *Data;
	int CurrentSize;
	int MaxSize;
	int IsMaxHeap;
};
 
template<class T>
MHeap<T>::MHeap(int n, int big)
{
	if(n <= 0)
		return;
	CurrentSize = 0;
	MaxSize = n;
	IsMaxHeap = big;
	Data = (T *)malloc(sizeof(T) * MaxSize);
	if (!Data)
		return;
}
 
template<class T>
MHeap<T>::~MHeap()
{
	free(Data);
}
 
template<class T>
void MHeap<T>::BuildHeap()
{
	for (int i = (CurrentSize >> 1) - 1; i >= 0; i--) 
		ShiftDown(i); 
}
 
template<class T>
void MHeap<T>::ShiftDown(int pos)
{
	int index = pos;
	T temp = Data[index];
	
	for (int child = ((index << 1) + 1); child < CurrentSize; 
		index = child, child = ((index << 1) + 1)) {
		if((child < CurrentSize - 1)&& Cmp(Data[child], Data[child + 1]))
			child++;
		if(Cmp(Data[child], temp))
			break;
 
		Data[index] = Data[child];
	}
	
	Data[index]=temp;
}
 
template<class T>
void MHeap<T>::ShiftUp(int pos) 
{
	int index = pos;
	T temp = Data[index];
	while(index > 0) {
		int parent = ((index - 1) >> 1);
		if (Cmp(temp, Data[parent]))
			break;
			
		Data[index] = Data[parent];
		index = parent;
	}
	Data[index] = temp;
}
 
template<class T>
bool MHeap<T>::Push(const T& val)
{
	if(CurrentSize == MaxSize)
		return false;
	Data[CurrentSize] = val;
	ShiftUp(CurrentSize);
	CurrentSize++;
	return true;
}
 
template<class T>
bool MHeap<T>::Top(T &val)
{	
	if(CurrentSize==0)
		return false;
 
	val = Data[0];
	return true;
}
 
template<class T>
void MHeap<T>::Pop()
{	
	if(CurrentSize==0)
		return;
 
	Data[0] = Data[--CurrentSize];
	ShiftDown(0);
	
	return;
}
 
template<class T>
bool MHeap<T>::Remove(int pos, T& val)
{
	T temp = Data[pos];
	
	if(pos < 0 || pos >= CurrentSize)
		return false;
 
	Data[pos] = Data[--CurrentSize];
	ShiftUp(pos);
	ShiftDown(pos);
	val = temp;
	
	return true;
}
 
template<class T>
bool MHeap<T>::Empty()
{
	return CurrentSize <= 0;
}
 
#endif
 
 
int main(int argc, char **argv)
{
	MHeap<int> heap(256, 1);
	
	for (int i = 1; i < argc; i++) {
		int tmp = atoi(argv[i]);
		heap.Push(tmp);
	}
		
	while(!heap.Empty()) {
		int res;
		heap.Top(res);
		printf("%d\n", res);
		heap.Pop();
	}
	
	return 0;
}
