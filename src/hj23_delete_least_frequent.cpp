/*
HJ23 删除字符串中出现次数最少的字符
知识点：字符串、哈希
时间限制：1 秒
空间限制：32 MB

样例 1：
输入：
aabcddd

输出：
aaddd

样例说明：
出现次数最少的字符为 'b' 和 'c'，因此需要同时删除这两个字符。

描述：
对于给定的仅由小写字母构成的字符串，删除字符串中出现次数最少的字符。
输出删除后的字符串，字符串中其它字符保持原来的顺序。
特别地，若有多个字符出现的次数都最少，则把这些字符都删除。

输入描述：
在一行上输入一个长度为 1 <= length(s) <= 20、仅由小写字母构成的字符串 s，
代表待处理的字符串。

输出描述：
在一行上输出一个字符串，代表删除后的答案。
题目保证这个字符串至少包含一个字符。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    string s;
    cin >>s;
    vector<int> res(26,0);
    for(auto i:s){
        for(int j = 0; j < res.size();j++){
            if(i == 'a'+j){
                res[j]++;
            }
        }
    }
    vector<int> mini;
    int left = INT_MAX,right;
    for(int i =0;i < res.size();i++){
        if(res[i]!= 0 &&res[i] < left ){
            mini.clear();
            mini.push_back(i);
            left = res[i];
            continue;
        }
        if(res[i]!= 0 &&res[i] == left ){
             mini.push_back(i);
            left = res[i];
        }

    }
for (int index : mini) {
    char c = 'a' + index;
    s.erase(remove(s.begin(), s.end(), c), s.end());
}
    for(auto i :s){
        cout <<i;
    }
    
}
