#define d 256
#include<bits/stdc++.h>
using namespace std;

void rabincarp(char pat[], char txt[], int q)
{
	int N = strlen(txt);
	int M = strlen(pat);
	int h = 1;
	int p = 0;
	int t = 0;
	for (int i = 0; i < M - 1; i++)
		h = (h * d) % q;

	for (int i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	for (int i = 0; i <= N - M; i++)
	{
		if (p == t)
		{	int j;
			for (j = 0; j < M; j++)
			{
				if (pat[j] != txt[i + j])
					break;
			}
			if (j == M)
				cout << "Pattern found at index " << i << endl;

		}
		if (i < N - M)
		{
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			if (t < 0)
				t += q;
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

	rabincarp(pat, txt, 5);


	return 0;
}