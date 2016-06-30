#pragma once
#include <memory>
#include <vector>
#include "IFunctionProduct.h"
class ISumaProductFunction
{
public:
    virtual void AddBackFunctionProduct(std::unique_ptr<IFunctionProduct> p_egz_funcki) = 0;
    virtual void AddFrontFunctionProduct(std::unique_ptr<IFunctionProduct> p_egz_funcki) = 0;
    virtual IFunctionProduct & GetNthFunctionProduct(int position) = 0;
    virtual void EraseNthFunctionProduct(int position) = 0;
    virtual const std::size_t  GetNumberOfElements() = 0;
    virtual void SortAllFunctionProduct() = 0;

    virtual void ReduceDuplicatesClever() = 0;

    virtual std::vector<std::unique_ptr<IFunctionProduct>> & getElementsAsVectorPtr() = 0;
    virtual void SortSuma() = 0;    
    
    virtual void ShowSumaProductFunction() = 0;
    virtual std::string GetSumaProductFunctionString() = 0;
    
    virtual ~ISumaProductFunction(){};
};


