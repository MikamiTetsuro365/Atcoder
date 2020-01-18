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

    ll a, b;
    cin >> a >> b;

    if(a + b == 15){
        cout << "+" << endl;
    }else if(a * b == 15){
        cout << "*" << endl;
    }else{
        cout << "x" << endl;
    } 

}