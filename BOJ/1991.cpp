#include <cstdio>
using namespace std;

int n, d[50][2];
void preOrder(int s);
void inOrder(int s);
void postOrder(int s);
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a, b, c; scanf(" %c %c %c", &a, &b, &c);
		if (b != '.') {
			d[a - 'A'][0] = b - 'A';
		}
		else {
			d[a - 'A'][0] = -1;
		}
		if (c != '.') {
			d[a - 'A'][1] = c - 'A';
		}
		else {
			d[a - 'A'][1] = -1;
		}
	}
	preOrder(0);
	printf("\n");
	inOrder(0);
	printf("\n");
	postOrder(0);
	printf("\n");
	return 0;
}
void preOrder(int s) {
	if (s == -1) return;
	printf("%c", s + 'A');
	preOrder(d[s][0]);
	preOrder(d[s][1]);
}
void inOrder(int s) {
	if (s == -1) return;
	inOrder(d[s][0]);
	printf("%c", s + 'A');
	inOrder(d[s][1]);
}
void postOrder(int s) {
	if (s == -1) return;
	postOrder(d[s][0]);
	postOrder(d[s][1]);
	printf("%c", s + 'A');
}