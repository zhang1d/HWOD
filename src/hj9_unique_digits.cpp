/*
HJ9 提取不重复的整数

知识点：数组、哈希

样例 1：
输入：9876673
输出：37689
说明：先将数字倒序得到 3766789，再去除重复数字得到 37689。

样例 2：
输入：12345678
输出：87654321

描述：
对于给定的正整数 n，按照从右向左的阅读顺序，返回一个不含重复数字的新整数。
具体地，如果遇到相同数字，保留在最右侧出现的第一个数字。

输入描述：
在一行上输入一个整数 n（1 <= n <= 10^8），代表给定的整数。保证 n 的最后一位不为 0。

输出描述：
在一行上输出一个整数，代表处理后的数字。
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
   string res;
   unordered_set<char> temp;
    for(int i = 0;i < s.size() ;i++){
        
        if(temp.find(s[i]) != temp.end() ){
           
            continue;
        }else{
             temp.insert(s[i]);
        }
        res.push_back(s[i]);
    }
    for(auto i : res){
        cout<<i;
    }
    return 0;
}
