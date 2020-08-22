#include <bits/stdc++.h>
#include "./../subsetsum/main.h"

using namespace std;

// @param: arr: input array, n: size of array
// @output: true/false based on the condition
// This uses another function subsetsum from file of subsetsum
bool equal_sum_partition(int arr[], int n) {
    int sum=0;
    for(int i=0; i<n; i++) sum += arr[i];
    if(sum % 2 != 0)
        return false;
    return subsetsum(arr, sum/2, n);
}

int main()
{
    // Problem statement:
    // arr[]: 1 5 11 5
    // o/p: true/false
    // is there partition possible which leads to equal sum?
    // [1 5 5], [11]
    // Idea: array sum should be even otherwise equal sum will never be possible
    int arr[] = {1,1,1,3};
    int n = 4;
    memset(dp, -1, sizeof(dp));
    cout << equal_sum_partition(arr, n);
    return 0;
}
