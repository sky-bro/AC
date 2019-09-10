void insertion_sort(int a[], int size)
{
    for (int i = 1; i < size; i++)
    {
        
        for (int j = 0; j < i; j++){
            if (a[j] > a[i]){
                int tmp = a[i];
                for (int k = i;k>j; k--){
                    a[k] = a[k-1];
                }
                a[j] = tmp;
                break;
            }
        }
    }
}