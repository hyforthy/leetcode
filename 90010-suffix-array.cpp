// 后缀数组

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXN 1000001
int wa[MAXN],wb[MAXN],wv[MAXN],ws[MAXN];
 
int cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a + l] == r[b + l];
}
 
/* douling algrithm 求字符串r的后缀数组，r最后一个字符是人为设定的0('\0')，
 * 后缀数组sa实际从sa[1]还是有效(sa[0]就是那个人为设定的0)
 */
void CalSA(int *r, int *sa, int n, int m)
{
	int i, j, p, *x = wa, *y = wb, *t;
	
	// 各个后缀按第一个字符排序， 计数排序
	for(i = 0; i < m; i++) 
		ws[i] = 0;
	for(i = 0; i < n; i++)
		ws[x[i] = r[i]]++;
	for(i = 1; i < m; i++)
		ws[i] += ws[i - 1];
	for(i = n - 1; i >= 0; i--)
		sa[--ws[x[i]]] = i;
		
	for(j = 1, p = 1; p < n; j *= 2, m = p) {
	// 各个后缀按前j + 1个字符排序，基数排序
		// 各个后缀按第二关键字排序
		for(p = 0, i = n - j; i < n; i++)
			y[p++] = i;
		for(i = 0; i < n; i++) {
			if(sa[i] >= j)
				y[p++] = sa[i] - j;
		}
		
		// 各个后缀按第一关键字排序，计数排序
		for(i = 0;i < n; i++)
			wv[i] = x[y[i]];
		for(i = 0; i < m; i++)
			ws[i] = 0;
		for(i = 0; i < n; i++)
			ws[wv[i]]++;
		for(i = 1; i < m; i++)
			ws[i] += ws[i-1];
		for(i = n - 1; i >= 0; i--)
			sa[--ws[wv[i]]] = y[i];
		
		// 计算名次数组x，前j + 1个字符相同的后缀名次相同
		for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
     }
	 
     return;
}
 
int rank[MAXN], height[MAXN];
 
/* 求名次相邻的两个后缀之间的最长公共前缀(lcp)
 * height[i] = lcp(suffix(sa(i)), suffix(sa(i - 1)))
 */
void CalHeight(int *r,int *sa,int n)
{
	int i, j, k = 0;
	for(i = 1; i <= n; i++)
		rank[sa[i]] = i;
	for(i = 0; i < n; height[rank[i++]] = k) {
		for(k?k--:0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++)
			;
	}
	return;
}
 
 
int log2[MAXN];
int dpmin[MAXN][20];
void InitRMQ(int n)
{
	// log2[i]等于满足条件 2^k < i(k为大于等于0的整数) 的最大k值
	// 亦即log2[i]就是小于等于LOG2(i)的最大整数
	log2[0] = -1;
	for(int i = 1; i <= n; i++)
		log2[i] = ((i & (i - 1)) == 0) ? log2[i - 1] + 1 : log2[i - 1];
	
	// dpmin[i][j]代表RMQ中在[i, i + 2^j - 1]区间范围内最小的元素ID
	for(int i = 1; i <= n; i++)
		dpmin[i][0] = i;
	for(int j = 1; j <= log2[n]; j++) {
		for(int i = 1; i <= n + 1 - (1 << j); i++) {
			int tmp1 = dpmin[i][j - 1];
			int tmp2 = dpmin[i + (1 << (j - 1))][j - 1];
			
			if(height[tmp1] < height[tmp2]) 
				dpmin[i][j] = tmp1;
			else 
				dpmin[i][j] = tmp2;
		}
	}
	
     return;
}
 
/* 求RMQ中[a, b]区间范围内最小的元素ID
 */
int AskRMQ(int a, int b)
{
    int tmp;
	
    tmp = log2[b - a + 1];
	b = b - (1 << tmp) + 1;
    a = dpmin[a][tmp];
	b = dpmin[b][tmp];
	
    return height[a] < height[b] ? a : b;
}
 
/* 计算后缀 suffix(a) 和 suffix(b) 的最长公共前缀(lcp)
 * a不能等于b
 */
int CalLcp(int a,int b)
{
	a = rank[a];
	b = rank[b];
	
	if(a > b) {
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	
	return height[AskRMQ(a + 1, b)];
}
 
int main()
{
	int r[256], sa[256];
	const char *str = "abcabdabcddabd";
	
	for (int i = 0; i <= strlen(str); i++)
		r[i] = str[i];
		
	CalSA(r, sa, strlen(str) + 1, 'z' + 1);
	
	for (int i = 1; i <= strlen(str); i++)
		printf("%d: %s\n", sa[i], str + sa[i]);
	
	CalHeight(r, sa, strlen(str));
	for (int i = 1; i <= strlen(str); i++)
		printf("%d\n", height[i]);
		
	InitRMQ(strlen(str));
	printf("CalLcp: %d, %d, %d\n", CalLcp(0, 6), CalLcp(3, 9), CalLcp(3, 6));
	return 0;

}