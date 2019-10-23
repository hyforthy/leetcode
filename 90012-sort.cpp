
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
/* shell排序 */
void shellsort(int *array, int n)
{
	for (int increment = n / 2; increment > 0; increment /= 2) {
	
		for (int i = increment; i < n; ++i) {
			int j;
			int tmp = array[i];
			
			for (j = i - increment; j >= 0 && tmp < array[j]; j -= increment)
				array[j + increment] = array[j];
			
			array[j + increment] = tmp;
		}
	}
	
	return;
}
 
/* 插入排序 */
void insertsort(int *array, int n)
{
	for (int i = 1; i < n; ++i) {
		int j;
		int tmp = array[i];
		for (j = i - 1; j >= 0 && tmp < array[j]; --j)
			array[j+ 1] = array[j];
		array[j + 1] = tmp;
	}
	
	return;
}
 
/* 二分插入排序 */
void binaryinsertsort(int *array, int n)
{
	for (int i = 1; i < n; ++i) {
		int start = 0, end = i - 1;
		int tmp = array[i];
		
		if (array[end] > tmp) {
			while (start <= end) {
				int mid = (start + end) / 2;
				if (tmp >= array[mid])
					start = mid + 1;
				else if (tmp < array[mid])
					end = mid - 1;
			}
			
			for (int j = i - 1; j >= start; j--)
				array[j + 1] = array[j];
			array[start] = tmp;
		}
		
	}
	
	return;
}
 
/* 冒泡排序 */
void bubblesort(int *array, int n)
{
	for (int i = 1; i < n; ++i) {
		int cond = true;
		for (int j = 0; j < n - i; ++j) {
			if (array[j] > array[j + 1]) {
				int tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;	
				cond = false;
			}
		}
		
		if (cond)
			break;
	}
	
	return;
}
 
/* 鸡尾酒排序（双向冒泡排序） */
void cocktailsort(int *array, int n)
{
	int start = 0, end = n - 1;
	while (start < end) {
		int cond = true;
		for (int i = start; i < end; i++) {
			if (array[i] > array[i + 1]) {
				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;	
				cond = false;
			}
		}
		
		if (cond)
			break;
		end--;
		
		cond = true;
		for (int i = end; i > start; i--) {
			if (array[i] < array[i - 1]) {
				int tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp; 
				cond = false;
			}
		}
		if (cond)
			break;
		start++;
	}
	
	return;
}
 
/* 选择排序 */
void selectsort(int *array, int n)
{
	for (int i = 1; i < n; ++i) {
		int index = n - i;
		
		for (int j = 0; j < n - i; ++j)
			if (array[j] > array[index])
				index = j;
		
		if (index != n - i) {
			int tmp;
			tmp = array[n - i];
			array[n - i] = array[index];
			array[index] = tmp;
		}
	}
	
	return;
}
 
 
void heapadjust1(int *array, int start, int end)
{
	int i;
	int top = array[start];
		
	for (i= start; (i << 1) + 1 <= end;) {
		int tmp = (i << 1) + 1;
		if (tmp + 1 <= end && array[tmp + 1] > array[tmp])
			tmp++;
			
		if (array[tmp] <= top)
			break;
		
		array[i] = array[tmp];
				
		i = tmp;
	}
	
	array[i] = top;
 
}
 
/* 非递归堆排序 */
void heapsort1(int *array, int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
		heapadjust1(array, i, n - 1);
	
	for (int i = n - 1; i > 0; --i) {
		int tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		
		heapadjust1(array, 0, i - 1);
	}
	
	return;
	
}
 
void heapadjust2(int *array, int start, int end)
{
	int top, tmp;
	
	if ((start << 1) + 1 > end )
		return;
	
	top = array[start];
	tmp = (start << 1) + 1;
	if (tmp + 1 <= end && array[tmp + 1] > array[tmp])
		tmp++;
		
	if (array[tmp] <= array[start])
		return;
		
	array[start] = array[tmp];
	array[tmp] = top;
	
	heapadjust2(array, tmp, end);
	
	return;
}
 
/* 递归堆排序 */
void heapsort2(int *array, int n)
{
 
	for (int i = n / 2 - 1; i >= 0; --i)
		heapadjust2(array, i, n - 1);
	
	for (int i = n - 1; i > 0; --i) {
		int tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		
		heapadjust2(array, 0, i - 1);
	}
	
	return;
}
 
 
 
 
 
 
int partition1(int *array, int start, int end)
{
	int mid = array[start];
	
	while(start < end) {
		while(end > start && array[end] >= mid)
			--end;
		array[start] = array[end];
		
		while(start < end && array[start] <= mid)
			++start;
		array[end] = array[start];	
	}
	
	array[start] = mid;
	
	return start;
}
 
