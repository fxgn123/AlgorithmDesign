#include<stdio.h>
#include <string.h>

#define Inf 9999
void readin();
void Dijkstra(int map[8][8],char ver[8][2]);
int main() {
	readin();
	return 0;
}

void readin() {
	char ver[8][2] = { "a","b","c","d","e","f","g","h" };
	int map[8][8];
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			if (a != b) map[a][b] = Inf;
			else map[a][b] = 0;
		}
	}
	map[0][1] = 1; map[1][3] = 2; map[3][2] = 1; map[2][0] = 2;
	map[4][3] = 2; map[3][5] = 8; map[5][4] = 2; map[4][6] = 2;
	map[6][5] = 3; map[6][7] = 3; map[7][5] = 2;
	Dijkstra(map,ver);
}
void Dijkstra(int map[8][8],char ver[8][2]) {
	int visit[8] = { 0 };
	char route[8][8][64] ={'#'};
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			if (map[a][b] != Inf) {
				strcpy(route[a][b], ver[a]);
				strcat(route[a][b], ver[b]);
			}
		}
	}
	int tap[8] = { 0 };
	tap[0] = 1;
	for (int a=1; a < 8; a++) {
		int min = Inf;	
		int minb = 0;
		for (int b = 1; b < 8; b++) {
			for (int c = 0; c < 8; c++) {
				if (tap[c]) {
					if ((map[c][b] < min) && (tap[b] == 0)) {
						min = map[c][b];
						minb = b;
					}
				}
			}
		}
		tap[minb] = 1;
		for (int a1 = 0; a1 < 8; a1++) {
			for (int b = 0; b < 8; b++) {
				if ((map[a1][minb] + map[minb][b]) < map[a1][b]) {
					map[a1][b] = map[a1][minb] + map[minb][b];
					strcpy(route[a1][b], route[a1][minb]);
					route[a1][b][strlen(route[a1][b])-1] = '\0';
					strncat(route[a1][b], route[minb][b],8);
				}
			}
		}
		
	}
	printf("a到h的路径为:%s\n",route[0][7]);
	printf("a到h的路径距离为:%d",map[0][7]);
}