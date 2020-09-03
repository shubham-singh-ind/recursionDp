#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
bool solve(string a, string b) {
    // Both strings are equal
    if(a.compare(b) == 0) return true;
    if(a.size() <= 1) return false;
    int n = a.size();
    string temp = a+" "+b;
    if(mp.find(temp) != mp.end()) return mp[temp];
    bool flag = false; // not scrambled
    for(int k=1; k<n; k++) {
        // swap
        int caseI = solve(a.substr(0, k), b.substr(n-k)) && solve(a.substr(k), b.substr(0, n-k));
        // don't swap
        int caseII = solve(a.substr(0, k), b.substr(0, k)) && solve(a.substr(k), b.substr(k));
        if(caseI || caseII) {
            flag = true;
            break;
        }
    }
    mp[temp] = flag;
    return mp[temp];
}

bool s(string a, string b) {
    if(a.size() != b.size()) return false;
    if(a.size()==0 && b.size()==0) return true;
    return solve(a, b);
}

int main()
{
    string a = "great";
    string b = "agret";
    if(s(a, b))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
