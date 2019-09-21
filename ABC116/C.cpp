#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//最終的に0を目指していく
//連続して高さを減らせなければ別々に操作する必要がある
int main(){

    int N = 0;
    cin >> N;

    std::vector<int> h(N + 1,0);

    for(int i = 0; i < N; i++){
        cin >> h[i];
    }

    int total = 0;
    int start = 0;
    //int end = 0;
    for(;;){
        if(h[start] == 0){
            start++;
            if(start == N){
                std::cout << total << std::endl;
                break;
            }
        }else{
            for(int i = start; i < N + 1; i++){
                if(h[i] == 0){
                    total ++;
                    break;
                }
                h[i]--;
            }         
        }
    }
}
