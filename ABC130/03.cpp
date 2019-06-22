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
    double sum = 0;
    //cout << sum << endl;
    if(x == 0){
        if(y == 0){
            sum = W * H / 2.0;
            cout << sum << " " << "0" << endl;
            return 0;
        }
        sum = 0.000000001 * (H - y) / 2;
        cout << sum << " " << "1" << endl;
        return 0;
    }else if(y == 0){
        if(x == 0){
            sum = W * H / 2.0;
            cout << sum << " " << "0" << endl;
            return 0;
        }
        sum = 0.000000001 * (W - x) / 2;
        cout << sum << " " << "1" << endl;
        return 0;
    }

    

    if(W == H){

        if(x == y){
            sum = W * H / 2.0;
            cout << sum << " " << "1" << endl;
        }else{
            if(x < y){
                sum = x * H * 1.0;
                cout << sum  << " " << "0" << endl;
            }else{
                sum = y * W * 1.0;
                cout << sum  << " " << "0" << endl;
            }
        }
    }else{
            if(x < y){
                sum = x * H * 1.0;
                cout << sum  << " " << "0" << endl;
            }else{
                sum = y * W * 1.0;
                cout << sum  << " " << "0" << endl;
            }      
    }



} 