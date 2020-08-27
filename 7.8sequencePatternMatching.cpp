#include <bits/stdc++.h>

using namespace std;

string A, B;
int dp[101][101];
int spm(int n1, int n2) {
    // Base case: smallest valid input
    if(n1 == 0) return 1;
    if(n2 == 0) return 0;
    int &s = dp[n1][n2];
    if(s != -1) return s;
    if(A[n1-1] == B[n2-1])
        s = spm(n1-1, n2-1);
    else
        s = spm(n1, n2-1);
    return s;
}

int main()
{
    // Given two strings A and B, is string A is a subsequence of string B
    // I/P: two strings A, B
    // O/P: boolean

    // SOLUTION WAY 2: IF LCS(A,B) IS EQUAL TO LENGTH OF A THEN TRUE ELSE FALSE

    A = "ABCD";
    B  = "AB";
    memset(dp, -1, sizeof(dp));
    cout << spm(A.size(), B.size());
    return 0;
}
