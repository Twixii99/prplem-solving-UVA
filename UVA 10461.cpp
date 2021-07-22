#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define sp(n) fixed << setprecision((n))
#define OO INT_MAX
#define PI acos(-1)

#define lp(i, n) for(int (i) = 0; (i) < (int)(n); ++(i))
#define lps(s, n) for(int i = (int)(s); i < (int)((n); ++i)
#define all(v) (v).begin(), (v).end()

#define init(v, i) fill(all(v), (i))

typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int N = 502;
int case_no = 1;

bool graph[N][N];
int time_work[N];
int v, e, q, max_sum, ans;

vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    for(int i = 1; i <= v; ++i) {
        if(graph[node][i] && !visited[i]) {
            ans += time_work[i];
            dfs(i);
        }
    }
    return 0;
}

int reverse_bfs(int node) {
    queue<int> waiting;
    visited = vector<bool>(v+5, false);
    int temp = max_sum;
    waiting.push(node);
    visited[node] = true;
    while (!waiting.empty()) {
        int curr = waiting.front();
        waiting.pop();
        temp -= time_work[curr];
        for (int i = 1; i <= v; ++i) {
            if (graph[i][curr] && !visited[i]) {
                waiting.push(i);
                visited[i] = true;
            }
        }
    }
    return temp;
}

int main() {
    IO;
//#ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//#endif

    while (true) {
        cin >> v >> e;
        if(v == 0 && e == 0)
            return 0;

        max_sum = 0;
        fill(time_work, time_work+N, 0);
        lp(i, N) lp(j, N) graph[i][j] = 0;

        lp(i, v) {
            cin >> time_work[i + 1];
            max_sum += time_work[i + 1];
        }

        lp(i, e) {
            int a, b;
            cin >> a >> b;
            graph[b][a] = 1;
        }

        cout << "Case #" << case_no++ << ":\n";
        queue<int> waiting;
        cin >> q;
        while (q--) {
            int node;
            cin >> node;
            ans  = 0;
            visited = vector<bool>(v+5, false);
            dfs(node);
            cout << reverse_bfs(node) - ans << "\n";
        }
        cout << endl;
    }
}