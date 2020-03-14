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

    ll H, W;
    cin >> H >> W;
        
    if(H == 1 || W == 1){
        cout << 1 << endl;
        return 0;
    }

    if(((H * W) % 2) == 1){
        cout << (H  *  W) / 2 + 1 << endl;
    }else{
        cout << (H  *  W) / 2 << endl;
    }
 

}