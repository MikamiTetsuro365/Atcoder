#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    string s; cin >> s;

    ll ans1 = 0;
    ll ans2 = 0;
    for(ll i = 0; i < s.length() - 2; i++){
        if(s.substr(i, 3) == "JOI"){
            //cout << s.substr(i, 3) << endl;
            ans1++;
        }else if(s.substr(i, 3) == "IOI"){
            ans2++;
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
}