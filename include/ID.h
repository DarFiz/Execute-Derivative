#pragma once 
#include <string>
#include "ISumaProductFunction.h"

namespace alg
{
 
class ID
{
  public:
    virtual void AddIndeks(std::string indeks) = 0;
    virtual std::string & GetIndeks() = 0;
    virtual void DExecute(ISumaProductFunction & egz_sumy) = 0;
    // virtual void Execute(ISumaProductFunction & r_egz_suma ) = 0;    
};

}