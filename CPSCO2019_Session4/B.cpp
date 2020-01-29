#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//無駄なbit全探査
int main() {

    ll N, D;
    cin >> N >> D;

    vector<string > s(D);

    for(ll i = 0; i < D; i++){
        cin >> s[i];
    }
    //前処理 N日目出席する人何人イルカ
    vector<ll > DD(D, 0);
    for(ll i = 0; i < D; i++){
        ll tmp = 0;
        for(ll j = 0; j < N; j++){
            if(s[i][j] == 'o'){   
                tmp += pow(2, j);
            }
        }
        //cout << tmp << endl;  
        DD[i] = tmp;
    }

    ll ans = -1;
    for(ll i = 0; i <= (1<<D); i++){
        if(__builtin_popcount(i) != 2) continue;
        //for(ll j = 0; j M)
        //ll tmp = pow(2, N) - 1;
        ll tmp = 0;
        for(ll j = 0; j < D; j++){
            if((i>>j) & 1 == 1){
                tmp |= DD[j];
            }
        }
        ans = max(ans, (ll)__builtin_popcount(tmp));
    }
    cout << ans << endl;

}