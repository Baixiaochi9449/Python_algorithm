#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f; // 使用更大的INF值

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    
    // 初始化对角线
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    
    while (m--) {
        int a, b, val;
        cin >> a >> b >> val;
        graph[a][b] = min(graph[a][b], val);
        graph[b][a] = graph[a][b];
    }
    
    vector<int> dist(n + 1, INF);
    vector<bool> visit(n + 1, false);
    int res = 0;
    
    // 关键修改1：初始化起点
    dist[1] = 0;
    
    // 关键修改2：循环n次，不是n-1次
    for (int i = 0; i < n; i++) {
        int minval = INF;
        int node = -1;
        
        // 找到未访问的最小距离节点
        for (int j = 1; j <= n; j++) {
            if (!visit[j] && dist[j] < minval) {
                minval = dist[j];
                node = j;
            }
        }
        
        // 关键修改3：检查是否找到有效节点
        if (node == -1 || minval == INF) {
            cout << "impossible" << endl;
            return 0;
        }
        
        visit[node] = true;
        res += minval; // 关键修改4：在这里累加
        
        // 更新其他节点的距离
        for (int j = 1; j <= n; j++) {
            if (!visit[j] && graph[node][j] < dist[j]) {
                dist[j] = graph[node][j];
            }
        }
    }
    
    cout << res << endl;
    return 0;
}