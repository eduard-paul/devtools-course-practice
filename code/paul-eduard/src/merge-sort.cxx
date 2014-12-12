// Copyright 2014 Paul Eduard

#include "include/merge-sort.h"
#include <stdint.h>
#include <vector>
#include <climits>

static void Merge(std::vector<int64_t> *mas, unsigned int left,
    unsigned int m, unsigned int right) {

    unsigned int n1 = m-left+1;
    unsigned int n2 = right-m;
    std::vector<int64_t> L(n1);
    std::vector<int64_t> R(n2);
    for (unsigned int i = 0; i < n1; ++i) {
        L[i] = (*mas)[left+i];
    }
    for (unsigned int i = 0; i < n2; ++i) {
        R[i] = (*mas)[m+i+1];
    }
    unsigned int k = left, i = 0, j = 0;
    while ((i < n1) && (j < n2)) {
        if (L[i] <= R[j]) {
            (*mas)[k++] = L[i];
            i++;
        } else {
            (*mas)[k++] = R[j];
            j++;
        }
    }
    while (i < n1) (*mas)[k++] = L[i++];
    while (j < n2) (*mas)[k++] = R[j++];
}

int Merge_Sort(std::vector<int64_t> *mas, unsigned int l, unsigned int r) {
    if ((*mas).size() == 0) return -1;
    if (l >= r) return 0;
    unsigned int middle = (l+r)/2;
    Merge_Sort((mas), l, middle);
    Merge_Sort((mas), middle+1, r);
    Merge((mas), l, middle, r);
    return 0;
}
