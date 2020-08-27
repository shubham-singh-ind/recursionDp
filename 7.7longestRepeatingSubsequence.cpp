#include <bits/stdc++.h>

using namespace std;

string X,A,B;
int x;
int dp[101][101];
int lcs(int n1, int n2) {
    // Base case: smallest valid input
    if(n1==0 || n2== 0) return 0;
    int &s = dp[n1][n2];
    if(s != -1) return s;
    if(A[n1-1] == B[n2-1])
        s = 1 + lcs(n1-1, n2-1);
    else
        s = max(lcs(n1-1, n2), lcs(n1, n2-1));
    return s;
}
int lcs2(int n1, int n2) {
    // Base case: smallest valid input
    if(n1==0 || n2== 0) return 0;
    int &s = dp[n1][n2];
    if(s != -1) return s;
    if(A[n1-1] == B[n2-1] && n1 != n2)
        s = 1 + lcs(n1-1, n2-1);
    else
        s = max(lcs(n1-1, n2), lcs(n1, n2-1));
    return s;
}

int lrsWay1() {
    set<char> s;
    for(int i=0; i<x; i++) {
        if(s.find(X[i]) != s.end())
            B.push_back(X[i]);
        else {
            A.push_back(X[i]);
            s.insert(X[i]);
        }
    }
    memset(dp, -1, sizeof(dp));
    return lcs(A.size(), B.size());
}

int lrsWay2() {
    A=X;
    B=X;
    memset(dp, -1, sizeof(dp));
    return lcs2(A.size(), B.size());
}

int main()
{
//Given a string, print the longest repeating subsequence such that the two
//subsequence don’t have same string character at same position, i.e.,
//any i’th character in the two subsequences shouldn’t have the same index
//in the original string.
    X = "AABEBCDD";

//    AABEBCDD
//    AABEBCDD

    x = X.size();
    cout << lrsWay2();
    return 0;
}
