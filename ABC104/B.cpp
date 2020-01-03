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
    string S;
    cin >> S;

    if(S[0] != 'A'){
        cout << "WA" << endl;
        return 0;
    }

    /*
    if(!(S[2] == 'C' && S[S.length() - 2] == 'C')){
        cout << "WA" << endl;
        return 0;
    }
    */
    ll cn = 0;
    for(ll i = 1; i < S.length(); i++){
        if((i < S.length()-1 && i > 1) && S[i] == 'C'){
            cn++;
            if(cn > 1){
                cout << "WA" << endl;
                return 0;              
            }
            continue;
        }
        if(S[i] <= 'Z' && S[i] >= 'A'){
            cout << "WA" << endl;
            return 0;            
        }
    }

    if(cn == 0){
        cout << "WA" << endl;
        return 0;
    }

    cout << "AC" << endl;

}