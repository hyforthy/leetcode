// 图的邻接表和邻接矩阵表示
// 
// 图的算法：深度优先遍历、广度优先遍历、拓扑排序、Dijkstra算法（单源最短路径）、floyd算法（每对顶点之间的最短距离）
// 
//      Prim算法（最小生成树）、Kruskal算法（最小生成树）
// 



/*
 * 图的表示及相关算法的实现
 
 * class类：
 * GraphMatrix 邻接矩阵形式
 * GraphList 邻接表形式
 *
 * api接口：
 * GraphTraverse 图的遍历
 * NonPreFirstTopsort 无前趋的顶点优先的拓扑排序
 * DfsTopsort 有向无环图深度优先遍历拓扑排序
 * Dijkstra Dijkstra算法
 * Floyd floyd算法
 * Prim Prim算法
 * KruskalKruskal算法
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <stack>
#include <queue>
#include "heap"
 
using namespace std;
 
enum {
	UNVISITED,
	VISITED
};
 
#define INFINITY 100000000
 
 
/**************** 图的边的定义 ***************/
struct Edge
{
	// from是边的始点, to是边的终点, weight是边的权值
	int from, to, weight;
	
	
	Edge()                 //构造函数
	{
		from = -1;   
		to = -1;  
		weight = 0;
	}
	
	Edge(int f,int t,int w)  //构造函数
	{
		from = f;   
		to = t;   
		weight = w;
	}
 
	
	bool operator >=(const Edge e) const
	{
		return weight > e.weight;
	}
	
	bool operator <=(const Edge e) const
	{
		return weight < e.weight;
	}
};
 
/**************** 图的定义 ***************/
class Graph
{
public:	
	Graph(int n)
	{
		NVertex = n;
		NEdge = 0;
		InDegree = new int[NVertex];
		Mark = new int[NVertex];
		for(int i = 0; i < NVertex; i++)
		{
			Mark[i] = UNVISITED;
			InDegree[i] = 0;
		}
	}
	
	~Graph()                         // 析构函数
	{
		delete [] Mark;
		delete [] InDegree;
	}
	
	int GetVertexNum()
	{
		return NVertex;
	}
	
	int GetEdgeNum()
	{
		return NEdge;
	}
	
	bool IsEdge(const Edge e)
	{
		return e.to >= 0 && e.weight > 0 && e.weight < INFINITY;
	}
	
	int GetFromVertex(Edge e)
	{
		return e.from;
	}
	
	int GetToVertex(Edge e)
	{
		return e.to;
	}
	
	int GetWeight(Edge e)
	{
		return e.weight;
	}
	
	int *GetMark()
	{
		return Mark;
	}
	
	void ClearMark() 
	{
		for (int i = 0; i < NVertex; i++)
			Mark[i] = UNVISITED;
	}
	
	int *GetInDegree() 
	{
		return InDegree;
	}
	
	// 返回与顶点v相关联的第一条边
	virtual const Edge &GetFirstEdge(int v) = 0;
	
	// 返回与边e有相同关联顶点e的下一条边
	virtual const Edge &GetNextEdge(const Edge &e) = 0;
	
	virtual void SetEdge(int from, int to, int weight) = 0;
	virtual void DelEdge(int from, int to) = 0;
	
protected:
	int NVertex;       // 最多可以保存的图的顶点的个数
	int NEdge;     	   // 图的边的个数
	int *Mark;         // Mark标记顶点是否访问过
	int *InDegree;     // Indegree保存顶点的入度
};
 
 
/**************** 邻接矩阵表示的图 ***************/
class GraphMatrix: public Graph   
{
private:
	int **GMatrix;           // 指向相邻矩阵的指针
 
public:
 
	// n是图的顶点数
	GraphMatrix(int n): Graph(n)
	{
		GMatrix = (int**)new int*[NVertex];
		
		for(int i = 0; i < NVertex; i++)
			GMatrix[i]  =  new int[NVertex];
 
		for(int i = 0; i < NVertex; i++) {              
			for(int j = 0; j < NVertex; j++)
				GMatrix[i][j] = 0;
		}
	}
	
