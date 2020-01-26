#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {
    

    ll N;
    cin >> N;
    
    vector<ll > tmp(2*1000000, 0);
    
    ll mx = -1;
    for(ll i = 0; i < N; i++){
        ll a, b; 
        cin >> a >> b;
        tmp[a]++;
        tmp[b+1]--;
        mx = max(mx, b);
    }
    
    vector<ll > sum(2*1000000, 0);

    for(ll i = 1; i <= 1000019; i++){
        sum[i] += sum[i-1] + tmp[i];
    }    
    
    bool f = false;
    ll ans = 0;
    for(ll i = 0; i <= mx; i++){
        if(sum[i] == 0 && f == false){
            ans++;
            f = true;
        }else if(sum[i] != 0){
            f = false;
        }
    }    
    
    cout << ans << endl;
    
}