/*
HJ10 字符个数统计

知识点：字符集、数组或哈希集合

样例 1：
输入：[@A8aA].0
输出：8

描述：
对于给定的字符串，统计其中 ASCII 码在 0 到 127 范围内的不同字符的个数。

备注：受限于输入，本题实际输入字符集为 ASCII 码在 33 到 126 范围内的可见字符，
其中不包含空格和换行。

输入描述：
输入一个长度 1 <= length(s) <= 500 的字符串 s，仅由题目规定的可见字符构成。

输出描述：
在一行上输出一个整数，代表给定字符串中 ASCII 码在 0 到 127 范围内的不同字符的个数。
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include<algorithm>
using namespace std;
int main()
{   
    string s;
    cin >>s;
    unordered_set<char> res;
    for(auto i : s){
        res.insert(i);
    }
    cout << res.size();
    return 0;
}
