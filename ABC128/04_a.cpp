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

using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;


    vector<ll > V(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> V[i];
    }

    ll ans = 0;
    for(ll l = 0; l <= min(K, N); l++){
        for(ll r = 0; l + r <= min(K, N); r++){
            //ぷらいおりてぃきゅー
            //昇順
            priority_queue<ll, vector<ll >, greater<ll > > que;
            ll sum = 0;
            for (ll i = 0; i < l; i++){
                que.push(V[i]);
                sum += V[i];
            }
            for(ll i = 0; i < r; i++){
                que.push(V[N-i-1]);
                sum += V[N-i-1];
            }
            //マイナスの価値の宝石を消す
            for(ll i = 0; i < min(K - l -r, (ll)que.size()); i++){
                if(que.top() < 0){
                    sum -= que.top();
                    que.pop();
                }
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;

} 