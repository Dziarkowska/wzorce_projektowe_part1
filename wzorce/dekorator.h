#include <iostream>
#include <fstream>
#include <string>
#include "person.h"

using namespace std;

class Guide : public Person
{
private:
    Person* p;
public:
    Guide(Person* p1){
        p = p1;
    }
    void show(){   		
        p->show();
        cout<<"Magister Turystyki i Rekreacji"<<endl;       
    }
};

class Guard : public Person
{
private:
    Guide* g;
public:
    Guard(Guide* g1){
        g = g1;
    }
    void show(){    	
        g->show();
        cout<<"Posiada czarny pas karate"<<endl;       
    }
};

