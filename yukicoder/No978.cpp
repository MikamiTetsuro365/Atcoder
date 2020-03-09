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
        ret %= MOD;
    }
    return ret;
}

//区間a~bの和の計算
ll intervalSum_a_b(ll a, ll b){
    return intervalSum_1_a(b) - intervalSum_1_a(a-1);
}

//

//転倒数
ll invNum(vector<ll > num){
    //BITに順番に数を追加していく.
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        //数列の値を追加する前
        //num[i]が追加される前，intervalSum(num[i])でそれより小さい数がいくつ追加されているか調べる.
        //iは何個目にnum[i]がBITに追加されるか
        //つまりi - intervalSum(num[i])で実際の数列で左端から
        //数を転倒していったときi個目にいる自分が自身より大きい数と何回すれ違うかを表す.
        ans += i - intervalSum_1_a(num[i]);
        //最後にnum[i]を区間に足しておく.
        add(num[i], 1);
    }
    return ans;
}

int main() {    
    ll p;
    cin >> N >> p;
    bit.assign(N+1, 0);

    //立っているビットが常に1つある状態にしたいので添字は1からスタート
    //構築
    vector<ll > tmp(N, 0);
    tmp[0] = 0;
    tmp[1] = 1;
    for(ll i = 2; i < N; i++){
        tmp[i] = p * tmp[i-1] + tmp[i-2];
        //cout << tmp[i] << endl;
        tmp[i] %= MOD;
    }

    for(ll i = 1; i <= N; i++){
        //cout << tmp[i-1] << " ";
        add(i, tmp[i-1]);
    }
    //cout << endl;

    ll sum = 0;
    for(ll i = 1; i <= N; i++){
        sum += tmp[i-1] * intervalSum_1_a(i);
        sum %= MOD;
        //cout << tmp[i-1] * intervalSum_1_a(i) << endl;
    }

    cout << sum << endl;

}