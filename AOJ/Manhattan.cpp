//#include <bits/stdc++.h>
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
    double N;
    cin >> N;

    double ans1 = N * sqrt(2);
    double ans2 = (int)N + 1;

    if(ans1 > ans2){
        cout << fixed << setprecision(9) << ans1 << endl;
    }else{
        cout << fixed << setprecision(9) << ans2 << endl;
    }

} 