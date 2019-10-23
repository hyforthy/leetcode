/*
Description
For the daily milking, Farmer John's N cows (1 ≤ N ≤ 50,000) always line up in the same order. One day Farmer John decides to organize a game of Ultimate Frisbee with some of the cows. To keep things simple, he will take a contiguous range of cows from the milking lineup to play the game. However, for all the cows to have fun they should not differ too much in height.
Farmer John has made a list of Q (1 ≤ Q ≤ 200,000) potential groups of cows and their heights (1 ≤ height ≤ 1,000,000). For each group, he wants your help to determine the difference in height between the shortest and the tallest cow in the group.
Input
Line 1: Two space-separated integers, N and Q. 
Lines 2..N+1: Line i+1 contains a single integer that is the height of cow i 
Lines N+2..N+Q+1: Two integers A and B (1 ≤ A ≤ B ≤ N), representing the range of cows from A to B inclusive.
Output
Lines 1..Q: Each line contains a single integer that is a response to a reply and indicates the difference in height between the tallest and shortest cow in the range.
Sample Input
6 3
1
7
3
4
2
5
0 4
3 5
1 1
Sample Output
6
3
0
*/
 
/*
RMQ(Range Minimum/Maximum Query)问题：
   RMQ问题是求给定区间中的最值问题。当然，最简单的算法是O(n)的，但是对于查询次数很多（设置多大100万次），O(n)的算法效率不够。可以用线段树将算法优化到O（logn)（在线段树中保存线段的最值）。不过，Sparse_Table算法才是最好的：它可以在O(nlogn)的预处理以后实现O(1)的查询效率。下面把Sparse Table算法分成预处理和查询两部分来说明(以求最小值为例)。 
预处理:
预处理使用DP的思想，f(i, j)表示[i, i+2^j - 1]区间中的最小值，我们可以开辟一个数组专门来保存f(i, j)的值。
例如，f(0, 0)表示[0,0]之间的最小值,就是num[0], f(0, 2)表示[0, 3]之间的最小值, f(2, 4)表示[2, 17]之间的最小值
注意, 因为f(i, j)可以由f(i, j - 1)和f(i+2^(j-1), j-1)导出, 而递推的初值(所有的f(i, 0) = i)都是已知的
所以我们可以采用自底向上的算法递推地给出所有符合条件的f(i, j)的值。
查询:
假设要查询从m到n这一段的最小值, 那么我们先求出一个最大的k, 使得k满足2^k <(n - m + 1).
于是我们就可以把[m, n]分成两个(部分重叠的)长度为2^k的区间: [m, m+2^k-1], [n-2^k+1, n];
而我们之前已经求出了f(m, k)为[m, m+2^k-1]的最小值, f(n-2^k+1, k)为[n-2^k+1, n]的最小值
我们只要返回其中更小的那个, 就是我们想要的答案, 这个算法的时间复杂度是O(1)的.
例如, rmq(0, 11) = min(f(0, 3), f(4, 3))
*/
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;
 
#define maxs( a , b ) a>b?a:b
#define mins( a , b ) a>b?b:a
const int MAX_N = 50005;
 
int d[MAX_N];
int dpmin[MAX_N][20];
int dpmax[MAX_N][20];
int n;
 
void create_Dpmin(){
     int i , j;
     for(i = 0; i < n; i++)
          dpmin[i][0] = d[i];
     for(j = 1; j <= log((double)n) / log(2.0); j++) {
          for(i = 0; i + (1 << j) - 1 < n ; i++){
               dpmin[i][j] = mins(dpmin[i][j - 1], dpmin[i + (1 << (j - 1))][j - 1]);    
          }
     }     
}
void create_Dpmax(){
     int i , j;
     for(i = 1; i < n; i++)
          dpmax[i][0] = d[i];
     for(j = 1 ; j <= log((double)n) / log(2.0); j++){
          for(i = 1; i + (1 << j) - 1 < n; i++){
               dpmax[i][j] = maxs( dpmax[i][j - 1] , dpmax[i + (1 << (j - 1))][j - 1] );    
          }
     }     
}
 
int getmax( int a , int b ){
    int k = (int)(log((double)(b - a + 1)) / log(2.0));
    return maxs(dpmax[a][k], dpmax[b - (1 << k) + 1][k]);    
}
 
int getmin( int a , int b ){
    int k = (int)(log((double)(b-a+1))/log(2.0));
    return mins(dpmin[a][k] , dpmin[b - (1 << k) + 1][k]);    
}
void Init()
{
     create_Dpmin();
     create_Dpmax();     
}
 
int main()
{   
    freopen( "in.txt" , "r" , stdin );
    int i, m, a, b;
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
           scanf("%d",&d[i]); 
    } 
    Init();
    while(m--){
           scanf("%d%d",&a,&b);     
           printf("%d\n",getmax(a,b) - getmin(a,b));  
    }   
    return 0;    
}

