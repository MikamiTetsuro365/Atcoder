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
    int ans = 0;
    int A, B,C;
    cin >> A >> B >> C;
    vector <int > a(3, 0);
    a[0] = A;
    a[1] = B;
    a[2] = C;
    sort(a.begin(), a.end()); 
    if(A == a[0] && B == a[2]){
        cout << "Yes" << endl;
    }else if(A == a[2] && B == a[0]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}