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

    for(ll i = 0; i < s.length(); i++){
        if(s[i] == 'A'){
            cout << "X";
        }else if(s[i] == 'B'){
            cout << "Y";
        }else if(s[i] == 'C'){
            cout << "Z";
        }else{
            cout << char(s[i] - 3);
        }    
    }
}