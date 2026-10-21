int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int **arr = (int **)malloc(n * sizeof(int *));
    int *sizes = (int *)calloc(n, sizeof(int));
    int *capacity = (int *)calloc(n, sizeof(int));
    int *answers = (int *)malloc(queries_rows * sizeof(int));

    for (int i = 0; i < n; i++) {
        capacity[i] = 2;
        arr[i] = (int *)malloc(capacity[i] * sizeof(int));
    }

    int lastAnswer = 0;
    int count = 0;

    for (int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            if (sizes[idx] == capacity[idx]) {
                capacity[idx] *= 2;
                arr[idx] = (int *)realloc(arr[idx], capacity[idx] * sizeof(int));
            }

            arr[idx][sizes[idx]] = y;
            sizes[idx]++;
        } else {
            lastAnswer = arr[idx][y % sizes[idx]];
            answers[count++] = lastAnswer;
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(sizes);
    free(capacity);

    *result_count = count;
    return answers;
}