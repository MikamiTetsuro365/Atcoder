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
ll M;
string s;
vector<ll > input1;  
vector<vector <ll > > input2;

int main(){
    
    //cin >> N;
    int N, X;
    cin >> N >> X;

    vector<int>D(N+1, 0);
    vector<int>L(N+1, 0);
    int sum = 1;
    for(int i = 0; i < N; i++){
        cin >> L[i];
    }

    for(int i = 1; i <= N; i++){
        int d = D[i-1] + L[i-1];
        //cout << d << endl;
        D[i] = d;
        if(d <= X){
            sum++;
        }
    }

    cout << sum << endl;

} 