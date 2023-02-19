#pragma once
#include <iostream>
#include<typeinfo>
#include <algorithm>
#include <vector>

typedef int(*funToReturn)(int, int);
typedef int(*mathFun)(int, int);
typedef int(*memberFunction)(int, int);


namespace FunctionPointerMethods {
    class TestFunctionPointer {
    public:
        int memberMethodAdd(int c, int d) { return c + d; }
        static int staticMemberMethodAdd(int c, int d) { return c + d; }
        int constMemberMethodAdd(int c, int d) const { return c + d; }
    };

    class TestFunctionPointer2 {
    public:
        int memberAdd(int c, int d) { return c + d; }
        int memberMultiply(int c, int d) { return c * d; }
    };

    struct StructWithFptr {
        int (*functionToExecute)(int, int);
    };

    //What is function pointer and how to create
    void Q1_Q2_what_is_fp();
   // int callFunctionPointerFromArgument(int (*someFun)(int, int), int valToPass1, int valToPass2);
    void testFptrMemberMethod();
    void Q1avoidwithoutArguments();
    void Q3_fp_as_argument();
    int (*returnFunctionPointer(int type))(int, int);
    funToReturn returnFunctionPointer2(int type);
    void Q4_return_fp();
    void functionPointerArray();
    void Q6WherToUseFunctionPointers();
    void CompareFtprs();
    void functionPointerArrayMemberMethod();
    void fptrAsAMemberField();
}