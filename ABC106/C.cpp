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

    string S;
    ll K;
    cin >> S >> K;

    for(ll i = 0; i < K; i++){
        //cout << S[i] << endl;
        if(S[i] != '1'){
            cout << S[i] << endl;
            return 0;
        }
    }
    cout << "1" << endl;
    return 0;     
} 