/*
HJ13 句子逆序

知识点：数组

样例 1：
输入：
Nowcoder Hello
输出：
Hello Nowcoder

样例 2：
输入：
A b C d
输出：
d C b A

描述：
对于给定的若干个单词组成的句子，每个单词均由大小写字母混合构成，
单词间使用单个空格分隔。输出以单词为单位逆序排放的结果，即仅逆序
单词间的相对顺序，不改变单词内部的字母顺序。

输入描述：
在一行上输入若干个字符串，每个字符串代表一个单词，组成给定的句子。
除此之外，保证每个单词非空，由大小写字母混合构成，且总字符长度不超过 10^3。

输出描述：
在一行上输出一个句子，代表以单词为单位逆序排放的结果。
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
   
    stringstream ss(s);
    vector<string> re_s;
    string temp;
    while (ss >> temp)
    {
        re_s.push_back(temp);
    }
    
    for(int i = re_s.size() - 1;i >= 0; i--){
        cout << re_s[i] << ' ';
    }
    return 0;
}
