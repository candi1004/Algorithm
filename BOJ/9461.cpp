#include <cstdio>
using namespace std;

int t;
long long d[101] = { 0,1,1,1,2,2 };
int main() {
	scanf("%d", &t);
	for (int i = 6; i < 101; i++) {
		d[i] = d[i - 1] + d[i - 5];
	}
	while (t--) {
		int n; scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
	return 0;
}