/*快速排序1 */
void quicksort1(int *array, int n)
{
	if (n > 1) {
		int cut = partition1(array, 0, n - 1);
		quicksort1(array, cut);
		quicksort1(array + cut + 1, n - cut - 1);
	}
	
	return;
} 
 
int partition2(int *array, int start, int end)
{
	int mid = array[end];
	
	for (int i = start; i < end; ++i) {
		if (array[i] < mid)	{
			int tmp = array[i];
			array[i] = array[start];
			array[start++] = tmp;
		}
	}
	
	array[end] = array[start];
	array[start] = mid;
	
	return start;
}
 
/*快速排序2 */
void quicksort2(int *array, int n)
{
	if (n > 1) {
		int cut = partition2(array, 0, n - 1);
		quicksort2(array, cut);
		quicksort2(array + cut + 1, n - cut - 1);
	}
	
	return;
} 
 
void mergearray(int *array, int start, int mid, int endp1)
{
	int *arraytmp;
	int index;
	int i, j;
	
	arraytmp = (int *)calloc(endp1 - start, sizeof(int));
	if (!arraytmp)
		return;
		
	index = 0;
	for (i = 0, j = mid; i < mid && j < endp1;) {
		arraytmp[index++] = array[i] <= array[j]? array[i++] : array[j++];
	}
	
	while (i < mid)
		array[--j] = array[--mid];
	while (index)
		array[--j] = arraytmp[--index];
	
	/**
	* another method， but the one above is better
	while (j < endp1)
		arraytmp[index++] = array[j++];
	while (i < mid)
		arraytmp[index++] = array[i++];
			
	memcpy(array, arraytmp, (endp1 - start) *	sizeof(int));
	**/
		
	free(arraytmp);
	return;
}
 
/* 递归归并排序 */
void mergesort1(int *array, int n)
{
	if (n > 1) {
		int cut = n / 2;
		mergesort1(array, cut);
		mergesort1(array + cut, n - cut);
		mergearray(array, 0, cut, n);
	}
	return;
}
 
/* 非递归归并排序 */
void mergesort2(int *array, int n)  
{  
    int i, start, mid, endp1, index;  /* endp1 means end + 1 */
    int *arraytmp;
	
	arraytmp = (int*)calloc(n, sizeof(int));
	if (!arraytmp) {
		return;
	}
    
    for (i = 1; i < n; i *= 2)  {
        for (start = 0; start < n - i; start = endp1) {
			int start1;
			mid = start + i;
			endp1 = mid + i;
			start1 = mid;
			
			if (endp1 > n)
				endp1 = n;
			
			while (start < mid && start1< endp1)
				arraytmp[index++] = array[start] <= array[start1]? array[start++]:array[start1++];
			
			while (start < mid)
				array[--start1] = array[--mid];
			while (index)
				array[--start1] = arraytmp[--index];             
        } 
	}		
    
	free(arraytmp); 
	return;	
} 
 
/* 计数排序 */ 
void countingsort(int *array,int n)  
{  
    int i, maxvalue;  
    int *tmp;  
    int *result;
	
  
	maxvalue = 0;
	for (i = 0; i < n; i++)
		maxvalue = maxvalue < array[i]? array[i] : maxvalue;
		
	tmp = (int *)malloc((maxvalue + 1) * sizeof(int));
	if (!tmp)
		return;
	result = (int *)malloc((n) * sizeof(int)); 
	if (!result) {
		free(tmp);
		return;
	}
	
    for(i = 0; i <= maxvalue; i++)  
        tmp[i] = 0;  
    for(i = 0; i < n; i++)  
        tmp[array[i]]++;    
    for(i = 1; i <= maxvalue; i++)  
        tmp[i] += tmp[i-1];  
		
    for(i = n-1; i >= 0; i--)  
    {  
        result[--tmp[array[i]]] = array[i];  
          
    }  
    for(i = 0; i < n; i++)  
        array[i] = result[i];  
	
	free(tmp);
	free(result);
	return;
}   
 
