#include<stdio.h>

#define Inf 9999
void Floyd(int map[4][4]);
void readin();

int main() {
	readin();
	return 0;
}

void readin() {
	int map[4][4];
	map[0][0] = 0;   map[0][1] = 2;   map[0][2] = 6; map[0][3] = 4;
	map[1][0] = Inf; map[1][1] = 0;   map[1][2] = 3; map[1][3] = Inf;
	map[2][0] = 7;   map[2][1] = Inf; map[2][2] = 0; map[2][3] = 1;
	map[3][0] = 5;   map[3][1] = Inf; map[3][2] = 1; map[3][3] = 0;
	Floyd(map);
}
void Floyd(int map[4][4]) {
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			for (int c = 0; c < 4; c++) {
				if ((map[b][a] + map[a][c]) < map[b][c]) {
					map[b][c] = map[b][a] + map[a][c];
				}
			}
		}
		
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] != Inf) {
				printf("%d ", map[i][j]);
			}
			else {
				printf("无法到达");
			}

		}
		printf("\n");
	}
}