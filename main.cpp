#include<iostream>

using namespace std;

#define size 100
int p[size];
int m[size][size], s[size][size];
int n;

void matrixchain()
{
	int i, r, j, k;
	memset(m, 0, sizeof(m));
	memset(s, 0, sizeof(s));//��ʼ������
	for (r = 2; r <= n; r++)//�������˵Ĺ�ģΪr 
	{
		for (i = 1; i <= n - r + 1; i++)
		{
			j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//��m[][]��ʼ��ֵ
			s[i][j] = i;//s[][]�洢��������ľ��ߵ�
			for (k = i + 1; k < j; k++)//Ѱ������ֵ
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}


void printOrder(int i, int j)
{
	if (i == j)
	{
		cout << "A[" << i << "]";
		return;
	}
	cout << "(";
	printOrder(i, s[i][j]);
	printOrder(s[i][j] + 1, j);//�ݹ�1��s[1][j]
	cout << ")";
}



int main()
{
	cout << "���������ĸ���n : " << endl;
	cin >> n;
	int i, j;
	cout << "�����������" << endl;
	for (i = 0; i <= n; i++)
		cin >> p[i];
	matrixchain();
	printOrder(1, n);
	cout << endl;
	cout << "��С��������ֵΪ��" << m[1][n] << endl;
	return 0;

}
