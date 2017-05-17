#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int a, int b)
{ 	if (a < b) return a; else return b;
}
void mf(int a[10][10], int n) {
    int c, e, f;
    scanf("%d %d %d", &c, &e, &f);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) a[i][j] = 0; else a[i][j] = INT_MAX;
        }
    while (c != -1) {
        a[c - 1][e - 1] = f;
        scanf("%d %d %d", &c, &e, &f);
    }
}
int main()
{   int n, i, j, k, a[10][10];
    scanf("%d", &n);
    mf(a, n);
    for (k = 0; k<n; k++)
        for (i = 0; i<n; i++)
            for (j = 0; j<n; j++)
                if (a[i][k]<INT_MAX && a[k][j]<INT_MAX) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    for (i = 0; i<n; ++i, printf("\n"))
        for (j = 0; j < n; ++j) {
            if (a[i][j] == INT_MAX) printf(" f "); else printf("%d ", a[i][j]);
        }
    system("pause");
}
