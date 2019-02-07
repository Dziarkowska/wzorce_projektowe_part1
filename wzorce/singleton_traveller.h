#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>

class Singleton_Traveller 
{
private:
	
	Singleton_Traveller(std::string n = "traveller", int c = 10, int e = 10, int a = 30){
		name = n;
		comfort = c;
		energy = e;
		age = a;
		//std::cout << "Singleton instance created!\n";
	}
	Singleton_Traveller(Singleton_Traveller const&); //
	void operator=(Singleton_Traveller const&); //
public:
	std::string name;
	int comfort;
	int energy;
	int age;
	static Singleton_Traveller& getInstance(){
		static Singleton_Traveller INSTANCE;
		return INSTANCE;
	}
	void display(){
		std::cout<<"imie: "<<name<<std::endl<<"comfort: " <<comfort<<std::endl<<"energy: "<<energy<<std::endl<<"age: "<<age<<std::endl;
	}
    
};