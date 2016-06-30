#include <string>
#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Function.h"
#include "FunctionProduct.h"
#include "MockIFunction.h"


namespace {

// The fixture for testing class Foo.
class FunctionProductTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  FunctionProductTest() {
    // You can do set-up work for each test here.
  }

  virtual ~FunctionProductTest() {
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

TEST_F(FunctionProductTest, MethodFrontMultuplyBy) 
{
	std::unique_ptr<MockIFunction> p_egzFunkcji1(new MockIFunction());
	EXPECT_CALL(*p_egzFunkcji1,GetNumberOfIndeks()).WillOnce(testing::Return(0));
	std::string nazwa1 = "Nazwa1";
	EXPECT_CALL(*p_egzFunkcji1,GetName()).WillOnce(testing::ReturnRef(nazwa1));
	std::string indeks1 = "x1";
	EXPECT_CALL(*p_egzFunkcji1,GetNthIndeks(0)).WillOnce(testing::ReturnRef(indeks1));

	std::unique_ptr<MockIFunction> p_egzFunkcji2(new MockIFunction());
	EXPECT_CALL(*p_egzFunkcji2,GetNumberOfIndeks()).WillOnce(testing::Return(0));
	std::string nazwa2 = "Nazwa2";
	EXPECT_CALL(*p_egzFunkcji2,GetName()).WillOnce(testing::ReturnRef(nazwa2));

	FunctionProduct egzProduct;
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcji1));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcji2));

	ASSERT_TRUE(egzProduct.GetNthFunction(0).GetName() == "Nazwa2");
	ASSERT_TRUE(egzProduct.GetNthFunction(0).GetNumberOfIndeks() == 0);

	ASSERT_TRUE(egzProduct.GetNthFunction(1).GetName() == "Nazwa1");
	ASSERT_TRUE(egzProduct.GetNthFunction(1).GetNumberOfIndeks() == 0);
	ASSERT_TRUE(egzProduct.GetNthFunction(1).GetNthIndeks(0) == "x1");
}

TEST_F(FunctionProductTest, MethodBackMultuplyBy) 
{
	std::unique_ptr<MockIFunction> p_egzFunkcji1(new MockIFunction());
	std::string nazwa1 = "A";
	EXPECT_CALL(*p_egzFunkcji1,GetName()).WillOnce(testing::ReturnRef(nazwa1));

	std::unique_ptr<MockIFunction> p_egzFunkcji2(new MockIFunction());
	std::string nazwa2 = "B";
	EXPECT_CALL(*p_egzFunkcji2,GetName()).WillOnce(testing::ReturnRef(nazwa2));

	FunctionProduct egzProduct;
	egzProduct.BackMultiplyBy(std::move(p_egzFunkcji1));
	egzProduct.BackMultiplyBy(std::move(p_egzFunkcji2));

	ASSERT_TRUE(egzProduct.GetNthFunction(0).GetName() == "A");
	ASSERT_TRUE(egzProduct.GetNthFunction(1).GetName() == "B");
}


TEST_F(FunctionProductTest, MethodSortFunctionProduct) 
{  
	std::unique_ptr<MockIFunction> p_egzFunkcjiA(new MockIFunction());
	std::string nazwaA = "A";
	EXPECT_CALL(*p_egzFunkcjiA,GetName()).WillRepeatedly(testing::ReturnRef(nazwaA));

	std::unique_ptr<MockIFunction> p_egzFunkcjiB(new MockIFunction());
	std::string nazwaB = "B";
	EXPECT_CALL(*p_egzFunkcjiB,GetName()).WillRepeatedly(testing::ReturnRef(nazwaB));

	std::unique_ptr<MockIFunction> p_egzFunkcjiC(new MockIFunction());
	std::string nazwaC = "C";
	EXPECT_CALL(*p_egzFunkcjiC,GetName()).WillRepeatedly(testing::ReturnRef(nazwaC));


	EXPECT_CALL(*p_egzFunkcjiA,LessThen(testing::Ref(*p_egzFunkcjiA))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiA,LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(true));
	EXPECT_CALL(*p_egzFunkcjiA,LessThen(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(true));

	EXPECT_CALL(*p_egzFunkcjiB,LessThen(testing::Ref(*p_egzFunkcjiA))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiB,LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiB,LessThen(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(true));

	EXPECT_CALL(*p_egzFunkcjiC,LessThen(testing::Ref(*p_egzFunkcjiA))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiC,LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiC,LessThen(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(false));

	FunctionProduct egzProduct;
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiB));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiA));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiC));

	egzProduct.SortFunctionProduct();

	ASSERT_TRUE(egzProduct.GetNthFunction(0).GetName() == "A");
	ASSERT_TRUE(egzProduct.GetNthFunction(1).GetName() == "B");
	ASSERT_TRUE(egzProduct.GetNthFunction(2).GetName() == "C");
}


