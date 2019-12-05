#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

//階乗
vector<ll>fact;
//逆元
vector<ll>inv;
//逆元階乗
vector<ll>finv;

//拡張ユークリッドの互除法
pii extgcd(ll a, ll b){
    //前提：aとbが互いに素であること．
    pii x(make_pair(1,0), a);
    pii y(make_pair(0,1), b);

    ll div = 0;

    //終了条件:(GCD(a,b), 0)または(0,GCD(a,b))
    while(true){
        if(y.second == 0) return x;
        
        div = x.second / y.second;
        x.second = x.second  - div * y.second;
        x.first.first = x.first.first - div * y.first.first;
        x.first.second = x.first.second - div * y.first.second;

        if(x.second == 0) return y;

        div = y.second / x.second;
        y.second = y.second - div * x.second;
        y.first.first = y.first.first - div * x.first.first;
        y.first.second = y.first.second - div * x.first.second;
    }
}

//逆元
ll modinv(ll a, ll m = MOD){
    //前提：aとmが互いに素であること．
    pii ans;
    ans = extgcd(a, m);

    ll invNum = 0;
    invNum = ans.first.first;
    invNum %= m;
    //C++特有の剰余がマイナスになってしまう対策
    if(invNum < 0) invNum += m;

    return invNum;
}

//割り算MOD
ll warizan_mod(ll warareru, ll waru, ll m = MOD){
    //割られる数に逆元をかけるだけ
    warareru %= m;
    return warareru * modinv(waru, m) % m;
}

void combination(ll num, ll m = MOD){
    fact.assign(num + 1919, 0);
    finv.assign(num + 1919, 0);
    inv.assign(num  + 1919, 0);

    //初期化
    fact[0] = 1; inv[0] = 1;
    //テーブルに列挙
    for(ll i = 1; i < fact.size(); i++){
        fact[i] = fact[i - 1] * i % m;
        inv[i]  = modinv(fact[i]);
    }
}

//二項係数 n!/(k!*(n-k)!)
ll nCk(ll n, ll k, ll m = MOD){
    if(n < 0 || k < 0 || n < k) return 0;
    return fact[n] * (inv[k] * inv[n - k] % m) % m;
}


int main(){
 
    ll X, Y;
    cin >> X >> Y;
    
    //x方向の動き(1,2)をa y方向の動き(2,1)をbとする
    //するとXとYはa+2b=Xと2a+b=Yで表すことができる
    //aとbの合計がXとYにたどり着くまでの移動回数

    //1回毎に移動距離は3なのでX＋Yが3の倍数ではなかったら求めることはできない
    if((X + Y) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }

    //ここで割り切れるならX/3とY/3がx方向とy方向へのそれぞれの移動回数
    ll A = X - (X + Y) / 3;
    ll B = Y - (X + Y) / 3;

    if(A < 0 || B < 0){
        cout << 0 << endl;
        return 0;        
    }
    if(A < B) swap(A, B);
    combination(A + B);
    //cout << nCk(X, Y) << endl; 
    cout << nCk(A + B, A) << endl; 



}