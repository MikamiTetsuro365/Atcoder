#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

using namespace std;

ll check(ll num){
    string s = to_string(num);
    ll sum = 0;
    for(ll i = 0; i < s.length(); i++){
        sum += s[i] - '0';
    }
    return sum;
}

int main(){

    ll N; cin >> N;
    
    ll ans = 1;

    vector<ll > conf(N+1, 0);
    
    for(ll i = 1; i < N; i++){
        ll num = check(i) + i;
        //cout << num << endl;
        if(num > N) continue;
        conf[num] += conf[i] + 1;
    }

    cout << conf[N] + 1 << endl;

}