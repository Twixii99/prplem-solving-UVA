// https://web.stanford.edu/class/cs9/lectures/06/Recursion%20Problems.pdf

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


void colorize(int r, int c);
void printv();

string dashes;
vector<string> rooms;

int main() {
    int t, i, j, k, r;
    cin >> t;
    getchar();
    while(t--) {
        i = j = k = r = 0;
        string temp;
        do {
            getline(cin, temp);
            if(temp.at(0) != '_') {
                ++k;
                rooms.push_back(temp);
                j = temp.find('*');
                if(j != string::npos)
                    i = j, r = k-1;
            } else
                dashes = temp;
        } while(temp.at(0) != '_');

        colorize(r, i);
        printv();
        rooms.clear();
    }
}

void printv() {
    for(int x = 0; x < rooms.size(); ++x)
        cout << rooms[x] << "\n";
    cout << dashes << endl;
}

void colorize(int r, int c) {
    if(rooms[r][c] == 'X'  || rooms[r][c] == '#')
        return;

    rooms[r][c] = '#';

    colorize(r+1, c);
    colorize(r-1, c);
    colorize(r, c+1);
    colorize(r, c-1);
}