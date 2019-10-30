#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N, M; cin >> N >> M;

    vector<ll > t(N,0);
    vector<ll > d(N,0);
    vector<ll > d_d(N,0);
    vector<pi> ans;

    for(ll i = 0; i < N; i++){
        t[i]=i;
    }
    //途中までの結果
    for(ll i = 0; i < M; i++){
        ll x, y; cin >> x >> y;
        swap(t[x-1], t[y-1]);
    }
    //最終的な結果
    for(ll i = 0; i < N; i++){
        cin >> d[i]; d[i]--;
        //目標位置と縦棒の位置を対応させる
        //バブルソートする
        ll j = 0;
        //並び替える前の前処理
        for(j = 0; j < N; j++){
            if(t[j] == i){
                break;
            }
        }
        d_d[j] = d[i];
    }

    /*
    for(ll i = 0; i < N; i++){
        cout << d_d[i] << endl;
    }
    */
    
    //バブルソート
    for(ll i = 0; i < N - 1; i++){
        for(ll j = N - 1; j > i; j--){
            if(d_d[j] < d_d[j-1]){
                swap(d_d[j], d_d[j-1]);
                ans.push_back(make_pair(j, j+1));
            }
        }
    }

    cout << ans.size() << endl;

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

}