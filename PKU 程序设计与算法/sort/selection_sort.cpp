void selection_sort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int tmpMin = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (a[j] < a[tmpMin])
            {
                tmpMin = j;
            }
        }
        if (tmpMin == i)
            continue;
        int tmp = a[tmpMin];
        a[tmpMin] = a[i];
        a[i] = tmp;
    }
}