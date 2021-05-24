#include "location.h"


Location::Location(){

}
Location::Location(std::string le_nom,int espace, float cout_location) : Cout(le_nom) {
  this-> espace = espace;
  this->cout_location = cout_location;
}

double Location::calculerCout() {
 
 return (espace * cout_location/30)/100;
}
void Location:: set_espace(int espace){
    this->espace = espace;
}
void Location::set_cout_location(float cout_location){
  this->cout_location = cout_location;
}
void Location::set_espace(std::istream& is) {
  is>>espace;
}
void Location::set_cout_location(std::istream& is) {
  is>>cout_location;
}