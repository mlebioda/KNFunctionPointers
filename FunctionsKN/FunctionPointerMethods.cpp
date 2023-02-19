#include "FunctionPointerMethods.h"
#include "Common.h"
using namespace common;

namespace {
    void printHelloWorld()
    {
        int a = 0;
        std::cout << "Hello world" << std::endl;
        std::cin >> a;
    }

    int callFunctionPointerFromArgument(int (*someFun)(int, int), int valToPass1, int valToPass2)
    {
        return someFun(valToPass1, valToPass2);
    }

    void findMinOrMax(const std::vector<int>& vec, int (*customFunction)(int, int))
    {
        int number = vec.size() == 0 ? 0 : vec.front();
        /* for (int i = 0; i < vec.size(); i++)
         {
             if (customFunction(number, vec[i]))
                 number = vec[i];
         }*/
        printf("The number is: %d", number);
    }

}


void Q1_Q2_what_is_fp()
{
    //Q1 What is and how to create a fp
        //1. Fp wskazuje na adres funkcji.
        // Jest to adekwatne do:
    int i = 22;
    int* p = &i; //p points to i address.
    // function pointer points to function address.

    //2. How to create a function pointer
    //  2.1 Type of function pointer
    // Gdyby to zrobiæ adekwatnie do pointera dla zwyk³ej zmiennej wygl¹da³o by to w ten sposób
    // int *add(int a, int b); NIE MO¯E TAK BYÆ poniewa¿ to jest wskaŸnik na int
  //  int (*fun)(int, int);
   // fun = add; 

    // cannot do this in clas member
    //fun = &add; // the same what above but for old compilers 


//Q2 How to call a function pointer

    int (*fun)(int, int);
    fun = add;
    int result = (*fun)(3, 5);
    int result2 = fun(3, 5);
    std::cout << "result: " << result << std::endl;
    std::cout << "result2: " << result << std::endl;

    //Compiler errors
    //int (*fun)(int, int, int) = fun;
    //fun(3,4,5);
    // TO CHECK WHY





//Q7 void pointer function pointer


}

void FunctionPointerMethods::testFptrMemberMethod()
{
    int (TestFunctionPointer:: * memberFunctionPtr)(int, int);
    //int (TestFunctionPointer:: * staticMemberFunctionPtr)(int, int) = &TestFunctionPointer::staticMemberMethodAdd;
    int (TestFunctionPointer:: * constMemberFunctionPtr)(int, int) const = &TestFunctionPointer::constMemberMethodAdd;
    memberFunctionPtr = &TestFunctionPointer::memberMethodAdd;
    //std::cout << memberFunctionPtr(4, 5); //ERROR
    TestFunctionPointer instance;
    int result = (instance.*memberFunctionPtr)(3, 6);
    std::cout << "Non pointer" << result << std::endl;

    TestFunctionPointer* instance2 = new TestFunctionPointer();
    result = (instance2->*memberFunctionPtr)(5, 10);
    std::cout << "Pointer" << result << std::endl;


   // staticMemberFunctionPtr 
    // memberFunctionPtr = Test::constMemberMethodAdd; //error
    // memberFunctionPtr = Test::staticMemberMethodAdd; //error
    /// memberFunctionPtr = add;//error

}

void FunctionPointerMethods::functionPointerArrayMemberMethod()
{
    typedef int(FunctionPointerMethods::TestFunctionPointer2:: * memberFunctionPtr)(int, int);
    memberFunctionPtr Arr[2] = { &FunctionPointerMethods::TestFunctionPointer2::memberAdd, &FunctionPointerMethods::TestFunctionPointer2::memberMultiply };
    FunctionPointerMethods::TestFunctionPointer2 instance;
    
    for (int i = 0; i < 2; i++)
    {
        printf("Arr[%d] = %d\n", i, (instance.*Arr[i])(3, 5));
    }
}



void FunctionPointerMethods::Q1avoidwithoutArguments()
{
    void (*func)() = printHelloWorld;
    func();
}

//Q3 How to pass a function pointer as an argument
void FunctionPointerMethods::Q3_fp_as_argument()
{
    int x = callFunctionPointerFromArgument(common::add, 3, 4);
    std::cout << "Result: " << x << std::endl;
}

//typedef int(*funToReturn)(int, int);
funToReturn FunctionPointerMethods::returnFunctionPointer2(int type) {
    switch (type)
    {
    case 0:
        return common::add;
    default:
        return common::multiply;
    }
}


int (*FunctionPointerMethods::returnFunctionPointer(int type))(int, int) {
    switch (type)
    {
    case 0:
        return common::add;
    default:
        return common::multiply;
    }
}

void FunctionPointerMethods::Q4_return_fp()
{
    //Q4 how to return a function pointer
    int (*function)(int, int);
    function = FunctionPointerMethods::returnFunctionPointer(0);
    std::cout << "Result (type 0): " << function(3, 4) << std::endl;
    function = FunctionPointerMethods::returnFunctionPointer(1);
    std::cout << "Result (type 1): " << function(3, 4) << std::endl;

    /*std::cout << "without typedef:" << std::endl;
    int (*someFun2)(int, int);
    someFun2 = q4Fun2(0);
    std::cout << "Q4 type 0 result: " << someFun2(3, 4) << std::endl;
    someFun2 = q4Fun2(1);
    std::cout << "Q4 type 1 result: " << someFun2(3, 4) << std::endl;
    */
}

typedef int(*mathFun)(int, int);
void FunctionPointerMethods::functionPointerArray()
{
    mathFun Arr[2] = { common::add, common::multiply };
    for (int i = 0; i < 2; i++)
    {
        printf("Arr[%d] = %d\n", i, Arr[i](3, 5));
    }
    //  printf("%s", "Now without typedef\n");

    int (*Arr2[2])(int, int) = { common::multiply, common::add };
    for (int i = 0; i < 2; i++)
    {
        //oldsyyntax
        //printf("Arr[%d] = %d\n", i, Arr2[i](3, 5));
    }
}

void FunctionPointerMethods::Q6WherToUseFunctionPointers()
{
    //The best cases to use a function pointer are function like qsort, where we can costumize rules of work of the funciton
    int arr[5] = { 3,2,4,1,5 };
    std::qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), common::compare);
    for (int a : arr) {
        std::cout << a << ",";
    }
    std::cout << std::endl;

    std::vector<int> v{ 2,23,1,32,4,51,-1 };
    findMinOrMax(v, common::greater);
    findMinOrMax(v, common::less);
}

void FunctionPointerMethods::CompareFtprs()
{
    int (*fptr)(int, int) = common::add;
    int (*fptr2)(int, int) = common::add;

    if (fptr == fptr2)
        std::cout << "fptr and fptr2 are equal" << std::endl;

    fptr2 = common::multiply;

    if (fptr != fptr2)
        std::cout << "fptr and fptr2 are not equal" << std::endl;

    if(fptr == common::add)
        std::cout << "fptr and add are equal" << std::endl;
}


void FunctionPointerMethods::fptrAsAMemberField()
{
    FunctionPointerMethods::StructWithFptr instance;
    instance.functionToExecute = common::add;
    int result = instance.functionToExecute(6, 12);
    std::cout << result;
}