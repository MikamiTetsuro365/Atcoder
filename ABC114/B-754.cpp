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

int main(){

    string s;
    cin >> s;

    ll mn = abs(stoi(s.substr(0,3)) - 753);
    for(ll i = 2; i < s.length(); i++){
        ll t = stoi(s.substr(i - 2,3));
        if(mn > abs(t - 753)){
            mn = abs(t - 753);
        }
    }
    cout << mn << endl;
}