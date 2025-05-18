#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the length of the Longest Common Subsequence (LCS) and print the LCS string
void lcs(char *s1, char *s2) {
    int n = strlen(s1); 
    int m = strlen(s2);

    // DP table to store the length of LCS
    int dp[n + 1][m + 1];

    // Filling the DP table  
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    // Length of LCS
    int lcs_length = dp[n][m];
    printf("The Length of Longest Common Subsequence is %d\n", lcs_length);

    // Backtracking to find the LCS string
    char lcs_str[lcs_length + 1];
    lcs_str[lcs_length] = '\0';
    int i = n, j = m, index = lcs_length - 1;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs_str[index] = s1[i - 1];
            index--;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("The Longest Common Subsequence is: %s\n", lcs_str);
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    // Call the function to find and print LCS
    lcs(s1, s2);
    
    return 0;
}

