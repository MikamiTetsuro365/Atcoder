#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//最小公倍数を素因数分解した形で持ちたい
//お互いを素因数分解して指数部が大きいやつを持っておく
//やるだけ
map<ll, ll> tPF;
void lcm(ll num){

    //素因数と指数部の並び
    map<ll, ll > PF;

    ll i = 2;

    while(num >= i * i){
        if(num % i == 0){
            PF[i]++;
            num /= i;
        }else{
            i++;
        }
    }
    //1は素因数分解できない
    if(num != 1){
        PF[num]++;
    }

    //指数部が大きい素因数だけ保持
    auto begin = PF.begin(), end = PF.end();
    for (auto iter = begin; iter != end; iter++) {
        auto it = tPF.find(iter->first);
        if(it != tPF.end()){
            tPF[iter->first] = max(it->second, iter->second);
        }else{
            tPF[iter->first] = iter->second;
        }
    }       
}

//ll pw[10001][10001];
ll fast_pow(ll a, ll n){
    if(a == 0) return 0;
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * fast_pow(a, n - 1) % MOD;
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return fast_pow(a * a % MOD, n / 2) % MOD;
    }
}

//逆元
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

int main() {

    ll N;
    cin >> N;

    //クソ準備
    /*
    for(ll i = 0; i <= 10000; i++){
        for(ll j = 0; j <= 10000; j++){
            pw[i][j] = fast_pow(i, j);
        }        
    }
    */

    map<ll, ll> input;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        input[t]++;
        lcm(t);
    }

    ll lcm = 1;
    auto begin = tPF.begin(), end = tPF.end();
    for (auto iter = begin; iter != end; iter++) {
        lcm *= fast_pow(iter->first, iter->second);
        lcm %= MOD;
    }    
    ll ans = 0;

    for(ll i = 0; i < N; i++){
        //答え算出
        ll t_ans = lcm * modinv(vec[i]) % MOD; 
        //cout << t_ans << endl;
        ans += t_ans;
        ans %= MOD;
    }

    cout << ans << endl;

}