TEST_F(FunctionProductTest, MethodSortFunctionProduct_ThesameFunction) 
{
  
	std::unique_ptr<MockIFunction> p_egzFunkcjiA(new MockIFunction());
	std::string nazwaA = "A";
	EXPECT_CALL(*p_egzFunkcjiA,GetName()).WillRepeatedly(testing::ReturnRef(nazwaA));


	std::unique_ptr<MockIFunction> p_egzFunkcjiB(new MockIFunction());
	std::string nazwaB = "A";
	EXPECT_CALL(*p_egzFunkcjiB,GetName()).WillRepeatedly(testing::ReturnRef(nazwaB));
	std::string indeksB1 = "a";
	EXPECT_CALL(*p_egzFunkcjiB,GetNthIndeks(0)).WillRepeatedly(testing::ReturnRef(indeksB1));
	std::string indeksB2 = "b";
	EXPECT_CALL(*p_egzFunkcjiB,GetNthIndeks(1)).WillRepeatedly(testing::ReturnRef(indeksB2));


	std::unique_ptr<MockIFunction> p_egzFunkcjiC(new MockIFunction());
	std::string nazwaC = "A";
	EXPECT_CALL(*p_egzFunkcjiC,GetName()).WillRepeatedly(testing::ReturnRef(nazwaC));
	std::string indeksC1 = "x";
	EXPECT_CALL(*p_egzFunkcjiC,GetNthIndeks(0)).WillRepeatedly(testing::ReturnRef(indeksC1));

	EXPECT_CALL(*p_egzFunkcjiA,LessThen(testing::Ref(*p_egzFunkcjiA))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiA,LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(true));
	EXPECT_CALL(*p_egzFunkcjiA,LessThen(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(true));

	EXPECT_CALL(*p_egzFunkcjiB,LessThen(testing::Ref(*p_egzFunkcjiA))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiB,LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiB,LessThen(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(false));

	EXPECT_CALL(*p_egzFunkcjiC,LessThen(testing::Ref(*p_egzFunkcjiA))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiC,LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(true));
	EXPECT_CALL(*p_egzFunkcjiC,LessThen(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(false));

	FunctionProduct egzProduct;
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiB));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiA));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiC));

	egzProduct.SortFunctionProduct();

	ASSERT_TRUE(egzProduct.GetNthFunction(0).GetName() == "A");

	ASSERT_TRUE(egzProduct.GetNthFunction(1).GetNthIndeks(0) == "x");

	ASSERT_TRUE(egzProduct.GetNthFunction(2).GetNthIndeks(0) == "a");
	ASSERT_TRUE(egzProduct.GetNthFunction(2).GetNthIndeks(1) == "b");
}

