#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    string O, E;
    cin >> O >> E;

    vector<char > ans(O.length()+E.length());

    ll cn = 0;
    for(ll i = 0; i < O.length(); i++){
        ans[cn] = O[i];
        cn += 2;
    }

    cn = 1;
    for(ll i = 0; i < E.length(); i++){
        ans[cn] = E[i];
        cn += 2;
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
    cout << endl;
 
}