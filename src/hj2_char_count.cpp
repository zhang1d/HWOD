/*
示例 1：
输入：
HELLONowcoder123 o
输出：
3

示例 2：
输入：
H E L L O Nowcoder123 1
输出：
1

描述：
对于给定的由大小写字母、数字和空格混合构成的字符串 s，给定字符 c，按要求统计：
若 c 为大写或者小写字母，统计其大小写形态出现的次数和；
若 c 为数字，统计其出现的次数。

输入描述：
第一行输入一个长度 1 ≤ length(s) ≤ 10^3，由大小写字母、数字和空格构成的字符串 s。
保证首尾不为空格。
第二行输入一个字符 c，保证 c 为大小写字母或数字。

输出描述：
在一行上输出一个整数，代表统计结果。
*/

#include <cctype>
#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::getline(std::cin, s);

    char c;
    std::cin >> c;

    int count = 0;
    for (char current : s) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            if (current == c) {
                ++count;
            }
        } else if (std::tolower(static_cast<unsigned char>(current)) ==
                   std::tolower(static_cast<unsigned char>(c))) {
            ++count;
        }
    }

    std::cout << count;
    return 0;
}
