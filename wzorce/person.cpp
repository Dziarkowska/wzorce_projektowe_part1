#include <iostream>
#include "person.h"
#include <string>

using namespace std;

Person::Person(){
}
Person::~Person(){
}
int Person::getAge(){
	return age;
}
void Person::setAge(int newage){
 	age=newage;
}

int Person::getComfort(){
	return comfort;
}
void Person::setComfort(int newcomfort){
 	comfort=newcomfort;
}
int Person::getEnergy(){
	return energy;
}
void Person::setEnergy(int newenergy){
 	energy=newenergy;
}
int Person::getPosX(){
	return posX;
}
void Person::setPosX(int x){
	posX = x;
}
int Person::getPosY(){
	return posY;
}
void Person::setPosY(int y){
	posY = y;
}
void Person::show(){
	cout << name << endl <<"Age:" << age << endl << "comfort: " << comfort << endl;
	cout << "energy: " << energy << endl;	
}
