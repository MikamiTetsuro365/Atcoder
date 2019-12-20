#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll A, K; 
    cin >> A >> K;

    ll nicho = 2000000000000LL;
    ll tmp = A;
    ll ans = 0;
    if(K == 0){
        cout << nicho - A << endl;
        //ans = nicho - A;
    }else{
        for(ll i = 0;;i++){
            if(nicho <= tmp){
                cout << i << endl;
                return 0;
            }
            tmp += 1 + (K * tmp);
        }
        //ここわかりずらい
        /*
        while(nicho > tmp){
            tmp += 1 + (K * tmp);
            ans++;
        }
        */
    }

    //cout << ans << endl;

}