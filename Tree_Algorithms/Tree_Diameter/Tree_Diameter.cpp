/*
 * Problem Name: Tree_Diameter
 * Language: C++
 * Category: Tree_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 200005;
vector<int> adj[MAXN];
int farthest_node = 1;
int max_dist = -1;
 
void dfs(int u, int p, int d){
    if(d > max_dist){
        max_dist = d;
        farthest_node = u;
    }
    for(int v : adj[u]){
        if(v != p){
            dfs(v, u, d+1);
        }
    }
}
 
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    int node_a = farthest_node;
    max_dist = -1;
    dfs(node_a, 0, 0);
    cout << max_dist << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}