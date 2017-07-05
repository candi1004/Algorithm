#include <cstdio>
using namespace std;

int n;
long long d[1001][10], ans, mod=10007;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <=j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		ans += d[n][i];
	}
	printf("%lld", ans%mod);
	return 0;
}