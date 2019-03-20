#include <cstdio>

int qksm(int *src, int num)
{
	if (num < 2)
		return 0;

	int i = 0;
	int j = num - 1;

	int key = src[0];

	while (i < j) {

		while (key <= src[j] && j > i)
			j--;
		if (j > i)
			src[i++] = src[j];

		while(key >= src[i] && i < j)
			i++;
		if (i < j)
			src[j--] = src[i];
	}

	src[i] = key;
	return i;
}

void qksall(int *src, int num)
{
	int pos = qksm(src, num);

	if (num <= 2)
		return;

	qksall(src + pos + 1, num - pos - 1);
	qksall(src, pos);
}

int main()
{
	int data[] = {13};
	qksall(data, sizeof(data) / sizeof(int));

	for (int i = 0; i < sizeof(data) / sizeof(int); i++)
		printf("%d\n", data[i]);
}