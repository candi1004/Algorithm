#include <cstdio>
using namespace std;

int n;
long long d[101][10], mod = 1000000000, ans;
int main() {
	for (int i = 1; i < 10; i++) {
		d[1][i] = 1;
	}
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) {
				d[i][j] += d[i - 1][j - 1];
			}
			if (j + 1 < 10) {
				d[i][j] += d[i - 1][j + 1];
			}
			d[i][j] %= mod;
		}
	
	}
	for (int i = 0; i < 10; i++) {
		ans += d[n][i];
	}
	printf("%lld", ans%mod);
	return 0;
}