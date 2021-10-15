int findLongestConseqSubseq(int arr[], int N)
{
  unordered_set<int> s;
  for (int i = 0; i < N; i++)
    s.insert(arr[i]);
  int ans = 0;

  for (int i = 0; i < N; i++)
  {
    if (s.find(arr[i] - 1) == s.end())
    {
      int j = arr[i];
      int c = 0;
      while (s.find(j) != s.end())
      {
        j++;
        c++;
      }
      ans = max(c, ans);
    }
  }
  return ans;

}