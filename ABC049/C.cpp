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

    string d1 = "maerd";
    string d2 = "remaerd";
    string e1 = "esare";
    string e2 = "resare";

    reverse(s.begin(), s.end());

    //cout << s << endl;

    ll cn = 0;
    while(cn < s.length()){
        if(s.substr(cn, 5) == d1 || s.substr(cn, 5) == e1){
            cn += 5;
        }else if(s.substr(cn, 6) == e2){
            cn += 6;
        }else if(s.substr(cn, 7) == d2){
            cn += 7;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

}