#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N, x;
    cin >> N >> x;
    priority_queue<ll ,vector<ll >, greater<ll > > que;
    for(ll i = 0; i < N; i++){
        ll in = 0;
        cin >> in;
        que.push(in);  
    }

    ll ans = 0;
    while(!que.empty() || x > 0){
        if(x - que.top() >= 0){
            x -= que.top();
            que.pop();
            ans++;
        }else
        {
            break;
        }
    }

    if(x > 0 && ans != 0 && que.empty()) ans--;

    cout << ans << endl;

} 