#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//式変形とGreedyな発想で片側を適当に決める
//doubleで判定するのはバグの元（自戒の念を込めて）
int main() {

    ll N = 0;
    cin >> N;

    for(ll h = 1; h <= 3500; h++){
        for(ll n = 1; n <= 3500; n++){
            ll bunshi = N * h * n;
            ll bunbo  = 4*h*n-N*n-N*h;

            //もし分母が負だと答えも負になるのでNG
            if(bunbo <= 0) continue;
            //もし分子/分母で余りが発生すると1/wにはなれないのでNG
            if(bunshi % bunbo > 0) continue;

            cout << h << " " << n << " " << bunshi / bunbo << endl;
            return 0; 
        }        
    }

}