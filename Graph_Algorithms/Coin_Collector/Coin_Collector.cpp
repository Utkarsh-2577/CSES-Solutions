/*
 * Problem Name: Coin_Collector
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
void dfs1(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& order){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs1(v, adj, vis, order);
        }
    }
    order.push_back(u);
}
 
void dfs2(int u, vector<vector<int>>& rev_adj, vector<int>& scc, int id){
    scc[u] = id;
    for(int v : rev_adj[u]){
        if(scc[v] == 0){
            dfs2(v, rev_adj, scc, id);
        }
    }
}
 
int kosaraju(int n, vector<vector<int>>& adj, vector<vector<int>>& rev_adj, vector<int>& scc){
    vector<bool> vis(n+1, false);
    vector<int> order;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs1(i, adj, vis, order);
        }
    }
    int scc_cnt = 0;
    for(int i = n-1; i >= 0; i--){
        int u = order[i];
        if(scc[u] == 0){
            scc_cnt++;
            dfs2(u, rev_adj, scc, scc_cnt);
        }
    }
    return scc_cnt;
}
 
vector<vector<int>> build_scc_dag(int n, vector<vector<int>>& adj, vector<int>& scc, int scc_cnt){
    vector<vector<int>> dag(scc_cnt+1);
    for(int u = 1; u <= n; u++){
        for(int v : adj[u]){
            if(scc[u] != scc[v]){
                dag[scc[u]].push_back(scc[v]);
            }
        }
    }
    return dag;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<long long> k(n+1);
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
 
    vector<vector<int>> adj(n+1), rev_adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
 
    vector<int> scc(n+1, 0);
    int scc_cnt = kosaraju(n, adj, rev_adj, scc);
 
    vector<long long> scc_coins(scc_cnt+1, 0);
    for(int i = 1; i <= n; i++){
        scc_coins[scc[i]] += k[i];
    }
 
    vector<vector<int>> dag = build_scc_dag(n, adj, scc, scc_cnt);
    vector<long long> dp(scc_cnt+1, 0);
    long long ans = 0;
 
    for(int u = 1; u <= scc_cnt; u++){
        dp[u] = max(dp[u], scc_coins[u]);
        ans = max(ans, dp[u]);
        for(int v : dag[u]){
            dp[v] = max(dp[v], dp[u]+scc_coins[v]);
        }
    }
 
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    while(t--) solve();
}