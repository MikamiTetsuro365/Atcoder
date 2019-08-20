#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <queue>
#include <functional>
#include <numeric>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ll ans = 0;
    ll N, M;
    cin >> N >> M;

    vector<ll > A(N, 0);

    vector<pair <ll, ll> > act;
    map<ll, ll> B;
    vector<ll > C;
    
    priority_queue<ll, vector<ll>, greater<ll > > que;

    for(ll i = 0; i < N; i++){
        cin >> A[i];
        que.push(A[i]);
        ans += A[i];
    }


    for(ll i = 0; i < M; i++){
        ll b, c;
        cin >> b >> c;
        /* 
        if(B.count(c) == 0){
            C.push_back(c);
        }
        B[c] += b;
        */
        act.push_back(make_pair(c, b));
    }
    //cout << B.size() << " " << C.size() << endl;
    //大きいものから優先して使っていく
    sort(act.rbegin(), act.rend());
    //sort(C.rbegin(), C.rend());

    for(ll i = 0; i < M; i++){
        ll count = 0;
        //cout << C[i] << endl;
        if(que.top() >= act[i].first){
            break;
        }
        for(ll j = 0; j < act[i].second; j++){
            
            if(que.top() >= act[i].first){
                break;
            }
            //cout << que.top() << endl;
            ans -= que.top();
            count++;
            que.pop();

        }
        for(ll j = 0; j < count; j++){
            ans += act[i].first;
            que.push(act[i].first);
        }         
    }

    cout << ans << endl;

}