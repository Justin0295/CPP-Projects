#ifndef __HURRICANE_H
#define __HURRICANE_H

#include <string>
using namespace std;

class Hurricane
{
private:
  string name;
  double lat;
  double lon;
  int windspeed;
public:
  Hurricane();
  Hurricane(string, double, double, int);

  string getName();
  double getLatitude();
  double getLongitude();
  int getWindspeed();
  int getCategory();

  void setLatitude(double);
  void setLongitude(double);
  void setWindspeed(int);
};

#endif