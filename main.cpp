#include<stdio.h>
struct object
{
	int id;
	int time;
};
struct object t[6] = { 1,1,2,5,3,2,4,10,5,3};//记录每个项目的序号以及所花时间
int n = 5;//记录共有几项任务
int temp[5];//标记选中任务id
int bj = 0;//用于记录选中任务数量
int sumt=0;//用于记录所有项目时间之和
int F(int k, int y) {
	if (k == 0)return 0;
	if (y == 0)return 0;
	if (k == 1) {
		if (t[0].time > (sumt / 2))return 0;
		else {
			return t[0].time;
		}
	}
	if (y < 0)return -9999;
	int left = F(k - 1, y);
	int right = F(k - 1, y - t[k-1].time) + t[k-1].time;
	if (left > right){
	return left;
	}
	else {
		return right;
	}
}
int taki(int k, int y) {
	int left = F(k - 1, y);
	int right = F(k - 1, y - t[k-1].time) + t[k-1].time;
	if (left > right) {
		return taki(k-1,y);
	}
	else {
		if (y <= 0)return 0;
		temp[bj] = k;
		bj++;
		return taki(k - 1, y- t[k - 1].time);
	}
}
int main() {
	for (int a = 0; a < n; a++) {
		printf("id为%d的项目所需时间为%d\n", t[a].id, t[a].time);
	}
	for (int a = 0; a < n; a++) {
		sumt = sumt + t[a].time;
	}
	int fint=F(5, sumt / 2);
	if (fint > sumt - fint) {
		printf("花费时间为%d\n", fint);
	}
	else {
		printf("花费时间为%d\n", sumt - fint);
	}
	taki(5, sumt / 2);
	printf("其中一台机器选中任务为：");
	for (int a = 0; a < bj; a++) {
		printf("%d ",temp[a]);
	}
	printf("\n其他分配给第二台机器\n");
	return 0;
}