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

using namespace std;
typedef long long ll;
ll N;

int main(){
    ll N, M;
    cin >> N >> M;

    ll K;
    vector<vector <ll > > balb;
    for(ll i = 0; i < M; i++){
        cin >> K;
        vector<ll > s(K);
        for(ll j = 0; j < K; j++){
            cin >> s[j];
        }
        balb.push_back(s);
        /*
        for(ll j = 0; j < balb[i].size(); j++){
            cout << balb[i][j] << ",";
        }
        cout << endl;
        */
    }

    vector<ll > P(M, 0);
    for(ll i = 0; i < M; i++){
        cin >> P[i];
    }

    //bit全探査
    ll sum = 0;
    for(ll bit = 0; bit < (1<<N); ++bit){
        //電球ごとに点灯するかチェック
        bool check = true;
        for(ll i = 0; i < M; i++){
            ll count = 0;
            for(ll j = 0; j < balb[i].size(); j++){
                //どのスイッチがONになっていて何個ONになっているか確認
                //cout <<balb[i][j] << endl;
                //つじつまをあわせるために-1する
                if(bit & (1<<balb[i][j]-1)){
                    count++;
                   
                }
            }
            //P次第で，偶数または奇数の場合光るかどうかを判断する
            if(count % 2 != P[i]){
                check = false;
            }

        }
        if(check == true){
            sum++;
        }
    }

    cout << sum << endl;

} 