#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M;

int main(){

    ll n; cin >> n;
    set<ll > d;
    for(ll i = 0; i < n; i++){
        ll t; cin >> t; d.insert(t);
    }
    ll x, y; cin >> x >> y;
    ll goal = max(abs(x), abs(y));
    if(goal == 0){
        cout << 0 << endl;
        return 0;
    }
    if(d.find(goal) != d.end()){
        cout << 1 << endl;
        return 0;
    }

    //setの最大値
    auto it = d.end(); it--;
    ll mx_d = *it;
    //cout << mx_d << endl;

    ll ans = 0;
    while(goal >= 2 * mx_d){
        goal -= mx_d;
        ans++;
    }
    if(goal == mx_d){
        ans++;
    }else{
        ans+=2;
    }
    cout << ans << endl;

}