	~GraphMatrix()
	{
		for(int i = 0; i < NVertex; i++)
			delete [] GMatrix[i];
		delete [] GMatrix;
	}
	
	const Edge &GetFirstEdge(int v)
	{
		static Edge e;
		e.from = v;
		e.to = -1;
		e.weight = 0;
		
		for(int i = 0;i < NVertex; i++) {
			if(GMatrix[v][i] != 0) {
				e.to = i;
				e.weight = GMatrix[v][i];
				break;
			}   
		}
		
		return e;
	}
	
	const Edge &GetNextEdge(const Edge &e)
	{
		static Edge e1;
		
		e1.from = e.from;
		e1.to = -1;
		e1.weight = 0;
		
		for(int i = e.to + 1; i < NVertex; i++) {
			if(GMatrix[e.from][i] != 0) {
				e1.to = i;
				e1.weight = GMatrix[e.from][i];
				break;
			}
		}
		
		return e1;
	}
	
	void SetEdge(int from, int to, int weight)
	{
		if (weight <= 0 || weight >= INFINITY)
			weight = 0;
		else {
			if (GMatrix[from][to] == 0) {
				NEdge++;
				InDegree[to]++;
			}
		}			
		
		GMatrix[from][to] = weight;          
	}
	
	void DelEdge(int from, int to)
	{
		if(GMatrix[from][to] != 0) {		
			NEdge--;
			InDegree[to]--;
		}
		GMatrix[from][to] = 0;       
	}
};
 
 
/**************** 邻接表表示的图 ***************/
struct ListNode      // 邻接表节点定义
{
	int vertex;      // 边的终点
	int weight;      // 边的权
	
	ListNode(int v, int w)
	{
		vertex = v;
		weight = w;
	}
	
	bool operator ==(const ListNode ln)
	{
		return vertex == ln.vertex;
	}
};
 
 
class GraphList: public Graph                    
{
public:
	GraphList(int n): Graph(n)
	{
		GList = new list<ListNode> *[NVertex];
		for (int i = 0; i < NVertex; i++) {
			GList[i] = new list<ListNode>;
		}
	}
	
	~GraphList()
	{
		for (int i = 0; i < NVertex; i++) {
			delete GList[i];
		}
		delete [] GList;
	}
	
	const Edge &GetFirstEdge(int v)              //返回顶点oneVertex的第一条边
	{
		static Edge e;
		list<ListNode> *temp = GList[v];
		list<ListNode>::iterator it = temp->begin();
		
		e.from = v;
		e.to = -1;
		e.weight = 0;
		
		if(it != temp->end())
		{
			e.to = it->vertex;
			e.weight = it->weight;
		}
		
		return e;
	}
	
	const Edge &GetNextEdge(const Edge &e)
	{
		static Edge e1;
		list<ListNode> *temp = GList[e.from];           
		list<ListNode>::iterator it = temp->begin();
		
		e1.from = e.from;
		e1.to = -1;
		e1.weight = 0;
		
		while (it != temp->end() && it->vertex <= e.to)
			it++;
			
		if (it != temp->end()) {
			e1.to = it->vertex;
			e1.weight = it->weight;   
		}
		
		return e1;
	}
	
	void SetEdge(int from, int to, int weight)   // 为图设定一条边
	{
		ListNode node(to, weight);
		list<ListNode> *temp = GList[from];
		list<ListNode>::iterator it = temp->begin();
		
		while(it != temp->end() && it->vertex < to)
			it++;
		
		if (it != temp->end() && it->vertex == to) {
			it->weight = weight;
			return;
		}
		
		temp->insert(it, node);
		NEdge++;
		InDegree[to]++;
		
		return;
	}
		
	void DelEdge(int from,int to)
	{
		list<ListNode> *temp = GList[from];
		list<ListNode>::iterator it = temp->begin();
		
		while(it != temp->end() && it->vertex < to)
			it++;
		
		if (it != temp->end() && it->vertex == to) {
			temp->erase(it);
			NEdge--;
			InDegree[to]--;
		}
		
	}
 
private:
	list<ListNode> **GList;
 
};
 
 
 
 
//typedef void (*CallbackFunc)(void *data);
 
