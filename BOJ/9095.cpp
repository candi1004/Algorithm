#include <cstdio>
using namespace std;

int t, d[11] = { 0,1,2,4 };
int main() {
	for (int i = 4; i < 11; ++i) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
	scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		printf("%d\n", d[n]);
	}
	return 0;
}