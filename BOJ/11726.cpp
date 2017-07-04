#include <cstdio>
using namespace std;

int n, d[1001];
int go(int k);
int main() {
	scanf("%d", &n);
	printf("%d\n", go(n));
	return 0;
}
int go(int k) {
	if (d[k] > 0) {
		return d[k];
	}
	if (k == 1) return 1;
	if (k == 2) return 2;
	d[k] = (go(k - 1) + go(k - 2))%10007;
	return d[k];
}