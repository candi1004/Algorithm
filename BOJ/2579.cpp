#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[301], d[301];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	d[1] = arr[1];
	d[2] = d[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 2] + arr[i], d[i - 3] + arr[i] + arr[i - 1]);
	}
	printf("%d\n", d[n]);
	return 0;
}