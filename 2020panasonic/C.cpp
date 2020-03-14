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

    long double a, b, c;
    cin >> a >> b >> c;

    long double eps = 1.0E-14;

    if((sqrt(a) + sqrt(b)) + eps < sqrt(c)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

}