
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 无穷大值

void floyd_warshall(int n, vector<vector<int>>& dist) {
    for (int k = 1; k <= n; k++) {        // 中转点
        for (int i = 1; i <= n; i++) {    // 起点
            for (int j = 1; j <= n; j++) {// 终点
                if (dist[i][k] < INF && dist[k][j] < INF) { // 避免溢出
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    // 初始化邻接矩阵
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // 自身到自身的距离为 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // 读取边信息
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w); // 可能有多条边
        dist[v][u] = min(dist[v][u], w); // 无向图
    }

    // 执行 Floyd-Warshall 算法
    floyd_warshall(n, dist);

    // 处理查询
    while (q--) {
        int s, e;
        cin >> s >> e;
        if (dist[s][e] == INF) {
            cout << "-1\n";  // 无法到达
        } else {
            cout << dist[s][e] << "\n"; // 最短路径
        }
    }

    return 0;
}
