#include <cstdio>
using namespace std;

int n, m, d[51][51];
int x[] = { 0,0,1,-1,1,1,-1,-1 };
int y[] = { 1,-1,0,0,1,-1,1,-1 };
bool chk[51][51];
void dfs(int a, int b);
int main() {
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &d[i][j]);
				chk[i][j] = false;
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] == 1 && !chk[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
void dfs(int a, int b) {
	chk[a][b] = true;
	for (int i = 0; i < 8; i++) {
		int X = a + x[i];
		int Y = b + y[i];
		if (X < m && Y < n && X >= 0 && Y >= 0 && d[X][Y] == 1 && !chk[X][Y]) {
			dfs(X, Y);
		}
	}
}
