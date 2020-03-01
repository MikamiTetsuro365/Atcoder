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

    string S;
    cin >> S;

    map<char, ll> mp;

    for(ll i = 0; i < S.length(); i++){
        mp[S[i]]++;
    }

    cout << mp['a']+mp['i']+mp['u']+mp['e']+mp['o'] << endl;

}