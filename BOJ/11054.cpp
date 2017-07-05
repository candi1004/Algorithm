#include <cstdio>
using namespace std;

int n, arr[10001], d[10001], d2[10001], Max;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		d2[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j] && d2[i] < d2[j] + 1) {
				d2[i] = d2[j] + 1;
			}

		}
	}
	for (int i = 0; i < n; i++) {
		if (Max < d[i] + d2[i]) {
			Max = d[i] + d2[i];
		}
	}	
	printf("%d\n", Max - 1);
	return 0;
}