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


using namespace std;
typedef long long ll;
ll W;
ll N;
ll K;

int main(){

    cin >> W >> N >> K;

    //vector<ll > A(N,0);
    //vector<ll > B(N,0);
    vector<pair<ll,ll> > BA;
    //AとB逆転注意
    ll A, B;
    for(ll i = 0; i < N; i++){
        cin >> A >> B;
        BA.push_back(make_pair(B,A));
    }
    //重要度の大きい順
    sort(BA.begin(),BA.end());

    //初期化
    vector<vector<ll > > dp;
    dp = vector<vector<ll > >(K + 1, vector<ll>(W + 1, -1));
    dp[0][0] = 0;

    ll mx = 0;
    for(ll i = 1; i <= N; i++){
        //自分自身を更新してしまわないよう逆から
        for(ll h = K; h > 0; h--){
            for(ll j = 0; j <= W; j++){
                if(dp[h-1][j] > -1 && j + BA[i-1].second <= W){
                    ll c1 = dp[h][j + BA[i-1].second];
                    ll c2 =  dp[h-1][j] + BA[i-1].first;
                    dp[h][j + BA[i-1].second] = max(c1, c2);
                    mx = max(dp[h][j + BA[i-1].second], mx);
                }
            }
        }
    }

    cout << mx << endl;

} 