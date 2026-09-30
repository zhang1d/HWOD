/*
HJ16 购物单

知识点：动态规划

样例 1：
输入：
50 5
20 3 5
20 3 5
10 3 0
10 2 0
10 1 0

输出：
130

说明：
第三、四、五件物品为主件，第一、二件物品是第五件物品的附件。
购买第一件或第二件物品时必须购买第五件物品；若同时购买两个附件，
第五件主件只需购买一次。购买第一、二、五件商品可获得最大满意度：130。

样例 2：
输入：
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0

输出：
2200

描述：
王强决定把年终奖用于购物，他把想买的物品分为主件与附件。主件可以没有附件，
至多有 2 个附件；附件不再有从属于自己的附件。若要购买某附件，必须先购买
该附件所属的主件，且每件物品只能购买一次。

对于每件物品，记价格为 v_i、重要度为 w_i。所购每件物品的满意度为价格与重要度
的乘积，总满意度为所购物品满意度之和。请在不超过预算的前提下，计算可获得的
最大满意度。

输入描述：
第一行输入两个整数 n、m（1 <= n <= 3*10^4；1 <= m <= 60），分别代表预算和物品总数。
此后 m 行，每行输入三个整数 v_i、w_i、q_i（1 <= v_i <= 10^4；1 <= w_i <= 5；
0 <= q_i <= m），分别代表物品价格、重要度和所属主件编号。q_i = 0 表示该物品为主件，
否则表示该附件从属于编号为 q_i 的主件。物品编号按输入顺序从 1 开始。

输出描述：
在一行上输出一个整数，代表可获得的最大满意度。

数据保证：
全部物品价格均为 10 的倍数；每个主件的附件数不超过 2。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> price(m + 1);
    vector<int> value(m + 1);
    vector<int> parent(m + 1);

    // attach[i]：主件 i 的所有附件
    vector<vector<int>> attach(m + 1);

    // 读取物品
    for (int i = 1; i <= m; i++) {
        int v, w, q;
        cin >> v >> w >> q;

        price[i] = v;
        value[i] = v * w;
        parent[i] = q;

        if (q != 0) {
            attach[q].push_back(i);
        }
    }

    // 保存所有主件
    vector<int> mainItems;

    for (int i = 1; i <= m; i++) {
        if (parent[i] == 0) {
            mainItems.push_back(i);
        }
    }

    // dp[i][money]
    // 前 i 个主件组，在预算不超过 money 时的最大满意度
    vector<vector<int>> dp(
        mainItems.size() + 1,
        vector<int>(n + 1, 0)
    );

    // 一个主件组一个主件组处理
    for (int i = 1; i <= mainItems.size(); i++) {

        // 当前主件的编号
        int mainItem = mainItems[i - 1];

        for (int money = 0; money <= n; money++) {

            // 方案0：什么都不买
            dp[i][money] = dp[i - 1][money];

            // 方案1：只买主件
            if (money >= price[mainItem]) {

                dp[i][money] = max(
                    dp[i][money],
                    dp[i - 1][money - price[mainItem]]
                    + value[mainItem]
                );
            }

            // 方案2：主件 + 附件1
            if (attach[mainItem].size() >= 1) {

                int attach1 = attach[mainItem][0];

                int needMoney =
                    price[mainItem]
                    + price[attach1];

                int getValue =
                    value[mainItem]
                    + value[attach1];

                if (money >= needMoney) {

                    dp[i][money] = max(
                        dp[i][money],
                        dp[i - 1][money - needMoney]
                        + getValue
                    );
                }
            }

            // 方案3：主件 + 附件2
            if (attach[mainItem].size() >= 2) {

                int attach2 = attach[mainItem][1];

                int needMoney =
                    price[mainItem]
                    + price[attach2];

                int getValue =
                    value[mainItem]
                    + value[attach2];

                if (money >= needMoney) {

                    dp[i][money] = max(
                        dp[i][money],
                        dp[i - 1][money - needMoney]
                        + getValue
                    );
                }
            }

            // 方案4：主件 + 两个附件
            if (attach[mainItem].size() >= 2) {

                int attach1 = attach[mainItem][0];
                int attach2 = attach[mainItem][1];

                int needMoney =
                    price[mainItem]
                    + price[attach1]
                    + price[attach2];

                int getValue =
                    value[mainItem]
                    + value[attach1]
                    + value[attach2];

                if (money >= needMoney) {

                    dp[i][money] = max(
                        dp[i][money],
                        dp[i - 1][money - needMoney]
                        + getValue
                    );
                }
            }
        }
    }

    cout << dp[mainItems.size()][n] << endl;

    return 0;
}