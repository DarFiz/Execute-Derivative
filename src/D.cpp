#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "ISumaProductFunction.h"
#include "FunctionProduct.h"
#include "Function.h"
#include "ID.h"
#include "D.h"

namespace alg
{
	void D::AddIndeks(std::string indeks)
    {
		p_indeks_ = std::move(std::unique_ptr<std::string>(new std::string(indeks)));
	}
  
	std::string& D::GetIndeks()
	{
		return *p_indeks_;
	}

	void D::DFrontMultiply(ISumaProductFunction & r_egz_sumy)
	{
		for(unsigned int  i = 0; i < r_egz_sumy.GetNumberOfElements() ; ++i)
		{
			std::unique_ptr<IFunction> p_egz_fun(new Function);
			p_egz_fun->AddName("D");
			p_egz_fun->AddIndeks(GetIndeks());

			IFunctionProduct & r_egz_loc = r_egz_sumy.GetNthFunctionProduct(i);
			r_egz_loc.FrontMultiplyBy(std::move(p_egz_fun));
        }
    }

	void D::DExecute(ISumaProductFunction & r_egz_sumy)
	{
		DFrontMultiply(r_egz_sumy);
		bool D_egzist_flag = true;

		while(D_egzist_flag)
		{
			D_egzist_flag = false;
      
			int number_eleement = r_egz_sumy.GetNumberOfElements();
      
			for(int i = (number_eleement-1); i >= 0 ; --i)
			{
				std::vector<std::unique_ptr<IFunction>>::iterator pozycja_D =
						r_egz_sumy.GetNthFunctionProduct(i).FindFunctionWithName("D");

				if(pozycja_D != r_egz_sumy.GetNthFunctionProduct(i).GetEndIterator())
				{
					D_egzist_flag = true;
	  
					if((pozycja_D+1) != r_egz_sumy.GetNthFunctionProduct(i).GetEndIterator())
					{
						std::unique_ptr<IFunctionProduct> p_func_prod(new FunctionProduct(r_egz_sumy.GetNthFunctionProduct(i)));
						std::unique_ptr<IFunction> p_copy_D(new Function(**pozycja_D));
		  
						(*(pozycja_D+1))->AddIndeks((*pozycja_D)->GetNthIndeks(0));
						r_egz_sumy.GetNthFunctionProduct(i).EraseFunctionOnIterator(pozycja_D);

						std::vector<std::unique_ptr<IFunction>>::iterator pozycja_D2 =
								(p_func_prod->GetBeginIterator()+std::distance(r_egz_sumy.GetNthFunctionProduct(i).GetBeginIterator(),pozycja_D));

						p_func_prod->EraseFunctionOnIterator(pozycja_D2);
						(p_func_prod->GetVectorOfFunction()).insert((pozycja_D2+1),std::move(p_copy_D));
		 
						r_egz_sumy.AddBackFunctionProduct(std::move(p_func_prod));
					}
					else
					{
						r_egz_sumy.EraseNthFunctionProduct(i);
					}
				}
			}
		}
	}
}
