#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll N;
    cin >> N;

    N *= 2;

    vector<ll > v;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        v.push_back(t);
    }

    
    ll sumA = 0;
    ll sumB = 0;
    for(ll i = 0; i < N; i++){
        if(i % 2 == 1){
            sumA += v[i];
        }else{
            sumB += v[i];
        }
    }

    ll ans = sumA - sumB;
    for(ll i = 0; i < N; i += 2){
        sumA = sumA + v[i] - v[i+1];
        sumB = sumB - v[i] + v[i+1];
        ll tmp = sumA - sumB;
        //cout << tmp << " " << sumA << " " << sumB << endl;
        ans = max(ans, tmp);
        //if(ans < tmp) ans = tmp;
    }    

    cout << ans << endl;

}