/* 基数排序 */
void radixsort(int *array, int n)  
{    
    int tmp[10]; 
    int radix = 1;
	int maxbit = 0;
    int *result;
    
	int maxvalue = 0;
	for (int i = 0; i < n; i++)
		maxvalue = maxvalue < array[i]? array[i] : maxvalue;
	
	do {
		maxbit++;
		maxvalue /= 10;
	} while (maxvalue != 0);
	
	result = (int *)malloc(n * sizeof(int));
	if (!result)
		return;
		
    for(int i = 0; i < maxbit; i++)  
    {   
	
		/* 下面用的是计数排序， 其实也可用其他稳定排序算法：插入、冒泡、堆等 */
        for(int j = 0; j < 10; j++)  
            tmp[j] = 0;    
        for(int j = 0; j < n; j++)   
            tmp[(array[j] / radix) % 10]++;  
 
        for(int j = 1; j < 10; j++)  
            tmp[j] += tmp[j - 1];  
        for(int j = n - 1; j >= 0; j--)  
        {  
			int tmp1 = (array[j] / radix) % 10;   
            result[--tmp[tmp1]] = array[j];  
        }  
        for(int j = 0; j < n; j++)  
            array[j] = result[j];  
        radix *= 10;  
    }  
	
	free(result);
	return;
}  
 
 
typedef struct  node{  
	int key;
    struct  node* next;  
}keynode;  
 
/* 桶排序, bucketsize一般设为数组元素数 */
void bucketsort(int *array, int n, int bucketsize)  
{  
    int start = 0;
	keynode **bucket;
	int minvalue = 0, maxvalue = 0;
	
	for (int i = 0; i < n; i++) {
		minvalue = minvalue > array[i]? array[i] : minvalue;
		maxvalue = maxvalue < array[i]? array[i] : maxvalue;
	}
		
	bucket = (keynode **)malloc(sizeof(keynode *) * bucketsize);  
    memset(bucket, 0, sizeof(keynode *) * bucketsize);
   
    for(int i = 0; i < n; i++)  
    {  
		keynode * p;
		int index;
        keynode *node = (keynode *)malloc(sizeof(keynode));  
        node->key = array[i];  
        node->next = NULL;  
    
        index = (array[i] - minvalue) * (bucketsize - 1) / (maxvalue - minvalue);
		p = bucket[index];  
 
        if(!p) {  
            bucket[index] = node;  
        }  
        else if (p->key > node->key) {
			bucket[index] = node;
			node->next = p;
		}
		else {
            while((p->next) && p->next->key <= node->key)
				p = p->next;
            node->next = p->next;  
            p->next = node;  
        }  
    }  
	
    for(int i = 0; i < bucketsize; i++) {  
        for(keynode *p = bucket[i]; p; p = p->next) {  
            array[start++] = p->key;
			free(p);
		}
	}
	free(bucket);
	
	return;
}  
 
 
 
 
int main(int argc, char **argv)
{
	int *array;
	
	if (argc < 3) {
		printf("usage: sort [method] [int] <int> ...\n");
		return -1;
	}
	
	array = (int *)calloc(argc - 1, sizeof(int));
	if (!array) {
		printf("malloc failed\n");
		return -1;
	}
	
	for (int i = 2; i < argc; i++)
		array[i - 2] = atoi(argv[i]);
	
	if (!strcmp("shell", argv[1]))
		shellsort(array, argc - 2);
	else if (!strcmp("insert", argv[1]))
		insertsort(array, argc - 2);
	else if (!strcmp("binaryinsert", argv[1]))
		binaryinsertsort(array, argc - 2);
	else if (!strcmp("bubble", argv[1]))
		bubblesort(array, argc - 2);
	else if (!strcmp("cocktail", argv[1]))
		cocktailsort(array, argc - 2);
	else if (!strcmp("select", argv[1]))
		selectsort(array, argc - 2);
	else if (!strcmp("quick1", argv[1]))
		quicksort1(array, argc - 2);
	else if (!strcmp("quick2", argv[1]))
		quicksort2(array, argc - 2);
	else if (!strcmp("heap1", argv[1]))
		heapsort1(array, argc - 2);
	else if (!strcmp("heap2", argv[1]))
		heapsort2(array, argc - 2);
	else if (!strcmp("merge1", argv[1]))
		mergesort1(array, argc - 2);
	else if (!strcmp("merge2", argv[1]))
		mergesort2(array, argc - 2);
	else if (!strcmp("counting", argv[1]))
		countingsort(array, argc - 2);
	else if (!strcmp("radix", argv[1]))
		radixsort(array, argc - 2);
	else if (!strcmp("bucket", argv[1]))
		bucketsort(array, argc - 2, argc - 2);
	else {
		printf("method wrong\n");
		return -1;
	}
	
	for (int i = 0; i < argc - 2; i++)
		printf("%d ", array[i]);
	printf("\n");
	
	free(array);
 
	return 0;
}

