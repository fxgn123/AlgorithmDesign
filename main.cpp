#include<stdio.h>
struct object
{
	int id;
	int time;
};
struct object t[6] = { 1,1,2,5,3,2,4,10,5,3};//��¼ÿ����Ŀ������Լ�����ʱ��
int n = 5;//��¼���м�������
int temp[5];//���ѡ������id
int bj = 0;//���ڼ�¼ѡ����������
int sumt=0;//���ڼ�¼������Ŀʱ��֮��
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
		printf("idΪ%d����Ŀ����ʱ��Ϊ%d\n", t[a].id, t[a].time);
	}
	for (int a = 0; a < n; a++) {
		sumt = sumt + t[a].time;
	}
	int fint=F(5, sumt / 2);
	if (fint > sumt - fint) {
		printf("����ʱ��Ϊ%d\n", fint);
	}
	else {
		printf("����ʱ��Ϊ%d\n", sumt - fint);
	}
	taki(5, sumt / 2);
	printf("����һ̨����ѡ������Ϊ��");
	for (int a = 0; a < bj; a++) {
		printf("%d ",temp[a]);
	}
	printf("\n����������ڶ�̨����\n");
	return 0;
}