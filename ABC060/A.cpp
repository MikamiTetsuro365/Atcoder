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

    string A, B, C;

    cin >> A >> B >> C;

    if(A[A.size()-1] == B[0] && B[B.size()-1] == C[0]){
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;

}