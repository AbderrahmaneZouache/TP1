#ifndef __ELECTRICITE_H__
#define __ELECTRICITE_H__

#include <iostream>
#include <string>

#include "cout.h"

class Electricite : public Cout {
  private:
    int voltage;
    int amperage;
    int cout_electric;
  public:
    Electricite ();
    Electricite(std::string le_nom, int voltage, int amperage,  int cout_electric);
    
    void set_voltage(int);
    void set_amperage(int);
    void set_cout_electric(int);

    void set_voltage(std::istream&);
    void set_amperage(std::istream&);
    void set_cout_electric(std::istream&);

    double calculerCout() override;
};

#endif