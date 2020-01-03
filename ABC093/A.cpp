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
    vector<char > S(s.length());
    S[0] = s[0];
    S[1] = s[1];
    S[2] = s[2];

    sort(S.begin(), S.end());

    if(S[0] == 'a' && S[1] == 'b' && S[2] == 'c'){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}