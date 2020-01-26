#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {

    string S;
    cin >> S;
    
    for(ll i = 0; i < S.length(); i++){
        if(S[i] == 'O'){
            cout << 'A';
        }else if(S[i] == 'A'){
            cout << 'O';
        }else{
            cout << S[i];
        }
    }
    cout << endl;
    
}