#include <cstdio>
#include <algorithm>
using namespace std;

int n, sum;
int a[51], b[51];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < n; j++) {
		scanf("%d", &b[j]);
		b[j] *= -1;
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		sum += (a[i] * b[i] * -1);
	}
	printf("%d\n", sum);
	return 0;
}