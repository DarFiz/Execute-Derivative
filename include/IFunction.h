#pragma once
#include <memory>
#include <string>
#include <vector>

class IFunction
{
public:
    virtual void AddName(std::string nazwa_funkcji) = 0;
    virtual std::string & GetName() = 0;
    
    virtual void AddIndeks(std::string nazwa_indeksu) = 0;
    virtual std::string & GetNthIndeks(int position) = 0;
    //dlaczego wyrzuca naruszenie pamieci ponizsze
    //virtual std::size_t & GetNumberOfIndeks() = 0;
    virtual std::size_t GetNumberOfIndeks() = 0;
    
    virtual bool operator==(IFunction& rhs) = 0;
    virtual bool operator<(IFunction& rhs) = 0;

    
    virtual std::vector<std::unique_ptr<std::string>>::iterator GetEndIterator() = 0;    
    virtual std::vector<std::unique_ptr<std::string>>::iterator GetBeginIterator() = 0;   
    
    virtual void ShowFunction() = 0;
    virtual std::string GetFunctionString() = 0;
    
    virtual ~IFunction(){};
};