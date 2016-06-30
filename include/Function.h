#pragma once
#include "IFunction.h"
#include <string>
#include <vector>
#include <memory>

class Function: public IFunction
{
public:
    Function();
    //czemu nie działa Function(const Function &); ?
    Function( Function &);
    Function( IFunction &);
    void AddName(std::string nazwa_funkcji);
    std::string & GetName();
    
    void AddIndeks(std::string nazwa_indeksu);
    std::string & GetNthIndeks(int position);
    std::size_t  GetNumberOfIndeks();
    
    bool operator==(IFunction& rhs);
    bool operator<( IFunction& rhs);
    std::vector<std::unique_ptr<std::string>>::iterator GetEndIterator();    
    std::vector<std::unique_ptr<std::string>>::iterator GetBeginIterator();
    
    void ShowFunction();
    std::string GetFunctionString();
    
    
private:
    std::unique_ptr<::std::string> p_nazwa_;
    std::vector<std::unique_ptr<std::string>> vp_nazwy_indeksow_;
};