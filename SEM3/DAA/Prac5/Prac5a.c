#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int v;  
    char d;
} Cell;

void LCS(char *a, char *b, int m, int n, Cell cost[MAX][MAX]) 
{
    for (int i = 1; i <= m; i++) {
        cost[i][0].v = 0;
        cost[i][0].d = 'H'; 
    }
    for (int j = 1; j <= n; j++) {
        cost[0][j].v = 0;
        cost[0][j].d = 'H';
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] != b[j - 1]) {
                cost[i][j].v = (cost[i][j - 1].v > cost[i - 1][j].v) ? cost[i][j - 1].v : cost[i - 1][j].v;
                cost[i][j].d = (cost[i][j - 1].v > cost[i - 1][j].v) ? 'S' : 'U';
            } else {
                cost[i][j].v = cost[i - 1][j - 1].v + 1;
                cost[i][j].d = 'D';
            }
        }
    }
}

void printLCS(Cell cost[MAX][MAX], char *a, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (cost[i][j].d == 'D') {
        printLCS(cost, a, i - 1, j - 1);
        printf("%c", a[i - 1]);
    } else if (cost[i][j].d == 'U') {
        printLCS(cost, a, i - 1, j);
    } else {
        printLCS(cost, a, i, j - 1);
    }
}

int main() {
    char a[MAX], b[MAX];
    Cell cost[MAX][MAX]; 

    printf("Enter first string: ");
    scanf("%s", a); 

    printf("Enter second string: ");
    scanf("%s", b);  

    int m = strlen(a);
    int n = strlen(b);

    LCS(a, b, m, n, cost);

    printf("Length of LCS: %d\n", cost[m][n].v);
    printf("LCS: ");
    printLCS(cost, a, m, n);
    printf("\n");

    return 0;
}
