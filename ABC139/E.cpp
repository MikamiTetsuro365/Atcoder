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
//O(N^3)くらいで最悪のパターンでTLEじゃ...
int main(){

    ll N;
    cin >> N;

    vector<vector<ll > > vec(N, vector<ll >(N - 1, 0));

    //どこまで確認したか
    vector<ll > p(N, 0);

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N - 1; j++){
            ll in;
            cin >> in;
            vec[i][j] = in - 1;
        }
    }

    ll ans = 0;
    
    //最大回数試合をさせて残っている選手がいれば-1する方針
    ll day = 0;
    bool fin_flg = false;
    while(day <= N * (N - 1) / 2){
        fin_flg = false;
        for(ll i = 0; i < N; i++){
            //cout << i << endl;
            //cout << "1" << endl;
            if(p[i] >= N - 1) continue;
            //cout << "1" << endl;
            if(vec[i][p[i]] == -1){
                //cout << vec[i][p[i]] << endl;
                p[i]++;
                continue;
            } 
            //cout << "1" << endl;
            //cout << i + 1 << " " << p[i] << endl;
            //cout <<  vec[vec[i][p[i]]][p[vec[i][p[i]]]] << endl;

            if(i == vec[vec[i][p[i]]][p[vec[i][p[i]]]] && i < vec[i][p[i]]){
                //cout << i + 1 << " " << vec[i][p[i]] + 1 << " " << p[i] << endl;
                //cout << "yes" << endl;
                vec[vec[i][p[i]]][p[vec[i][p[i]]]] = -1;
                vec[i][p[i]] = -1;
                //cout << vec[vec[i][p[i]]][p[vec[i][p[i]]]] << endl;
                p[i]++;
                //p[vec[i][p[i]]]++;
                //cout << i + 1 << " " << p[i] << endl;
                fin_flg = true;
            }

            ans++;

        }
        if(fin_flg == false){
            break;
        }
        //確認
        /*
        for(ll j = 0; j < N; j++){
            for(ll k = 0; k < N - 1; k++){
                cout << vec[j][k] << " ";
            }
            cout << p[j] <<  endl;
        }
        */

        day++;
        //cout << "day : " << day << endl;
    }

    //全試合終わっているか?

    for(ll k = 0; k < N; k++){
       if(p[k] != N - 1){
           cout << "-1" << endl;
           return 0;
       }
    }
    cout << day << endl;

}