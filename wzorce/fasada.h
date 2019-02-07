#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class Directions{
public:
    void  guide(){
        cout<<"go North"<<endl;
    }

};
class Location
{

public:
    void showLocation(){
        cout<<"Your current possition: 1.3930384  2.383479"<<endl;
    }
};

class Map{
private:
    Directions directions;
    Location location;
public:
    void show(){
        directions.guide();
        location.showLocation();
    }

};



