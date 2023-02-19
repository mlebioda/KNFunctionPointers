#include <iostream>
#include<typeinfo>
#include <algorithm>
#include <vector>
#include "FunctionPointerMethods.h"
#include "Common.h"

using namespace FunctionPointerMethods;

class TestWithOperator {
public:
    int a;
    int b;
    TestWithOperator(int c, int d): a(c), b(d) {}
    int operator +(const TestWithOperator & a) {
        return a.a + a.b + this->a + this->b;
    }    
};

//C++ od 11 Generic Lambda
void lambdaVarriable() {
    auto addLambda = [](auto x, auto y) { return x + y; };
    //auto jaki typ?
    std::string str1 = "lambda", str2 = "result";
    int a = 1, b = 2;
    TestWithOperator t1{ 1, 2 }, t2{ 4,5 };
   // TestFunctionPointer t4{ 1,2 }, t3{ 3,5 };
    std::cout << typeid(addLambda).name() << std::endl;
    std::cout << typeid(t1).name() << std::endl;
    std::cout << addLambda(str1, str2) << std::endl;
    std::cout << addLambda(a, b) << std::endl;
    std::cout << addLambda(t1, t2) << std::endl;
}


















//Lambda
//c++ 14 generic, polymorphic lambda
void labda1()
{
    auto add = [](auto x, auto y) { return x + y; };//auto c++14
    int a = 2, b = 4;
    std::string s1 = "2", s2 = "4";
    std::cout << std::endl << add(a, b) << std::endl;
    std::cout << std::endl << add(s1, s2) << std::endl;
}

void captureClauseEmpty()
{
    int a = 4, b = 5;
    auto function = [](int c, int d) { return /*a + b */ c + d; };
    std::cout << function(a, b);
}

void captureClauseRef()
{
    int a = 4, b = 5;
    auto function = [&](int c, int d) { 
        a -= 1;
        b *= 12;
        return a + c + b + d;
    };

    std::cout << function(9, 1) << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;

}

void captureClauseValue()
{
    int a = 4, b = 5;
    auto function = [=](int c, int d) {
      //  a -= 1;
     //   b *= 12;
        return a + c + b + d;
    };

    std::cout << function(9, 1) << std::endl;

}

void captureClauseValueAndReference()
{
    int a = 4, b = 5, e = 5;
    auto function = [&e, b](int c, int d) {
        e -= 1;
            e -= 1;
        return e + c + b + d;
    };

    std::cout << function(9, 1) << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "e=" << e << std::endl;

}

void captureClauseValueAndReference2()
{
    int a = 4, b = 5, e = 5;
    auto function = [&e, b](int c, int d) {
       // a -= 1;
        e -= 1;
        return  c + b + d;
    };

    std::cout << function(9, 1) << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "e=" << e << std::endl;

}



int main()
{
    std::cout << "OUTPUT:" << std::endl;
    fptrAsAMemberField();
   // CompareFtprs();
   // testFptrMemberMethod();
    //functionPointerArrayMemberMethod();
   //captureClauseEmpty();
   // captureClauseRef();
 //  captureClauseValue();
   // captureClauseValueAndReference();
   // captureClauseValueAndReference2();

  //Q1avoidwithoutArguments();
  // Q1_Q2_what_is_fp();
   // Q3_fp_as_argument();
   // Q4_return_fp();
  //  functionPointerArray();
 //Q6WherToUseFunctionPointers();
 //   labda1();
    
}

