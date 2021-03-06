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

    string S;
    cin >> S;

    vector<bool > N(26, false);

    for(ll i = 0; i < S.length(); i++){
        N[S[i]-'a'] = true;
    }

    for(ll i = 0; i < 26; i++){
        if(N[i] == false){
            cout << (char) (i + 'a') << endl;
            return 0;
        }
    }

    cout << "None" << endl;

}