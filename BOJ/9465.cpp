#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t;
int arr[100001][2];
int d[100001][2];
int main() {
	scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[j][i]);
			}
		}
		d[0][0] = arr[0][0];
		d[0][1] = arr[0][1];
		d[1][1] = d[0][0] + arr[1][1];
		d[1][0] = d[0][1] + arr[1][0];
		for (int i = 2; i < n; i++) {
			d[i][0] = max(d[i - 1][1] + arr[i][0], d[i - 2][1] + arr[i][0]);
			d[i][1] = max(d[i - 1][0] + arr[i][1], d[i - 2][0] + arr[i][1]);
		}
		printf("%d\n", max(d[n - 1][0], d[n - 1][1]));
	}
	return 0;
}