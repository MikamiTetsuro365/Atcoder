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

    ll X, L, R;
    cin >> X >> L >> R;

    if(X <= L){
        cout << L << endl;
    }else if(R <= X){
        cout << R<< endl;
    }else if(L <= X && X <= R){
        cout << X << endl;
    }

}