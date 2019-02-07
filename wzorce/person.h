#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
public:
	std::string name="Ania";
	int age=25;
	int comfort=10;
	int energy=10;
	int posX;
	int posY;

	Person();
	~Person();
	int getAge();
    void setAge(int );
    int getComfort();
    void setComfort(int );
    int getEnergy();
    void setEnergy(int );
    int getPosX();
    void setPosX(int);
    int getPosY();
    void setPosY(int);
    void show();
    //virtual void search()=0;
    //virtual void help()=0;
};