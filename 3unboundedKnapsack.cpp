#include <iostream>

using namespace std;
// Rod cutting
// Coin change I
// Coin change II
// Maximum ribbon cut

int unboundedKnapsack(int wt[], int val[], int w, int n) {
    // Base case: smallest valid input
    if(w==0 || n==0) return 0;
    if(wt[n-1] <= w)
        return max(val[n-1]+unboundedKnapsack(wt, val, w-wt[n-1], n),
                   unboundedKnapsack(wt, val, w, n-1));
    return unboundedKnapsack(wt, val, w, n-1);
}

int main()
{
    // Multiple occurrences of a same item is allowed
    return 0;
}
