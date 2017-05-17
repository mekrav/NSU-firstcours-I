#include <stdio.h>
#include <stdlib.h>
int inf = 16000;
int min(int a, int b)
{ 	if (a < b) return a; else return b;
}
void z(int a[100][100], int n) {
    int c, e, f;
    scanf("%d %d %d", &c, &e, &f);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) a[i][j] = 0; else a[i][j] = inf;
        }
    while (c != -1) {
        a[c - 1][e - 1] = f;
        scanf("%d %d %d", &c, &e, &f);
    }
}
int main()
{   int n, i, j, k, a[100][100];
    scanf("%d", &n);
    z(a, n);
    for (k = 0; k<n; k++)
        for (i = 0; i<n; i++)
            for (j = 0; j<n; j++)
                if (a[i][k]<inf && a[k][j]<inf) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    for (i = 0; i<n; ++i, printf("\n"))
        for (j = 0; j < n; ++j) {
            if (a[i][j] == inf) printf(" f "); else printf("%d ", a[i][j]);
        }
    system("pause");
}
