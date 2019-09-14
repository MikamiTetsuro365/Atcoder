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
#include <set>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;
//途中です
int main(){

    ll N;
    cin >> N;

    vector<vector<ll > > vec(N, vector<ll >(N - 1, 0));

    //どこまで確認したか
    vector<ll > p(N, 0);
    queue<ll > que;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N - 1; j++){
            ll in;
            cin >> in;
            vec[i][j] = in - 1;   
        }
        que.push(i);
    }

    //最大試合数(可能性)
    ll ans = 0;

    while(que.size()){
        queue<ll > tmp_que;
        while(que.size()){

        }
    }




}