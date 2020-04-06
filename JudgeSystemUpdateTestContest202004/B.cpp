#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll N;
    cin >> N;

    priority_queue<ll ,vector<ll >, greater<ll > > r_que;
    priority_queue<ll ,vector<ll >, greater<ll > > b_que;

    for(ll i = 0; i < N; i++){
        ll x; char c;
        cin >> x >> c;
        if(c == 'B') b_que.push(x);
        else r_que.push(x);
    }

    while(!r_que.empty()){
        cout << r_que.top() << endl;
        r_que.pop();
    }


    while(!b_que.empty()){
        cout << b_que.top() << endl;
        b_que.pop();
    }

}