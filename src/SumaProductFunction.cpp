#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "IFunctionProduct.h"
#include "SumaProductFunction.h"

void SumaProductFunction::AddBackFunctionProduct(std::unique_ptr<IFunctionProduct> p_egz_funkci)
{
	vp_suma_prod_func_.push_back(std::move(p_egz_funkci));
}

void SumaProductFunction::AddFrontFunctionProduct(std::unique_ptr< IFunctionProduct > p_egz_funkci)
{
	vp_suma_prod_func_.insert(vp_suma_prod_func_.begin(),std::move(p_egz_funkci));
}

IFunctionProduct & SumaProductFunction::GetNthFunctionProduct(int position)
{
	return *(vp_suma_prod_func_[position]);
}

void SumaProductFunction::EraseNthFunctionProduct(int position)
{
	vp_suma_prod_func_.erase(vp_suma_prod_func_.begin() + position);
}

const std::size_t SumaProductFunction::GetNumberOfElements()
{
	return vp_suma_prod_func_.size();
}

void SumaProductFunction::SortAllFunctionProduct()
{
	for(std::unique_ptr<IFunctionProduct> & p_fun_prod : vp_suma_prod_func_)
	{
	p_fun_prod->SortFunctionProduct();
	};
}

void SumaProductFunction::ReduceDuplicatesClever()
{
	std::vector<std::unique_ptr<IFunctionProduct>>::iterator it_end_no_duplicates = std:: unique(vp_suma_prod_func_.begin(),vp_suma_prod_func_.end(),[](const std::unique_ptr<IFunctionProduct> & a, const std::unique_ptr<IFunctionProduct> & b)
									    {
											if(*a == *b){a->GetMnoznik()+=b->GetMnoznik();};
											return *a == *b;
									    });
  
	vp_suma_prod_func_.erase(it_end_no_duplicates, vp_suma_prod_func_.end());
}

std::vector< std::unique_ptr< IFunctionProduct > >& SumaProductFunction::getElementsAsVectorPtr()
{
	return vp_suma_prod_func_;
}

// bool porownajProducty( const std::unique_ptr<IFunctionProduct> & a,  std::unique_ptr<IFunctionProduct> & b)
// {
//  
//   if (a->GetName() != b->GetName()) return ( a->GetName() < b->GetName() );
//   if (a->GetNumberOfIndeks() != b->GetNumberOfIndeks()) return ( a->GetNumberOfIndeks() > b->GetNumberOfIndeks() );
// 
//   for(int i=0; i < a->GetNumberOfIndeks(); i++)
//   {
//     if(a->GetNthIndeks(i) != b->GetNthIndeks(i)) return a->GetNthIndeks(i) < b->GetNthIndeks(i);
//   }
//  
//   
// }

// bool porownajProducty(const IFunctionProduct & lhs, const IFunctionProduct & rhs)
// {
//   
// }

void SumaProductFunction::SortSuma()
{
	std::sort(vp_suma_prod_func_.begin(), vp_suma_prod_func_.end() ,
				[](const std::unique_ptr<IFunctionProduct> & lhs, const std::unique_ptr<IFunctionProduct> & rhs){return *lhs < *rhs;});
}

void SumaProductFunction::ShowSumaProductFunction()
{
	for(std::unique_ptr<IFunctionProduct> & p_fun_prod : vp_suma_prod_func_)
	{
	std::cout << "+"; p_fun_prod->ShowFunctionProduct();
	}
}

std::string SumaProductFunction::GetSumaProductFunctionString()
{
	std::string str_suma;
  
	for(std::unique_ptr<IFunctionProduct> & p_fun_prod : vp_suma_prod_func_)
	{
		str_suma +=  "+" + p_fun_prod->GetFunctionProductString();
	}

	return str_suma;
}