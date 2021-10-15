int sb(int arr[], int n, int x)
{
  int start = 0, end = 0;
  int sum = 0;
  int min_size = n + 1;
  while (end < n)
  {
    while (sum <= x && end < n)
      sum += arr[end++];

    while (sum > x && start < n)
    {
      if (end - start < min_size)
        min_size = end - start;

      sum -= arr[start++];
    }
  }
  return min_size;

}
