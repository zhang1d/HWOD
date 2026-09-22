/*
HJ8 合并表记录

知识点：哈希

样例 1：
输入：
4
0 1
0 2
1 2
3 4
输出：
0 3
1 2
3 4
说明：第 1、2 条记录索引相同，合并数值为 1 + 2 = 3。

样例 2：
输入：
2
0 1
0 1
输出：
0 2

描述：
数据表中，一条记录包含表索引和数值两个值。请对表索引相同的记录进行合并，
即将相同索引的数值进行求和运算，随后按照索引值的大小从小到大依次输出。

输入描述：
第一行输入一个整数 n（1 <= n <= 500），代表数据表的记录数。
此后 n 行，第 i 行输入两个整数 xi、yi（0 <= xi <= 11111111；1 <= yi <= 10^5），
代表数据表第 i 条记录的索引和数值。

输出描述：
一共若干行（视输入数据变化），第 i 行输出两个整数，代表合并后数据表中第 i 条
记录的索引和数值。
*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> data;
    int p, q;
    cin >> p >> q;
    data.insert(pair<int, int>(p, q));
    for (size_t i = 0; i < n - 1; i++)
    {
        int p, q;
        cin >> p >> q;
        if(data.find(p) != data.end()){
            data[p] +=q; 
            continue;
        }

        data.insert(pair<int, int>(p, q));
    }
    for(auto i :data){
        cout << i.first << ' ' <<i.second <<'\n';
    }
    return 0;
}
