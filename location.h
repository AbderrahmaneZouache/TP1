#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <iostream>
#include <string>

#include "cout.h"

class Location : public Cout {
  private:
    int espace;
    float cout_location;
  public:
    Location ();
    Location(std::string le_nom, int espace, float cout_location);
    
    void set_espace(int);
    void set_cout_location(float);

    void set_espace(std::istream&);
    void set_cout_location(std::istream&);
    
    double calculerCout() override;
};

#endif