#include <bits/stdc++.h>

using namespace std;

int dp[101][101];
int count_subsetsum(int ar[], int sum, int n) {
    //Base case: smallest valid input
    if(sum == 0) return 1;
    if(n == 0) return 0;
    int &s = dp[n][sum];
    if(s != -1) return s;
    if(ar[n-1] <= sum)
        s = count_subsetsum(ar, sum-ar[n-1], n-1) + count_subsetsum(ar, sum, n-1);
    else
        s = count_subsetsum(ar, sum, n-1);
    return s;
}

int targetSum(int ar[], int s, int n) {
    int sum = 0;
    for(int i=0; i<n; i++) sum += ar[i];
    int s1 = abs(sum-s)/2;
    memset(dp, -1, sizeof(dp));
    return count_subsetsum(ar, s1, n);
}

int main()
{
    // Target sum:
    // arr[]: 1 1 2 3
    // sum: 1
    // Assign +/- in front of every element such that sum of those becomes given sum
    // Output: count of how much combination is possible
    // Same as count subsets with diff
    int ar[] = {1,1,2,3};
    int sum = 1;
    cout << targetSum(ar, sum, 4);
    return 0;
}
  
