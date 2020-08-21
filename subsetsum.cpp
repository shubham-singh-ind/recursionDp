#include <iostream>
#include <cstring>

using namespace std;

int dp[101][101];
bool subsetsum(int ar[], int sum, int n) {
    //Base case: smallest valid value's output
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    int &s = dp[n][sum];
    if(s != -1) return s;
    if(ar[n-1] <= sum) {
        s = subsetsum(ar, sum-ar[n-1], n-1) || subsetsum(ar, sum, n-1);
    } else {
        s = subsetsum(ar, sum, n-1);
    }
    return s;
}

bool topDown(int arr[], int sum, int n) {
    bool dp[101][101];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            // Initialization
            if(i==0)
                dp[i][j] = false;
            else if(j==0)
                dp[i][j] = true;
            else if(arr[i-1] <= j){
                dp[i][j] = dp[i][j-arr[i-1]] || dp[i-1][j];
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    //: Problem statement
    // arr[]: 2 3 7 8 10
    // sum: 11
    // o/p: Yes (8+3)
    // o/p: No
    int arr[] = {2,3,7,8,10};
    int n=5;
    int sum = 11;
    memset(dp, -1, sizeof(dp));
    cout << subsetsum(arr, sum, n);
    return 0;
}
