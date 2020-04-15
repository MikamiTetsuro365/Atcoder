#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;
typedef pair<pair<double, double >, double > pdd;
typedef pair<double, double > pd;  
vector<ll > vec;
vector<vector<ll > > vec2;
vector<vector<ll > > G;
ll MOD = 1000000007;
ll INF = 1145141919454519;
 
int main(){

    ll N;
    cin >> N;

    vec.assign(N+191919, INF);
    for(ll i = 0; i < N; i++){
        cin >> vec[i];
    }

    ll ans = INF;    

    for(ll i = 0; i < N; i++){
        ans = min(ans, vec[i+N/2+1]-vec[i]);
    }

    cout << ans << endl;

}