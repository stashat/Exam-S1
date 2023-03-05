#ifndef CONVEYOR_H
#define CONVEYOR_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"package.h"
using namespace std;


//Definition der Klasse Conveyor
class Conveyor{
	vector<Region> regions; //nicht leer
  vector<Package> packages;
  public:
  Conveyor(vector<Region>, vector<Package> ={});
  vector<Package> add_packages(const vector<Package>&);
  bool overlap(const Conveyor& ) const;
  vector<Region> clear_regions();
  void dispatch(Conveyor& , Conveyor& );
  friend ostream& operator<<(ostream&, const Conveyor&); 
};
#endif