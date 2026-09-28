/*
HJ21 简单密码

知识点：字符串、字符转换、映射

样例 1：
输入：
NowCoder123

输出：
o69d6337123

描述：
将给定的密码按照以下规则进行变换：
1. 小写字母参考九键手机键盘映射为对应的数字：
   abc -> 2，def -> 3，ghi -> 4，jkl -> 5，
   mno -> 6，pqrs -> 7，tuv -> 8，wxyz -> 9。
2. 大写字母先转换为小写，再向后移动一位：
   A -> b，B -> c，……，Y -> z，Z -> a。
3. 数字保持不变。

输入描述：
在一行上输入一个长度为 1 <= length(s) <= 100 的字符串 s，
代表给定的密码。

输出描述：
在一行上输出一个字符串，代表变换后的密码。
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
   cin >> s;
   string original = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
   string cipher = "bcdefghijklmnopqrstuvwxyza222333444555666777788899990123456789";
   for( auto ch : s){
      for(int i = 0; i < original.size(); i++){
         if(ch == original[i]){
            cout<<cipher[i];
         }
      }
   }
}
