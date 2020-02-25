#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i ++ ) {
        for (int j = i; j > 0; j -- ) {
            if (a[j] >= a[j-1]) break;
            if (a[j] < a[j-1]) {
                swap(&a[j], &a[j-1]);
            }
        }
    }

    for (int i = 0; i < n; i ++ ) {
		printf("%d\n", a[i]);
	}

    system("pause");
    return 0;
}