TEST_F(FunctionProductTest, MethodSortFunctionProduct_ThesameFunction_TheSameNumberOfIndex) 
{
	std::unique_ptr<MockIFunction> p_egzFunkcjiA(new MockIFunction());
	std::string nazwaA = "A";
	EXPECT_CALL(*p_egzFunkcjiA,GetName()).WillRepeatedly(testing::ReturnRef(nazwaA));
	std::string indeksA1 = "a";
	EXPECT_CALL(*p_egzFunkcjiA,GetNthIndeks(0)).WillRepeatedly(testing::ReturnRef(indeksA1));
	std::string indeksA2 = "b";
	EXPECT_CALL(*p_egzFunkcjiA,GetNthIndeks(1)).WillRepeatedly(testing::ReturnRef(indeksA2));

	std::unique_ptr<MockIFunction> p_egzFunkcjiB(new MockIFunction());
	std::string nazwaB = "A";
	EXPECT_CALL(*p_egzFunkcjiB,GetName()).WillRepeatedly(testing::ReturnRef(nazwaB));
	std::string indeksB1 = "a";
	EXPECT_CALL(*p_egzFunkcjiB,GetNthIndeks(0)).WillRepeatedly(testing::ReturnRef(indeksB1));
	std::string indeksB2 = "a";
	EXPECT_CALL(*p_egzFunkcjiB,GetNthIndeks(1)).WillRepeatedly(testing::ReturnRef(indeksB2));

	std::unique_ptr<MockIFunction> p_egzFunkcjiC(new MockIFunction());
	std::string nazwaC = "A";
	EXPECT_CALL(*p_egzFunkcjiC,GetName()).WillRepeatedly(testing::ReturnRef(nazwaC));
	std::string indeksC1 = "x";
	EXPECT_CALL(*p_egzFunkcjiC,GetNthIndeks(0)).WillRepeatedly(testing::ReturnRef(indeksC1));
	std::string indeksC2 = "y";
	EXPECT_CALL(*p_egzFunkcjiC,GetNthIndeks(1)).WillRepeatedly(testing::ReturnRef(indeksC2));


	EXPECT_CALL(*p_egzFunkcjiA,LessThen(testing::Ref(*p_egzFunkcjiA))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiA,LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiA,LessThen(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(true));

	EXPECT_CALL(*p_egzFunkcjiB,LessThen(testing::Ref(*p_egzFunkcjiA))).WillRepeatedly(testing::Return(true));
	EXPECT_CALL(*p_egzFunkcjiB,LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiB,LessThen(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(true));

	EXPECT_CALL(*p_egzFunkcjiC,LessThen(testing::Ref(*p_egzFunkcjiA))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiC,LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiC,LessThen(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(false));


	FunctionProduct egzProduct;
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiB));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiA));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiC));

	egzProduct.SortFunctionProduct();

	ASSERT_TRUE(egzProduct.GetNthFunction(0).GetNthIndeks(0) == "a");
	ASSERT_TRUE(egzProduct.GetNthFunction(0).GetNthIndeks(1) == "a");

	ASSERT_TRUE(egzProduct.GetNthFunction(1).GetNthIndeks(0) == "a");
	ASSERT_TRUE(egzProduct.GetNthFunction(1).GetNthIndeks(1) == "b");

	ASSERT_TRUE(egzProduct.GetNthFunction(2).GetNthIndeks(0) == "x");
	ASSERT_TRUE(egzProduct.GetNthFunction(2).GetNthIndeks(1) == "y");

}

TEST_F(FunctionProductTest, Default_Init_Of_licznik_) 
{
	FunctionProduct egz_fun_prod;
      
	ASSERT_TRUE(egz_fun_prod.GetMnoznik() == 1);
}

TEST_F(FunctionProductTest, MethodEqualComparision) 
{
	std::unique_ptr<MockIFunction> p_egzFunkcjiA(new MockIFunction());
	std::unique_ptr<MockIFunction> p_egzFunkcjiB(new MockIFunction());

	std::unique_ptr<MockIFunction> p_egzFunkcjiC(new MockIFunction());
	std::unique_ptr<MockIFunction> p_egzFunkcjiD(new MockIFunction());

	EXPECT_CALL(*p_egzFunkcjiA, Equals(testing::Ref(*p_egzFunkcjiC))).WillRepeatedly(testing::Return(true));
	EXPECT_CALL(*p_egzFunkcjiB, Equals(testing::Ref(*p_egzFunkcjiD))).WillRepeatedly(testing::Return(true));


	FunctionProduct egzProduct;
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiA));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiB));


	FunctionProduct egzProduct2;
	egzProduct2.FrontMultiplyBy(std::move(p_egzFunkcjiC));
	egzProduct2.FrontMultiplyBy(std::move(p_egzFunkcjiD));

	ASSERT_TRUE(egzProduct == egzProduct2);
}

