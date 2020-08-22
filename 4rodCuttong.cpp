#include <bits/stdc++.h>

using namespace std;

int dp[101][101];
int rodCutting(int length[], int prize[], int w, int n) {
    // Base case: smallest valid input
    if(n==0 || w==0) return 0;
    int &s = dp[n][w];
    if(length[n-1] <= w)
        s = max(prize[n-1]+rodCutting(length, prize, w-prize[n-1], n),
                   rodCutting(length, prize, w, n-1));
    else
        s = rodCutting(length, prize, w, n-1);
    return s;
}

int main()
{
    // length[]: 1 2 3 4 5  6  7  8
    // prize[]:  1 5 8 9 10 17 20
    // n: 8
    // Cut the rod any number of times so that prize is highest
    int length[] = {1,2,3,4,5,6,7,8};
    int prize[] = {1,5,8,9,10,17,20};
    memset(dp, -1, sizeof(dp));
    cout << rodCutting(length, prize, 8, 8);
    return 0;
}
