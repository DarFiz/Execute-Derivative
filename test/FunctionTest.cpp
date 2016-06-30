#include <string>

#include "gtest/gtest.h"
#include "Function.h"


namespace {

// The fixture for testing class Foo.
class FunctionTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  FunctionTest() {
    // You can do set-up work for each test here.
  }

  virtual ~FunctionTest() {
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

TEST_F(FunctionTest, MethodGetNameCheck) 
{
	Function egzFunkcji;
	egzFunkcji.AddName("wyraz");
	ASSERT_TRUE(egzFunkcji.GetName() == "wyraz");

	egzFunkcji.AddName("wyraz2");
	ASSERT_TRUE(egzFunkcji.GetName() == "wyraz2");

	egzFunkcji.AddName("");
	ASSERT_TRUE(egzFunkcji.GetName() == "");
}

TEST_F(FunctionTest, MethodGetNameCheck2) 
{
	Function egzFunkcji;

	ASSERT_TRUE(egzFunkcji.GetName() == "");
}

TEST_F(FunctionTest, MethodGetIndeksCheck) 
{
	Function egzFunkcji;
	egzFunkcji.AddIndeks("indeks0");
	egzFunkcji.AddIndeks("indeks1");
	egzFunkcji.AddIndeks("indeks2");

	ASSERT_TRUE(egzFunkcji.GetNthIndeks(0) == "indeks0");
	ASSERT_TRUE(egzFunkcji.GetNthIndeks(1) == "indeks1");
	ASSERT_TRUE(egzFunkcji.GetNthIndeks(2) == "indeks2");
}

TEST_F(FunctionTest, MethodGetNumberOfIndeks) 
{
	Function egzFunkcji;
	egzFunkcji.AddIndeks("indeks0");
	egzFunkcji.AddIndeks("indeks1");
	egzFunkcji.AddIndeks("indeks2");

	ASSERT_TRUE((egzFunkcji.GetNumberOfIndeks() == std::size_t(3)));
}

TEST_F(FunctionTest, MethodOperatorEqualComparison) 
{
	Function egzFunkcji;
	egzFunkcji.AddName("wyraz");

	Function egzFunkcji2;
	egzFunkcji2.AddName("wyraz");

	ASSERT_TRUE(egzFunkcji == egzFunkcji2);

	egzFunkcji.AddIndeks("indeks0");
	egzFunkcji.AddIndeks("indeks1");
	egzFunkcji.AddIndeks("indeks2");

	egzFunkcji2.AddIndeks("indeks0");
	egzFunkcji2.AddIndeks("indeks1");
	egzFunkcji2.AddIndeks("indeks2");

	ASSERT_TRUE(egzFunkcji == egzFunkcji2);

	egzFunkcji2.AddIndeks("indeks3");

	ASSERT_FALSE(egzFunkcji == egzFunkcji2);
}

TEST_F(FunctionTest, MethodOperatorLowerThen1) 
{
	Function egzFunkcji;
	egzFunkcji.AddName("wyraz");

	Function egzFunkcji2;
	egzFunkcji2.AddName("wyraz");

	egzFunkcji.AddIndeks("indeks0");
	egzFunkcji.AddIndeks("indeks1");
	egzFunkcji.AddIndeks("indeks0");

	egzFunkcji2.AddIndeks("indeks0");
	egzFunkcji2.AddIndeks("indeks1");
	egzFunkcji2.AddIndeks("indeks2");

	ASSERT_TRUE(egzFunkcji < egzFunkcji2);

	egzFunkcji2.AddName("Aba");

	ASSERT_TRUE(egzFunkcji2 < egzFunkcji);
}

TEST_F(FunctionTest, MethodOperatorLowerThen2) 
{
	Function egzFunkcji;
	egzFunkcji.AddName("wyraz");

	Function egzFunkcji2;
	egzFunkcji2.AddName("wyraz");

	egzFunkcji.AddIndeks("indeks0");
	egzFunkcji.AddIndeks("indeks1");
	egzFunkcji.AddIndeks("indeks2");

	egzFunkcji2.AddIndeks("indeks0");
	egzFunkcji2.AddIndeks("indeks1");
	egzFunkcji2.AddIndeks("indeks2");

	ASSERT_FALSE(egzFunkcji < egzFunkcji2);
}

TEST_F(FunctionTest, MethodOperatorLowerThen3) 
{
	Function egzFunkcji1;
	egzFunkcji1.AddName("wyraz");
	egzFunkcji1.AddIndeks("indeks0");
	egzFunkcji1.AddIndeks("indeks1");
	egzFunkcji1.AddIndeks("indeks2");

	Function egzFunkcji2;
	egzFunkcji2.AddName("wyraz");
	egzFunkcji2.AddIndeks("indeks0");
	egzFunkcji2.AddIndeks("indeks1");
	egzFunkcji2.AddIndeks("indeks2");
	egzFunkcji2.AddIndeks("indeks2");

	ASSERT_TRUE(egzFunkcji1 < egzFunkcji2);
}

TEST_F(FunctionTest, MethodCopyConstructor) 
{
	Function egzFunkcji;
	egzFunkcji.AddName("wyraz");
	egzFunkcji.AddIndeks("indeks0");
	egzFunkcji.AddIndeks("indeks1");
	egzFunkcji.AddIndeks("indeks2");

	// IFunction & ref_egzFunckcji =  egzFunkcji;
	Function egzFunkcji2(egzFunkcji);
      
	ASSERT_TRUE(egzFunkcji == egzFunkcji2);
//       ASSERT_TRUE(egzFunkcji.GetName() == egzFunkcji2.GetName());
//       ASSERT_TRUE(egzFunkcji.GetNthIndeks(0) == egzFunkcji2.GetNthIndeks(0));
//       ASSERT_TRUE(egzFunkcji.GetNthIndeks(1) == egzFunkcji2.GetNthIndeks(1));
//       ASSERT_TRUE(egzFunkcji.GetNthIndeks(2) == egzFunkcji2.GetNthIndeks(2));
}
// Tests that Foo does Xyz.
}//end namespace