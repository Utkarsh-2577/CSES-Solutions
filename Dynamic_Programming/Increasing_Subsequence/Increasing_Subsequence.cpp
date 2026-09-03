/*
 * Problem Name: Increasing_Subsequence
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
 
    vector<int> tails;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(tails.begin(), tails.end(), x[i]);
        if(it == tails.end()){
            tails.push_back(x[i]);
        }
        else *it = x[i];
    }
 
    cout << tails.size() << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}