#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll N, M;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

int main() {

    cin >> N >> M;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        if(t % 2 == 1){
            t = 0;
        }
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end());
    
    vector<ll > B;

    for(ll i = 0; i < N; i++){
        B.push_back(vec[i] / 2);
    }

    ll LCM = 0;
    for(ll i = 0; i < N; i++){
        if(i == 0){
            LCM = B[i];
            continue;
        }
        LCM = lcm(LCM, B[i]);
        //Mを超えたらそもそも成り立たないしオーバーフローの可能性あるので
        //LCMは0で答えも0
        if(LCM > M){
            LCM = 0;
            break;
        }
        //cout << LCM << endl;
    }    

    //cout << LCM << endl;

    if(LCM == 0){
        cout << 0 << endl;
    }else{
        //奇数倍のみが答えを満たす
        ll kisu = M / LCM;
        //偶数倍の個数は奇数倍から引いておく
        ll gusu = M / (LCM * 2);

        if(kisu - gusu < 0){
            cout << 0 << endl;
        }else{
            cout << kisu - gusu << endl;
        }
        
        
    }
}