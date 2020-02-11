#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//愚直な式展開をプログラム化した（くそ）

int main() {

    ll N;
    cin >> N;

    ll sum = 0;
    ll fugou = 1;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        sum = sum + fugou * 2 * t;
        //cout << ":" << sum << endl;
        vec.push_back(sum);
        //符号の変化を忘れずに
        fugou *= -1;
    }
    //fugou *= -1;

    ll idx = N-1;
    vector<ll > ans(N, 0);
    //一箇所固定して求めていく
    for(ll i = N-1; i >= 0; i--){
        if(i == N - 1) ans[0] = vec[i] / 2;
        else ans[idx] = fugou * (ans[0] - vec[i]), idx--;
        //符号の変化を忘れずに
        fugou *= -1;
        //cout << vec[i] << endl;
    }

    for(ll i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;

}