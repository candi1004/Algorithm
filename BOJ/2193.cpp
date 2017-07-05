#include <cstdio>
using namespace std;

int n;
long long d[91] = { 0,1 };
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	printf("%lld", d[n]);
	return 0;
}