#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

//int call = 0;
int dp[101][101];
int pp(string s, int i, int j) {
    //Base Case:
    if(i >= j || isPalindrome(s, i, j)) return 0;
    if(dp[i][j] != -1) return dp[i][j];
//    call++;
    int ans = INT_MAX;
    for(int k= i; k < j; k++) {
        int tempAns = pp(s, i, k) + pp(s, k+1, j) + 1;
        ans = min(ans, tempAns);
    }
    dp[i][j] = ans;
    return ans;
}

int main()
{
    // Find minimum # of partition
    string s = "ababbbabbababa";
    memset(dp, -1, sizeof(dp));
    cout << pp(s, 0, s.size()-1) <<endl;
//    cout<<call;
    return 0;
}
