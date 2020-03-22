#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;


struct BIT{

    //Binary Indexed Treeの本体
    vector<ll > bit;

    //定義
    BIT(ll N) : bit(N){
        for(ll i = 0; i <= N + 1; i++) bit[i] = 0; 
    }
    //要素の追加
    void add(ll a, ll w){
        //区間の長さと現在追加しようとしている値の添字を足すと求めることができる
        //区間の長さは区間番号を２進数にした時,最も下位にある立ったビットで分かる
        //x & -xで最も下位の立ったbitが分かる
        for(ll i = a; i <= bit.size(); i += i & -i){
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
        for(ll i = 0; i < bit.size(); i++){
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


};

ll G[1919][1919];
int main(){

    ll H, W, K;
    cin >> H >> W >> K; 
    BIT tate(W);
    BIT yoko(H);
    
    for(ll i = 0; i < H; i++){
        ll sum = 0;
        string s; cin >> s;
        for(ll j = 0; j < W; j++){
            //cout << s[j] << endl;
            yoko.add(i+1, s[j]-'0');
            tate.add(j+1, s[j]-'0');   
        }
        
    }

    ll ans = 0;
    //縦チェック
    for(ll i = 0; i < H; i++){
        //cout << yoko.intervalSum_1_a(i+1) << endl;
        ll num = yoko.intervalSum_1_a(i+1);
        cout << num << endl;
        if(num > K){
            ans++;
            yoko.add(i+1, -num);   
        }
    }  
    //横チェック
    for(ll i = 0; i < W; i++){
        //cout << yoko.intervalSum_1_a(i+1) << endl;
        ll num = tate.intervalSum_1_a(i+1);
        
        if(num > K){
            ans++;
            tate.add(i+1, -num);   
        }
    }     

    cout << ans << endl;

    // for(ll i = 0; i < H; i++){
    //     cout << yoko.intervalSum_1_a(i+1) << endl;
    // }


}