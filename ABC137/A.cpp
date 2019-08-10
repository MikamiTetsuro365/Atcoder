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

    ll A, B;
    cin >> A >> B;
    ll ans = max(A+B, A -B);
    ll ans2 = max(A-B, A * B);
    cout << max(ans, ans2) << endl;

    /*
    string v;
    cin >> v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(v.length() == 2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    */
}