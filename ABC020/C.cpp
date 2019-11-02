#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;
typedef pair<ll, pair<ll, ll > > iip;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

ll H, W, T;
ll s_x, s_y;
ll g_x, g_y;

ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0,  0, 1,-1};

vector<vector<ll > > check(vector<vector<ll > > G, ll mid){
    //準備
    vector<vector<ll > > dist(H, vector<ll >(W, 1145141919));
    vector<vector<bool > > used(H, vector<bool >(W, false));
    priority_queue<iip , vector<iip>, greater<iip > > que;
    //初期化
    que.push(make_pair(0, make_pair(s_y, s_x)));

    while(!que.empty()){
        ll d = 0;
        d = que.top().first;
        //現在地
        ll y = que.top().second.first;
        ll x = que.top().second.second;
        que.pop();
        //探査済みなら飛ばす
        if(used[y][x] == true) continue;
        //探査済にする
        used[y][x] = true;
        //最小距離を更新
        dist[y][x] = d;

        for(ll i = 0; i < 4; i++){
            //次の地点
            ll ny = y + dy[i];
            ll nx = x + dx[i];
            ll cost = 0;
            if(ny >= 0 && ny < H && nx >= 0 && nx < W){
                if(G[ny][nx] == -1){
                    cost = mid;
                }else{
                    cost = 1;
                }
                cost += d;
                if(dist[ny][nx] <= cost) continue;
                que.push(make_pair(cost, make_pair(ny, nx)));
                //仮dist
                dist[ny][nx] = cost;
                
            }
        }
    }
    return dist;
}

int main(){

    cin >> H >> W >> T;

    vector<vector<ll > > G(H, vector<ll >(W, 1));
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            char s; cin >> s;
            if(s == 'S'){
                G[i][j] = 0;
                s_x = j;
                s_y = i;
            }else if(s == 'G'){
                G[i][j] = 0;
                g_x = j;
                g_y = i;
            }else if(s == '#'){
                G[i][j] = -1;
            }
        }        
    }


    //vector<vector<ll > > dist = check(G, 1);
    //cout << dist[g_y][g_x] << endl;

    ll left = 1; ll right = 1145141919;

    //最大値を探す
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        vector<vector<ll > > dist = check(G, mid);
        if(dist[g_y][g_x] <= T){
            left = mid;
        }else{
            right = mid;
        }

    }

    cout << left << endl;

}