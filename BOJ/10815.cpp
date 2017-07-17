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
	while (m--) {
		int k; scanf("%d", &k);
		int left = 0;
		int right = n;
		int ans = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (d[mid] == k) {
				ans = 1;
				break;
			}
			else if (d[mid] > k) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (ans == 1) printf("%d ", ans);
		else printf("%d ", ans);
	}
	return 0;
}