#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;
//区間ごとにanが何回採用されるかを求めると良い
int main(){
 
    ll N;
    cin >> N;
 
    //vector<ll > A(N, 0);
    vector<ll > idx(N+2, 0);
 
    for(ll i = 1; i <= N; i++){
        ll t; cin >> t;
        //各要素の位置を記録
        idx[t] = i;
    }
 
    ll ans = 0;
 
    //番兵：2つ先，2つ前を見るので複数入れとかないと飛び越してしまう
    //set<ll > usedIdx = {0, N+1};
    multiset<ll > usedIdx;
    usedIdx.insert(0);
    usedIdx.insert(0);
    usedIdx.insert(N+1);
    usedIdx.insert(N+1);
    //自分自身の要素が採用される区間はいくつか？を求める．
    
    //大きい順に挿入された位置を見て自分より右or左に自分より大きい数字があるかを調べる
    for(ll i = N; i >= 1; i--){
        auto it = usedIdx.lower_bound(idx[i]);
        //自分より右側で自分より大きい
        ll R  = *it;
        it++;
        //さらに右側
        ll RR = *it;
        it--; it--;
        //自分より左側で自分より大きい
        ll L  = *it;
        it--;
        ll LL = *it;

        //cout << *left_idx << " " << *right_idx << endl;
        //位置を追加
        usedIdx.insert(idx[i]);
        // //答え更新
        // ans += ((idx[i] - *left_idx) * (*right_idx - idx[i])) * i;

        //左側の自分より大きい数基準での組み合わせ
        //ただの組み合わせの掛け算
        ans += i * (R - idx[i]) * (L - LL);
        //右側の自分より大きい数基準での組み合わせ
        ans += i * (idx[i] - L) * (RR - R);
    }
 
    cout << ans << endl;
 
} 