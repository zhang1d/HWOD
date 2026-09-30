/*
HJ36 字符串加密
知识点：字符串、数组、映射

样例 1：
输入：
trailblazers
attackatdawn

输出：
tpptadtpitvh

样例说明：
1. 将 trailblazers 去重，只保留各字母第一次出现的位置，得到 trailbzes。
2. 按字母顺序补充未出现的字母 cdfghjkmnopquvwxy，
   得到新字母表 trailbzescdfghjkmnopquvwxy。
3. 按照以下对照表替换明文中的每个字母：
   原字母表：abcdefghijklmnopqrstuvwxyz
   新字母表：trailbzescdfghjkmnopquvwxy
   明文 attackatdawn 加密后为 tpptadtpitvh。

描述：
对于给定的字符串 s，先进行去重：若存在重复字母，只保留第一次出现的字母，
并保持这些字母的原有顺序。
随后，从 'a' 到 'z' 依次在末尾补充 s 中未出现的字母，构成完整的新字母表。
对于给定的明文 t，将其中每个字母替换为新字母表中对应位置的字母。
这里的对应位置是指该字母在原字母表 abcdefghijklmnopqrstuvwxyz 中的位置。

输入描述：
第一行输入字符串 s，代表构建新字母表的底串。
第二行输入字符串 t，代表需要加密的明文。
两个字符串均仅由小写字母构成，长度分别满足：
1 <= length(s) <= 100，1 <= length(t) <= 100。

输出描述：
在一行上输出一个字符串，代表加密后的密文。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;
int main()
{
   string s;
   cin >> s;
   string t;
   cin >> t;
   set<char> temp;
   string quchong;
   for (auto ch : s)
   {
      if (temp.find(ch) != temp.end())
         continue;
      quchong += ch;
      temp.insert(ch);
   }
   char flag = 'a';
   auto it = temp.begin();
   auto count = quchong.size();
   for (auto i = 0; i < count; i++)
   {
      while (*it - flag)
      {
         quchong += flag;
         flag++;
      }
      flag++;
      it++;
   }
   while (flag <= 'z')
   {
      quchong += flag;
      flag++;
   }
   for (auto i : t)
   {
      cout << quchong[i - 'a'];
   }
}
