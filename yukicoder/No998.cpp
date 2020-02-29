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

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<ll > tmp;
    tmp.push_back(A);
    tmp.push_back(B);
    tmp.push_back(C);
    tmp.push_back(D);

    sort(tmp.begin(), tmp.end());

    for(ll i = 1; i < 4; i++){
        if(tmp[i-1] + 1 != tmp[i]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

}