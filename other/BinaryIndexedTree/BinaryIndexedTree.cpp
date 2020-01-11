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

//二分探査 累積和がw以上になる最小のx
/*
ll lowerBound(ll w){
    if(w <= 0) return 0;
    ll x = 0;
    ll k = 1;
    while(k * 2 <= N) k *= 2;
    for(ll i = k; i > 0; i /= 2){
        if(x + i <= N && bit[x + i] < w){
            w -= bit[x + i];
            x += i;
        }
    }
    return x + 1;
}
*/



int main() {    
    ll q;
    cin >> N;
    bit.assign(N+1, 0);

    //立っているビットが常に1つある状態にしたいので添字は1からスタート
    //構築
    for(ll i = 1; i <= N; i++){
        ll t = 0; cin >> t;
        add(i, t);
    }

    /*クエリの処理
    vector<ll > ans;
    for(ll i = 0; i < q; i++){
        ll com; cin >> com;
        ll x, y; cin >> x >> y; 
        if(com == 0){
            add(x, y);
        }else{
            ans.push_back(intervalSum(y) - intervalSum(x-1));
            //cout << intervalSum(y) - intervalSum(x-1) << endl;
        }
    }
    */
    
    //転倒数
    /*
    vector<ll > num(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> num[i];
    }
    cout << invNum(num) << endl;
    */

}