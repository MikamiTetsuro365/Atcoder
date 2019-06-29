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


    vector<ll > value;
    ll mx = 0;
    for(ll l = 0; l <= K; l++){
        if(l > N){
            break;
        }

        for(ll r = 0; r < K - l + 1; r++){
            priority_queue<ll, vector<ll >, greater<ll > > que;
            ll l_sum = 0;
            ll total = 0;
            ll r_sum = 0;
            ll re_K = K - l - r;
            if(r + l > N){
                break;
            }
            //cout << l << "," << r  << "," << re_K << endl;
            //キューにストック
            for(ll i = 0; i < l; i++){
                que.push(V[i]);
                l_sum += V[i];
            }
            //キューにストック(後ろからlを超えない範囲で)
            //ll j = N - 1;
            for(ll i = N - 1; i > N - r - 1; i--){
                que.push(V[i]);
                r_sum += V[i];
                //cout << V[i];

            }
            //cout << endl;
            //cout << endl;
            total = l_sum + r_sum;
            //cout << total << endl;
            //残りの手数で符の価値を持つ宝石だけ捨てる．価値を更新
            for(ll i = 0; i < que.size(); i++){
                if(re_K <= i) break;
                if(re_K <= 0) break;
                if(que.top() > 0){
                    //cout << que.top() << endl;
                    break;
                }
                if(que.top() < 0){

                    total += -1 * que.top();
                    que.pop();
                }
            } 
            //cout << total << endl;
            mx = max(total, mx);
            value.push_back(total);
        }
        
    }
    cout << mx << endl;
} 