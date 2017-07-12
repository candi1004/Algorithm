#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector <int> vec[100001];
int parent[100001];
void dfs(int s);
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a, b; scanf("%d %d", &a,&b);
		vec[a].push_back(b); vec[b].push_back(a);
	}
	memset(parent, -1, sizeof(parent));
	dfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
}
void dfs(int s) {
	for (int i = 0; i < vec[s].size(); i++) {
		int next = vec[s][i];
		if (parent[next] == -1) {
			parent[next] = s;
			dfs(next);
		}
	}
}