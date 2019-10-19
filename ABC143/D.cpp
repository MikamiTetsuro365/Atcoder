#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N; cin >> N;

    vector<ll > kukan(5000, 0);

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        kukan[t]++;
    }

    sort(vec.begin(), vec.end());

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        for(ll j = i + 1; j < N; j++){
            ll a = vec[i];
            ll b = vec[j];

            ll m_c = 0;
            if(a > b){
                m_c = a - b + 1;
            }

            if(b > a){
                m_c = max(b - a + 1, m_c);
            }
            cout << m_c << " " << a + b << endl;
            for(ll k = m_c + 1; k < a + b; k++){
                if(kukan[k] == 0) continue;
                if(k == a && k == b){
                    ans += max(ll(0), kukan[k] - 2);
                    continue;
                }
                if(k == a){
                    ans += max(ll(0), kukan[k] - 1);
                    continue;     
                }
                if(k == b){
                    ans += max(ll(0), kukan[k] - 1);
                    continue;     
                }
                ans += kukan[k];
            }

        }    
    }
    
    cout << ans << endl;



}