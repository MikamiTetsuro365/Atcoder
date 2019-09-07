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

    ll X, t;
    cin >> X >> t;

    if(X < t){
        cout << 0 << endl;
    }else{
        cout << X - t << endl;
    }

} 