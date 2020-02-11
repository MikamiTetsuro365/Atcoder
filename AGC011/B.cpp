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

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end());
    vec.push_back(INF);

    //累積わ
    // start r[0] = 0
    vector<ll > r(N + 2, 0);
    for(ll i = 0; i < N + 1; i++){
        r[i+1] = r[i] + vec[i];
    }

    //確認
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll num = vec[i] * 2;
        while(true){
            ll choka = upper_bound(vec.begin(), vec.end(), num) - vec.begin();
            //ll ika = choka - 1;
            num = r[choka] * 2;
            //cout << ":" <<  num << endl;
            if(vec[choka] > num){
                if(vec[choka] == INF){
                    ans++; 
                }
                break;
            }
        }        
        //cout << num << " " << r[ika] << endl;
    }

    cout << ans << endl;

}