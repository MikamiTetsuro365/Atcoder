#include "bits/stdc++.h"
#include <unordered_set>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N, H;
    cin >> N >> H;

    vector<ll > A;
    vector<ll > B;

    for(ll i = 0; i < N; i++){
        ll a, b; cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        //attack.push_back(make_pair(a, b));
    }

    //sort(attack.rbegin(), attack.rend());
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    ll ans = 0;
    //逆からさかのぼって求めるイメージ
    //捨ててから斬りつける
    //とりあえず剣を投げつけたほうがダメージが大きく入るので投げつける
    //しかし，切りつけたほうが効率が良いときは斬りつけるほうが最適
    for(ll i = 0; i < N; i++){
        if(H <= 0){
            cout << ans << endl;
            return 0;
        }
        //剣を投げつけるより，切りつけたほうが良い刀があればそっちに切り替える
        /*if(attack[0].first > attack[i].second){
            break;
        }
        */
        if(A[0] > B[i]) break;
        H -= B[i];
        ans++;
    }

    ans += H / A[0];

    if(H % A[0] > 0){
        ans++;
    }

    cout << ans << endl;

}