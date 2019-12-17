#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
//もっと簡単にかけるらしい
int main() {

    ll N; cin >> N;
    
    //初期値
    ll T = 1;
    ll A = 1;
    
    //TとAが与えられると投票数はTx, Axになるはず
    //ここで最小のxを求める
    //条件としては注目する得票数は前の得票数以上であること
    
    ll x = 1;
    ll t, a; 
    for(ll i = 0; i < N; i++){
        cin >> t >> a;
        if(T == t && A == a) continue;
        //longlongの範囲なのでdoubleで切り上げ処理ceilは誤差を生むことがあるので自分で実装する
        //x = max(ceil(T * x / t), ceil(A * x / a));
        ll x1 = T * x / t;
        ll x2 = A * x / a;
        //切り上げ処理　余りがあればプラス1
        if(T * x % t != 0){
            x1++;
        }
        if(A * x % a != 0){
            x2++;
        }

        x = max(x1, x2);
        
        T = t;
        A = a;
    }
    ll ans = T * x + A * x;
    cout << ans << endl;
}
