#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    string S;
    cin >> S;

    string s = S.substr(0, (S.length()-1)/2);
    string ss = S.substr((S.length()+3)/2 - 1, S.length());

    //cout << s << " " << ss << endl;

    for(ll i = 0; i < (S.length()-1)/2; i++){
        if(S[i] != S[S.length() / 2 - 1 -i]){
            cout << "No" << endl;
            return 0;
        }
    }

    for(ll i = (S.length()+3)/2 - 1; i < S.length(); i++){
        if(S[i] != S[S.length() - 1 - i]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

}