#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll N; cin >> N;
    ll ans = INF;

    for(ll i = 1; i <= N; i++){
        ll t_ans = 0;
        //とりうる相方で最大
        ll j = N / i;
        t_ans += abs(i - j);
        t_ans += N - (i * j);
        ans = min(ans, t_ans);  
    }

    cout << ans << endl;

}