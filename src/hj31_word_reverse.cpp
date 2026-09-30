/*
HJ31 单词倒排
知识点：字符串、排序
时间限制：1 秒
空间限制：32 MB

样例 1：
输入：
Nowcoder Hello

输出：
Hello Nowcoder

样例 2：
输入（行末有一个空格）：
$bo*y gi!r#l 

输出：
l r gi y bo

描述：
对于给定的若干个单词组成的句子，每个单词均由大小写字母构成，
单词间使用非字母字符分隔。输出以单词为单位逆序排放的结果，
即仅逆序单词间的相对顺序，不改变单词内部的字母顺序。
输出时去除原有的分隔符，转而使用单个空格间隔单词。

输入描述：
在一行上输入若干个单词，每个单词长度为 1 <= length(s) <= 20，
仅由大小写字母构成。单词间夹杂一定数量的非字母字符作为分隔符，
分隔符保证为可见字符（样例中也包含空格）。
总字符长度不超过 10^4。

输出描述：
在一行上输出以单词为单位逆序排放的句子，单词间使用单个空格分隔。
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
    getline(cin,s);
    vector<string> res;
    int j = 0; 
    string word;
    for(auto i : s){

        if((i<='z' && i>='a' )|| (i<= 'Z' && i>= 'A')){
            word += i;
        }else{
           res.push_back(word);
           word.clear();
        }
    }
     res.push_back(word);
    for(int i = res.size()-1; i>=0; i--){
        cout<<res[i]<<' ';
    }
    
}
