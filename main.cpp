#include <algorithm>
#include <iostream> 
#include<stdio.h>
using namespace std;

const int N = 4;
int c = 8;
int v[] = { 0,1,4,2,3 }, w[] = { 0,4,1,2,5 };
int x[N + 1];
int m[10][10];
void Knapsack(int v[], int w[], int c, int n, int m[][10])
{
	int jMax = min(w[n] - 1, c);
	for (int j = 0; j <= jMax; j++)
	{
		m[n][j] = 0;
	}

	for (int j = w[n]; j <= c; j++)
	{
		m[n][j] = v[n];
	}

	for (int i = n - 1; i > 1; i--)
	{
		jMax = min(w[i] - 1, c);
		for (int j = 0; j <= jMax; j++)
		{
			m[i][j] = m[i + 1][j];
		}

		for (int j = w[i]; j <= c; j++) 
		{
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
		}
	}
	m[1][c] = m[2][c];
	if (c >= w[1])
	{
		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
	}
}
void Traceback(int m[][10], int w[], int c, int n, int x[])
{
	for (int i = 1; i < n; i++)
	{
		if (m[i][c] == m[i + 1][c])
		{
			x[i] = 0;
		}
		else
		{
			x[i] = 1;
			c -= w[i];
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;
}

int main()
{
	cout << "待装物品重量分别为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	cout << "待装物品价值分别为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	Knapsack(v, w, c, N, m);
	cout << "背包能装的最大价值为：" << m[1][c] << endl;
	Traceback(m, w, c, N, x);
	cout << "背包装下的物品编号为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		if (x[i] == 1)
		{
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}