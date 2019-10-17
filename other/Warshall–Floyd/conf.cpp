#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = INFINITY;
int main(){
    //INF+INFがマイナスになる！ハマリポイントっぽい
    ll ans = min((ll)-1, INF + INF);
    cout << ans << endl;
}