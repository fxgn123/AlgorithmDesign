#include<stdio.h>


void readin();
void order(int T[100]);//˳�����
void Er_fen(int T[100]);//���ַ�����
int main() {
	readin();
	return 0;
}
void readin(){
	int T[100];
	for (int a = 0; a < 100; a++) {
		T[a] = a * a + 1;
	}
	//order(T);
	Er_fen(T);
}
void order(int T[100]) {
	int x;
	printf("������ҵ���:");
	scanf("%d", &x);
	for (int a = 0; a < 100; a++) {
		if (x == (T[a])) {
			printf("�±�Ϊ:%d",a+1);
			return;
		}
	}
	printf("�±�Ϊ:0\n");
}
void Er_fen(int T[100]) {
	int x;
	printf("������ҵ���:");
	scanf("%d", &x);
	int left = 0, right = 99;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (T[mid] == x) {
			printf("�±�Ϊ:%d", mid + 1);
			return;
		}
		else {
			if (T[mid] > x)right = mid - 1;
			else left = mid + 1;
		}
	}
	printf("�±�Ϊ:0\n");
}