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

    ll Q, H, S, D;
    cin >> Q >> H >> S >> D;
    ll N;
    cin >> N;

    vector<ll > A(4, 0);
    A[0] = D;
    A[1] = 2 * S;
    A[2] = 4 * H;
    A[3] = 8 * Q;

    vector<ll > B(3, 0);
    B[0] = S;
    B[1] = 2 * H;
    B[2] = 4 * Q;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    cout << (N / 2) * A[0] + (N % 2) * B[0] << endl;


} 