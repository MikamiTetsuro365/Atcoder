#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;
vector<vector<pi > > G;
vector<bool > seen;

ll MOD = 1000000007;
ll INF = 11451419194545;
ll ans = 0;
ll N, M;

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



void dfs(ll idx, ll depth = 0, ll from = -1){

    if(depth == 0){
        ans = M;
    }

    //子の個数をカウント
    ll cn = 0;

    seen[idx] = true;

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //探査済み
        if(seen[to] == true){
            continue;
        }

        cn++;
        dfs(to ,depth + 1 ,idx);
    }
    
    if(cn > 0){
        if(depth == 0){
            ans *= nPk(M-1, cn);
        }else{
            ans *= nPk(M-2, cn);
        }
        ans %= MOD;
    }
}

int main(){
    
    cin >> N >> M;
    combination(M + 1919);

    //初期化
    G.assign(N, vector<pi >());
    seen.assign(N, false);

 
    //グラフ入力
    for(ll i = 0; i < N - 1; i++){
        ll u, v, w;
        w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    dfs(0);

    cout << ans << endl;

}