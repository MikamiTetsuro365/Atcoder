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

    vector<ll > A(3, 0);
    cin >> A[0] >> A[1] >> A[2];

    if(A[0] == A[1] && A[1] == A[2]){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    while(true){
        sort(A.begin(), A.end());
        if(A[0] == A[1] && A[1] == A[2]){
            cout << ans << endl;
            return 0;            
        }else if(A[0] == A[1] && A[1] != A[2]){
            A[0]++;
            A[1]++;
        }else{
            A[0]+=2;
        }
        ans++;
    }

}