#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
ll N;

//小さい数から調べていく
//小さい数を左右端に配置していく最小回数を調べれば良い
//配置箇所が変わると次の数から交換回数の最小が変化するのでBITで頑張る

//Binary Indexed Treeの本体
vector<ll > bit;
//要素の追加
void add(ll a, ll w){
    //区間の長さと現在追加しようとしている値の添字を足すと求めることができる
    //区間の長さは区間番号を２進数にした時,最も下位にある立ったビットで分かる
    //x & -xで最も下位の立ったbitが分かる
    for(ll i = a; i <= N; i += i & -i){
        bit[i] += w;
    }
}

//区間1~aの和の計算
ll intervalSum_1_a(ll a){
    //次にどこを足せばよいかは区間番号からその区間番号の長さを引くと求まる
    ll ret = 0;
    for(ll i = a; i > 0; i -= i & -i){
        ret += bit[i];
    }
    return ret;
}

//区間a~bの和の計算
ll intervalSum_a_b(ll a, ll b){
    return intervalSum_1_a(b) - intervalSum_1_a(a-1);
}

int main() {    
    cin >> N;
    bit.assign(N+1, 0);
    
    //転倒数
    vector<ll > index(N+1, 0);
    for(ll i = 1; i <= N; i++){
        ll t = 0; cin >> t;
        add(i, 1);
        index[t] = i;
    }

    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ll l = intervalSum_1_a(index[i] - 1);
        ll r = intervalSum_a_b(index[i] + 1, N);
        //cout << index[i] << " " << l << " " << r <<  endl;
        //ll r = intervalSum_a_b(index[i] + 1, N);
        ans += min(l, r);
        //調べた要素を0に変更する
        //今回は全ての値が1で既知なので-1することで0を表現
        add(index[i], -1);
    }

    cout << ans << endl;

}