#include <bits/stdc++.h>

using namespace std;

string A, B;
int N1, N2;
string scs_print() {
    int dp[N1+1][N2+1];
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<=N1; i++) {
        for(int j=0; j<=N2; j++) {
            //Base case
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(A[i-1] == B[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string result = "";
    int i=N1;
    int j=N2;
    while(i>0 && j>0) {
        if(A[i-1] == B[j-1]) {
            result += A[i-1];
            i--; j--;
        }else if(dp[i-1][j] > dp[i][j-1]) {
            result += A[i-1];
            i--;
        }else{
            result += B[j-1];
            j--;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    A = "acbcf";
    B = "adcbaf";

    N1 = A.size();
    N2 = B.size();
    cout << scs_print();
    return 0;
}
