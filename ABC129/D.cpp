#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll H, W; cin >> H >> W;

    vector<vector<ll > > grid(H+2, vector<ll >(W+2, 0));

    vector<vector<ll > > row_dist(H+2, vector<ll >(W+2, 0));
    vector<vector<ll > > col_dist(H+2, vector<ll >(W+2, 0));
    vector<vector<ll > > re_row_dist(H+2, vector<ll >(W+2, 0));
    vector<vector<ll > > re_col_dist(H+2, vector<ll >(W+2, 0));

    for(ll i = 1; i <= H; i++){
        string s; cin >> s;
        for(ll j = 1; j <= W; j++){
            if(s[j-1] == '.'){
                grid[i][j] = 1;
            }
        }        
    }
    
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(grid[i][j] == 1){
                row_dist[i][j] += row_dist[i][j-1] + 1;
                col_dist[i][j] += col_dist[i-1][j] + 1;
            }
        }        
    }

    //反対
    for(ll i = H; i > 0; i--){
        for(ll j = W; j > 0; j--){
            if(grid[i][j] == 1){
                re_row_dist[i][j] += re_row_dist[i][j+1] + 1;
                re_col_dist[i][j] += re_col_dist[i+1][j] + 1;
            }
        }        
    }

    ll ans = 0;

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(grid[i][j] == 0) continue;
            ll t_ans = 0;
            //cout << t_ans << endl;
            t_ans = row_dist[i][j] + col_dist[i][j] + re_row_dist[i][j] + re_col_dist[i][j] - 3;
            ans = max(ans, t_ans);
        }        
    }

    cout << ans << endl;

}