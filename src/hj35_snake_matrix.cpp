/*
HJ35 蛇形矩阵
知识点：数组
时间限制：1 秒
空间限制：32 MB

样例 1：
输入：
4

输出：
1 3 6 10
2 5 9
4 8
7

样例说明：
第一步，k = 1：a[1][1] = 1。
第二步，k = 2：a[2][1] = 2，a[1][2] = 3。
第三步，k = 4：a[3][1] = 4，a[2][2] = 5，a[1][3] = 6。
第四步，k = 7：a[4][1] = 7，a[3][2] = 8，a[2][3] = 9，a[1][4] = 10。

描述：
输出一个 n 行 n 列的上三角形蛇形矩阵，从 1 开始依次填充自然数。
行、列下标从 1 开始，有效格子满足 i + j <= n + 1，
共需填充 n * (n + 1) / 2 个格子。

具体构造方法：
依次从第 1、2、……、n 行的第 1 列出发，沿右上方向填充。
若第 i 行第 1 列的元素 a[i][1] = k，则将
a[i-1][2]、a[i-2][3]、……、a[1][i]
依次赋值为 k + 1、k + 2、……、k + i - 1。
随后从下一行的第 1 列继续填入 k + i，重复上述过程，直到填满。
（原文此处写作 a[i][2]，根据样例应为 a[i+1][1]。）

输入描述：
在一行上输入一个整数 n（1 <= n <= 100），代表矩阵的大小。

输出描述：
输出上三角蛇形矩阵，共 n 行。
第 i 行输出 n - i + 1 个整数，相邻整数之间用空格分隔。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = n * (n + 1)/2;
    vector<vector<int>> res(n + 1,(vector<int>(n + 1,0))) ;
    for(int k = n + 1;k >=2;k--){
    for(int i = 1;i < k;i++){
       
            res[i][k - i] = sum--;
        
    }
}
    for(int i = 1;i <= n;i++){

        for(int j = 1;j <= n;j++){
            if(!res[i][j]){
                continue;
            }
            cout <<res[i][j] <<' ';
        }
        cout << '\n';
    }
}
