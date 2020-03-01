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

    if(a <= 0 && b >= 0 ){
        cout << "Zero" << endl;
        return 0;
    }
    
    if(a >= 1 && b >= 1){
        cout << "Positive" << endl;
        return 0;
    }

    if(a < 0 && b < 0){
        if((b-a+1)%2==0) cout << "Positive" << endl;
        else cout << "Negative" << endl;
        return 0;
    }

    cout << "Positive" << endl;

}