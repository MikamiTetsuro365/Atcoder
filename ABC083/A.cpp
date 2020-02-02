#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    if(A+B > C+D){
        cout << "Left" << endl;
    }else if(A+B < C+D){
        cout << "Right" << endl;
    }else{
        cout << "Balanced" << endl;
    }

}