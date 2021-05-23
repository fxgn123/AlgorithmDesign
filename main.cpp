#include <iostream>
using namespace std;
#define MAXN 101    //���Ͷ�ʵ���Ŀ��
#define MAXM 101    //���Ͷ�ʽ��
int m, n;            //Ͷ�ʽ��m��Ͷ����Ŀn��
int f[MAXN][MAXM];  //��k��Ͷ��x��Ԫ������
int F[MAXN][MAXM];  //x��ԪͶ��ǰk����Ŀ�����Ч��
int x[MAXN][MAXM];  //�����ӵ�i��ʱ���ܹ�����xԪʱ����i�������kԪ

//��̬�滮ʵ�����Ͷ������
void invest() {
	int i, j, k, t;
	for (k = 2; k <= n; k++) {
		memset(F[k], -1, sizeof(int) * (m + 1));  //��ʼ���������ֵ��ֵ��-1
	}
	for (k = 0; k <= m; k++) {
		F[1][k] = f[1][k]; //Ͷ�ʵ�һ����Ŀ
	}
	for (k = 2; k <= n; k++) { //Ͷ��ǰk����Ŀ
		F[k][0] = 0;      //Ͷ��ǰk����Ŀ��ʼ���������0
		x[k][0] = 0;
		for (j = 1; j <= m; j++) {     //Ͷ�ʽ�����j
			for (i = 0; i <= j; i++) { //Ͷ�ʵ�ǰ��Ŀ�Ľ��
				t = f[k][i] + F[k - 1][j - i];
				if (t > F[k][j]) {  //���t>֮ǰ�ģ���ô�����������
					F[k][j] = t;
					x[k][j] = i;
				}
			}
		}
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			printf("(%d,%d)\t", F[i][j], x[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", F[n][m]);
}

int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) { //����Ч�溯��
		f[i][0] = 0;         //Ͷ��0Ԫ��������0
		for (j = 1; j <= m; j++)
			scanf("%d", &f[i][j]);
	}
	invest();
	return 0;
}