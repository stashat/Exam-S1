#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"package.h"
#include"conveyor.h"
using namespace std;

//Implementierung der Klasse Conveyor
  Conveyor::Conveyor(vector<Region> regions, vector<Package> packages): regions{regions}, packages{packages}{
  	if(regions.empty())
      throw runtime_error("empty regions");
    for(const auto& p: packages){
			if(!p.destination_in(regions))
        throw runtime_error("Error");
    }
  }

  vector<Package> Conveyor::add_packages(const vector<Package>& new_packages){
  	vector<Package> rest_packages;
    for(const auto& np: new_packages){
    	if(np.destination_in(regions))
        packages.push_back(np);
      else
        rest_packages.push_back(np);
    }
  	return rest_packages;
  }
  bool Conveyor::overlap(const Conveyor& c) const{
  	for(const auto& r: regions){
    	for(const auto& cr: c.regions){
      	if(r==cr)
          return true;
      }
    }
    return false;
  }
vector<Region> Conveyor::clear_regions(){
  if(packages.empty())
    throw runtime_error("Error");
  vector<Region> rest_regions;
  for(size_t i {0}; i< regions.size(); i++){
    bool found{false};
    for(const auto& p: packages){
      if(regions.at(i)== p.get_destination()){
        found = true;
        break;
      }
    }
    if(found==false){
      	rest_regions.push_back(regions.at(i));
        regions.erase(regions.begin()+i);
      	i--;
      }
  
  }
  
  return rest_regions;
}

void Conveyor::dispatch(Conveyor& one, Conveyor& two){
  if(one.overlap(two))
    throw runtime_error("Error");
  for(size_t i {0}; i< packages.size(); i++){
  	if(packages.at(i).destination_in(one.regions)){
    	one.packages.push_back(packages.at(i));
      packages.erase(packages.begin()+i);
      i--;
    }
  }
  for(size_t i {0}; i< packages.size(); i++){
    if(packages.at(i).destination_in(two.regions)){
    	two.packages.push_back(packages.at(i));
      packages.erase(packages.begin()+i);
      i--;
    }
  }
}

  ostream& operator<<(ostream& os, const Conveyor& c){
  	os << "[{"<< region_names.at(static_cast<size_t>(c.regions.at(0)));
    for(size_t i {1}; i< c.regions.size(); i++){
    	os << ", " << region_names.at(static_cast<size_t>(c.regions.at(i)));
    }
    os << "}, {";
    if(!c.packages.empty()){
      os << c.packages.at(0);
      for(size_t i {1}; i< c.packages.size(); i++)
        os << ", " << c.packages.at(i);
    }
    os << "}]";
    return os;  
  
  }