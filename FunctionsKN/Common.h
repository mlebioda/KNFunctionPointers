#pragma once
#include <iostream>
#include<typeinfo>
#include <algorithm>
#include <vector>

namespace common
{
    int add(int a, int b);

    int multiply(int a, int b);

    int compare(const void* p, const void* q);
    int less(int i, int j);
    int greater(int i, int j);
};

