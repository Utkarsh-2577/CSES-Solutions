/*
 * Problem Name: Flight_Routes_Check
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v, adj, vis);
        }
    }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1), rev_adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
 
    vector<bool> vis1(n+1, false);
    dfs(1, adj, vis1);
 
    for(int i = 1; i <= n; i++){
        if(!vis1[i]){
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return;
        }
    }
 
    vector<bool> vis2(n+1, false);
    dfs(1, rev_adj, vis2);
 
    for(int i = 1; i <= n; i++){
        if(!vis2[i]){
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return;
        }
    }
 
    cout << "YES\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    while(t--) solve();
}