/************** 图相关算法部分 *************/
 
// 深度优先遍历：
void DFS(Graph &g, int v)
{
	int *mark = g.GetMark();
	mark[v] = VISITED;	
	printf("%d ", v);
	
	for(Edge e = g.GetFirstEdge(v); g.IsEdge(e); e = g.GetNextEdge(e)) {
		int vertex = g.GetToVertex(e);
		if(vertex >= 0 && mark[vertex] == UNVISITED) {
			DFS(g, vertex); 
		}
	}
		
	return;
}
 
// 广度优先遍历
void BFS(Graph& g, int v)
{
	queue<int> q;
	int *mark = g.GetMark();
	
	mark[v]= VISITED;
	q.push(v);
	printf("%d ", v);
	
	while(!q.empty()) {
		int vertex = q.front();
		q.pop();
		
		for(Edge e = g.GetFirstEdge(vertex); g.IsEdge(e); e = g.GetNextEdge(e)) { 
			int vertex2 = g.GetToVertex(e);
			if(vertex2 >= 0 && mark[vertex2]== UNVISITED) {    
				mark[vertex2]= VISITED;
				printf("%d ", vertex2);
				q.push(vertex2); 
			}   
		}
	}
	
	return;
}
 
// 图的遍历
void GraphTraverse(Graph& g, bool dfs)
{
	int *mark = g.GetMark();
	int nvertex = g.GetVertexNum();
	g.ClearMark();
	
	for(int i = 0; i < nvertex; i++) {
		if(mark[i]== UNVISITED) {
			if(dfs)
				DFS(g, i);       //深度优先搜索
			else
				BFS(g, i);       //广度优先搜索
		}
	}
	
	return;
}
 
// 无前趋的顶点优先的拓扑排序
void NonPreFirstTopsort(Graph& g)                     
{
	queue<int> q;
	int nvertex = g.GetVertexNum();
	int *mark = g.GetMark();
	int *indegree = new int[nvertex];
	
	memcpy(indegree, g.GetInDegree(), sizeof(int) * nvertex);
	g.ClearMark();
	
	// 图中无前驱的顶点入队
	for(int i = 0; i < nvertex; i++) {
		if(indegree[i] == 0)
			q.push(i);                            
	}
	
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		printf("%d ", v);
		mark[v] = VISITED;
		
		for(Edge e = g.GetFirstEdge(v); g.IsEdge(e); e = g.GetNextEdge(e)) {
			int vertex = g.GetToVertex(e);
			indegree[vertex]--;
			
			// 入度为零说明前面的顶点都已经处理，接下来可以处理此节点
			if(indegree[vertex] == 0)
				q.push(vertex);
		}
	}
	
	for(int i = 0; i < nvertex; i++) { 
		if(mark[i] == UNVISITED) {            
			printf("ERROR:graph is circled\n");        //图有环
			break;
		}
	} 
	
	delete [] indegree;
	return;
}
 
 
void DoTopsort(Graph& g, int v,int *result,int &tag)
{
	int *mark = g.GetMark();
	
	mark[v]= VISITED;
	for(Edge e =  g.GetFirstEdge(v); g.IsEdge(e); e = g.GetNextEdge(e)) {  
		if(mark[g.GetToVertex(e)] == UNVISITED)
			DoTopsort(g, g.GetToVertex(e),result,tag);
	}
	result[tag++] = v;
	
	return;
}
 
// 有向无环图(Directed Acyclic Graph)深度优先遍历拓扑排序
void DfsTopsort(Graph& g)
{
	int nvertex = g.GetVertexNum();
	int *result = new int[nvertex];
	int *mark = g.GetMark();
	int tag = 0;
	
	g.ClearMark();
	for(int i = 0; i < nvertex; i++) {
		if(mark[i] == UNVISITED)
			DoTopsort(g,i,result,tag);
	}
	
	for(int i = nvertex - 1; i >= 0; i--)  
		printf("%d ", result[i]);
	
	delete [] result;
	return;
}
 
