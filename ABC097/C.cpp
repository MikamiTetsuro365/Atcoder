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
    
    cin >> N;

    //エラトステネスの篩
    ll pSize = 55555;
    vector<bool > IsPrime(pSize + 1, true);
    
    //初期化
    IsPrime[0] = false;
    IsPrime[1] = false;

    //2は素数
    //合成数gはSprt(n)以下の約数を持つのでループはSprt(n)までで良い
    for(ll i = 2; i <= sqrt(pSize); i++){
        if(IsPrime[i] == true){
            //自分自身は素数，それ以上の倍数は素数ではない
            for(ll j = 2; i * j <= pSize; j++){
                IsPrime[i * j] = false;
            }
        }
    }

    vector<ll > ans;
    ll cnt = 0;
    for(ll i = 2; i <= pSize; i++){
        if(IsPrime[i] == true){
            if(i % 5 == 1){
                if(cnt < N - 1){
                    cout << i << " ";
                    cnt++;
                }else{
                    cout << i << endl;
                    break;
                }
                ans.push_back(i);
            }
        }
    }



    //確認
    /*
    for(ll i = 0; i < pSize; i++){
        if(IsPrime[i] == true){
            cout << i << endl;
        }
    } 
    */
} 