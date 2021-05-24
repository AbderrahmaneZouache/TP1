#ifndef __EAU_H__
#define __EAU_H__

#include <iostream>
#include <string>

#include "cout.h"

class Eau : public Cout {
  private:
    float debit;
    float cout_eau;
  public:
    Eau();
    Eau(std::string le_nom, float debit, float cout_eau);
    
    void set_debit(float);
    void set_cout_eau(float);

    void set_debit(std::istream&);
    void set_cout_eau(std::istream&); // istream = input stream

    double calculerCout() override;
    
   
    
};

#endif