#pragma once

#include <memory>
#include <vector>
#include "IFunctionProduct.h"
#include "ISumaProductFunction.h"

class SumaProductFunction: public ISumaProductFunction
{
public:
    void AddBackFunctionProduct(std::unique_ptr<IFunctionProduct> p_egz_funcki);
    void AddFrontFunctionProduct(std::unique_ptr<IFunctionProduct> p_egz_funcki);
    IFunctionProduct & GetNthFunctionProduct(int position);
    void EraseNthFunctionProduct(int position);
    const std::size_t  GetNumberOfElements();
    void SortAllFunctionProduct();
  
    void ReduceDuplicatesClever();
    
    std::vector<std::unique_ptr<IFunctionProduct>> & getElementsAsVectorPtr();
    void SortSuma();
    
    void ShowSumaProductFunction();
    std::string GetSumaProductFunctionString();
    
    
private:
    std::vector<std::unique_ptr<IFunctionProduct>> vp_suma_prod_func_; 
};

