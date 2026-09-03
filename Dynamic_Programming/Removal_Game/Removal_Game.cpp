/*
 * Problem Name: Removal_Game
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
    int n;
    cin >> n;
    vector<ll>  x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
 
    vector<vector<ll>> dp(n, vector<ll> (n, 0));
 
    for(int len = 1; len <= n; len++){
        for(int i = 0; i <= n-len; i++){
            int j = i+len-1;
 
            if(i == j){
                dp[i][j] = x[i];
            }
            else if(i+1 == j){
                dp[i][j] = max(x[i], x[j]);
            }
            else{
                ll option1 = x[i] + min(dp[i+2][j], dp[i+1][j-1]);
                ll option2 = x[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] = max(option1, option2);
            }
        }
    }
 
    cout << dp[0][n-1] << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}