#include <stdio.h>
#include <string.h>


#define MAXLEN 30

void LCS(char* x, char* y, int m, int n, int a[][MAXLEN], int b[][MAXLEN]) {
	int i, j;
	for (i = 0; i <= m; i++)	a[i][0] = 0;
	for (j = 1; j <= n; j++)	b[0][j] = 0;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				a[i][j] = a[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (a[i - 1][j] >= a[i][j - 1]) {
				a[i][j] = a[i - 1][j];
				b[i][j] = 3;
			}
			else {
				a[i][j] = a[i][j - 1];
				b[i][j] = 2;
			}

		}
	}
}

void PrintLCS(int b[][MAXLEN], char* x, int i, int j) {
	if (i == 0 || j == 0)	return;
	if (b[i][j] == 1) {
		PrintLCS(b, x, i - 1, j - 1);
		printf("%c", x[i - 1]);
	}
	else if (b[i][j] == 3)
		PrintLCS(b, x, i - 1, j);
	else
		PrintLCS(b, x, i, j - 1);
}

int main() {
	char x[MAXLEN] = { "AACDASDABDC" };
	char y[MAXLEN] = { "ACFSADDA" };
	int a[MAXLEN][MAXLEN],
		b[MAXLEN][MAXLEN];
	int m, n;
	m = strlen(x);
	n = strlen(y);

	LCS(x, y, m, n, a, b);
	PrintLCS(b, x, m, n);

	return 0;
}
