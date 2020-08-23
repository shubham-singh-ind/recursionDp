#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int coinChange(int coin[], int sum, int n) {
    //Base case: smallest valid value's output
    if(n == 0)
        return INT_MAX - 1;
    if(sum == 0)
        return 0;
    if(n==1) {
        if(sum % coin[n-1] == 0)
            return sum / coin[n-1];
        else
            return INT_MAX-1;
    } 
    int &s = dp[n][sum];
    if(s != -1) return s;
    if(coin[n-1] <= sum) {
        s = min(1 + coinChange(coin, sum-coin[n-1], n) , coinChange(coin, sum, n-1));
    } else {
        s = coinChange(coin, sum, n-1);
    }
    return s;
}
int main() {
    int coin[] = {1,2,3};
    memset(dp, -1, sizeof(dp));
    cout << coinChange(coin, 5, 3);
	return 0;
}
