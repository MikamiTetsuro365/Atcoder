#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//階乗
vector<ll>fact;
//逆元
vector<ll>inv;
//逆元階乗
vector<ll>finv;

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

ll warizan_mod(ll warareru, ll waru, ll m = MOD){
    //割られる数に逆元をかけるだけ
    warareru %= m;
    return warareru * modinv(waru, m) % m;
}

//階乗と逆元を列挙
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

//階乗 n!
ll factrial(ll n){
    return fact[n];
}

//順列 nPk n!/(n-k)!
ll nPk(ll n, ll k, ll m = MOD){
    if(n < 0 || k < 0 || n < k) return 0;
    return fact[n] * inv[n - k] % m;
}

//二項係数 nCk n!/(k!*(n-k)!)
ll nCk(ll n, ll k, ll m = MOD){
    if(n < 0 || k < 0 || n < k) return 0;
    return fact[n] * (inv[k] * inv[n - k] % m) % m;
}

//重複組み合わせ n+k-1Ck
ll nHk(ll n, ll k, ll m = MOD){
    return nCk(n+k-1, k);
}

int main() {

    ll N, M;
    cin >> N >> M;

    //準備
    combination(100000);

    if(N < 3){
        cout << 0 << endl;
        return 0;
    }

    //先頭がA，末尾がBのような組み合わせ
    ll ans = nCk(N+M-2, N-1);
    cout << ans << endl;

    //AAAを含まない組み合わせ
    //AAやAで成り立つような文字列
    //AAは最大N/2+1個作れる
    for(ll i = 0; i < N / 2 + 1; i++){
        //AAをi個作った時，AAと残りのAの並べ方
        ll aa = i;
        ll a = N - aa * 2;
        ll cmb = nCk(a + aa, aa);
        //Bが置ける場所
        ll b_space = a + aa;
        //使えるB
        ll b_rest = M - (a + aa);

        if(b_rest < 0) continue;

        //AとBの置き方は独立して考えられる
        //Bをどう配置するか->重複組み合わせ；
        cmb *=  nHk(b_space, b_rest);
        cmb %= MOD;
        cout << cmb << endl;
        ans -= cmb;
    }


    cout << ans << endl;

}