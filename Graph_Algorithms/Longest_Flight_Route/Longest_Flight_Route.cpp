/*
 * Problem Name: Longest_Flight_Route
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 100005;
vector<int> adj[MAXN];
int dp[MAXN];
int child[MAXN];
int n, m;
 
int dfs(int u){
    if(u == n){
        return 1;
    }
    if(dp[u] != -1){
        return dp[u];
    }
    
    int best = -2;
    int nxt = -1;
    
    for(int v : adj[u]){
        int res = dfs(v);
        if(res > 0 && res+1 > best){
            best = res+1;
            nxt = v;
        }
    }
    
    child[u] = nxt;
    return dp[u] = best;
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
        child[i] = -1;
    }
    
    int ans = dfs(1);
    
    if(ans < 0){
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << "\n";
        int curr = 1;
        while(curr != -1){
            cout << curr << (child[curr] != -1 ? " " : "");
            curr = child[curr];
        }
        cout << "\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}