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

    ll K, X;
    cin >> K >> X;

    if(K == 1){
        cout << X << endl;
        return 0;
    }

    for(ll i = X - K + 1; i <= X + K - 1; i++ ){
        if(i != X + K - 1){
            cout << i << " " ;
        }else{
            cout << i << endl;
        }
        
    }



}