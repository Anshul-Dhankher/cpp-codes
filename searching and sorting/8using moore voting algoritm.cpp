int fc(int a[], int size)
{
    int count = 1;
    int mj_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[mj_index] == a[i])
            count++;
        else
            count--;

        if (count == 0)
        {
            count = 1;
            mj_index = i;
        }
    }
    return a[mj_index];
}

bool ismajor(int a[], int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (cand == a[i])
            count++;
    }
    if (count > size / 2)
        return true;

    return false;
}


int majorityElement(int a[], int size)
{
    int c = fc(a, size);

    if (ismajor(a, size, c))
        return c;

    return -1;


}