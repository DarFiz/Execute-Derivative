#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Function.h"



Function::Function():p_nazwa_(new std::string(""))
{
  
}

Function::Function( Function& r_fun)
{
	p_nazwa_ = std::move(std::unique_ptr<std::string>(new std::string(r_fun.GetName())));
    
	for(std::vector<std::unique_ptr<std::string>>::iterator it = r_fun.GetBeginIterator(); it != r_fun.GetEndIterator(); ++it)
	{
		AddIndeks(**it);
	}
}

Function::Function( IFunction& r_fun)
{
	p_nazwa_ = std::move(std::unique_ptr<std::string>(new std::string(r_fun.GetName())));
    
	for(std::vector<std::unique_ptr<std::string>>::iterator it = r_fun.GetBeginIterator(); it != r_fun.GetEndIterator(); ++it)
	{
		AddIndeks(**it);
	}
}

void Function::AddName(std::string nazwa_funkcji)
{
	std::unique_ptr<::std::string> pl_nazwa_funkcji(new std::string(nazwa_funkcji));
	p_nazwa_ = std::move(pl_nazwa_funkcji);
}

//lamie zasady bo pointer zamiast unique_ptr
std::string & Function::GetName()
{
	return *p_nazwa_;
}

void Function::AddIndeks(std::string nazwa_indeksu)
{
	std::unique_ptr<::std::string> pl_nazwa_indeksu(new std::string(nazwa_indeksu));
	vp_nazwy_indeksow_.push_back(move(pl_nazwa_indeksu));
}

std::string  & Function::GetNthIndeks(int position)
{           
	return *(vp_nazwy_indeksow_[position]);
}

 std::size_t Function::GetNumberOfIndeks()
{
	return vp_nazwy_indeksow_.size();
}

bool Function::operator==(IFunction& rhs)
{
	if (GetName() != rhs.GetName()) return false;
	if (GetNumberOfIndeks() != rhs.GetNumberOfIndeks()) return false;

	for(unsigned int i=0; i < rhs.GetNumberOfIndeks(); i++)
	{
		if(GetNthIndeks(i) != rhs.GetNthIndeks(i)) return false;
	}

	return true;
}

bool Function::operator<( IFunction& rhs)
{
	if (GetName() != rhs.GetName()) return ( GetName() < rhs.GetName() );
	if (GetNumberOfIndeks() != rhs.GetNumberOfIndeks()) return ( GetNumberOfIndeks() < rhs.GetNumberOfIndeks() );

	for(unsigned int i=0; i < rhs.GetNumberOfIndeks(); i++)
	{
		if(GetNthIndeks(i) != rhs.GetNthIndeks(i)) return GetNthIndeks(i) < rhs.GetNthIndeks(i);
	}
 
	return false;
}


std::vector< std::unique_ptr< std::string > >::iterator Function::GetBeginIterator()
{
	return vp_nazwy_indeksow_.begin();
}

std::vector< std::unique_ptr< std::string > >::iterator Function::GetEndIterator()
{
	return vp_nazwy_indeksow_.end();
}

void Function::ShowFunction()
{
	std::cout<< *p_nazwa_<<"(";
      
	int num_ind_min_jeden = GetNumberOfIndeks()-1;
      
	for(int i = 0; i < num_ind_min_jeden; ++i)
	{
		std::cout<< *(vp_nazwy_indeksow_[i]) << ",";
	}
      
	std::cout<< *(vp_nazwy_indeksow_[num_ind_min_jeden]) << ")";
}

std::string Function::GetFunctionString()
{
	std::string str_fun = *p_nazwa_ + "(";
      
	int num_ind_min_jeden = GetNumberOfIndeks()-1;
      
	for(int i = 0; i < num_ind_min_jeden; ++i)
	{
		str_fun += *(vp_nazwy_indeksow_[i]) + ",";
	}
      
	str_fun +=  *(vp_nazwy_indeksow_[num_ind_min_jeden]) + ")";
      
	return str_fun;
}

// bool Function::operator!=( IFunction& rhs)
// {
//
//   if (GetName() != rhs.GetName()) return false;
//   if (GetNumberOfIndeks() != rhs.GetNumberOfIndeks()) return false;
//
//   for(int i=0; i < rhs.GetNumberOfIndeks(); i++)
//   {
//     if(GetNthIndeks(i) != rhs.GetNthIndeks(i)) return false;
//   }
//
//   return true;
// }
