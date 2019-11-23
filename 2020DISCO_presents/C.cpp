#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll H, W, K; 
    cin >> H >> W >> K;
    
    vector<pii> in;

    vector<vector<ll > > grid(H, vector<ll >(W, -1));

    ll cn = 1;
    for(ll row = 0; row < H; row++){
        for(ll col = 0; col < W; col++){
            char t = 0; cin >> t;
            if(t == '#'){
                grid[row][col] = cn;
                in.push_back(make_pair(make_pair(row, col), cn));
                cn++;
            }
        }
    }

    bool f = 0;
    //cout << "ok" << endl;
    
    for(ll i = 0; i < in.size(); i++){
        //cout << in[i].first.first << " " << in[i].first.second << endl;
        //左
        ll row = in[i].first.first;
        ll col = in[i].first.second;
        for(ll left = col-1; left >= 0; left--){
            if(grid[row][left] != -1) break;

            grid[row][left] = in[i].second;
        }
        //右
        for(ll right = col+1; right < W; right++){
            if(grid[row][right] != -1) break;

            grid[row][right] = in[i].second;
        }
    }
    
    //確認

    for(ll col = 0; col < W; col++){
        for(ll row = 0; row < H; row++){
            if(grid[row][col] == -1) continue;
            //うえ
            for(ll up = row-1; up >= 0; up--){
                if(grid[up][col] != -1) break;
                grid[up][col] = grid[up+1][col];               
            }
            //した
            for(ll down = row+1; down < H; down++){
                if(grid[down][col] != -1) break;
                grid[down][col] = grid[down-1][col];    
            }
        }

    }

    for(ll row = 0; row < H; row++){
        for(ll col = 0; col < W; col++){
            cout << ( col ? " " : "" ) << grid[row][col];
        }
        cout << endl;
    }


}