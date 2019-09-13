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

    ll N = 0;
    cin >> N;


    vector <ll > T(N, 0);
    vector <ll > A(N, 0);

    ll max_h_T = 0;
    ll max_h_A = 0;

    for(ll i = 0; i < N; i++){
        cin >> T[i];
        max_h_T = max(max_h_T, T[i]);
    }

    for(ll i = 0; i < N; i++){
        cin >> A[i];
        max_h_A = max(max_h_A, A[i]);
    }

    //そもそも最大値が違うとムリダナ
    if(max_h_T != max_h_A){
        cout << "0" << endl;
        return 0;
    }

    bool flg = false;

    ll ans = 1;
    ll max_continue = 0;
    for(ll i = 0; i < N; i++){

        if(T[i] < A[i]){
            if(T[i] == T[i + 1]){
                //cout << T[i] << endl;
                //われぇ！いつA[i]になったんや？ 今(A[i])より小さい高さはA[i+1]には来ないんやで
                if(A[i] > A[i + 1] ){
                    ans = 0;
                }else{
                    ans = ans * T[i] % 1000000007;
                }
                
            }
        }else if(T[i] > A[i]){
            if(A[i] == A[i + 1]){
                //cout << A[i] << endl;
                //われぇ！いつT[i]になったんや？ 今(T[i])より小さい高さはT[i-1]には来ないんやで
                if(T[i - 1] < T[i]){
                    ans = 0;
                }else{
                    ans = ans * A[i] % 1000000007;
                }
                
            }
        }

        if(T[i] == max_h_T && A[i] == max_h_A){
            max_continue++;
            flg = true;
        }

    }

    //互いに同じ位置で高い山に巡り合わなかったとき
    if(flg == false){
        cout << "0" << endl;
        return 0;
    }

    //最大値だけは後回しで求めた・・・クソ無駄（感想
    for(ll i = 0; i < max((ll)0, max_continue - 2); i++){
        //cout << ans << endl;
        ans = ans * max_h_T % 1000000007;
    }

    cout << ans << endl;

} 