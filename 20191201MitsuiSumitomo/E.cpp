#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

class Combination{
    private:
    vector<ll>fact, inv;
    ll mod;

    public:
    ll modpow(ll x, ll n){
        ll res = 1;
        while(n > 0){
            if(n & 1)res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
    ll modinv(ll x){
        ll y = mod, u = 1, v = 0;
        while(y){
            ll t = x / y;
            x -= t * y; swap(x, y);
            u -= t * v; swap(u, v);
        }
        u %= mod;
        if(u < 0)u += mod;
        return u;
    }
    Combination(ll num, ll _mod = 1000000007){
        fact = vector<ll>(2 * num + 10);
        inv = vector<ll>(2 * num + 10);
        mod = _mod;
        fact[0] = 1;
        inv[0] = modinv(fact[0]);
        for(ll i = 1; i < fact.size(); i++){
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = modinv(fact[i]);
        }
    }
    ll factrial(ll n){
        return fact[n];
    }
    ll nPk(ll n, ll k){
        return fact[n] * inv[n - k] % mod;
    }
    ll nCk(ll n, ll k){
        return nPk(n, k) * inv[k] % mod;
    }
    ll nHk(ll n, ll k){
        return nCk(n+k-1, k);
    }
};

int main(){

    Combination cmb(100000);

    ll N = 0;
    cin >> N;
    
    vector<ll > memo(100100, 0);
 
    ll tmp = N-1;
    ll ans = 3;
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        ll tmp = 0;
        ll t_ans = ans;
        if(i == 0) continue;
        if(i - t == 0){
            continue;
        }
        
        ans %= MOD;

        tmp = cmb.nCk(i-1, t) % MOD;

        tmp =(tmp * cmb.modpow(2, (i-1)-t)) % MOD;

        tmp -= memo[t];

        ans *= tmp;

        ans %= MOD;

        memo[t] = ans;
        

    }

    cout << ans << endl;

    





}