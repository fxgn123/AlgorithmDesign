#include<stdio.h>
#include<malloc.h>

#define MAX_VERTEX_NUM 10

typedef struct {//����ͼ�����ݽṹ
	int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�������ڴ洢Ȩ��
	int vexnum;//�ڵ���
	int edgenum;//����
}MGraph;
void kruskal(MGraph* G);
void Prim(MGraph* G, int START);
void readin();

int main() {
	readin();
	return 0;
}

void Prim(MGraph* G, int START) {//Prim�㷨
	int visited[MAX_VERTEX_NUM] = { 0 };//�����Ѿ���Ľڵ�
	int prevex[MAX_VERTEX_NUM] = { -1 };//�����Ѵ�ڵ��ǰ���ڵ�
	int sign;//��ǵ�ǰ�����ڵ�
	for (int i = 0; i < G->vexnum; i++) {//��a������С������
		if (i == START) {
			visited[i] = 1;//��ָ��i�ڵ����
			sign = i;//��ǵ�ǰ�����ڵ�
			break;
		}
	}
	for (int j = 0; j < G->vexnum - 1; j++) {
		int min = 100;//�����СȨֵ
		int sign1 = -1;
		for (int i = 0; i < G->vexnum; i++) {
			if ((G->edges[sign][i] != 0) && (visited[i] == 0) && (G->edges[sign][i] < min)) {
				min = G->edges[sign][i];
				sign1 = i;
			}
			if ((i == G->vexnum - 1) && (sign1 != -1)) {
				visited[sign1] = 1;
				prevex[sign1] = sign;
				sign = sign1;
			}
		}
	}
	for (int i = 0, sign2 = START; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			if (prevex[j] == sign2) {
				printf("�ڵ�:%d �ڵ�:%d Ȩ��:%d\n", sign2, j, G->edges[sign2][j]);
				sign2 = j;
			}
		}
	}
}
void readin() {
	MGraph* mgraph = (MGraph*)malloc(sizeof(MGraph));
	int i = -1;
	int START;
	printf("�������м����ڵ㣬�м�����:");
	scanf("%d %d", &mgraph->vexnum, &mgraph->edgenum);
	printf("������ͼ���ڽӾ���:\n");
	for (int a = 0; a < mgraph->vexnum; a++) {
		for (int b = 0; b < mgraph->vexnum; b++) {
			scanf("%d", &mgraph->edges[a][b]);
		}
	}
	printf("��������ĸ��ڵ㿪ʼ������С������:");
	scanf("%d", &START);
	//kruskal(mgraph);
	Prim(mgraph, START);
}
void kruskal(MGraph* G) {
	int min;
	int signa, signb;
	int visited[MAX_VERTEX_NUM] = { 0 };//�����Ѿ���Ľڵ�
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
		printf("�ڵ�:%d �ڵ�:%d Ȩ��:%d\n", signa, signb, G->edges[signa][signb]);
	}
	
}