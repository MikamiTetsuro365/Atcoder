#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    cin >> N;

    ll ans = 1;
    ll tmp = 1;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    vec.push_back(-1);

    for(ll i = 0; i < N; i++){
        if(vec[i] <= vec[i+1]){
            //cout << vec[i] << endl;
            tmp++;
        }else{
            ans = max(tmp, ans);
            tmp = 1;
        }
    }

    cout << ans << endl;

}