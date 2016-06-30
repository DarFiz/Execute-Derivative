#include "gmock/gmock.h"
#include <IFunction.h>
#include <string>


class MockIFunction : public IFunction
{
	public:
		MOCK_METHOD1(AddName, void(std::string nazwa_funkcji));
		MOCK_METHOD0(GetName, std::string & ());
		MOCK_METHOD1(AddIndeks, void(std::string nazwa_indeksu));
		MOCK_METHOD1(GetNthIndeks, std::string & (int position));
		MOCK_METHOD0(GetNumberOfIndeks, std::size_t ());

		MOCK_METHOD1(Equals, bool(IFunction & rhs));
		bool operator==(IFunction& rhs){return Equals(rhs);};

		MOCK_METHOD1(LessThen, bool(IFunction & rhs));
		bool operator<(IFunction& rhs){return LessThen(rhs);};

		MOCK_METHOD0(GetEndIterator, std::vector<std::unique_ptr<std::string>>::iterator ());
		MOCK_METHOD0(GetBeginIterator, std::vector<std::unique_ptr<std::string>>::iterator ());
		MOCK_METHOD0(ShowFunction, void ());
		MOCK_METHOD0(GetFunctionString, std::string ());
};