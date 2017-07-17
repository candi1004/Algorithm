#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, d[500001];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	sort(d, d + n);
	scanf("%d", &m);
	for (int i = 0; i <m; i++) {
		int k; scanf("%d", &k);
		auto lb = lower_bound(d, d + n, k);
		auto ub = upper_bound(d, d + n, k);
		printf("%d ", ub - lb);
	}
	return 0;
}