/*
HJ0 01 背包问题
知识点：动态规划、01 背包

样例 1：
输入：
4 5
2 3
1 2
3 4
2 2
输出：
7

样例 2：
输入：
3 4
2 4
3 5
4 7
输出：
7

描述：
有 n 件物品和一个容量为 m 的背包。第 i 件物品的重量为 w_i，价值为 v_i。
每件物品最多只能选择一次，也可以不选择。请在总重量不超过背包容量的前提下，
选择若干件物品，使总价值最大。

输入描述：
第一行输入两个整数 n 和 m，分别表示物品数量和背包容量。
接下来 n 行，每行输入两个整数 w_i 和 v_i，分别表示第 i 件物品的重量和价值。
保证 1 <= n <= 100，1 <= m <= 1000，1 <= w_i <= 1000，0 <= v_i <= 10^4。

输出描述：
输出一个整数，表示能够获得的最大总价值。
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // weight[i]：第 i 个物品的重量
    // value[i] ：第 i 个物品的价值
    vector<int> weight(n + 1);
    vector<int> value(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    // dp[i][j]：
    // 只考虑前 i 个物品，
    // 背包容量不超过 j 时，能够获得的最大价值
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 枚举物品
    for (int i = 1; i <= n; i++) {

        // 枚举背包容量
        for (int j = 0; j <= m; j++) {

            // 情况 1：不选择第 i 个物品
            dp[i][j] = dp[i - 1][j];

            // 情况 2：选择第 i 个物品
            if (j >= weight[i]) {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i - 1][j - weight[i]] + value[i]
                );
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}