TEST_F(FunctionProductTest, MethodLowerThenComparision1)
{
	std::unique_ptr<MockIFunction> p_egzFunkcjiA(new MockIFunction());
	std::unique_ptr<MockIFunction> p_egzFunkcjiB(new MockIFunction());

	EXPECT_CALL(*p_egzFunkcjiA, Equals(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiA, LessThen(testing::Ref(*p_egzFunkcjiB))).WillRepeatedly(testing::Return(true));

	FunctionProduct egzProduct1;
	egzProduct1.FrontMultiplyBy(std::move(p_egzFunkcjiA));

	FunctionProduct egzProduct2;
	egzProduct2.FrontMultiplyBy(std::move(p_egzFunkcjiB));

	ASSERT_TRUE(egzProduct1 < egzProduct2);
}

TEST_F(FunctionProductTest, MethodLowerThenComparision2) 
{
	std::unique_ptr<MockIFunction> p_egzFunkcjiA1(new MockIFunction());
	std::unique_ptr<MockIFunction> p_egzFunkcjiA2(new MockIFunction());

	std::unique_ptr<MockIFunction> p_egzFunkcjiB1(new MockIFunction());
	std::unique_ptr<MockIFunction> p_egzFunkcjiB2(new MockIFunction());

	EXPECT_CALL(*p_egzFunkcjiA1, Equals(testing::Ref(*p_egzFunkcjiB1))).WillRepeatedly(testing::Return(true));

	EXPECT_CALL(*p_egzFunkcjiA2, Equals(testing::Ref(*p_egzFunkcjiB2))).WillRepeatedly(testing::Return(false));
	EXPECT_CALL(*p_egzFunkcjiA2, LessThen(testing::Ref(*p_egzFunkcjiB2))).WillRepeatedly(testing::Return(true));

	FunctionProduct egzProduct1;
	egzProduct1.FrontMultiplyBy(std::move(p_egzFunkcjiA2));
	egzProduct1.FrontMultiplyBy(std::move(p_egzFunkcjiA1));

	FunctionProduct egzProduct2;
	egzProduct2.FrontMultiplyBy(std::move(p_egzFunkcjiB2));
	egzProduct2.FrontMultiplyBy(std::move(p_egzFunkcjiB1));

	ASSERT_TRUE(egzProduct1 < egzProduct2);
}

TEST_F(FunctionProductTest, MethodFindFunctionWithName) 
{
	std::unique_ptr<MockIFunction> p_egzFunkcjiA(new MockIFunction());
	std::string nazwaA = "A";
	EXPECT_CALL(*p_egzFunkcjiA,GetName()).WillRepeatedly(testing::ReturnRef(nazwaA));

	std::unique_ptr<MockIFunction> p_egzFunkcjiB(new MockIFunction());
	std::string nazwaB = "B";
	EXPECT_CALL(*p_egzFunkcjiB,GetName()).WillRepeatedly(testing::ReturnRef(nazwaB));

	std::unique_ptr<MockIFunction> p_egzFunkcjiC(new MockIFunction());
	std::string nazwaC = "C";
	EXPECT_CALL(*p_egzFunkcjiC,GetName()).WillRepeatedly(testing::ReturnRef(nazwaC));

	FunctionProduct egzProduct;
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiC));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiB));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiA));

	ASSERT_TRUE(std::distance(egzProduct.GetBeginIterator(),egzProduct.FindFunctionWithName("A")) == 0);
	ASSERT_TRUE(std::distance(egzProduct.GetBeginIterator(), egzProduct.FindFunctionWithName("B")) == 1);
	ASSERT_TRUE(std::distance(egzProduct.GetBeginIterator(), egzProduct.FindFunctionWithName("C")) == 2);
}

TEST_F(FunctionProductTest, MethodCopyConstructor) 
{
	std::unique_ptr<IFunction> p_egzFunkcjiA(new Function);
	p_egzFunkcjiA->AddName("A");
	p_egzFunkcjiA->AddIndeks("a");
	p_egzFunkcjiA->AddIndeks("b");

	std::unique_ptr<IFunction> p_egzFunkcjiB(new Function);
	p_egzFunkcjiB->AddName("B");
	p_egzFunkcjiB->AddIndeks("a");
	p_egzFunkcjiB->AddIndeks("a");

	std::unique_ptr<IFunction> p_egzFunkcjiC(new Function);
	p_egzFunkcjiC->AddName("C");
	p_egzFunkcjiC->AddIndeks("a");
	p_egzFunkcjiC->AddIndeks("b");

	FunctionProduct egzProduct;
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiC));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiB));
	egzProduct.FrontMultiplyBy(std::move(p_egzFunkcjiA));

	FunctionProduct egzProduct2(egzProduct);
	ASSERT_TRUE(egzProduct == egzProduct2);
      
//       ASSERT_TRUE(std::distance(egzProduct.GetBeginIterator(),egzProduct.FindFunctionWithName("A")) == 0);
//       ASSERT_TRUE(std::distance(egzProduct.GetBeginIterator(), egzProduct.FindFunctionWithName("B")) == 1);
//       ASSERT_TRUE(std::distance(egzProduct.GetBeginIterator(), egzProduct.FindFunctionWithName("C")) == 2);
}
// Tests that Foo does Xyz.
}//end namespace
