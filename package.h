#ifndef PACKAGE_H
#define PACKAGE_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
using namespace std;

enum class Region{EU, US, SA, AFR, AUS, OTHER};
const std::vector<std::string> region_names{"EU", "USA", "South America", "Africa", "Australia", "Other"};

//Definition der Klasse Package
class Package{
	int weight; //2 und 200
  Region destination;
  public:
  Package(int, Region=Region::EU);
  Region get_destination()const;
  bool destination_in(const vector<Region>& ) const;
  friend ostream& operator<<(ostream&, const Package&);
 
};
#endif