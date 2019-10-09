#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<double, double > pi; 
typedef pair<pair<double, double >, double > pii; 
int main(){

    ll N, C;
    cin >> N >> C;

    priority_queue<pii, vector<pii>, greater<pii> >  que;
    
    //重複は削除
    map<ll, map<pair<ll, ll>, ll > > mp;
    for(ll i = 0; i < N; i++){
        ll S, T, C; cin >> S >> T >> C;
        que.push(make_pair(make_pair(S, T), C));
    }

    
    ll ans = 0;

    cout << ans << endl;

}