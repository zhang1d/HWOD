/*
HJ4 字符串分隔

知识点：字符串

示例 1：
输入：
hellonowcoder

输出：
hellonow
coder000

示例 2：
输入：
0

输出：
00000000

描述：
对于给定的由小写字母和数字混合构成的字符串 s，按每 8 个字符换一行的方式书写：
书写前 8 个字符，换行；书写接下来的 8 个字符，换行；重复上述过程，直到字符串被完全书写。
如果最后一行不满 8 个字符，则在字符串末尾补充 0，直到长度为 8。

输入描述：
在一行上输入一个长度 1 ≤ length(s) ≤ 100，由小写字母和数字构成的字符串 s。

输出描述：
输出若干行，每行输出 8 个字符，代表按题意书写的结果。
*/

#include <iostream>
#include <string>
#include <cmath>
int main (){
    std::string s;
    std::cin >> s;
    int append = 0;
    for(int i = 0; i < s.size(); i++){
        int sycd = std::abs(s.size() - i * 8);
        if(sycd <=8){
            std::string fgs(s.begin()+append,s.end());
            std::cout << fgs;
            for(int j =0 ;j<8-sycd;j++){
                std::cout <<0;
            }
            std::cout <<'\n';
            break;
        }
        std::string fgs(s.begin()+append,s.begin()+append+8);
        std::cout << fgs << '\n';
        append += 8;
    }

    return 0;
}