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

    string s; cin >> s;
    ll k = 0;
    ll o = 0;
    for(ll i = 0; i < s.length(); i++){
        if(s[i] == 'A'){
            k = i;
            break;
        }
    }

    for(ll i = s.length()-1; i >= 0; i--){
        if(s[i] == 'Z'){
            o = i;
            break;
        }
    }

    cout << o - k + 1 << endl;

}
