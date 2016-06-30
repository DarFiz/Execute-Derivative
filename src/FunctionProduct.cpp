#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

#include "IFunction.h"
#include "Function.h"
#include "IFunctionProduct.h"
#include "FunctionProduct.h"

FunctionProduct::FunctionProduct(): liczba_(1)
{

}

FunctionProduct::FunctionProduct(FunctionProduct& r_fun_prod)
{
	liczba_ =  r_fun_prod.GetMnoznik();
 
	for(unsigned int i = 0; i < r_fun_prod.GetNumberOfFunction(); i++)
	{
		std::unique_ptr<IFunction> p_func = std::move(std::unique_ptr<IFunction>(new Function( r_fun_prod.GetNthFunction(i))));
		BackMultiplyBy(std::move(p_func));
	}
}

FunctionProduct::FunctionProduct(IFunctionProduct& r_fun_prod)
{
	liczba_ =  r_fun_prod.GetMnoznik();
 
	for(unsigned int i = 0; i < r_fun_prod.GetNumberOfFunction(); i++)
	{
		std::unique_ptr<IFunction> p_func = std::move(std::unique_ptr<IFunction>(new Function( r_fun_prod.GetNthFunction(i))));
		BackMultiplyBy(std::move(p_func));
	}
}

void FunctionProduct::FrontMultiplyBy(std::unique_ptr< IFunction > p_function)
{
	pv_ifunction_product_.insert(pv_ifunction_product_.begin(),move(p_function));
}

void FunctionProduct::BackMultiplyBy(std::unique_ptr< IFunction > p_function)
{
	pv_ifunction_product_.push_back(move(p_function));
}

IFunction & FunctionProduct::GetNthFunction(int position)
{
	return *(pv_ifunction_product_[position]);
}

void FunctionProduct::SortFunctionProduct()
{
  
	std::sort(pv_ifunction_product_.begin(),pv_ifunction_product_.end(),[](const std::unique_ptr<IFunction> & a,  const std::unique_ptr<IFunction> & b)
																					{
																						return *a < *b;
																					});
}

void FunctionProduct::SetMnoznik(int liczba)
{
	liczba_ = liczba;
}

int & FunctionProduct::GetMnoznik()
{
	return liczba_;
}

const std::size_t  FunctionProduct::GetNumberOfFunction()
{
	return pv_ifunction_product_.size();
}

std::vector< std::unique_ptr< IFunction > > & FunctionProduct::GetVectorOfFunction()
{
	return pv_ifunction_product_;
}

bool FunctionProduct::operator==(IFunctionProduct& rhs)
{
	if (GetNumberOfFunction() != rhs.GetNumberOfFunction()) return false;
  
	for(unsigned int i = 0; i < rhs.GetNumberOfFunction(); i++)
	{
		if( !(GetNthFunction(i) == rhs.GetNthFunction(i)) ) return false;
	}
  
	return true;
}

bool FunctionProduct::operator<(IFunctionProduct& rhs)
{
	if (GetNumberOfFunction() != rhs.GetNumberOfFunction()) return GetNumberOfFunction() < rhs.GetNumberOfFunction();
  
	for(unsigned int i = 0; i < rhs.GetNumberOfFunction(); ++i)
	{
		if( !(GetNthFunction(i) == rhs.GetNthFunction(i)) ) return GetNthFunction(i) < rhs.GetNthFunction(i);
	}
  
	return false;
}

std::vector<std::unique_ptr<IFunction>>::iterator FunctionProduct::FindFunctionWithName(std::string name)
{
      std::vector<std::unique_ptr<IFunction>>::iterator it_position = std::find_if(pv_ifunction_product_.begin(),pv_ifunction_product_.end(),
											[&name](const std::unique_ptr<IFunction> & p_fun)
														{
															return p_fun->GetName() == name;
														});

      return it_position;
}

std::vector< std::unique_ptr< IFunction > >::iterator FunctionProduct::GetEndIterator()
{
    return pv_ifunction_product_.end();
}
std::vector< std::unique_ptr< IFunction > >::iterator FunctionProduct::GetBeginIterator()
{
	return pv_ifunction_product_.begin();
}

void FunctionProduct::EraseFunctionOnIterator(std::vector< std::unique_ptr< IFunction > >::iterator it)
{
	pv_ifunction_product_.erase(it);
}

void FunctionProduct::ShowFunctionProduct()
{
	std::cout << liczba_;

	for(std::unique_ptr<IFunction> & p_fun : pv_ifunction_product_)
	{
		std::cout << "*"; p_fun->ShowFunction();
	}
}

std::string FunctionProduct::GetFunctionProductString()
{
	std::string str_prod_funct = std::to_string(liczba_);
      
	for(std::unique_ptr<IFunction> & p_fun : pv_ifunction_product_)
	{
		str_prod_funct += "*" +  p_fun->GetFunctionString();
	}

	return str_prod_funct;
}
