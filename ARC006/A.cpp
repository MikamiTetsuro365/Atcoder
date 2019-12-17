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

    ll N, L; cin >> N >> L;
    vector<ll > amida(N, 0);
    for(ll i = 1; i <= N; i++){
        amida[i-1] = i;
    }

    for(ll i = 0; i <= L; i++){
        string s;
        getline(cin, s);
        ll cn = 1;
        for(ll j = 1; j < s.length(); j+=2){
            if(s[j] == '-'){
                swap(amida[cn], amida[cn-1]);
            }
            cn++;
        }
    }

    string s;
    getline(cin, s);
    ll cn = 0;
    for(ll j = 0; j < s.length(); j+=2){
        if(s[j] == 'o'){
            break;
        }
        cn++;
    }

    cout << amida[cn] << endl;


}