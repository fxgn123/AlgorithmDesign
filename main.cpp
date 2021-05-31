#include<stdio.h>
#define MAXNUM 100
#define MAXHUFF 100
#define MAXWEIGHT 1000
typedef struct {
	int weight;
	char ch;
	int parent;
	int lchild;
	int rchild;
}HFN;
typedef struct {
	int code[MAXNUM];
	int start;
}HFC;

HFN huffman[MAXHUFF];
HFC code[MAXHUFF+1];

void HFMtreebulid(int n) {
	for (int i = 0; i < n * 2 - 1; ++i) {//初始化
		huffman[i].weight = 0;
		huffman[i].parent = -1;
		huffman[i].lchild = -1;
		huffman[i].rchild = -1;
	}
	for (int i = 0; i < n; i++) {
		printf("请分别输入第%d个哈夫曼字符和权重", i);
		getchar();
		scanf("%c", &huffman[i].ch);
		scanf("%d", &huffman[i].weight);
		//getchar();
		//printf("%c...%d...\n", huffman[i].ch, huffman[i].weight);
		//getchar();
	}
	int x1, w1, x2, w2;
	for (int i = 0; i < n - 1; i++) {
		x1 = -1;
		x2 = -1;
		w1 = MAXWEIGHT;
		w2 = MAXWEIGHT;
		for (int j = 0; j < n + i; j++) {
			if ((huffman[j].parent == -1) && (huffman[j].weight < w1)) {
				w2 = w1;
				x2 = x1;
				x1 = j;
				w1 = huffman[j].weight;
			}
			else if((huffman[j].parent == -1) && (huffman[j].weight < w2)) {
				x2 = j;
				w2 = huffman[j].weight;
			}
		}
		huffman[n + i].lchild = x1;
		huffman[n + i].rchild = x2;
		huffman[n + i].weight = w1 + w2;
		huffman[x1].parent = n + i;
		huffman[x2].parent = n + i;
	}
}
void Print(int n) {
	HFC hcode;
	int nowParent;
	int c;
	for (int i = 0; i < n; i++) {
		hcode.start = n - 1;
		c = i;
		nowParent= huffman[i].parent;
		while (nowParent != -1) {
			if (huffman[nowParent].lchild == c) {
				hcode.code[hcode.start] = 0;
			}
			else {
				hcode.code[hcode.start] = 1;
			}
			hcode.start--;
			c = nowParent;
			nowParent = huffman[c].parent;
		}
		for (int j = hcode.start + 1; j < n; j++) {
			code[i].code[j] = hcode.code[j];
			printf("%d", hcode.code[j]);
		}
		printf("\n");
		code[i].start = hcode.start;
	}
}
int main() {
	printf("请输入有多少个哈夫曼字符");
	int n = 0;
	scanf("%d", &n);
	if (n == 0) {
		return 0;
	}
	HFMtreebulid(n);
	Print(n);
	for (int i = 0; i < n; ++i) {
		printf("%c 's Huffman Code is:", huffman[i].ch);
		for (int j = code[i].start + 1; j < n; ++j) {
			printf("%d", code[i].code[j]);
		}
		printf("\n");
	}
	return 0;
}