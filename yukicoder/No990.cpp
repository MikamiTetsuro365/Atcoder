#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll N, M, K;
vector<ll > A;
vector<ll > B;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main() {

    
    cin >> N >> M >> K;
    
    MOD = K;

    char op;
    cin >> op;
    
    ll sum = 0;
    if(op == '+'){
        map<ll, ll> mo;
        //mod + mod が 0になればKの倍数
        for(ll i = 0; i < M; i++){
            ll t; cin >> t;
            mo[t % K]++;
        }
        for(ll i = 0; i < N; i++){
            ll t; cin >> t;
            //A+BがKの倍数になるのはAとBをKで割ったときのあまりの我がKの倍数になるとき
            //あまりが０のときは０を探す
            auto it = mo.find((K - t % K) % K);
            if(it != mo.end()){
                sum += it->second;
            }
        }
    }else{
        //Kとの最大公約数同士がKの倍数であれば良い
        map<ll, ll> gcdB;
        for(ll i = 0; i < M; i++){
            ll t; cin >> t;
            gcdB[gcd(t, K)]++;
        }
        
        map<ll, ll> gcdA;
        for(ll i = 0; i < N; i++){
            ll t; cin >> t;
            gcdA[gcd(t, K)]++;
        }
        
        auto begin = gcdA.begin(), end = gcdA.end();
        for (auto itA = begin; itA != end; itA++) {
            ll gA = itA->first;
            ll numA = itA->second;
            auto begin = gcdB.begin(), end = gcdB.end();
            for (auto itB = begin; itB != end; itB++) {
                ll gB = itB->first;
                ll numB = itB->second;
                if(gA * gB % K == 0){
                    sum += numA * numB;   
                }
            }
        }
        
    }

    cout << sum << endl;

}