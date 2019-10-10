#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

vector<bool > prime;

//primeListには素数は入ってません
void isPrime(ll N){
    prime[0] = false;
    prime[1] = false;

    //ルートN以下まで繰り返す
    for(ll i = 2; i < ceil(sqrt(N)) ; i++){
        //素数になりえないとき
        //cout << i << endl;
        if(prime[i] == false) continue;
        
        //Nまでのi(素数)の倍数を斑入り落とす
        for(ll j = i * i; j < N; j += i){
            prime[j] = false;
        }    
    }
}


//素因数分解した指数部の個数 x, y... の(x+1)(y+1)個
//ルジャンドルの定理
vector<pi> factorialPrimeFactor(ll num){

    //素因数と指数部の並び
    ll j = 0;
    vector<pi > PF;

    for(ll i = 2; i < prime.size(); i++){
        if(prime[i] == false) continue;
        if(i > num) break;
        
        PF.push_back(make_pair(i, 0));
        //cout << PF.size() << endl;
        ll cn = 1;
        while(pow(i, cn) < num ){
            //cout << "cn "<< PF[j].second << endl;
            PF[j].second += num / pow(i, cn);
            cn++;
        }
        j++;
    }

    return PF;
}

int main(){
    ll N = 0; cin >> N;

    prime.assign(N + 500, true);
    isPrime(N);

    vector<pi > t_ans = factorialPrimeFactor(N);
    
    ll ans = 1;

    for(ll i = 0; i < t_ans.size(); i++){
        cout << t_ans[i].second << endl;
        ans *= t_ans[i].second + 1;
        ans %= MOD;
    }

    cout << ans << endl;

}