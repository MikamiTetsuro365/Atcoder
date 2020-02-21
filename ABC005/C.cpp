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

    ll T, N, M;
    cin >> T >> N;

    priority_queue<pi > que;
    queue<ll > B;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        que.push(make_pair(t, 0));
    }

    cin >> M;

    for(ll i = 0; i < M; i++){
        ll t; cin >> t;
        que.push(make_pair(t, 1));
    }

    while(!que.empty()){
        ll num = que.top().first;
        ll type = que.top().second;
        que.pop();
        if(type == 1){
            B.push(num);
            
        }else{
            if(!B.empty()){
                ll Btop = B.front();
                if(T >= (Btop - num)){
                    B.pop();
                }else{
                    cout << "no" << endl;
                    return 0;
                }
            }
        }
    }

    if(B.empty()){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    

}