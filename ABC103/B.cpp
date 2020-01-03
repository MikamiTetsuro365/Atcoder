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
    string S, T; cin >> S >> T;
    string tmp = "";

    for(ll i = 0; i < S.length(); i++){
        if(T == tmp + S.substr(0, S.length()-i)){
            cout << "Yes" << endl;
            return 0;
        }
        //cout << tmp + S.substr(0, S.length()-i) << endl;
        //cout << S.length()-1-i << endl;
        tmp = S[S.length()-1-i] + tmp;
        //cout << tmp << endl;
    }


    cout << "No" << endl;
}