// 用于minheap堆，方便快速取得最小的dist
struct DijDist
{
	int vertex;
	int distance;
	
	DijDist(int v = -1, int d = INFINITY)
	{
		vertex = v;
		distance = d;
	} 
	
	bool operator <=(const DijDist &elem) const
	{
		return distance <= elem.distance;
	}
	
	bool operator >=(const DijDist &elem) const
	{
		return distance >= elem.distance;
	}
};
 
 
// Dijkstra算法（单源最短路径），dist保存src到各个点的距离，path
// 中保存src到各个点的最短路径上的点, dist、path都无需外部初始化
// path[i]是src到i的最短路径上紧邻i的前面的点
void Dijkstra(Graph& g, int src, int *dist, int *path)
{
	int nvertex = g.GetVertexNum();
	int *mark = g.GetMark();
	MHeap<DijDist> minheap(nvertex, 0);
	DijDist de;
	
	de.vertex = src;
	de.distance = 0;
	minheap.Push(de);
	
	for (int i = 0; i < nvertex; i++) {
		dist[i] = INFINITY;
		path[i] = -1;
	}
	dist[src] = 0;
	
	g.ClearMark();
	for(int i = 0; i < nvertex; i++) {
		int v = -1;
		
		do {
			if(minheap.Empty())
				break;
			minheap.Top(de);
			minheap.Pop();
			v = de.vertex;
		} while(mark[v] == VISITED);
	
		if(v == -1 || mark[v] == VISITED)                          
			break;
			
		mark[v] = VISITED;
		
		for(Edge e = g.GetFirstEdge(v); g.IsEdge(e); e = g.GetNextEdge(e)) {
			int vertex = g.GetToVertex(e);
			if(dist[vertex] > (dist[v] + g.GetWeight(e)))
			{
				dist[vertex] = dist[v] + g.GetWeight(e);                 
				de.vertex = vertex;
				de.distance = dist[vertex];
				minheap.Push(de);
				path[vertex] = v;
			}
		}
	} 
}
 
// 打印src到target最短路径上的各个点 
void DijShowPath(int *path, int src, int target)   
{
    stack<int> st;
    while(target != src) {
		st.push(target);
        target = path[target];
		
		// src到target没有到达路径
		if (target == -1) {
			st.push(-1);
			break;
		}
		
    }
	st.push(src);
	
    while(st.size() > 1) {
        printf("%d -> ", st.top());
        st.pop();
    }
	
	printf("%d\n", st.top());
} 
 
// floyd算法，计算每对顶点之间的最短距离
void Floyd(Graph& g,int **dist, int **path)
{
	int nvertex = g.GetVertexNum();
	
	// dist数组, 初始化每对顶点之间的距离
	for(int i = 0;i < nvertex; i++) {
		for(int j = 0; j < nvertex; j++) {
			dist[i][j] = i == j ? 0 : INFINITY;
			path[i][j] = -1;
		}
		
		for(Edge e = g.GetFirstEdge(i); g.IsEdge(e); e = g.GetNextEdge(e)) {
			dist[i][e.to] = g.GetWeight(e);
			path[i][e.to] = i;
		}
	}
 
	
	// 若j、k两个顶点间的最短路径包含顶点i，则有dist[j][k] > (dist[j][i] + dist[i][k])
	// 通过i测试到所有的点，从而更新每对顶点之间距离
	for(int i = 0; i < nvertex; i++) {
		for(int j = 0; j < nvertex; j++) {
			for(int k = 0; k < nvertex; k++) {
				if(dist[j][k] > (dist[j][i] + dist[i][k])) {
					dist[j][k] = dist[j][i] + dist[i][k];
					path[j][k] = i;
				}
			}
		}
	}
	
	for(int i = 0; i < nvertex; i++) {
		for(int j = 0;j < nvertex; j++)
			printf("dist<%d, %d>: %d\n", i, j, dist[i][j]);
	}
	
	for(int i = 0; i < nvertex; i++) {
		for(int j = 0;j < nvertex; j++)
			printf("path<%d, %d>: %d\n", i, j, path[i][j]);
	}
}
 
