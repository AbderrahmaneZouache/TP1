#include "electricite.h"


Electricite::Electricite(){

}
Electricite::Electricite(std::string le_nom, int voltage, int amperage,  int cout_electric) : Cout(le_nom) {
   this-> voltage = voltage;
   this-> amperage = amperage;
   this->cout_electric = cout_electric;
}

double Electricite::calculerCout() {

   return ( voltage * amperage * 24 * cout_electric) / 100000.0 ;
 
}
      void Electricite::set_voltage(int vol){
        this->voltage = voltage;

      }
      
      void Electricite:: set_amperage(int amperage){
          this->amperage = amperage;
            
      }
      void Electricite:: set_cout_electric(int cout_electric){
          this->cout_electric = cout_electric;
      }
      void Electricite::set_voltage(std::istream& is) {
      is>>voltage;
      }
      void Electricite::set_amperage(std::istream& is) {
      is>>amperage;
      }
      void Electricite::set_cout_electric(std::istream& is) {
      is>>cout_electric;
      }