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
ll N;

int main(){

    cin >> N;
    vector<ll > n(N,0);
    for(ll i = 2; i <= N; i++){
        n[i - 1] = i;
    }

    for(ll i = 2; i < sqrt(N); i++){
        for(ll j = 1; j < N; j++){
            if(j + 1 % i == 0){
                
            }
        }      
    }





} 