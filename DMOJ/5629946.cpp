#include <bits/stdc++.h>
using namespace std;
typedef array<int, 4> arr4;

const int FINAL = 1e6;

int T;
int c, m, y, k;
int C, M, Y, K;
int totalSum;
int curSum;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    vector<arr4> printers;
    for (int j = 0; j < T; j++){
        printers.clear();


        for (int i = 0; i < 3; i++){
            cin >> c >> m >> y >> k;
            printers.push_back({c, m, y, k});
        }

        C = 1e6;
        M = 1e6;
        Y = 1e6;
        K = 1e6;

        for (int i = 0; i < 3; i++){
            C = min(printers[i][0], C);
            M = min(printers[i][1], M);
            Y = min(printers[i][2], Y);
            K = min(printers[i][3], K);
        }

        int values [4] = {C, M, Y, K};
        totalSum = C + M + Y + K;
        curSum = totalSum;

        if (totalSum < FINAL){
            cout << "Case #" << j+1 << ": IMPOSSIBLE" << endl;
        }
        else{
            for (int x = 3; x >= 0; x--){
                if (curSum > FINAL){
                    curSum -= values[x];
                    values[x] = 0;
                }
                else if( curSum == FINAL) {
                    continue;
                }
                else{
                    values[x+1] = FINAL - curSum;
                    break;
                }
            }

            cout << "Case #" << j+1 << ": ";
            for (int  i = 0; i < 3; i++){
                cout << values[i] << " ";
            } cout << values[3] << endl;

//            cout << "TEST" << endl;
        }
    }
}