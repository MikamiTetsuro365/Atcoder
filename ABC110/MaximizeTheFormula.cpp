#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

int A,B,C = 0;

int main(){

    vector<int > ABC;

    for(int i = 0; i < 3; i++){
        int t = 0;
        cin >> t;
        ABC.push_back(t);
    }

    sort(ABC.begin(),ABC.end());

    int total =( ABC[2] * 10 + ABC[1] ) + ABC[0];

    cout << total << endl;
    
}