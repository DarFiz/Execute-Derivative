#pragma once

#include <string>
#include <memory>
#include "IFunction.h"

class IFunctionProduct
{
public:
    virtual void FrontMultiplyBy(std::unique_ptr<IFunction> p_function) = 0;
    virtual void BackMultiplyBy(std::unique_ptr<IFunction> p_function) = 0;
    virtual IFunction & GetNthFunction(int position)   = 0;
    virtual const std::size_t  GetNumberOfFunction()   = 0;
    virtual std::vector<std::unique_ptr<IFunction>> & GetVectorOfFunction() = 0;
    virtual void SortFunctionProduct() = 0;
    virtual void SetMnoznik(int liczba) = 0;
    virtual int  & GetMnoznik() = 0;
    virtual std::vector<std::unique_ptr<IFunction>>::iterator FindFunctionWithName(std::string name) = 0;
    virtual std::vector<std::unique_ptr<IFunction>>::iterator GetEndIterator() = 0;    
    virtual std::vector<std::unique_ptr<IFunction>>::iterator GetBeginIterator() = 0;    
    //zmien ze wzgledu na wydajnosc poprzez porownywanie iteratorow
     virtual bool operator==(IFunctionProduct& rhs) = 0;
     virtual bool operator<(IFunctionProduct& rhs) = 0;
     
     virtual void EraseFunctionOnIterator(std::vector<std::unique_ptr<IFunction>>::iterator it) = 0;
     
     virtual void ShowFunctionProduct() = 0;
     virtual std::string GetFunctionProductString() = 0;
     
     virtual ~IFunctionProduct(){};
};