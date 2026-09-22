/*
HJ6 质数因子

知识点：排序

样例 1：
输入：
180

输出：
2 2 3 3 5

样例 2：
输入：
47

输出：
47

描述：
对于给定的整数 n，从小到大依次输出它的全部质因子。
即找到这样的质数 p1、p2、……、pk，使得 n = p1 * p2 * …… * pk。

输入描述：
在一行上输入一个整数 n（2 <= n <= 2 * 10^9 + 14），代表待分解的整数。

输出描述：
在一行上从小到大输出若干个整数，代表 n 的质因子。

样例说明：
180 = 2 * 2 * 3 * 3 * 5。
*/

#include <iostream>
#include <vector>

int main()
{
    long long n;
    std::cin >> n;

    std::vector<long long> factors;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    for (std::size_t i = 0; i < factors.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << factors[i];
    }

    return 0;
}
