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

    //番兵を挿れておく
    set<ll > usedIdx = {0, N+1};
    //小さい値からその左右に自分より小さい要素がどの位置にあるかを調べる
    //つまり，自分より小さい要素があるところまでの区間では自分が採用される
    //逐次，setに自分の位置を追加しながら調べていく
    
    for(ll i = 1; i <= N; i++){
        //右側で自分より小さい要素の位置(自分以上の最小)
        auto right_idx = usedIdx.lower_bound(idx[i]);
        //左側で自分より小さい要素の位置(自分以下の最大)
        auto left_idx = usedIdx.lower_bound(idx[i]);
        if(*left_idx > idx[i]) left_idx--;
        //追加
        usedIdx.insert(idx[i]);
        //答え更新
        ans += ((idx[i] - *left_idx) * (*right_idx - idx[i])) * i;
        //cout << ((idx[i] - *left_idx) * (*right_idx - idx[i])) << endl;
        //cout << "left:" << *left_idx << "right:" <<*right_idx << endl;

    }

    cout << ans << endl;


} 