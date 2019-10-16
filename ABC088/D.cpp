#include "bits/stdc++.h"
#include <unordered_set>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

ll dx[4] ={-1, 1, 0, 0};
ll dy[4] ={ 0, 0,-1, 1};

int main(){

    ll x, y; cin >> y >> x;

    vector<vector<ll > > vec(y, vector<ll >(x, 0));
    vector<vector<ll > > conf(y, vector<ll >(x, 0));
    vector<vector<pair<ll, ll > > > path(y);

    for(ll row = 0; row < y; row++){
        string S; cin >> S;
        for(ll col = 0; col < x; col++){
            if(S[col] == '#'){
                vec[row][col] = 1;
                conf[row][col] = 1;
            }
            //準備
            path[row].push_back(make_pair(0, 0));
        }       
    }

    //BFS
    //初期化
    conf[0][0] = 1;
    queue<pair<ll, ll > > que;
    que.push(make_pair(0, 0));

    bool f = false;
    ll i = 0;
    while(!que.empty()){
        //cout << i << endl;
        pair<ll, ll > from = que.front();
        que.pop();
        //現在地
        ll now_x = from.second;
        ll now_y = from.first;
        //探索済みフラグ建てる  
        conf[now_y][now_x] = 1;
        
        for(ll i = 0; i < 4; i++){
            //次の移動先
            ll next_x = now_x  + dx[i];
            ll next_y = now_y  + dy[i];
            if(next_x < x && next_x >= 0 && next_y < y && next_y >= 0){
                if(vec[next_y][next_x] == 1) continue;
                if(conf[next_y][next_x] == 1) continue;
                //cout << "next" << next_x << " " << next_y << endl;
                //cout << "now" << now_x << " " << now_y << endl;
                //キューに積む
                que.push(make_pair(next_y, next_x));
                
                //探索済みフラグ建てる
                conf[next_y][next_x] = 1;
                //経路記憶
                path[next_y][next_x].first = now_y;
                path[next_y][next_x].second = now_x;
                //ゴールにたどり着いていたらループを抜ける
                if(next_y == y-1 && next_x == x-1){
                    f = true;
                    break;
                }
            }   
        }
        if(f == true){
            break;
        }
        i++;
    }

    //ゴールにたどり着けていなかったら
    if(f == false){ 
        cout << -1 << endl;
        return 0;
    }

    //ゴール前までの最短経路色塗り
    ll X = x - 1; ll Y = y - 1;
    while(!(X == 0 && Y == 0)){
        //cout << X << " " << Y << endl;
        vec[Y][X] = 1;
        ll t_X = path[Y][X].second;
        ll t_Y = path[Y][X].first;
        X = t_X;
        Y = t_Y;
    }

    //点数計算
    ll ans = 0;
    for(ll row = 0; row < y; row++){
        for(ll col = 0; col < x; col++){
            if(vec[row][col] == 0){
                ans++;
            }
        }       
    }
    //始点分省く
    cout << ans - 1 << endl;

}