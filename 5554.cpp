#include <cstdio>
using namespace std;

int n, sum, h, m;
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d", &n);
		sum += n;
	}
	h = sum / 60;
	m = sum % 60;
	printf("%d\n%d", h, m);
	return 0;
}