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

    vector<vector<int>> vec(N, vector<int>(1000, 0));

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N - 1; j++){
            cin >> vec[i][j];
        }
    }

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N - 1; j++){
            cin >> vec[i][j];
        }
    }


}