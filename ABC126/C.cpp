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


int main(){

    double N , K;
    cin >> N >> K;

    double ans = 0;
    for(ll i = 1; i <= N; i++){
        ll count = 0;
        for(ll j = i; j < K; j *= 2){
            count++;
        }
        //cout << pow(1/2, count) << endl;
        ans += pow(0.5, count);

    }

    ans *= 1 / N;
    printf("%.12f\n", ans);

} 