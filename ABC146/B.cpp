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
    ll N; 
    cin >> N >> s;

    for(ll i = 0; i < s.size(); i++){
        char ss = s[i] + N;
        if(ss > 90){
            ss %= 90;
            ss += 64;
        }
        cout << ss;
    }
    cout << endl;

}