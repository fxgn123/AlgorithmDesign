#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int left, int mid, int right) //二分归并排序 
{
	int i, k;
	int* tmp = (int*)malloc((right - left + 1) * sizeof(int));
	int left1 = left;
	int left2 = mid;
	int right1 = mid + 1;
	int right2 = right;
	for (k = 0; left1 <= left2 && right1 <= right2; k++)
	{
		if (a[left1] <= a[right1])
		{
			tmp[k] = a[left1++];
		}
		else
		{
			tmp[k] = a[right1++];
		}
	}
	if (left1 <= left2)
	{
		for (i = left1; i <= left2; i++)
		{
			tmp[k++] = a[i];
		}
	}

	if (right1 <= right2)
	{
		for (i = right1; i <= right2; i++)
		{
			tmp[k++] = a[i];
		}
	}
	for (i = 0; i < right - left + 1; i++)
	{
		a[left + i] = tmp[i];
	}
	free(tmp);
	return;
}
void merge_sort(int a[], int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
	return;
}


int select(int a[], int left, int right, int k)
{
	int n = right - left;
	if (n < 5)
	{
		merge_sort(a, left, right - 1);
		return a[left + k - 1];
	}
	int i;
	int s = n / 5;
	int* m = new int[s];//中位数数组
	for (i = 0; i < s; i++)
	{
		merge_sort(a, left + i * 5, left + i * 5 + 5 - 1);
		m[i] = a[left + i * 5 + 2];
	}
	merge_sort(m, 0, i - 1);
	int mid = m[i / 2];
	int* a1 = new int[n];
	int* a2 = new int[n];
	int* a3 = new int[n];
	int num1 = 0, num2 = 0, num3 = 0;
	for (int i = left; i < right; i++)
	{
		if (a[i] < mid)
		{
			a1[num1++] = a[i];
		}
		else if (a[i] == mid)
		{
			a2[num2++] = a[i];
		}
		else
			a3[num3++] = a[i];
	}
	if (num1 >= k)
	{
		return select(a1, 0, num1, k);
	}
	if (num1 + num2 >= k)
	{
		return mid;
	}
	else
		return select(a3, 0, num3, k - num1 - num2);
}

int main()
{
	int n;
	int a[1000];
	printf("数组大小：");
	scanf("%d", &n);
	printf("数据：");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int k;
	printf("第几小：");
	scanf("%d", &k);
	printf("第%d小元素：", k);
	printf("%d\n", select(a, 0, n, k));
	return 0;
}
