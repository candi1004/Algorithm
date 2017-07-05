#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, v;
void dfs(int k);
void bfs(int k);
bool chk[1001];
vector<int> vec[1001];
int main() {
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}
	dfs(v);
	printf("\n");
	bfs(v);
	return 0;
}
void dfs(int k) {
	chk[k] = true;
	printf("%d ", k);
	for (int i = 0; i<vec[k].size(); i++) {
		int now = vec[k][i];
		if (!chk[now]) {
			dfs(now);
		}
	}
}
void bfs(int k) {
	queue<int>q;
	memset(chk, false, sizeof(chk));
	chk[k] = true;
	q.push(k);
	while (!q.empty()) {
		int X= q.front();
		q.pop();
		printf("%d ", X);
		for (int i = 0; i < vec[X].size(); i++) {
			int now = vec[X][i];
			if (!chk[now]) {
				chk[now] = true;
				q.push(now);
			}
		}
	}

}