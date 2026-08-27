/*
 * Problem Name: Prime_Multiples
 * Language: C++
 * Category: Mathematics
 * Date: 2026-08-27
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    long long n;
    int k;
    cin >> n >> k;
    vector<long long> a(k);
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    
    long long ans = 0;
    for(int mask = 1; mask < (1<<k); mask++){
        long long prod = 1;
        int bits = 0;
        bool overflow = false;
        for(int i = 0; i < k; i++){
            if((mask >> i)&1){
                bits++;
                if(n/a[i] < prod){
                    overflow = true;
                    break;
                }
                prod *= a[i];
            }
        }
        if(overflow){
            continue;
        }
        if(bits%2 == 1){
            ans += n/prod;
        }
        else{
            ans -= n/prod;
        }
    }
    
    cout << ans << "\n";
}