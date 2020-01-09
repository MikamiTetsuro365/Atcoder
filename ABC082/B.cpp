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

    string s, t;
    cin >> s >> t;

    vector<char > ss;
    vector<char > tt;

    for(ll i = 0; i < s.length(); i++){
        ss.push_back(s[i]);
    }
    sort(ss.begin(), ss.end());

    for(ll i = 0; i < t.length(); i++){
        tt.push_back(t[i]);
    }
    sort(tt.rbegin(), tt.rend());

    string tmp1;
    string tmp2;

    for(ll i = 0; i < s.length(); i++){
        tmp1 += ss[i];
    }

    for(ll i = 0; i < t.length(); i++){
        tmp2 += tt[i];
    }  

    //cout << tmp1 << " " << tmp2 << endl;

    if(tmp1 < tmp2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}