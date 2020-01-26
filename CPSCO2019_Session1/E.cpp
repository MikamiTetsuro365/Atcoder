#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

//一見すると何回も同じ操作が起こるとしんどそう
//2つの数のXORは0，奇数個でもとに戻ってくるし偶数個で0になる
//つまりXORをとった後，Xに変えるという操作は元の数か0を戻すという操作にしてよい
//もっというと0は戻さなくて良さそう
//後は効率よく範囲を取り出して数字を戻す操作だけをする
//徐々に検索対象と計算対象の要素は減っていくので問題ない
int main() {

    ll N, Q;
    cin >> N >> Q;

    //要素の重複を許すset
    multiset<ll > st;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        st.insert(t);
    }

    vector<ll > ans;
    for(ll i = 0; i < Q; i++){
        ll l, r, x;
        cin >> l >> r >> x;
        //以上以下の範囲を取得
        auto s = st.lower_bound(l);
        auto e = st.upper_bound(r);

        //setから取り出し
        vector<ll > tmp;
        ll t_ans = 0;
        ll cn = 0;
        while(s != e){
            t_ans ^= *s;
            tmp.push_back(*s);
            s++;
            cn++;
        }
        //削除
        for(ll i = 0; i < tmp.size(); i++){
            st.erase(tmp[i]);
        }

        //cout << ans << endl;
        if(cn % 2 == 1){
            st.insert(x);
        }

        ans.push_back(t_ans);
    }
    //表示
    for(ll i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }

}