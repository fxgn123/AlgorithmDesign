#include<stdio.h>

struct box {
	int no;
	int weight;
}b[100];
int main() {
	int boxnum,maxweight;
	int loadno[100];
	int loadmax;
	printf("请输入盒子数量:\n");
	scanf("%d",&boxnum);
	printf("请输入集装箱最大承重:\n");
	scanf("%d",&maxweight);
	printf("请输入盒子的重量(空格隔开):\n");
	for (int a = 0; a < boxnum; a++) {
		scanf("%d",&b[a].weight);
		b[a].no = a + 1;
	}
	for (int a = 0; a < boxnum-1; a++) {
		for (int c = 0; c < boxnum - a - 1; c++) {
			if (b[c].weight > b[c + 1].weight) {
				int tempa, tempb;
				tempa = b[c].no;
				tempb = b[c].weight;
				b[c].no = b[c + 1].no;
				b[c].weight = b[c + 1].weight;
				b[c + 1].weight = tempb;
				b[c + 1].no = tempa;
			}
		}
	}
	loadmax = 0;
	int bj = 0;
	for (int a = 0; a < boxnum; a++) {
		if (loadmax + b[a].weight > maxweight) {
			bj = a;
			break;
		}
		else {
			loadmax = loadmax + b[a].weight;
			loadno[a] = b[a].no;
		}
	}
	printf("可以装载%d个盒子,装载重量为%d\n", bj,loadmax);
	printf("转载的盒子序号为:");
	for (int a = 0; a < bj; a++) {
		printf("%d ",loadno[a]);
	}
	return 0;
}