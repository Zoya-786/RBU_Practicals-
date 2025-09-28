#include <stdio.h>
#include <string.h>

void LRS(char *s) {
    int n = strlen(s);
    int dp[n+1][n+1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == s[j-1] && i != j)
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }

    char lrs[dp[n][n] + 1];
    int index = dp[n][n];
    lrs[index] = '\0';

    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (s[i-1] == s[j-1] && i != j) {
            lrs[index - 1] = s[i-1];
            i--; j--; index--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LRS: %s\n", lrs);
}

int main() {

    char a[] = "AABCBDCA";
    LRS(a);

    return 0;
}
