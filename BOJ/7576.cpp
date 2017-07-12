#include <cstdio>
#include <queue>
using namespace std;

int n, m, d[1001][1001], cnt;
int x[] = { 0,0,1,-1 };
int y[] = { 1,-1,0,0 };
bool chk[1001][1001];
queue <pair<int, int> >qxy;
queue <int> qc;
void bfs();
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &d[i][j]);
			if (d[i][j] == 1) {
				qxy.push(make_pair(i, j));
				qc.push(1);
				chk[i][j] = true;
			}
		}
	}
	int flag = 0;
	bfs();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == 0) {
				flag = 1;
			}
		}
	}

	if (flag == 1) printf("%d\n",-1);
	else printf("%d\n", cnt-1);
	return 0;
}
void bfs() {
	pair<int, int>now;
	while (!qxy.empty()) {
		now = qxy.front();
		cnt = qc.front();
		qxy.pop(); qc.pop();
		for (int i = 0; i < 4; i++) {
			int X = now.first + x[i];
			int Y = now.second + y[i];
			if (X >= 0 && Y >= 0 && X < m && Y < n && !chk[X][Y] && d[X][Y] == 0) {
				chk[X][Y] = true;
				d[X][Y] = 1;
				qxy.push(make_pair(X, Y));
				qc.push(cnt + 1);
			}
		}
	}
}