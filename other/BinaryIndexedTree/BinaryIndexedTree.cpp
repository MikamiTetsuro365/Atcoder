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
ll intervalSum(ll a){
    //次にどこを足せばよいかは区間番号からその区間番号の長さを引くと求まる
    ll ret = 0;
    for(ll i = a; i > 0; i -= i & -i){
        ret += bit[i];
    }
    return ret;
}

int main() {    
    ll q;
    cin >> N >> q;
    bit.assign(N+1, 0);

    //立っているビットが常に1つある状態にしたいので添字は1からスタート
    /*
    for(ll i = 1; i <= N; i++){
        ll t = 0; cin >> t;
        add(i, t);
    }
    */

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

   for(ll i = 0; i < ans.size(); i++){
       cout << ans[i] << endl;
   }
}