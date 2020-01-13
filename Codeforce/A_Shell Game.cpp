#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

using namespace std;

int main(){

    ll N; 
    cin >> N;
    vector<ll > cup(1919, 0);
    cup[N] = 1;

    ll a[3], b[3];
    cin >> a[0] >> b[0];
    cin >> a[1] >> b[1];
    cin >> a[2] >> b[2];
    swap(cup[a[0]], cup[b[0]]);  
    swap(cup[a[1]], cup[b[1]]);
    swap(cup[a[2]], cup[b[2]]);

    for(ll i = 1; i <= 3; i++){
        if(cup[i] == 1){
            cout << i << endl;
            return 0;
        }
    }

}