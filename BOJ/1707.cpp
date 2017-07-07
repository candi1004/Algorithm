#include <cstdio>
#include <vector>
using namespace std;

int t;
void dfs(int s, int col);
vector<int>vec[20001];
int color[20001];
int main() {
	scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; i++) {
			vec[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			vec[a].push_back(b); vec[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				if (color[i] == color[vec[i][j]]) {
					flag = false;
				}
			}
			if (!flag) break;
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
void dfs(int s,int col) {
	color[s] = col;
	for (int i = 0; i <vec[s].size() ; i++) {
		int now = vec[s][i];
		if (color[now]==0) {
			dfs(now, 3 - col);
		}
	}
}