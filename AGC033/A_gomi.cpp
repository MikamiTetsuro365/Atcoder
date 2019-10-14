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
//解けるが...?TLE
int main(){

    ll H, W;
    cin >> H >> W;
    
    map<pair<ll, ll >, ll> mp;
    queue<pair<ll, ll > > que;
    queue<pair<ll, ll > > que2;

    ll ans = 0;
    for(ll i = 0; i < H; i++){
        string s; cin >> s;
        for(ll j = 0; j < W; j++){
            if(s[j] == '#'){
                que.push(make_pair(i, j));
                mp[make_pair(i, j)] = 1;
            }    
        }
    }

    bool swi = false;
    while(mp.size() < H * W){
        if(swi == false){
            while(!que.empty()){
                ll x = que.front().first;
                ll y = que.front().second;
                que.pop();
                for(ll d = 0; d < 4; d++){

                    if(x+dx[d] < W && x+dx[d] >= 0 && y+dy[d] < H && y+dy[d] >= 0){
                        que2.push(make_pair(x+dx[d], y+dy[d]));
                        mp[make_pair(x+dx[d], y+dy[d])] = 1;
                    }

                }
            }
            swi = true;
        }else if(swi == true){
            while(!que2.empty()){
                ll x = que2.front().first;
                ll y = que2.front().second;
                que2.pop();
                for(ll d = 0; d < 4; d++){

                    if(x+dx[d] < W && x+dx[d] >= 0 && y+dy[d] < H && y+dy[d] >= 0){
                        que.push(make_pair(x+dx[d], y+dy[d]));
                        mp[make_pair(x+dx[d], y+dy[d])] = 1;
                    }
                }
            }
            swi = false;
        }
        ans++;
    }

    cout << ans << endl;

}