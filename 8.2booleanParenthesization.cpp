#include <bits/stdc++.h>

using namespace std;

map<string, int> dp;
int ways(string s, int i, int j, bool isTrue) {
    // Base case:
    if(i > j) return 0;
    // only single character
    if(i == j) {
        if(isTrue == true)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

//    stringstream ss(temp);
//    string temp="";
//    ss >> temp;

    int ans = 0;
    for(int k=i+1; k<j; k += 2) {
        int leftTrue = ways(s, i, k-1, true);
        int leftFalse = ways(s, i, k-1, false);
        int rightTrue = ways(s, k+1, j, true);
        int rightFalse = ways(s, k+1, j, false);
        if(s[k] == '&') {
            if(isTrue) {
                ans += (leftTrue*rightTrue);
            }else{
                ans += (leftFalse*rightTrue+leftTrue*rightFalse+leftFalse*rightFalse);
            }
        } else if(s[k] == '|') {
            if(isTrue) {
                ans += (leftTrue*rightFalse+leftFalse*rightTrue+leftTrue*rightTrue);
            }else{
                ans += (leftFalse*rightFalse);
            }
        }else {
            if(isTrue) {
                ans += (leftTrue*rightFalse+rightTrue*leftFalse);
            }else {
                ans += (leftTrue*rightTrue+leftFalse*rightFalse);
            }
        }
    }

    return ans;
}


int main()
{
    // Return number of ways such that expression becomes true
    string s="T|F&T^F";
    cout << ways(s, 0, s.size()-1, true);
    return 0;
}
