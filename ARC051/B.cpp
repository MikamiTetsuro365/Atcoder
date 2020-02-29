#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int counter = 0;
int gcd(int a, int b) {
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
}

//フィボナッチ数列＝DP
int main() {

    ll N;
    cin >> N;

    vector<ll > dp;
    dp.push_back(0);
    dp.push_back(1);

    for(ll i = 1; i <= N + 1; i++){
        dp.push_back(dp[i] + dp[i-1]);
    }

    cout << dp[dp.size()-1] << " " << dp[dp.size()-2] << endl;

    //gcd(dp[dp.size()-1], dp[dp.size()-2]); 
    //cout << counter << endl;

}