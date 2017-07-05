#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[100001], d[100001], Max;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	Max = d[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (d[i - 1] + arr[i] >= arr[i]) {
			d[i] = d[i - 1] + arr[i];
		}
		else {
			d[i] = arr[i];
		}
		Max = max(Max, d[i]);
	}
	printf("%d\n", Max);
	return 0;
}