#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[1001], d[1001];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]&& d[i]<d[j]+1) {
				d[i] = d[j]+1;
			}
		}
	}
	sort(d, d + n);
	printf("%d\n", d[n - 1]);
	return 0;
}