#include <cstdio>
#include <cmath>
using namespace std;

int n, p, d[1000001], cnt;
int go(int k);
int main() {
	scanf("%d %d", &n, &p);
	d[n] = ++cnt;
	printf("%d\n", go(n));
	return 0;
}
int go(int k) {
	int sum = 0;
	while (k != 0) {
		int temp = k % 10;
		k /= 10;
		sum += (int)pow(temp, p);
	}
	if (d[sum] == 0) d[sum] = ++cnt;
	else return d[sum] - 1;
	go(sum);
}