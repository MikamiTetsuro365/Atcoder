#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll mod = 1000000007;
ll INF = 1145141919454519;

//貪欲にやるのはわかっていたが
//なんかしょうもないミスしてた
int main() {

    ll N;
    cin >> N;
    ll ans = 0;
    ll tmp = 0;

    for(ll i = 0; i < N; i++){
        ll A; cin >> A;
        vec.push_back(A);
    }
    vec.push_back(0);

    if(N == 1){
        cout << vec[0] / 2 << endl;
        return 0;
    }

    for(ll i = 0; i < N; i++){
        if(vec[i] == 0) continue;
        if(i > 0 && vec[i - 1] == 1){
            ans++;
            vec[i]--;
        }
        ans += vec[i] / 2;
        vec[i] %= 2;
    }

    cout << ans << endl;

}