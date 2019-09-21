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
#include <queue>
#include <functional>

using namespace std;
typedef long long int ll;
int main(){

    ll N, A, B;
    cin >> N >> A >> B;
    if(N == 2){
        cout << "Borys" << endl;
    }else if(A == B - 1){
        cout << "Borys" << endl;
    }else if((B - A - 1) % 2 == 0 ){
        cout << "Borys" << endl;
    }else{
        cout << "Alice" << endl;
    }
} 