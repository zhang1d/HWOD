/*
HJ5 进制转换

知识点：字符串

样例 1：
输入：
0xFA93

输出：
64147

描述：
对于给定的十六进制数，输出其对应的十进制表示。

在本题中，十六进制数的格式为：以 0x 开头，后跟若干个十六进制数字，
其中每个数字保证为 0-9 和 A-F 中的一个。A-F 依次代表十进制中的 10-15。

输入描述：
在一行上输入一个十六进制数 s，代表待转换的数字，格式见题干。
保证 s 转化得到的十进制数 x 的范围为 1 <= x < 2^31。

输出描述：
在一行上输出一个整数，代表 s 对应的十进制数。

样例说明：
0xFA93 = 3 * 16^0 + 9 * 16^1 + 10 * 16^2 + 15 * 16^3 = 64147。
*/
#include <iostream>
#include <string>
int main()
{
    std::string s;
    std::cin >> s;
    if (s.size() < 2)
    {
        std::cout << "ERROR" <<'\n';
        return 0;
    }
    if(s[0] != '0' ||(s[1] !='x' && s[1] != 'X')){
        std::cout << "ERROR" <<'\n';
        return 0;
    }
    std::string clh(s.begin()+2,s.end());
    auto res = std::stoi(clh,nullptr,16);
    std::cout<<res<<"\n";
    return 0;
}
