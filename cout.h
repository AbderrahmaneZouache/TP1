#ifndef __COUT_H__
#define __COUT_H__

#include <iostream>
#include <string>

class Cout  {
  protected:
    std::string nom;
   
  public:
    Cout();
    Cout(std::string le_nom);
   

    void set_nom(std::string);
    void set_nom(std::istream&);

    const std::string& getnom();

    
    virtual ~Cout() = default ;

    virtual double calculerCout() = 0 ;
};

#endif