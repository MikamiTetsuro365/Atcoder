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

    string N;
    ll K;
    cin >> N >> K;

    ll ans = 0;
    if(K == 1){
        ans = (N.length() - 1) * 9;
        ans += N[0] - '0';
    }else if(K == 2){
            for(ll i = 1; i <= N.length() - 1; i++){
                ans += i * 9;
            }

            ans *= N[0] - '0';

            for(ll i = 1; i < N.length(); i++){
                ans += N[i] - '0';
            }
    }else if(K == 3){
        return 1;
    }
    cout << ans << endl;
}