// 递归打印路径
void FloydShowPath_(int **path, int src, int target) 
{
	if (src == target || path[src][target] == src)
		return;
		
	if (path[src][target] == -1) {	
		printf("-1 -> ");
		return;
	}
 
	FloydShowPath_(path, src, path[src][target]);
	printf("%d -> ", path[src][target]);
	FloydShowPath_(path, path[src][target], target);
}
 
// 打印src到target最短路径上的各个点
void FloydShowPath(int **path, int src, int target) 
{
	if (src == target) {
		printf("%d\n", src);
		return;
	}
	
	printf("%d -> ", src);
	FloydShowPath_(path, src, target);
	printf("%d\n", target);
}
 
 
// Prim算法, 最小生成树（Minimum Spanning Tree）
// 用于无向图、稠密图（边很多）
void Prim(Graph& g, int src)        
{ 
	int nvertex = g.GetVertexNum();
	int *mark = g.GetMark();
	int nedge = g.GetEdgeNum();
	MHeap<Edge> minheap(nedge, 0);
	Edge *mst = new Edge[nedge];
	int nmst = 0;
	
	if (nedge < nvertex - 1) {
		printf("Error: NO MST\n");
		return;
	}
	
	g.ClearMark();
	mark[src] = VISITED;
 
	for(Edge e = g.GetFirstEdge(src); g.IsEdge(e); e = g.GetNextEdge(e))
		minheap.Push(e);
	
	for(int i = 1; i < nvertex; i++) {
		Edge temp;
		int v = -1;
		
		// 寻找权值最小的边
		do {
			if(minheap.Empty())
				break;
			minheap.Top(temp);
			minheap.Pop();
			v = temp.to;
		} while(mark[v] == VISITED);
		
		if (v == -1 || mark[v] == VISITED)
			break;
 
		// 添加到mst中
		mst[nmst++] = temp;
		mark[temp.to] = VISITED;
		for(Edge e = g.GetFirstEdge(temp.to); g.IsEdge(e); e = g.GetNextEdge(e)) {
			if(mark[e.to] == VISITED)
				continue;    
			minheap.Push(e);
		}
	} 
	
	if (nmst < nvertex - 1) {
		printf("Error: NO MST\n");
		return;
	}
		
	for (int i = 0; i < nmst; i++) {
		printf("%d -> %d: %d\n", mst[i].from, mst[i].to, mst[i].weight);
	}
}
 
// 并查集用于Kruskal算法
class UnionFind
{
private:
	int *ancestor;             
	int size;
	
public:
	UnionFind(int n)
	{
		size = n;
		ancestor = new int[n];
		for(int i = 0; i < n; i++) {
			// 每一个元素的祖先节点是它本身
			ancestor[i] = i;  
		}
	}
	~UnionFind()
	{
		delete [] ancestor;
	}
	
	// 寻找祖先节点
	int Find(int a)
	{
		if(a != ancestor[a]) { 
			//回溯时的压缩路径  
			ancestor[a] = Find(ancestor[a]);
		}
		
		return ancestor[a];  
	}
	
	// 合并a和b所在的集合
	void Union(int a,int b)     
	{
		int root1 = Find(a);
		int root2 = Find(b);
		if(root1 < root2) 
			ancestor[root2] = root1;
		else if (root1 > root2)
			ancestor[root1] = root2;
	}
	
	// a和b是否在同一集合中
	bool Differ(int a,int b)    
	{
		int root1 = Find(a);
		int root2 = Find(b);
		return root1 != root2;
	}
};
 
