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
#include <map>
 
using namespace std;
typedef long long int ll;
ll dp[100][2][2];
//０以上N以下の整数で、ある条件を満たすものの個数を求めよ

int main(){
    
    string s;
    cin >> s;

    vector<ll > S(s.length(), 0);
    //S[0] = 0; 
    ll t_s = stoi(s);
    ll ten = 10;
    for(ll i = s.length() - 1; i >= 0; i--){
        S[i] = t_s % ten;
        t_s = t_s / ten;
    }

    

    /*
    for(ll i = 0; i < s.length(); i++){
        cout << S[i] << endl;
    }
    */

    dp[0][0][0] = 1;

    for(ll i = 0; i < S.size(); i++){
        for(ll smaller = 0; smaller < 2; smaller++){
            for(ll j = 0; j < 2; j++){
                //桁によっては9まで回さない
                for(ll x = 0; x <= (smaller ? 9 : S[i]); x++){
                    dp[i+1][smaller || x < S[i]][j || x == 3] += dp[i][smaller][j];
                }
            }
        }
    }

    cout << dp[S.size()][0][1] + dp[S.size()][1][1] << endl;

 
} 