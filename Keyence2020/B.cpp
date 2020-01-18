#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
//終点でソート！

int main() 
{ 

    ll N;
    cin >> N;
    vector<pi > C(N);

    for(ll i = 0; i < N; i++){
        ll c, r; cin >> c >> r;
        C[i].first = c;
        C[i].second = r;
    }
    
    sort(C.begin(), C.end());

    vector<pi > CC(N);
    for(ll i = 0; i < N; i++){
        CC[i].first  = C[i].first + C[i].second;
        CC[i].second = C[i].first - C[i].second;
    }

    sort(CC.begin(), CC.end());

    ll ans = 0;
    ll mn = -INF; 
    for(ll i = 0; i < N; i++){
        if(mn <= CC[i].second){
            mn = CC[i].first;
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0; 
} 