#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, Max, Maxnode;
vector<pair<int,int> >vec[100001];
bool chk[100001];
void bfs(int s);
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int node; scanf("%d", &node);
		while (1) {
			int a, b; scanf("%d", &a);
			if (a == -1) break;
			scanf("%d", &b);
			vec[node].push_back(make_pair(a, b));
		}
	}
	bfs(1);
	Max = 0;
	memset(chk, false, sizeof(chk));
	bfs(Maxnode);
	printf("%d\n", Max);
	return 0;
}
void bfs(int s) {
	chk[s] = true;
	queue <pair<int,int> >pq;
	queue <int> qc;
	int now = 0;
	int cnt = 0;
	pq.push(make_pair(s, 1));
	qc.push(0);
	while (!pq.empty()) {
		now = pq.front().first;
		cnt = qc.front();
		if (Max < cnt) {
			Maxnode = now;
			Max = cnt;
		}
		pq.pop();
		qc.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			if (!chk[vec[now][i].first]) {
				pq.push(make_pair(vec[now][i].first, vec[now][i].second));
				chk[vec[now][i].first] = true;
				qc.push(vec[now][i].second + cnt);
			}
		}
	}
}