#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

int H, W, h, w = 0;

int main(){

    cin >> H >> W >> h >> w;

    int total = H * W;

    total = total - (h * W + w * H - w * h);

    cout << total << endl;
    
}