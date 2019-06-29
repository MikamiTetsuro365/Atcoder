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
    sort(p.begin(), p.end());
    /*
    p.erase(unique(p.begin(), p.end()), p.end());
    if(p.size() < N){
        cout << "0" << endl;
        return 0;
    }
    */

    if(p[p.size() / 2 - 1] == p[p.size() / 2]){
        cout << "0" << endl;
        return 0;
    }else{
        cout << p[p.size() / 2] - p[p.size() / 2 - 1] << endl;
    }

    /*
    for(int i = 0; i < N; i++){
        cout << p[i] << endl;
    } 
    */

} 