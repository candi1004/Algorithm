#include <cstdio>
using namespace std;

int d[3];
char c[] = { 'E','A','B','C','D' };
int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			int k; scanf("%d", &k);
			if (k == 0) {
				d[i]++;
			}
		}
		printf("%C\n", c[d[i]]);
	}
	return 0;
}