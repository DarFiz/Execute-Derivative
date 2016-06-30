#include "gmock/gmock.h"
#include <string>
#include <memory>

#include "IFunction.h"
#include "IFunctionProduct.h"


class MockIFunctionProduct : public IFunctionProduct
{
	public:
		MOCK_METHOD1(FrontMultiplyBy_RefArg, void(std::unique_ptr<IFunction> & p_function));
		void FrontMultiplyBy(std::unique_ptr<IFunction> p_function){ FrontMultiplyBy_RefArg(p_function);};
		
		MOCK_METHOD1(BackMultiplyBy_RefArg, void(std::unique_ptr<IFunction> & p_function));
		void BackMultiplyBy(std::unique_ptr<IFunction> p_function){ BackMultiplyBy_RefArg(p_function);};
		
		MOCK_METHOD1(GetNthFunction, IFunction &(int position));
		
		
		MOCK_METHOD0(GetNumberOfFunction, const std::size_t());
		
		MOCK_METHOD0(GetVectorOfFunction, std::vector<std::unique_ptr<IFunction>> & ());
		MOCK_METHOD0(SortFunctionProduct, void());
		MOCK_METHOD1(SetMnoznik, void(int liczba));
		MOCK_METHOD0(GetMnoznik, int  &());
		MOCK_METHOD1(FindFunctionWithName, std::vector<std::unique_ptr<IFunction>>::iterator (std::string name));
		MOCK_METHOD0(GetEndIterator, std::vector<std::unique_ptr<IFunction>>::iterator ());
		MOCK_METHOD0(GetBeginIterator, std::vector<std::unique_ptr<IFunction>>::iterator ());
		
		MOCK_METHOD1(Equals, bool(IFunctionProduct & rhs));
		bool operator==(IFunctionProduct& rhs){return Equals(rhs);};
		
		MOCK_METHOD1(LessThen, bool(IFunctionProduct & rhs));
		bool operator<(IFunctionProduct& rhs){return LessThen(rhs);};

		MOCK_METHOD1(EraseFunctionOnIterator,void(std::vector<std::unique_ptr<IFunction>>::iterator it));
		MOCK_METHOD0(ShowFunctionProduct, void());
		MOCK_METHOD0(GetFunctionProductString, std::string());
};