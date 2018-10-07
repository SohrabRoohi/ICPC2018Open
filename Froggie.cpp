/*
  Sohrab Roohi
*/

#include <bits/stdc++.h>

using namespace std;

const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/*
    ifstream in("C:\\Users\\Sohrab\\CLionProjects\\CodeforcesGIT\\input.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("C:\\Users\\Sohrab\\CLionProjects\\CodeforcesGIT\\output.txt");
    cout.rdbuf(out.rdbuf());
     */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<bool>> lanes;
    vector<int> speeds;
    vector<int> intervals;
    vector<int> offsets;
    vector<int> deleted;
    int L, W;
    cin >> L >> W;
    for(int i = 0; i < L; i++) {
        deleted.push_back(3);
    }
    for(int i = 0; i < L; i++) {
        int O, I, S;
        cin >> O >> I >> S;
        vector<bool> lane;
        speeds.push_back(S);
        intervals.push_back(I);
        offsets.push_back(O);
        for(int i = 0; i < O; i++) {
            lane.push_back(false);
        }
        for(int i = 0; i < W - O; i++) {
            if(i % I == 0) {
                lane.push_back(true);
            }
            else {
                lane.push_back(false);
            }
        }
        if(i % 2 == 0) {
            lanes.push_back(lane);
        }
        else {
            reverse(lane.begin(), lane.end());
            lanes.push_back(lane);
        }
    }
    int P;
    cin >> P;
    string com;
    cin >> com;
    int y = L;
    int moveNumber = 1;
    for(int i = 0; i < com.length(); i++) {
        char command = com[i];
        if(command == 'U') {
            y--;
        }
        else if(command == 'L') {
            P--;
        }
        else if(command == 'R') {
            P++;
        }
        else if(command == 'D') {
            y++;
        }
        for(int j = 0; j < L; j++) {
            if(j % 2 == 0) {
                for(int k = 0; k < speeds[j]; k++) {
                    lanes[j].insert(lanes[j].begin(), false);
                    lanes[j].erase(lanes[j].begin() + lanes[j].size() - 1);
                    int firstTrueIndex = -1;
                    for(int l = 0; l < lanes[j].size(); l++) {
                        if(lanes[j][l]) {
                            firstTrueIndex = l;
                            break;
                        }
                    }
                    if(firstTrueIndex - intervals[j] >= 0) {
                        lanes[j][firstTrueIndex-intervals[j]] = true;
                    }
                }
            }
            else {
                for(int k = 0; k < speeds[j]; k++) {
                    const bool value = lanes[j][0];
                    lanes[j].push_back(false);
                    lanes[j].erase(lanes[j].begin());
                    int firstTrueIndex = -1;
                    for(int l = lanes[j].size() - 1; l >= 0; l--) {
                        if(lanes[j][l]) {
                            firstTrueIndex = l;
                            break;
                        }
                    }
                    if(firstTrueIndex + intervals[j] < lanes[j].size()) {
                        lanes[j][firstTrueIndex + intervals[j]] = true;
                    }
                }
            }
        }
        moveNumber++;
        if(y >= L || y < 0) {
            continue;
        }
        if(P < 0 || P >= W) {
            continue;
        }
        if(lanes[y][P]) {
            cout << "squish";
            return 0;
        }
    }
    if(y > 0) {
        cout << "squish";
    }
    else {
        cout << "safe";
    }

    return 0;
}