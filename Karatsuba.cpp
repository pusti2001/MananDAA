#include <bits/stdc++.h>
using namespace std;

int base(long long number)
{
    int n = 10;
    while (n < number)
        n = n * 10;
    return n / 10;
}

int max(long long number, int b)
{
    int m = 1;
    while (m * b < number)
        m++;
    return m--;
}

long long rest(long long number, int b, int m)
{
    int rest = number - m * b;
    return rest;
}

long long karatsuba(long long n1, long long n2)
{
    if (n1 < 10 || n2 < 10)
        return n1 * n2;
    long long z0, z1, z2;
    int z2_1, z2_2;
    int b1, b2;
    long long result;
    b1 = base(n1);
    b2 = base(n2);
    if (b1 > b2)
        b1 = b2;
    else
        b2 = b1;
    z2_1 = max(n1, b1);
    z2_2 = max(n2, b2);
    z2 = karatsuba(z2_1, z2_2);
    z0 = karatsuba(rest(n1, b1, z2_1), rest(n2, b2, z2_2));
    z1 = karatsuba((z2_1 + rest(n1, b1, z2_1)), (z2_2 + rest(n2, b2, z2_2)));
    z1 = z1 - z0 - z2;
    result = z2 * b1 * b1 + z1 * b1 + z0;
    return result;
}

int main()
{
    long long number1, number2, result;
    cout << "Enter first number: ";
    cin >> number1;
    cout << "Enter second number: ";
    cin >> number2;
    result = karatsuba(number1, number2);
    cout << result;
    return 0;
}