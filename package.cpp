#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"package.h"
using namespace std;

//Implementierung der Klasse Package
 Package::Package(int weight, Region destination): weight{weight}, destination{destination}{
 	if(weight < 5 || weight >20000 )
    throw runtime_error("Weight error");
 }
  bool Package::destination_in(const vector<Region>& des) const{
    for(const auto& d : des){
    	if(d==destination)
        return true;
    }
    return false;
 
  }
Region Package::get_destination()const{
	return destination;
}
  ostream& operator<<(ostream& os, const Package& p){
  	os << "[" << region_names.at(static_cast<size_t>(p.destination)) << " " << p.weight <<" g";
    if(p.weight > 10000)
      os << " heavy";
    os << "]";
    return os;
  
  }