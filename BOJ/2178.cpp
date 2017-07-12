#include <cstdio>
#include <queue>
using namespace std;

int n, m;
char c[101][101];
int x[] = { 0,0,1,-1 };
int y[] = { 1,-1,0,0 };
bool chk[101][101];
int bfs(int a, int b);
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", &c[i]);
	}
	printf("%d",bfs(0, 0));
	return 0;
}
int bfs(int a, int b) {
	chk[a][b] = true;
	queue<pair<int, int> >qxy;
	queue<int>qc;
	qxy.push(make_pair(a, b));
	qc.push(1);
	int cnt = 0;
	while (1) {
		pair<int, int>now = qxy.front();
		cnt = qc.front();
		if (now.first == (n - 1) && now.second == (m - 1)) {
			break;
		}
		qxy.pop(); qc.pop();
		for (int i = 0; i < 4; i++) {
			int X = now.first + x[i];
			int Y = now.second + y[i];
			if (X >= 0 && Y >= 0 && X < n && Y < m && c[X][Y] == '1' && !chk[X][Y]) {
				chk[X][Y] = true;
				qxy.push(make_pair(X, Y));
				qc.push(cnt + 1);
			}
		}
	}
	return cnt;
}