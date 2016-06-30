#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "Function.h"
#include "FunctionProduct.h"
#include "SumaProductFunction.h"
#include "D.h"
#include <stdio.h>

void funk(int rzad_poch)
{
	std::unique_ptr<IFunction> p_egzFunkcji1(new Function);
	p_egzFunkcji1->AddName("s");
	p_egzFunkcji1->AddIndeks("Lx");

	std::unique_ptr<IFunction> p_egzFunkcji2(new Function);
	p_egzFunkcji2->AddName("s");
	p_egzFunkcji2->AddIndeks("Lx");

	std::unique_ptr<IFunctionProduct> p_egzProduct1(new FunctionProduct);
	p_egzProduct1->FrontMultiplyBy(std::move(p_egzFunkcji1));
	p_egzProduct1->FrontMultiplyBy(std::move(p_egzFunkcji2));
	p_egzProduct1->SetMnoznik(2);

	SumaProductFunction egz_suma_prod_func;
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct1));



	for (int ii=0; ii < rzad_poch; ++ii)
	{
		std::string str = "L"+std::to_string(ii+1);
		alg::D poch;
		poch.AddIndeks(str);
		std::cout << "Before Execute D: " + std::to_string(ii+1) << std::endl;
		poch.DExecute(egz_suma_prod_func);
		std::cout << "After Execute D: " + std::to_string(ii+1) << std::endl;
		std::cout << std::endl;

	}
// 	std::cout << "egz_suma_prod_func.SortAllFunctionProduct()"<< std::endl;
// 	egz_suma_prod_func.SortAllFunctionProduct();

	std::cout << "egz_suma_prod_func.SortSuma();"<< std::endl;
	egz_suma_prod_func.SortSuma();
//
	std::cout << "egz_suma_prod_func.ReduceDuplicatesClever();"<< std::endl;
	egz_suma_prod_func.ReduceDuplicatesClever();

// 	egz_suma_prod_func.ShowSumaProductFunction();
// 	std::cout << std::endl;

	std::cout << std::endl << "Liczba elementow to: " << egz_suma_prod_func.GetNumberOfElements()<< std::endl;
}

int main(int argc, char **argv)
{
	auto time_start = std::chrono::steady_clock::now();

	std::thread t1(funk,18);
	std::thread t2(funk,18);

	t1.join();
	t2.join();

//	funk(19);
//	funk(19);
      
	auto time_end = std::chrono::steady_clock::now();
	auto time_end_min_start_sec =std::chrono::duration_cast<std::chrono::seconds>(time_end - time_start).count();
	auto time_end_min_start_mili = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start ).count();

	std::cout << "Czas wykoywania kodu to: " << time_end_min_start_sec <<
	" sec " << time_end_min_start_mili % 1000<<" milisecond"<<std::endl;

	return 0;
}
