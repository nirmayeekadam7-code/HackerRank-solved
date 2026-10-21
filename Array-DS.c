int* reverseArray(int a_count, int* a, int* result_count) {
    *result_count = a_count;

    for (int i = 0; i < a_count / 2; i++) {
        int temp = a[i];
        a[i] = a[a_count - 1 - i];
        a[a_count - 1 - i] = temp;
    }

    return a;
}