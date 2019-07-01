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
    double W, H, x , y;
    cin >> W >> H >> x >> y;
    
    if(W / 2 == x && H / 2 == y){
        cout << setprecision(9)  << W * H / 2.0;
        cout << " 1"  << endl;
    }else{
        cout << setprecision(9)  << W * H / 2.0;
        cout << " 0"  << endl;
    }


} 