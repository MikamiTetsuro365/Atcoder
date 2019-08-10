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

    /* 
    cin >> N;
    vector<ll > p(N, 0);

    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    */
    ll cn = 0;
    for(int i = 1; i <= 999; i++){
        if(i % 13 == 5){
            cout << i << endl;
            cn++;
        }
    }

    cout << cn << endl;
    

    /*
    string v;
    cin >> v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(v.length() == 2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    */
}