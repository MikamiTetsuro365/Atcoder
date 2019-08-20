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

int main(){

    ll N;
    cin >> N;
    vector<ll > multiple(N, 0);
    ll two = 0;
    ll four = 0;
    ll other = 0;

    for(ll i = 0; i < N; i++){
        ll a;
        cin >> a;

        if(a % 2 == 0){
            //4の倍数は必ず４の倍数
            if((a / 2) % 2 == 0){
                four++;
            }else{
                //2も2つ以上集まれば4の倍数になるのでお役立ちしますよ
                two++;
                if(two % 2 == 0){
                    four++;
                }
            }
        }else{
            //
            other++;
        }

    }

    //Nが偶数こなら最低半分個４の倍数があれば良い
    if(N % 2 == 0){
        if(four >= N / 2){
            cout << "Yes" << endl;
            return 0;
        }
    }else{
        //Nが奇数こなら最低半分-1個4の倍数があると良い
        if(four >= N / 2 - 1){
            cout << "Yes" << endl;
            return 0;
        }        
    }

    cout << "No" << endl;
    return 0;

}