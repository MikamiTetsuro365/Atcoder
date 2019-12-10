#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {

    ll N; cin >> N;
    vector<map<ll, ll > > v(N);
    vector<ll > tr(N, 0);
    vector<ll > fl(N, 0);


    for(ll i = 0; i < N; i++){
        ll t; cin >> t; 
        for(ll j = 0; j < t; j++){
            ll a, b; cin >> a >> b;
            a--;
            v[i][a] = b;
        }
    }

    ll ans = 0;
    for(ll i = 0; i < (1<<N); i++){
        //ビットの位置を数える
        ll t_ans = 0;
        ll shogen = 0;
        bool f = true;
        for(ll j = 0; j < N; j++){
            //右シフトして最下位で立っているかどうか判定
            //syogen
            //cout << i << ":" << bitset<8>(i) << endl;
            //cout << (1 << j) << endl;
            if(i & (1 << j)){
                t_ans++;
                auto begin = v[j].begin(), end = v[j].end();
                for (auto iter = begin; iter != end; iter++) {
                    //正直者と不親切者を仮定する
                    //正直者の証言は必ず正直.正直者の発言だけに注目する
                    //仮定で不親切者と仮定されている者を正直というと矛盾
                    //また逆に仮定で正直者と仮定した者を不親切者というと矛盾
                    //この２つをチェックする
                    // 1 != 0 0 != 1 が 矛盾
                    if( (0 != (i & (1 << iter->first))) != iter->second){
                        f = false;
                    }
                }
            }
        } 

        if(f == true){
            ans = max(t_ans, ans);
        }
    }

    cout << ans << endl;

}