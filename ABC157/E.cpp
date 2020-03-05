#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
//コンテスト中はBIT26個使えば行けそうとか思ってたけど，setでやると簡単だった(ほんまか？)
int main() { 

    ll N, Q;
    string S;
    cin >> N >> S >> Q;
    S = S;
    //cout << S << endl;
    //26文字分Setを用意してアルファベットの現れる位置を管理する
    //初期化->番兵追加
    vector<set<ll > > D(26, set<ll >({-1, INF}));
    //setに追加
    for(ll i = 0; i < N; i++){
        D[S[i]-'a'].insert(i);
    }

    vector<ll > ans;
    for(ll i = 0; i < Q; i++){
        ll t; cin >> t;
        if(t == 1){
            ll idx;
            char to_ch;
            cin >> idx >> to_ch;
            idx--;
            //検索
            D[S[idx] - 'a'].erase(idx);
            D[to_ch - 'a'].insert(idx);
            S[idx] = to_ch;
            //cout << S << endl;
        }else{
            //cout << S << endl;
            ll s, e; cin >> s >> e;
            ll cn = 0;
            //ピッタリ-ピッタリで区間を調べるとs==eの時ダメ
            --s;
            for(ll j = 0; j < 26; j++){
                if(D[j].empty()) continue;
                //sからeの区間にアルファベットjは存在するか？を調べる.
                ll st = *D[j].lower_bound(s);
                ll et = *D[j].lower_bound(e);
                if(et > st){
                    cn++;
                }
                //cout << st << " " << et << endl;
            }
            ans.push_back(cn);
            //cout << cn << endl;
        }
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

}