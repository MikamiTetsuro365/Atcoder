#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//もっと簡単に考えろ
int main() {

    ll N;
    cin >> N;

    ll average = 0;
    vector<ll > R(N + 2, 0);
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        //R[i+1] = t + R[i];
        vec.push_back(t);
        average += t;
    }
    
    if(average % N > 0){
        cout << -1 << endl;
        return 0;
    }
    average /= N;

    ll ans = 0;
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        sum += vec[i];
        //cout << sum << " " << (i + 1) * average << endl;
        //それまでの島の人数が平均×島と一致していないならとりあえず橋をかける
        //島の片側についてちょうど平均×島だけ人数が居ますか？
        if(sum != (i + 1) * average){
            ans++;
        } 
    }

    cout << ans << endl;

}