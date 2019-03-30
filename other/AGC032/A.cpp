#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    
    ll N = 0;
    cin >> N;

    vector<ll > b(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> b[i];
    }

    //エラー判定
    /*
    for(ll i = 0; i < N; i++){
        if(b[i] > i+1){
            cout << "-1" << endl;
            return 0;
        }
    }
    */


    
}