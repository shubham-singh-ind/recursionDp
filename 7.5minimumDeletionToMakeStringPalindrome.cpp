#include <bits/stdc++.h>

using namespace std;

string A, B;
int dp[101][101];
int lcs(int n1, int n2) {
    if(n1==0 || n2==0) return 0;
    int &s = dp[n1][n2];
    if(s != -1) return s;
    if(A[n1-1] == B[n2-1])
        s = 1 + lcs(n1-1, n2-1);
    else
        s = max(lcs(n1, n2-1), lcs(n1-1, n2));
    return s;
}
int minimumDeletionToMakePalindrome() {
    B = A;
    reverse(B.begin(), B.end());
    memset(dp, -1, sizeof(dp));
    return A.size() - lcs(A.size(), B.size());
}

int main()
{
    A = "agbcba";
    cout << minimumDeletionToMakePalindrome();
    return 0;
}
