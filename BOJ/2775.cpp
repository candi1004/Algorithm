#include <cstdio>
using namespace std;

int t,d[15][15];
int main() {
	for (int i = 1; i < 15; i++) {
		d[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		d[i][1] = 1;
		for (int j = 2; j < 15; j++) {
			d[i][j] = d[i][j-1]+d[i-1][j];
		}
	}
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a, b; scanf("%d %d", &a, &b);
		printf("%d\n", d[a][b]);
	}
	return 0;
}