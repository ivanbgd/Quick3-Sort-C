#define SORTING
#ifdef SORTING

/* Sorting */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ITEMS 100000

void partition3(int* a, int l, int r, int *jp, int* op) {
    int x = a[l];
    int j = l, o = l;
    int t = 0;
    for (int i = l + 1; i < r + 1; i++) {
        if (a[i] < x) {
            o++;
            t = a[i];
            a[i] = a[o];
            a[o] = t;
            t = a[j];
            a[j] = a[o];
            a[o] = t;
            j++;
        }
        else if (a[i] == x) {
            o++;
            t = a[i];
            a[i] = a[o];
            a[o] = t;
        }
        else
            continue;
    }
    if (j > l) {
        t = a[l];
        a[l] = a[j - 1];
        a[j - 1] = t;
    }
    else {
        t = a[l];
        a[l] = a[j];
        a[j] = t;
    }
    *jp = j;
    *op = o;
}

void randomized_quick_sort3(int* a, int l, int r) {
    if (l >= r)
        return;
    int k = (rand() % (r + 1 - l)) + l;                         // might not be the best way, but it's good enough - google it - my solution is as fast as stdlib's (see below)
    int t = 0;
    t = a[l];
    a[l] = a[k];
    a[k] = t;
    int m1, m2;
    partition3(a, l, r, &m1, &m2);
    randomized_quick_sort3(a, l, m1 - 1);
    randomized_quick_sort3(a, m2 + 1, r);
}

int cmpFunc(const int* a, const int* b) {
    return (*a - *b);
}

/* Uses stdlib's qsort(). */
void randomized_quick_sort3_stdlib(int* a, int n, int l, int r) {
    qsort(a, n, sizeof(int), cmpFunc);
}

int main(void) {
    srand((unsigned)time(NULL));
    int n = 0;
    scanf("%d", &n);
    int* a = malloc(n * sizeof(int));                                   // array of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    randomized_quick_sort3(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);

    char c = getchar();
    c = getchar();
    return 0;
}

#endif // SORTING