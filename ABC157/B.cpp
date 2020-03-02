#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll dp[3][3];
ll ans[3][3];
int main(){

    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 3; j++){
            cin >> dp[i][j];
        }        
    }

    ll N;
    cin >> N;

    for(ll k = 0; k < N; k++){
        ll t; cin >> t;
        for(ll i = 0; i < 3; i++){
            for(ll j = 0; j < 3; j++){
                if(t ==dp[i][j]) ans[i][j] = 1;
               // cout << ans[i][j];
            }       
           // cout << endl; 
        }
    }

    if(ans[0][0] == 1 && ans[0][1] == 1 && 1 == ans[0][2]){
            cout << "Yes" << endl;
            return 0;        
    }

    if(ans[1][0] == 1 && ans[1][1] == 1 && 1 == ans[1][2]){
            cout << "Yes" << endl;
            return 0;        
    }

    if(ans[2][0] == 1 && ans[2][1] == 1 && 1 == ans[2][2]){
            cout << "Yes" << endl;
            return 0;        
    }

    if(ans[0][0] == 1 && ans[1][0] == 1 && 1 == ans[2][0]){
            cout << "Yes" << endl;
            return 0;        
    }

    if(ans[0][1] == 1 && ans[1][1] == 1 && 1 == ans[2][1]){
            cout << "Yes" << endl;
            return 0;        
    }

    if(ans[0][2] == 1 && ans[1][2] == 1 && 1 == ans[2][2]){
            cout << "Yes" << endl;
            return 0;        
    }

    if(ans[0][0] == 1 && ans[1][1] == 1 && 1 == ans[2][2]){
            cout << "Yes" << endl;
            return 0;        
    }


    if(ans[0][2] == 1 && ans[1][1] == 1 && ans[2][0] == 1){
            cout << "Yes" << endl;
            return 0;        
    }

    cout << "No" << endl;


}