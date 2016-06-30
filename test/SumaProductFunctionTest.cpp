#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <string>
#include "Function.h"
#include "FunctionProduct.h"
#include "SumaProductFunction.h"
#include "MockIFunctionProduct.h"


namespace {

// The fixture for testing class Foo.
class SumaProductFunctionTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  SumaProductFunctionTest() {
    // You can do set-up work for each test here.
  }

  virtual ~SumaProductFunctionTest() {
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

TEST_F(SumaProductFunctionTest, MethodAddFrontFunctionProduct)
{
	std::unique_ptr<MockIFunctionProduct> p_egzProduct1(new MockIFunctionProduct);
	std::unique_ptr<MockIFunctionProduct> p_egzProduct2(new MockIFunctionProduct);

	EXPECT_CALL(*p_egzProduct1,GetNumberOfFunction()).WillRepeatedly(testing::Return(0));
	EXPECT_CALL(*p_egzProduct2,GetNumberOfFunction()).WillRepeatedly(testing::Return(3));

	SumaProductFunction egz_suma_prod_func;
	egz_suma_prod_func.AddFrontFunctionProduct(std::move(p_egzProduct1));
	egz_suma_prod_func.AddFrontFunctionProduct(std::move(p_egzProduct2));

	ASSERT_TRUE(egz_suma_prod_func.GetNthFunctionProduct(0).GetNumberOfFunction() == 3);
	ASSERT_TRUE(egz_suma_prod_func.GetNthFunctionProduct(1).GetNumberOfFunction() == 0);
}

TEST_F(SumaProductFunctionTest, MethodGetNthFunctionProduct)
{
	std::unique_ptr<MockIFunctionProduct> p_egzProduct1(new MockIFunctionProduct);
	std::unique_ptr<MockIFunctionProduct> p_egzProduct2(new MockIFunctionProduct);

	EXPECT_CALL(*p_egzProduct1,GetNumberOfFunction()).WillRepeatedly(testing::Return(1));
	EXPECT_CALL(*p_egzProduct2,GetNumberOfFunction()).WillRepeatedly(testing::Return(2));

	SumaProductFunction egz_suma_prod_func;
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct1));
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct2));

	ASSERT_TRUE(egz_suma_prod_func.GetNthFunctionProduct(0).GetNumberOfFunction() == 1);
	ASSERT_TRUE(egz_suma_prod_func.GetNthFunctionProduct(1).GetNumberOfFunction() == 2);
}

TEST_F(SumaProductFunctionTest, MethodSortAllFunctionProduct) 
{
	using testing::StrictMock;
	
	std::unique_ptr<MockIFunctionProduct> p_egzProduct1(new StrictMock<MockIFunctionProduct>);
	EXPECT_CALL(*p_egzProduct1,SortFunctionProduct()).Times(1);

	std::unique_ptr<MockIFunctionProduct> p_egzProduct2(new StrictMock<MockIFunctionProduct>);
	EXPECT_CALL(*p_egzProduct2,SortFunctionProduct()).Times(1);

	SumaProductFunction egz_suma_prod_func;
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct1));
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct2));

	egz_suma_prod_func.SortAllFunctionProduct();
}

TEST_F(SumaProductFunctionTest, MethodReduceDuplikatesClever) 
{
	std::unique_ptr<MockIFunctionProduct> p_egzProduct1(new MockIFunctionProduct);
	std::unique_ptr<MockIFunctionProduct> p_egzProduct2(new MockIFunctionProduct);

	EXPECT_CALL(*p_egzProduct1,Equals(::testing::Ref(*p_egzProduct2))).WillRepeatedly(testing::Return(true));
	
	int licz1 = 2;
	EXPECT_CALL(*p_egzProduct1,GetMnoznik()).WillRepeatedly(testing::ReturnRef(licz1));
	
	int licz2 = 3;
	EXPECT_CALL(*p_egzProduct2,GetMnoznik()).WillRepeatedly(testing::ReturnRef(licz2));

	SumaProductFunction egz_suma_prod_func;
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct1));
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct2));

	egz_suma_prod_func.ReduceDuplicatesClever();

	ASSERT_TRUE(egz_suma_prod_func.GetNumberOfElements() == 1);
	ASSERT_TRUE(egz_suma_prod_func.GetNthFunctionProduct(0).GetMnoznik() == 5);
}

TEST_F(SumaProductFunctionTest, MethodGetNumberOfElements) 
{
	std::unique_ptr<MockIFunctionProduct> p_egzProduct1(new MockIFunctionProduct);
	std::unique_ptr<MockIFunctionProduct> p_egzProduct2(new MockIFunctionProduct);
	std::unique_ptr<MockIFunctionProduct> p_egzProduct3(new MockIFunctionProduct);

	SumaProductFunction egz_suma_prod_func;
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct1));
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct2));
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct3));

	ASSERT_TRUE(egz_suma_prod_func.GetNumberOfElements() == 3);
}

TEST_F(SumaProductFunctionTest, MethodSortSuma1) 
{
	std::unique_ptr<MockIFunctionProduct> p_egzProduct1(new MockIFunctionProduct);
	std::unique_ptr<MockIFunctionProduct> p_egzProduct2(new MockIFunctionProduct);
	std::unique_ptr<MockIFunctionProduct> p_egzProduct3(new MockIFunctionProduct);

	int licz1 = 1;
	EXPECT_CALL(*p_egzProduct1, GetMnoznik()).WillOnce(testing::ReturnRef(licz1));
	int licz2 = 2;
	EXPECT_CALL(*p_egzProduct2, GetMnoznik() ).WillOnce(testing::ReturnRef(licz2));
	int licz3 = 3;
	EXPECT_CALL(*p_egzProduct3, GetMnoznik() ).WillOnce(testing::ReturnRef(licz3));

	EXPECT_CALL(*p_egzProduct1, LessThen(::testing::Ref(*p_egzProduct2))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzProduct2, LessThen(::testing::Ref(*p_egzProduct1))).WillRepeatedly(testing::Return(true));
	EXPECT_CALL(*p_egzProduct1, LessThen(::testing::Ref(*p_egzProduct3))).WillRepeatedly(testing::Return(true));
	EXPECT_CALL(*p_egzProduct3, LessThen(::testing::Ref(*p_egzProduct1))).WillRepeatedly(testing::Return(false));

	EXPECT_CALL(*p_egzProduct2, LessThen(::testing::Ref(*p_egzProduct3))).WillRepeatedly(testing::Return(true));
	EXPECT_CALL(*p_egzProduct3, LessThen(::testing::Ref(*p_egzProduct2))).WillRepeatedly(testing::Return(false));

	SumaProductFunction egz_suma_prod_func;
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct1));
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct2));
	egz_suma_prod_func.AddBackFunctionProduct(std::move(p_egzProduct3));

	egz_suma_prod_func.SortSuma();

	ASSERT_TRUE(egz_suma_prod_func.GetNthFunctionProduct(0).GetMnoznik() == 2);
	ASSERT_TRUE(egz_suma_prod_func.GetNthFunctionProduct(1).GetMnoznik() == 1);
	ASSERT_TRUE(egz_suma_prod_func.GetNthFunctionProduct(2).GetMnoznik() == 3);
}
// Tests that Foo does Xyz.
}//end namespace
