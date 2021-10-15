

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int n)
{
    int Profit[n];
    for (int i = 0; i < n; i++)
        Profit[i] = 0;

    int maxprice = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (maxprice < price[i])
            maxprice = price[i];

        Profit[i] = max(Profit[i + 1], maxprice - price[i]);
    }

    int minprice = price[0];

    for (int i = 1; i < n; i++)
    {
        if (price[i] < minprice)
            minprice = price[i];
        Profit[i] = max(Profit[i - 1], Profit[i] + (price[i] - minprice));
    }

    int result = Profit[n - 1];

    return result;
}


int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}
