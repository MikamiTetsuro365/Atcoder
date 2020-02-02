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

    ll A, B;
    string S;
    cin >> A >> B >> S;

    if(S[A] != '-'){
        cout << "No" << endl;
        return 0;                
    }

    for(ll i = 0; i < A + B + 1; i++){
        if(i != A){
            if(!(S[i] >= '0' && S[i] <= '9')){
                cout << "No" << endl;
                return 0;     
            }
        }
    }

    cout << "Yes" << endl;
    return 0;

}