#include <bits/stdc++.h>
using namespace std;

// [Make matrix for those variables who are changing]
// Here weight (w) and size (n) is changing
// int dp[n+1][w+1];
// Constraint: n -> 100
// Constraint: m -> 1000
int dp[101][1001];

int knapsack(int wt[], int val[], int w, int n) {
    // Base condition: [Think of the smallest valid input and give output accordingly]
    if(w == 0 || n == 0) return 0;
    // Choice diagram code
    // [Always call next function with smaller input]
    if(dp[n][w] != -1)
        return dp[n][w];
    if(wt[n-1] <= w) {
        dp[n][w] = max(val[n-1] + knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1));
    }else {
        dp[n][w] = knapsack(wt, val, w, n-1);
    }
    return dp[n][w];
}

int main() {
    // Knapsack problem:
        // wt[] : 1 3 4 5
        // val[]: 1 4 5 7
        // W: 7
        // O/P: Max Profit
    // [Identify DP Problem]: (Recursion + Storage)
    // 1. Choice
    // 2. Optimal (max or min)
    // [First write Recursive solution -> Memoization -> Top-down (optional)]
    
    // [Choice diagram]
    //             w1
    //     w1<=w        w1 > w
    // Yes      No         No
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int w = 7;
    int n = 4;
    memset(dp, -1, sizeof(dp));
    cout << knapsack(wt, val, w, n);
	return 0;
}
