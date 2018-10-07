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
    
    char operation;
    cin >> operation;
    string word;
    cin >> word;
    if(operation == 'E') {
        char previousChar = 'A';
        int count = 0;
        for(int i = 0; i < word.length(); i++) {
            if(i == 0) {
                previousChar = word[i];
                count = 1;
            }
            else {
                if(word[i] == previousChar) {
                    count++;
                }
                else {
                    cout << previousChar << count;
                    previousChar = word[i];
                    count = 1;
                }
            }
        }
        cout << previousChar << count;
    }
    else {
        for(int i = 0; i < word.length(); i += 2) {
            char first = word[i];
            string second = "";
            second += word[i+1];
            int count = stoi(second);
            for(int j = 0; j < count; j++) {
                cout << first;
            }
        }
    }
    return 0;
}