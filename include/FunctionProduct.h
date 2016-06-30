#pragma once

#include <string>
#include <memory>
#include <vector>
#include "IFunction.h"
#include "IFunctionProduct.h"

class FunctionProduct: public IFunctionProduct
{
public:
    FunctionProduct();
    FunctionProduct(FunctionProduct &);
    FunctionProduct(IFunctionProduct &);
    void FrontMultiplyBy(std::unique_ptr<IFunction> p_function);
    void BackMultiplyBy(std::unique_ptr<IFunction> p_function);
    IFunction & GetNthFunction(int position);
    const std::size_t GetNumberOfFunction();
    std::vector<std::unique_ptr<IFunction>> & GetVectorOfFunction();
    void SortFunctionProduct();
    void SetMnoznik(int liczba);
    int & GetMnoznik();
    bool operator==(IFunctionProduct& rhs) ;
    bool operator<(IFunctionProduct& rhs);
    std::vector<std::unique_ptr<IFunction>>::iterator FindFunctionWithName(std::string name);
    std::vector<std::unique_ptr<IFunction>>::iterator GetEndIterator();
    std::vector<std::unique_ptr<IFunction>>::iterator GetBeginIterator();    
    void EraseFunctionOnIterator(std::vector<std::unique_ptr<IFunction>>::iterator it) ;
    
    void ShowFunctionProduct();
    std::string GetFunctionProductString();
    
private:
    int liczba_;
    std::vector<std::unique_ptr<IFunction>> pv_ifunction_product_;
    //std::unique_ptr<IFunction> pv_ifunction_product;
};