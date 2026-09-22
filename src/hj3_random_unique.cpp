/*
示例 1：
输入：
3
2
2
1

输出：
1
2

知识点：数组

描述：
对于明明生成的 n 个 1 到 500 之间的随机整数，需要完成以下任务：
1. 删除重复的数字，即相同的数字只保留一个；
2. 将这些数从小到大排序，并按照排好的顺序输出。

输入描述：
第一行输入一个整数 n（1 ≤ n ≤ 1000），代表明明生成的数字个数。
此后 n 行，每行输入一个整数 ai（1 ≤ ai ≤ 500），代表明明生成的随机整数。

输出描述：
输出若干行，每行输出一个整数，代表输入数据排序后的结果。
第一行输出最小的数字。
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <set>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0;i < n;i++){
        std::cin >> arr[i];
    }
    std::set<int> res;
    for(int i :arr){
        res.insert(i);
    }
    for(int i = 0; i <res.size(); i++){
        std::cout << *std::next(res.begin(), i) <<'\n';
    }
    return 0;
}
