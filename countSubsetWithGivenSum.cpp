#include <iostream>

using namespace std;

int count_subsetsum(int arr[], int sum, int n) {
    int dp[101][101];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(i == 0)
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
            else if(arr[i-1] <= j) {
                 dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    // arr[]: 2 3 5 6 8 10
    // sum: 10
    // o/p: 3, [2 8], [2 3 5], [10]
    int arr[] = {2,3,5,6,8,10};
    int sum=10;
    int n=6;
    cout << count_subsetsum(arr, sum, n);
    return 0;
}
