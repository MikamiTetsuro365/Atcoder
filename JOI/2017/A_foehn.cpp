#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll N, Q, S, T;

ll calc_temp(ll diff){
    ll ans = 0;
    if(diff > 0) ans = -diff * S;
    else ans = -diff * T; 

    return ans;
}
//ある地点の高低差を予め出しておく
//lからrまでの高低差がx分変動する=高低差配列のl-1とrの変化だけが最終的な気温の変化に効いてくる
//lからr-1までは高低差が変化したとしても気温の変化は変わらない
int main(){

    cin >> N >> Q >> S >> T;

    vector<ll > p(N+1, 0);
    vector<ll > diff(N, 0);
    ll temp = 0;
    //入力
    for(ll i = 0; i <= N; i++){
        cin >> p[i];
    }
    //地点間の高低差
    for(ll i = 1; i <= N; i++){
        diff[i-1] = p[i] - p[i-1]; 
    }
    //初期気温計算
    for(ll i = 0; i < N; i++){
        temp += calc_temp(diff[i]);
    }
    
    //cout << temp << endl;

    for(ll i = 0; i < Q; i++){
        ll l, r, x; cin >> l >> r >> x;
        
        if(0 < l){
            temp -= calc_temp(diff[l-1]);
            //高低差に反映
            //xがプラス l-1の差は増加 rは減少
            //xがマイナスは逆
            diff[l-1] += x;
            temp += calc_temp(diff[l-1]);
        }
        if(r < N ){
            temp -= calc_temp(diff[r]);
            //高低差に反映
            diff[r] -= x;
            temp += calc_temp(diff[r]);          
        }
        cout << temp << endl;
    }

}