#include<stdio.h>

void readin();
void mergeset(int *T, int p, int r);
void merge(int *T,int p, int r);
int main() {

	readin();
	return 0;
}

void readin() {
	printf("请输入需要排序的数组:");
	int T[100];
	int i = 0;
	int x = 0;
	while (1) {
		scanf("%d", &x);
		char s = getchar();
		T[i] = x;
		i++;
		if (s == '\n')break;
	}
	mergeset(T, 0, --i);
	for (int a = 0; a <=i; a++) {
		printf("%d ", T[a]);
	}
}
void mergeset(int *T, int p, int r) {
	if (p >= r) return;
	int mid = (p + r) / 2;
	mergeset(T, p, mid);
	mergeset(T,mid+1,r);
	merge(T, p, r);
}
void merge(int *T,int p, int r) {
	int t[100];
	int mid = (p + r) / 2;
	int i = p;
	int j = mid + 1;
	int a = p;
	while ((i <= mid) && (j <= r)) {
		if (T[i] > T[j])t[a++] = T[j++];
		else {
			t[a++] = T[i++];
		}
		
	}
	while (i <= mid)t[a++] = T[i++];
	while (j <= r)t[a++] = T[j++];
	for (int b = p; b <= r; b++) {
		T[b] = t[b];
	}
}