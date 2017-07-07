#include <cstdio>
#include <vector>
using namespace std;

int t, cycle;
void dfs(int s);
bool chk[1001];
vector<int>vec[1001];
int main() {
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		int n; scanf("%d", &n);
		for (int i = 0; i <= n; i++) {
			vec[i].clear();
			chk[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			int k; scanf("%d", &k);
			vec[i].push_back(k);
		}
		for (int i = 1; i <= n; i++) {
			if (!chk[i]) {
				cycle = i;
				dfs(i);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
void dfs(int s) {
	chk[s] = true;
	for (int i = 0; i < vec[s].size(); i++) {
		int now = vec[s][i];
		if (now == cycle) {
			return;
		}
		if (!chk[now]) {
			dfs(now);
		}
	}
}