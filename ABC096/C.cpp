#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

ll dx[2] = {-1, 1};
ll dy[2] = {-1, 1};

int main(){

    ll H, W;
    cin >> H >> W;

    vector<vector<char > > masu(H, vector<char >(W, 0));

    for(ll row = 0; row < H; row++){
        for(ll col = 0; col < W; col++){
            cin >> masu[row][col];
        }
    }

    for(ll row = 0; row < H; row++){
        for(ll col = 0; col < W; col++){
            if(masu[row][col] != '#') continue;
            bool f = false;
            for(ll i = 0; i < 2; i++){
                if(col + dx[i] < W && col + dx[i] >= 0 ){
                    if(masu[row][col + dx[i]] == '#'){
                        f = true;
                    }
                }
            }

            bool f2 = false;
            for(ll i = 0; i < 2; i++){
                if(row + dy[i] < H && row + dy[i] >= 0 ){
                    if(masu[row + dy[i]][col] == '#'){
                        f2 = true;
                    }
                }
            }

            if(f == false && f2 == false){
                cout << "No" << endl;
                return 0;
            }

        }
    }

    cout << "Yes" << endl;


}