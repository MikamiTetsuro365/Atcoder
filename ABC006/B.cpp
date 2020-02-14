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

    ll N;
    cin >> N;

    if(N == 1 || N == 2){
        cout << 0 << endl;
        return 0;
    }

    if(N == 3){
        cout << 1 << endl;
        return 0;
    }
    
    vec.assign(N+19, 0);
    vec[1] = 0;
    vec[2] = 0;
    vec[3] = 1;

    ll sum = 1;

    for(ll i = 4; i <= N; i++){
        vec[i] = sum;
        sum -= vec[i-3];
        if(sum < 0) sum += 10007;
        sum += vec[i];
        sum %= 10007;
        //cout << sum << endl;
    }

    cout << vec[N] << endl;

}