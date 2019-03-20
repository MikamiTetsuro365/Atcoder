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

ll total = 1;
vector<ll > length;
vector<ll > P_length;

//ぜんぜんわからん
ll sum(ll N, ll X){
    if(N == 0){
        if(X <= 0){
            return 0;
        }else{
            return 1;
        }
    }else if(X <= 1 + length[N-1]){
        return sum(N-1, X-1);
    }else{
        return P_length[N-1] + 1 + sum(N-1, X-2-length[N-1]);
    }
}

int main(){

    ll N, X;
    cin >> N >> X;

    //length 
    length = vector<ll > (N + 1, 1);
    P_length = vector<ll >(N + 1, 1);
    for(ll i = 1; i <= N; i++){
        length[i] = 2 * length[i-1] + 3;
        P_length[i] = 2 * P_length[i-1] + 1;
    }
    /*
    cout << length[N] << endl;
    //バンズのとこだけ
    if(N >= X){
        cout << "0" << endl;
        return 0;
    }
    //パティをすべて食べれるとき
    if(N >= length[N] - X ){
        cout << P_length[N] << endl;
        return 0;
    }
    //パティを半分くらいまで食べれるとき
    if(length[N - 1] == X){
        cout << P_length[N-1] << endl;
        return 0; 
    }
    //半分より少し多めに食べれるとき
    if(length[N - 1] + 1 <= X || length[N - 1] + (N - 1) >= X){
        cout << P_length[N-1] + 1 << endl;
        return 0; 
    }
    */
    //それ以外 レベルLバーガーの中にL-1バーガー更にL-1バーガーの中に．．．というとき
    total = sum(N,X);
    cout << total << endl;

}