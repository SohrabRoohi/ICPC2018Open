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

class Node
{
public:
    Node* next;
    int data;
};

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    list<int> values;
    values.push_back(1);
    int toInsert = 2;
    string s;
    cin >> s;
    int lastIndex = 0;
    auto it = values.begin();
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == 'L') {
            values.insert(it , toInsert);
            it--;
        }
        else {
            values.push_back(toInsert);
            it = values.end();
            it--;
        }
        toInsert++;
    }
    for(auto it = values.begin(); it != values.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}