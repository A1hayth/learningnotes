#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int w, m, n;
    cin >> w >> m >> n;

    // 计算 m 和 n 的行号
    int row1 = (m - 1) / w;
    int row2 = (n - 1) / w;

    // 计算 m 和 n 的列号
    int col1 = (row1 % 2 == 0) ? (m - 1) % w : (w - 1 - (m - 1) % w);
    int col2 = (row2 % 2 == 0) ? (n - 1) % w : (w - 1 - (n - 1) % w);

    // 计算曼哈顿距离
    int distance = abs(row1 - row2) + abs(col1 - col2);
    cout << distance << endl;

    return 0;
}
