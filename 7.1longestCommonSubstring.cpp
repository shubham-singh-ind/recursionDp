#include <bits/stdc++.h>

using namespace std;

int dp[101][101];

int lc_substring(string &s1, string &s2, int n1, int n2, int count) {
    // Base case: smallest valid input
    if(n1==0 || n2==0) return 0;
    int &s = dp[n1][n2];
    if(s != -1) return s;
    if(s1[n1-1] == s2[n2-1])
        s = lc_substring(s1, s2, n1-1, n2-1, count+1);
    else
        s = max(count, max(lc_substring(s1, s2, n1, n2-1, 0), lc_substring(s1, s2, n1-1, n2, 0)));
    return s;
}

int main()
{
    string s1="aaaaabbbbbbb";
    string s2="aaaaafbbbbbb";
    memset(dp, -1, sizeof(dp));
    cout << lc_substring(s1, s2, s1.size(), s2.size(), 0);

    return 0;
}
