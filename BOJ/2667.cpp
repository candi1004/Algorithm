#include <cstdio>
#include <algorithm>
using namespace std;

int x[] = {0,1,-1,0};
int y[] = {-1,0,0,1};
char block[26][26];
bool chk[26][26];
int d[900], n, cnt, idx;
void dfs(int a, int b);
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%s", block[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (block[i][j] == '1' && !chk[i][j]) {
				cnt = 0;
				dfs(i, j);
				d[idx++] = cnt;
			}
		}
	}
	sort(d, d + idx);
	printf("%d\n",idx);
	for (int i = 0; i < idx; i++) {
		printf("%d\n", d[i]);
	}
	return 0;
}
void dfs(int a, int b) {
	chk[a][b] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int X = a + x[i];
		int Y = b + y[i];
		if (X >= 0 && y >= 0 && X < n && Y < n && !chk[X][Y] && block[X][Y] == '1') {
			dfs(X, Y);
		}
	}
}