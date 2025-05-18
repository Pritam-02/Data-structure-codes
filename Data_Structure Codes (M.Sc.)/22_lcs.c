#include <stdio.h>
#include <string.h>

#define MAX 100

int dp[MAX][MAX];

int lcsMemoization(char *s1, char *s2, int m, int n) {
    // Base case: if any string is empty, the LCS is of length 0
    if (m == 0 || n == 0) {
        return 0;
    }

    // If the result is already computed, return it from the dp array
    if (dp[m][n] != -1) {
        return dp[m][n];
    }

    // If characters match, add 1 to the result and recurse for the remaining substring
    if (s1[m - 1] == s2[n - 1]) {
        dp[m][n] = 1 + lcsMemoization(s1, s2, m - 1, n - 1);
    } else {
        // Otherwise, take the maximum of excluding the current character from either string
        dp[m][n] = (lcsMemoization(s1, s2, m - 1, n) > lcsMemoization(s1, s2, m, n - 1)) ?
                    lcsMemoization(s1, s2, m - 1, n) : lcsMemoization(s1, s2, m, n - 1);
    }

    return dp[m][n];
}

void findLCS(char *s1, char *s2, int m, int n, char *lcs_str) {
    int index = dp[m][n];
    lcs_str[index] = '\0'; // Null-terminate the LCS string
    
    // Backtrack to build the LCS string
    while (m > 0 && n > 0) {
        if (s1[m - 1] == s2[n - 1]) {
            lcs_str[index - 1] = s1[m - 1];
            m--;
            n--;
            index--;
        } else if (dp[m - 1][n] > dp[m][n - 1]) {
            m--;
        } else {
            n--;
        }
    }
}

int longestCommonSubsequence(char *s1, char *s2, char *lcs_str) {
    int m = strlen(s1), n = strlen(s2);

    // Initialize the dp table with -1 (indicating uncomputed values)
    memset(dp, -1, sizeof(dp));

    // Compute the length of LCS using memoization
    int length = lcsMemoization(s1, s2, m, n);

    // Find the actual LCS string using the dp table
    findLCS(s1, s2, m, n, lcs_str);

    return length;
}

int main() {
    char text1[MAX], text2[MAX], lcs_str[MAX];
    
    printf("Enter first string: ");
    scanf("%s", text1);
    printf("Enter second string: ");
    scanf("%s", text2);
    
    int length = longestCommonSubsequence(text1, text2, lcs_str);
    
    printf("Longest Common Subsequence Length: %d\n", length);
    printf("Longest Common Subsequence: %s\n", lcs_str);
    
    return 0;
}