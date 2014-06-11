#include <cstdio>

using namespace std;

int N;
int matrix[100][100];

int main() {

	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i == 0 && j == 0) continue;
			else if(i == 0) matrix[i][j] += matrix[i][j-1];
			else if(j == 0) matrix[i][j] += matrix[i-1][j];
			else matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
		}
	}

	int result = 100*100*-200;

	for(int sx = 0; sx < N; sx++) {
		for(int sy = 0; sy < N; sy++) {
			for(int ex = sx; ex < N; ex++) {
				for(int ey = sy; ey < N; ey++) {
					int t = matrix[ex][ey];
					if(sx != 0) t -= matrix[sx-1][ey];
					if(sy != 0) t -= matrix[ex][sy-1];
					if(sx != 0 && sy != 0) t += matrix[sx-1][sy-1];

					if(t > result){
						result = t;
					}
				}
			}
		}
	}

	printf("%d\n", result);
	return 0;
}
