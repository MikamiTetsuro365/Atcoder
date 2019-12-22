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

    ll A, B, C;
    cin >> A >> B;

    vector<bool > ans(3, false);
    ans[A-1] = true;
    ans[B-1] = true;

    for(ll i = 0; i < 3; i++){
        if(ans[i] == false){
            cout << i + 1 << endl;
            return 0;
         }
    }


}