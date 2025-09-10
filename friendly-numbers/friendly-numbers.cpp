#include <iostream>
#include <algorithm>
using namespace std;

vector<long long>sum_of_divisors(int N){
    vector<long long>sumDiv(N+1, 1);
    // karena 1 tidak ada pembagi selain dirinya
    sumDiv[1] = 0;

    for(int i = 2; i <= N/2; i++){
        for(int j = 2*i; j <= N; j+=i){
            sumDiv[j] += i;
        }
    }

    return sumDiv;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    cin >> M >> N;

    vector<long long>sumDiv = sum_of_divisors(N); 
    vector<pair<int,int>>result;

    for(int i = M; i <= N; i++){
        int j = sumDiv[i];
        // cek interval
        if(j > i && j <= N) {
            if(sumDiv[j] == i){
                result.push_back({i, j});
            }
        } 
    }

    if(result.empty()){
        cout << "Absent\n";
    } else {
        for(auto &res : result){
            cout << res.first << " " << res.second << "\n";
        }
    }
    
}
