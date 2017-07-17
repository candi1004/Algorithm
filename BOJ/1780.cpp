#include <cstdio>
using namespace std;

int d[3001][3001], cnt[3];
void sol(int x, int y, int n);
bool pass(int x, int y, int n);
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &d[i][j]);
		}
	}
	sol(0, 0, n);
	for (int i = 0; i < 3; i++) {
		printf("%d\n",cnt[i]);
	}
	return 0;
}
void sol(int x, int y, int n) {
	if (pass(x, y, n)) {
		if(d[x][y]==-1) cnt[0]++;
		else if (d[x][y] == 0) cnt[1]++;
		else cnt[2]++;
		return;
	}
	int m = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sol(x + i * m, y + j*m, m);
		}
	}
}
bool pass(int x, int y, int n) {
	for (int i = x; i < x+n; i++) {
		for (int j = y; j <y+ n; j++) {
			if (d[x][y] != d[i][j]) {
				return false;
			}
		}
	}
	return true;
}