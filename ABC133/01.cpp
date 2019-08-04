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

    ll N , A , B;
    cin >> N >> A >> B;

    ll ans = min(N *A, B);
    cout << ans << endl;


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