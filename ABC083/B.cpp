#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, A, B;
    cin >> N >> A >> B;

    ll sum = 0;
    for(ll i = 1; i <= N; i++){
        string s = to_string(i);
        ll t_sum = 0;
        for(ll j = 0; j < s.length(); j++){
            t_sum += s[j] - '0';
        }
        if(t_sum >= A && t_sum <= B) sum += i;
    }

    cout << sum << endl;

}