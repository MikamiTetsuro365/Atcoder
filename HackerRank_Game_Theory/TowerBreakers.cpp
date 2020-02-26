#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//動きをコピーすると必勝になる
int main() {

    ll N;
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll A, B; cin >> A >> B;
        //1のときは必ず先行は詰む
        if(B == 1){
            cout << 2 << endl;
            continue;
        }
        if(A % 2 == 0){
            //偶数個タワーが有ると先行手を真似して動くと先行を詰ませられる
            cout << 2 << endl;
        }else{
            //奇数個タワーが有ると先行は後攻とみなせる
            cout << 1 << endl;
        }
    }

}