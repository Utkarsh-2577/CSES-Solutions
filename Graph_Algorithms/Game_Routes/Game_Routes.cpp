/*
 * Problem Name: Game_Routes
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 100005;
vector<int> adj[MAXN];
int dp[MAXN];
int n, m;
const int MOD = 1e9+7;
 
int dfs(int u){
    if(u == n){
        return 1;
    }
    if(dp[u] != -1){
        return dp[u];
    }
    
    int sum = 0;    
    for(int v : adj[u]){
        int res = dfs(v);
        if(res > 0){
            sum = (sum+res)%MOD;
        }
    }
    
    return dp[u] = sum;
}
 
void solve(){
    cin >> n >> m;    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for(int i = 1; i <= n; i++){
        dp[i] = -1;
    }
    int ans = dfs(1);
    
    cout << ans%MOD;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}