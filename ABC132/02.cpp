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
    //ll P , Q , R;
    //cin >> P >> Q  >> R;
    ll N = 0;
    cin >> N;
    vector <ll > p(N);
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }


    ll total = 0;
    for(int i = 1; i < N - 2; i++){
        vector<ll > p3(3,0);
        p3[0] = p[i-1];
        p3[1] = p[i];
        p3[2] = p[i+1];
        sort(p3.begin(),p3.end());
        if(p3[1] == p[i]){
            total++;
        }
    }
    cout << total << endl;

} 