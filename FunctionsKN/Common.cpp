#include "Common.h"
int common::add(int a, int b) {
    return a + b;
}

int common::multiply(int a, int b) {
    return a * b;
}

int common::compare(const void* p, const void* q) {
    int l = *(const int*)p;
    int r = *(const int*)q;
    return l < r;
}

//Napisaæ prost¹ funkcjê wykorzystuj¹c¹ function pointer

int common::greater(int i, int j)
{
    return i < j;
}

int common::less(int i, int j)
{
    return i > j;
}

