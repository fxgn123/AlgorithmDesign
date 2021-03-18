#include<stdio.h>
#include<malloc.h>

#define MAX_VERTEX_NUM 10

typedef struct {//定义图的数据结构
	int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//矩阵用于存储权重
	int vexnum;//节点数
	int edgenum;//边数
}MGraph;
void kruskal(MGraph* G);
void readin();

int main() {
	readin();
	return 0;
}
void readin() {
	MGraph* mgraph = (MGraph*)malloc(sizeof(MGraph));
	int i = -1;
	int START;
	printf("请输入有几个节点，有几条边:");
	scanf("%d %d", &mgraph->vexnum, &mgraph->edgenum);
	printf("请输入图的邻接矩阵:\n");
	for (int a = 0; a < mgraph->vexnum; a++) {
		for (int b = 0; b < mgraph->vexnum; b++) {
			scanf("%d", &mgraph->edges[a][b]);
		}
	}
	printf("请输入从哪个节点开始生成最小生成树:");
	scanf("%d", &START);
	kruskal(mgraph);
}
void kruskal(MGraph* G) {
	int min;
	int signa, signb;
	int visited[MAX_VERTEX_NUM] = { 0 };//保存已经存的节点
	for (int x = 0; x < G->vexnum - 1; x++) {
		min = 100;
		for (int a = 0; a < G->vexnum; a++) {
			for (int b = 0; b < G->vexnum; b++) {
				if ((G->edges[a][b] <= min) && (!(visited[a] && visited[b]))&& (G->edges[a][b] != 0)) {
					min = G->edges[a][b];
					signa = a;
					signb = b;
				}
			}
		}
		visited[signa] = 1;
		visited[signb] = 1;
		printf("节点:%d 节点:%d 权重:%d\n", signa, signb, G->edges[signa][signb]);
	}
	
}