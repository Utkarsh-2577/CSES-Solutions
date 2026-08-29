/*
 * Problem Name: Road_Construction
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
class dsu{
    vector<int> parent;
    vector<int> sz;
public:
    int components;
    int max_sz;
 
    dsu(int size){
        parent.resize(size);
        sz.resize(size, 1);
        components = size-1;
        max_sz = 1;
        for(int i = 0; i < size; i++){
            parent[i] = i;
        }
    }
    int find_set(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find_set(parent[i]);
    }
    void union_sets(int i, int j){
        int irep = find_set(i);
        int jrep = find_set(j);
        if(irep != jrep){
            parent[irep] = jrep;
            sz[jrep] += sz[irep];
            max_sz = max(max_sz, sz[jrep]);
            components--;
        }
    }
};
 
void solve(){
    int n, m;
    cin >> n >> m;
    dsu d(n+1);
 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        d.union_sets(u, v);
        cout << d.components << " " << d.max_sz << "\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}