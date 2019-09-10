void bubble_sort(int a[], int size){
    for (int i = size -1; i>0;--i){
        for (int j = 0; j < i; ++j){
            if (a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}