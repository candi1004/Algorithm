#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[1001], d[1001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i - j] + arr[j],d[i]);
		}
	}
	printf("%d\n", d[n]);
	return 0;
}