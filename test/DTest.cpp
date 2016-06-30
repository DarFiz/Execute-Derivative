#include "gtest/gtest.h"
#include <regex>
#include <fstream>
#include <iostream>
#include <string>
#include "Function.h"
#include "FunctionProduct.h"
#include "SumaProductFunction.h"
#include "D.h"


namespace {

// The fixture for testing class Foo.
class DTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

    DTest() {
    // You can do set-up work for each test here.
  }

  virtual ~DTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

// Tests that the Foo::Bar() method does Abc.

TEST_F(DTest, MethodAddIndeks) 
{
	alg::D poch;
	poch.AddIndeks("D");

	ASSERT_TRUE(poch.GetIndeks() == "D");
}

TEST_F(DTest, MethodCompareToForm) 
{
	std::unique_ptr<IFunction> p_egzFunkcji1(new Function);
	p_egzFunkcji1->AddName("sigma");
	p_egzFunkcji1->AddIndeks("Lx");

	std::unique_ptr<IFunction> p_egzFunkcji2(new Function);
	p_egzFunkcji2->AddName("sigma");
	p_egzFunkcji2->AddIndeks("Lx");

	std::unique_ptr<IFunctionProduct> p_egzProduct1(new FunctionProduct);
	p_egzProduct1->FrontMultiplyBy(std::move(p_egzFunkcji1));
	p_egzProduct1->FrontMultiplyBy(std::move(p_egzFunkcji2));
	p_egzProduct1->SetMnoznik(2);

	SumaProductFunction egz_suma_prod_func;
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct1));
      
    int rzad_poch = 10;
      
	for(int ii=0; ii < rzad_poch; ++ii)
	{
		std::string str = "L"+std::to_string(ii+1);
		alg::D poch;
		poch.AddIndeks(str);
		poch.DExecute(egz_suma_prod_func);
	}

//      egz_suma_prod_func.SortAllFunctionProduct();
// 	egz_suma_prod_func.SortSuma();
// 	egz_suma_prod_func.ReduceDuplicatesAfterSort();
// 	std::cout << egz_suma_prod_func.GetSumaProductFunctionString();
	
	
	std::ifstream template_form_file ( "../PochKowZc++Template.frm" );
	
	std::string  str ;
	std::string  str_temp ;

	while( getline(template_form_file, str_temp) )
	{
		str +=  str_temp + "\n";
	}
// 	 std::cout << str;
	template_form_file.close();
	std::regex reg ("dzialanie");
	str = std::regex_replace(str, reg, egz_suma_prod_func.GetSumaProductFunctionString());
// 	   	 std::cout << str;

	std::ofstream zapis_file ("file_with_cpp_tensor.frm");
	zapis_file << str;
	    
	zapis_file.close();
	    
	    
	std::string  shell_command_string = "form -q -l -d rzadpoch="+ std::to_string(rzad_poch) + " file_with_cpp_tensor.frm";
	const char * shell_command_const_char = shell_command_string.c_str();
	int licz =  system(shell_command_const_char);
	licz = licz ;
	    
	std::ifstream template_form_file2 ( "file_with_cpp_tensor.log" );
	
	std::string  str2 ;
	std::string  str_temp2 ;

	while( getline(template_form_file2, str_temp2) )
	{
		str2 +=  str_temp2 + "\n";
	}
// 	 std::cout << str;
	template_form_file2.close();

// 	std::regex reg2 (".* = (.*);.*");
	std::regex reg2 ("\\n");
	str2 = std::regex_replace(str2, reg2, "");
	
	reg2 = (".* = (.*);.*");
	str2 = std::regex_replace(str2, reg2, "$1");
	
// 	std::cout <<"!!!!!!!!!!!!!!!!!!";
// 	std::cout << str2;
	
	ASSERT_TRUE(str2 == "0");
}
// Tests that Foo does Xyz.
}//end namespace

