#include<bits/stdc++.h>
#define MAX 500
using namespace std;

int multiply(int A[MAX], int i, int fact_size);
void fact(int n)
{
    int A[MAX];
    A[0] = 1;
    int fact_size = 1;
    for (int i = 2; i <= n; i++)
        fact_size = multiply(A, i, fact_size);

    for (int i = fact_size - 1; i >= 0; i--)
        cout << A[i];
}

int multiply(int A[MAX], int i, int fact_size)
{   int carry = 0;

    for (int j = 0; j < fact_size; j++)
    {
        int prod = i * A[j] + carry;
        A[j] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {
        A[fact_size] = carry % 10;
        carry = carry / 10;
        fact_size++;
    }

    return fact_size;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    fact(100);
    return 0;
}