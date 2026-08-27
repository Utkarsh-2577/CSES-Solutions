/*
 * Problem Name: Josephus_Queries
 * Language: C++
 * Category: Mathematics
 * Date: 2026-08-27
 */

#include <bits/stdc++.h>
using namespace std;
 
int solve(int n, int k){
    if(n == 1){
        return 1;
    }
    
    if(k <= (n+1)/2){
        if(2*k > n){
            return 2*k%n;
        }
        else{
            return 2*k;
        }
    }
    
    int c = solve(n/2, k-(n+1)/2);
    if(n%2 == 1){
        return 2*c+1;
    }
    else{
        return 2*c-1;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
}