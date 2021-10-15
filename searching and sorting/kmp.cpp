
#include<bits/stdc++.h>
using namespace std;
void computeLPSarray(char pat[], int M, int lps[]);


void kmpsearch(char pat[], char txt[])
{
	int M = strlen(pat);
	int N = strlen(txt);

	int lps[M];

	computeLPSarray(pat, M, lps);
	int j = 0, i = 0;
	while (i < N)
	{
		if (txt[i] == pat[j])
		{
			i++;
			j++;
		}

		if (j == M)
		{
			cout << "pattern found at position " << i - j << endl;
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}


	}
}

void computeLPSarray(char pat[], int M, int lps[])
{
	int len = 0;

	lps[0] = 0;

	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
				len = lps[len - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
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

	kmpsearch(pat, txt);

	return 0;
}