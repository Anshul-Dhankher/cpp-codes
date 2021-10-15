#define d 256
#include<bits/stdc++.h>
using namespace std;

void rabinckarp(char pat[], char txt[], int q)
{
	int N = strlen(txt);
	int M = strlen(pat);
	int i, j;
	int h = 1;
	int p = 0;
	int t = 0;

	for (i = 0; i < M - 1; i++)
		h = d * h % q;

	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;

	}

	for (i = 0; i <= N - M; i++)
	{
		j = 0;
		if (p == t)
		{
			while (j < M)
			{
				if (pat[j] != txt[i + j])
					break;
				j++;
			}
			if (j == M)
				cout << "pattern found at postition " << i << endl;

		}

		if (i < N - M)
		{
			t = (d * (t - h * txt[i]) + txt[i + M]) % q;
			if (t < 0)
				t = t + q;
		}
	}
}

int main()
{
#ifndef ONLINE_JUGDE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEK";

	rabinckarp(pat, txt, 5);


	return 0;
}