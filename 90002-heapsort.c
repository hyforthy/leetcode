#include <stdio.h>
#include <stdlib.h>

void adjust(int *array, int n)
{
	int tt = array[0];
	int child;
	int i;
	
	for (i = 0; (child = (i << 1) + 1) < n; i = child) {
		
		if (child + 1 < n && array[child] < array[child + 1])
			child++;
			
		if (tt >= array[child])
			break;
			
		array[i] = array[child];
	}
	
	array[i] = tt;	
}


void heapsort(int *array, int n)
{
	int i = n / 2;
	
	for (; i >= 0; i--) {
		adjust(array + i, n - i);
	} 
	
	for (i = n - 1; i > 0; i--) {
		int tt = array[0];
		array[0] = array[i];
		array[i] = tt;
		adjust(array, i);
	}
	
	
}

int main()
{

	int a[] = {2, 1, 5, 8, 6, 5, 4, 9, 3, 0, 7, 10};
	int i = 0, n = sizeof(a) / sizeof(a[0]);
	heapsort(a, n);
	
	for (; i < n; i++)
		printf("%d\t", a[i]);
		
	return 0;
}