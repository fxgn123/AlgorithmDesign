#include<stdio.h>
#include<math.h>
#define inf 0x3f3f3f3f
struct points {
	double x, y;
};
double min(double x, double y) {
	if (x < y)return x;
	else return y;
}
double dis(points p1, points p2) {
	//printf("%lf\n", p1.x);
	//printf("%lf\n", sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
int cmpx(points& a, points& b) {
	return a.x < b.x;
}
double ecp(points p[], int n) {
	double dminsq = inf;
	if (n <= 3) {
		for (int a = 0; a < n; a++) {
			for (int b = a + 1; b < n; b++) {
				dminsq = min(dis(p[a], p[b]), dminsq);
				//printf("%lf\n", dminsq);
			}
		}
		//printf("%lf\n",dminsq);
	}
	else {
		points Pleft[1000], Pright[1000], s[1000];
		double mid, dl, dr, d;
		int len1 = ceil(1.0 * n / 2);
		int len2, num = 0;
		len2 = n - len1;
		for (int i = 0; i < len1; i++)	Pleft[i] = p[i];
		for (int i = 0; i < len2; i++)	Pright[i] = p[i];

		dl = ecp(Pleft, len1);
		dr = ecp(Pright, len2);
		d = min(dl, dr);
		dminsq = pow(d, 2);
		mid = p[len1 - 1].x;

		for (int i = 0; i < n; i++) {
			if (fabs(p[i].x - mid) < d)
				s[num++] = p[i];
		}

		for (int i = 0; i < num - 1; i++) {
			int k = i + 1;
			while (k <= num - 1 && pow((s[k].y - s[i].y), 2) + pow((s[k].x - s[i].x), 2) < dminsq) {
				dminsq = min(pow((s[k].y - s[i].y), 2) + pow((s[k].x - s[i].x), 2), dminsq);
				k++;
			}
		}
		
	}
	return sqrt(dminsq);
}
int main() {
	int n, i;
	double ans;
	struct points p[1000];
	printf("输入点的个数：");
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		printf("输入点的坐标：");
		scanf("%lf %lf", &p[i].x, &p[i].y);
		//printf("%lf\n", p[i].x);
	}
	ans = ecp(p, n);
	printf("最近对为%lf\n", ans);
	return 0;
}