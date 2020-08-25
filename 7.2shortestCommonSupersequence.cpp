#include <bits/stdc++.h>

using namespace std;

int dp[101][101];
int lcs(string &s1, string &s2, int n1, int n2) {
    // Base case: smallest valid input
    if(n1==0 || n2==0) return 0;
    int &s = dp[n1][n2];
    if(s != -1) return s;
    if(s1[n1-1] == s2[n2-1]) s = 1 + lcs(s1, s2, n1-1, n2-1);
    else s = max(lcs(s1,s2, n1-1, n2), lcs(s1,s2, n1, n2-1));
    return s;
}

int shortestCommonSupersequence(string &s1, string &s2) {
    memset(dp, -1, sizeof(dp));
    return s1.size()+s2.size()-lcs(s1,s2,s1.size(), s2.size());
}

int main()
{
    string s1="AGGTAB";
    string s2="GXTXAYB";
    // Problem:
    // Given 2 strings find the length of smallest string in which both the strings s1 and
    // s2 are present as a sequence
    // Input: "AGGTAB", "GXTXAYB"
    // Output: 9
    // How?: AGGXTXAYB
    cout << shortestCommonSupersequence(s1, s2);
    return 0;
}
