#include "eau.h"

Eau::Eau() {

}

Eau::Eau(std::string le_nom, float debit, float cout_eau) : Cout(le_nom) {
  this-> debit = debit;
  this->cout_eau = cout_eau;
}


double Eau::calculerCout() {
  return (debit * cout_eau * 24 * 60 * 60) / 100 ;
}
void Eau::set_debit(float d){
   this->debit=d;
}
void Eau :: set_cout_eau(float cout){
  this-> cout_eau = cout; 

}
void Eau::set_debit(std::istream& is) {
  is>>debit;
}
void Eau::set_cout_eau(std::istream& is) {
  is>>cout_eau;
}

