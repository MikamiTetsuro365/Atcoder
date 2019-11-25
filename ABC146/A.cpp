#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    string s; 
    cin >> s;

    map<string ,ll> mp;
    mp["SUN"] = 0;
    mp["MON"] = 1;
    mp["TUE"] = 2;
    mp["WED"] = 3;
    mp["THU"] = 4;
    mp["FRI"] = 5;
    mp["SAT"] = 6;

    ll ans = 7 - mp[s];

    cout << ans << endl;

}