#include "adts.h"
#include <iostream>

int main()
{
    StackOfIntsImplVector stack1;
    StackOfInts* ptrToStack = &stack1;
    try
    {
        ptrToStack->pop();
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    
    ptrToStack->push(4);
    ptrToStack->printStack();
    ptrToStack->push(6);
    ptrToStack->printStack();
    ptrToStack->pop();
    ptrToStack->printStack();

    std::cout << "\n-------------------- \n\n";

    StackOfIntsImplList stack2;
    ptrToStack = &stack2;

    ptrToStack->push(4);
    ptrToStack->printStack();
    ptrToStack->push(6);
    ptrToStack->printStack();
    ptrToStack->pop();
    ptrToStack->printStack();

}