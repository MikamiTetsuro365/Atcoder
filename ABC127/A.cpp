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

    ll A, B;
    cin >> A >> B;

    if(A >= 13){
        cout  << B << endl;
        return 0;
    }else if(A >= 6 && A <= 12){
        cout << B / 2 << endl;
        return 0;
    }

    cout << "0" << endl;

}