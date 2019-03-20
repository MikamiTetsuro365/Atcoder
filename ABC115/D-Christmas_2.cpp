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
//工事中
ll total = 1;
vector<ll > length;
vector<ll > P_length;

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
    total = sum(N,X);
    cout << total << endl;

}