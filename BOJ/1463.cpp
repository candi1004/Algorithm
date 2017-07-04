#include <cstdio>
using namespace std;

int n, d[1000001];
int go(int k);
int main() {
	scanf("%d", &n);
	printf("%d\n",go(n));
	return 0;
}
int go(int k) {
	if (k == 1) return 0;
	if (d[k] > 0) return d[k];
	d[k]= go(k-1) + 1;
	if (k%3==0) {
		int now = go(k/3) + 1;
		if (d[k] > now) {
			d[k] = now;
		}
	}
	if (k%2==0) {
		int now = go(k/2) + 1;
		if (d[k] > now) {
			d[k] = now;
		}
	}
	return d[k];
}