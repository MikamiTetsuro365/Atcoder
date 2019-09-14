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
typedef long long ll;
ll N;
//余りはA *B まででループする.
int main(){

    ll A, B, C;
    cin >> A >> B >> C;

    for(ll i = 1; i <= B; i++){
        //cout << A * i % B  << endl;
        if(A * i % B == C){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;

}