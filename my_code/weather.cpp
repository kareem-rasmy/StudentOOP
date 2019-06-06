#include <iostream>
#include <string>
#include "weather.h"

using namespace std;


std::ostream& operator<<(std::ostream& os, const GPS& gps){
	os << "Latitude:" << gps.latitude << ", Longitutde:" << gps.longitude;
	return os;
}
std::ostream& operator<<(std::ostream& os, const Weather& w){
	os << "Station name:" << w.station_nm <<"Station rating:"<< w.rating <<"Location:"<< w.my_loc;
	return os;
}
/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}


string Weather::get_name() const {
    return station_nm;
}
