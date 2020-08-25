#include <bits/stdc++.h>

using namespace std;

string A, B;
int dp[101][101];
int lcs(int n1, int n2) {
    // Base case: smallest valid input
    if(n1==0 || n2==0) return 0;
    int &s = dp[n1][n2];
    if(s != -1) return s;
    if(A[n1-1] == B[n2-1]) s = 1 + lcs(n1-1, n2-1);
    else s = max(lcs(n1, n2-1), lcs(n1-1, n2));
    return s;
}

typedef pair<int, int> pi;
pi minimumInsertionDeletion() {
    memset(dp, -1, sizeof(dp));
    int l = lcs(A.size(), B.size());
    pi result;
    result.first = A.size() - l;
    result.second = B.size() - l;
    return result;
}

int main()
{
    // Problem:
    // Minimum number of insertion and deletion to convert string a to string b
    // Input: "heap", "pea"
    A = "heap";
    B = "pea";
    pi result = minimumInsertionDeletion();
    cout << "Insertion: " << result.second<<", Deletion: "<<result.first;
    return 0;
}
