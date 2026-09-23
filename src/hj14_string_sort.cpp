/*
HJ14 字符串排序

知识点：字符串、排序

样例 1：
输入：
11
cap
to
cat
card
two
too
up
boat
boot
AA
Aa
------
AA
Aa
cap
to
cat
card
too
two
up
boat
boot
输出：
AA
Aa
boat
boot
cap
card
cat
to
too
two
up

描述：
对于给定的由大小写字母混合构成的 n 个单词，输出按字典序从小到大排序后的结果。

名词解释：
从字符串的第一个字符开始逐个比较，直至发现第一个不同的位置，比较这个位置
字符的 ASCII 码。ASCII 码较小（'A' < 'B' < ... < 'Z' < 'a' < ... < 'z'）
的字符串字典序也较小。

输入描述：
第一行输入一个整数 n（1 <= n <= 10^3），代表给定的单词个数。
此后 n 行，每行输入一个长度 1 <= length(s) <= 100、由大小写字母构成的字符串 s，
代表一个单词。

输出描述：
一共 n 行，每行输出一个字符串，代表排序后的结果。第一行输出字典序最小的单词。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> words(n);
    for (string& word : words)
    {
        cin >> word;
    }

    sort(words.begin(), words.end());

    for (const string& word : words)
    {
        cout << word << '\n';
    }

    return 0;
}
