#pragma once 

#include <string>
#include <memory>

#include "ISumaProductFunction.h"
#include "ID.h"

namespace alg
{
  class D: public ID
  {
    public:
      void AddIndeks(std::string indeks);
      std::string & GetIndeks();
      void DExecute(ISumaProductFunction & egz_sumy);
      void DFrontMultiply(ISumaProductFunction & r_egz_sumy);
    private:
      
      std::unique_ptr<::std::string> p_indeks_;
  };
  
}