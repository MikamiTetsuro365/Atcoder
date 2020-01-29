#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//尺取
int main() {

    ll N, D;
    cin >> N >> D;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());

    ll ans = 0;
    ll cn = 0;

    ll left = 0;
    ll right = 0;
    while(left < N){
        while(right < N){
            if(vec[right] > vec[left]+D) break;
            cn++;
            right++;
        }
        cn--;
        left++;
        if(cn >= 2){
            ans += cn * (cn-1) / 2;
        }
    }

    cout << ans << endl;
}