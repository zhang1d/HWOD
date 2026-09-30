/*
HJ34 图片整理
知识点：字符串、排序
时间限制：1 秒
空间限制：32 MB

样例 1：
输入：
Ihave1nose2hands10fingers

输出：
0112Iaadeeefghhinnnorsssv

描述：
对于给定的由大小写字母和数字组成的字符串，请按照 ASCII 码值从小到大排序。

输入描述：
在一行上输入一个字符串 s，长度满足 1 <= length(s) <= 10^3，
且仅由大小写字母和数字构成。

输出描述：
在一行上输出排序后的字符串。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >>s;
    sort(s.begin(),s.end());
    cout <<s;
}
