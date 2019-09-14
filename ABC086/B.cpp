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

int main(){

    string A, B;
    cin >> A >> B;

    double ans = sqrt(stod(A + B));
    //cout << ans << endl;
    if(ceil(ans) != floor(ans)){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

}