/*
 * Problem Name: Course_Schedule
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
vector<int> toposort(vector<vector<int>>& adj){
    int n = adj.size();
    vector<int> inward_degree(n, 0);
    for(int i = 1; i < n; i++){
        for(int nbr : adj[i]){
            inward_degree[nbr]++;
        }
    }
    queue<int> q;
    for(int i = 1; i < n; i++){
        if(inward_degree[i] == 0) q.push(i);
    }
    vector<int> sorted(n);
    int idx = 1;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        sorted[idx++] = val;
        for(int nbr : adj[val]){
            inward_degree[nbr]--;
            if(inward_degree[nbr] == 0) q.push(nbr);
        }
    }
    return sorted;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
 
    vector<int> ans = toposort(adj);
    for(int i = 1; i <= n; i++){
        if(ans[i] == 0){
            cout << "IMPOSSIBLE";
            return;
        }
    }
 
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
 
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    while(t--) solve();
}