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
    vector<map<int,int>> counts;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        map<int,int> values;
        for(int j = 0; j < 25; j++) {
            int v;
            cin >> v;
            values[v]++;
        }
        counts.push_back(values);
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            for(auto it = counts[i].begin(); it != counts[i].end(); it++) {
                if(counts[j].count(it->first)) {
                    cout << i + 1 << " " << j + 1;
                    return 0;
                }
            }
        }
    }
    cout << "no ties";
    
    
    return 0;
}