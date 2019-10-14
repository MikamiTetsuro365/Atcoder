#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = { 0, 0,-1, 1};

int main(){

    ll H, W;
    cin >> H >> W;
    
    //map<pair<ll, ll >, ll> mp;
    queue<pair<ll, ll > > que;
    //距離格納
    vector<vector<ll > > ans(H, vector<ll >(W, -114514));

    for(ll y = 0; y < H; y++){
        string s; cin >> s;
        for(ll x = 0; x < W; x++){
            if(s[x] == '#'){
                que.push(make_pair(y, x));
                ans[y][x] = 0;
                //mp[make_pair(i, j)] = 1;
            }    
        }
    }

    //黒点から広げて距離を出していく(これはもうBFS)
    while(!que.empty()){
        ll x = que.front().second;
        ll y = que.front().first;
        que.pop();
        for(ll d = 0; d < 4; d++){
            if(x+dx[d] < W && x+dx[d] >= 0 && y+dy[d] < H && y+dy[d] >= 0){
                //何も更新されていないマスだったら
                if(ans[y+dy[d]][x+dx[d]] == -114514){
                    que.push(make_pair(y+dy[d], x+dx[d]));
                    ans[y+dy[d]][x+dx[d]] = ans[y][x] + 1;
                }
            }

        }
    }

    ll mx_dist = 0;
    for(ll y = 0; y < H; y++){
        for(ll x = 0; x < W; x++){
            //cout << ans[y][x] << endl;
            mx_dist = max(mx_dist, ans[y][x]);
        }
    }    

    cout << mx_dist << endl;

}