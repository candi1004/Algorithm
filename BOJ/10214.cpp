#include <cstdio>
using namespace std;

int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int game = 9;
		int asum = 0, bsum = 0;
		while (game--) {
			int a, b; scanf("%d %d", &a, &b);
			asum += a; bsum += b;
		}
		if (asum > bsum)printf("Yonsei\n");
		else if (asum < bsum)printf("Korea\n");
		else printf("Draw\n");
	}
	return 0;
}