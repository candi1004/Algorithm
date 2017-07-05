#include <cstdio>
using namespace std;

int n, m, ans;
int d[1001][1001];
bool chk[1001];
void dfs(int k);
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		d[a][b] = d[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			dfs(i);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
void dfs(int k) {
	chk[k] = true;
	for (int i = 1; i <=n ; i++) {
		if (!chk[i] && d[k][i] == 1) {
			dfs(i);
		}
	}
}