// Kruskal算法，最小生成树（Minimum Spanning Tree）
// 通过小堆、并查集实现
void Kruskal(Graph& g)       
{
	int nvertex = g.GetVertexNum();
	int nedge = g.GetEdgeNum();
	MHeap<Edge> minheap(nedge, 0);
	Edge *mst = new Edge[nedge];
	UnionFind uf(nvertex);
	int nmst = 0;
	
	if (nedge < nvertex - 1) {
		printf("Error: NO MST\n");
		return;
	}
	
 
	
	// 图的所有边push入堆
	for(int i = 0; i < nvertex; i++) {
		for(Edge e =  g.GetFirstEdge(i); g.IsEdge(e); e = g.GetNextEdge(e)) {   
			// 无向图可以加此条件判断，减少冗余边处理
			// if(g.GetFromVertex(e) < g.GetToVertex(e))
			minheap.Push(e);  
		}
	}
	
	for(int i = 1; i < nvertex; ) {
		Edge e;
		int from;
		int to;
		
		// 获得下一条权值最小的边
		minheap.Top(e);
		minheap.Pop();
		
		from = g.GetFromVertex(e);   //记录该条边的信息
		to =  g.GetToVertex(e);
		
		if(uf.Differ(from,to))       //如果边e的两个顶点不在一个等价类
		{
			uf.Union(from,to);       //将边e的两个顶点所在的两个等价类合并为一个
			mst[nmst++] = e;
			i++;
		}
	}
	
		
	if (nmst < nvertex - 1) {
		printf("Error: NO MST\n");
		return;
	}
		
	for (int i = 0; i < nmst; i++) {
		printf("%d -> %d: %d\n", mst[i].from, mst[i].to, mst[i].weight);
	}
}
 
 
/* 输入形式：
 * line1：图的表示形式（1 邻接矩阵，0 邻接表）
 * line2：图是否有向图（1 有向图， 0 无向图）
 * line3：图的顶点数
 * line4：图的边数
 * line5 ~ end ：图的边（from to weight 空格隔开）
 */
int main()
{
	int gform;					// 图的表示形式
	int directed;				// 图是否有向图
	int nvertex;				// 图的顶点数
	int nedge;					// 图的边数
 
	Graph *g;
	
	scanf("%d", &gform);
	scanf("%d", &directed);
	scanf("%d", &nvertex);
	scanf("%d", &nedge);
	                        
	if(gform == 0)
		g = new GraphList(nvertex);
	else
		g = new GraphMatrix(nvertex);
 
	while (nedge-- > 0) {
		int from, to, weight;       // 每条边的起点、终点和权值
		
		scanf("%d %d %d", &from, &to, &weight);
		g->SetEdge(from, to, weight);
		if (!directed)
			g->SetEdge(to, from, weight);
	}
	
	printf("\n\nDFS:\n");
	GraphTraverse(*g, true);
	printf("\n\n");
	
	printf("BFS:\n");
	GraphTraverse(*g, false);
	printf("\n\n");
	
	printf("NonPreFirstTopsort:\n");
	NonPreFirstTopsort(*g);
	printf("\n\n");
	
	if (directed) {
		printf("DfsTopsort:\n");
		DfsTopsort(*g);
		printf("\n\n");
	}
	
	printf("DijShowPath:\n");
	int *dist = new int[nvertex];
	int *path = new int[nvertex];
	Dijkstra(*g, nvertex / 2, dist, path);
	DijShowPath(path, nvertex / 2, nvertex - 1);
	delete [] dist;
	delete [] path;
	printf("\n");
	
	printf("FloydShowPath:\n");
	int **distt = new int *[nvertex];
	int **pathh = new int *[nvertex];
	for (int i = 0; i < nvertex; i++) {
		distt[i] = new int[nvertex];
		pathh[i] = new int[nvertex];
	}
	Floyd(*g, distt, pathh);
	FloydShowPath(pathh, nvertex / 2, nvertex - 1);
	for (int i = 0; i < nvertex; i++) {
		delete [] distt[i];
		delete [] pathh[i];
	}
	delete [] distt;
	delete [] pathh;
	printf("\n");
	
	printf("Prim:\n");
	Prim(*g, nvertex / 2);
	printf("\n");
	
	printf("Kruskal:\n");
	Kruskal(*g);
	
	
	return 0;

}
