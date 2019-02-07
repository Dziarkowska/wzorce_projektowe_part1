#include <Windows.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "singleton_traveller.h"
#include "prototyp.h"
#include "budowniczy.h"
#include "adapter.h"
#include "fasada.h"
#include "dekorator.h"
#include "factorymhetod.h"
using namespace std;

int main(){
	//singleton
    Singleton_Traveller *traveller;
    traveller = &traveller->getInstance();
    traveller->display();
    //Prototype
    cout<<"-------------"<<endl;
    AnimalPrototype * pObiekt1 = new PolarAnimalPrototype("white");
    AnimalPrototype * pObiekt2 = pObiekt1->clone();
    pObiekt1->display();
    cout<<"-------------"<<endl;
    pObiekt2->setAge(1);
    pObiekt2->display(); 
    cout<<"-------------"<<endl;
    pObiekt1->display();   
    delete pObiekt2;
    delete pObiekt1;
    //builder
    Menager menager;
    WarmOutfitBuilder warmOutfitBuilder;
    ColdOutfitBuilder coldOutfitBuilder;

    menager.chooseOutfit(&coldOutfitBuilder);
    menager.showOutfit();

    menager.chooseOutfit(&warmOutfitBuilder);
    menager.showOutfit();
    cout<<"-------------"<<endl;
    //adapter
    PotentiallCorpse *polarwolf = new WolfAdapter();
    PotentiallCorpse *polarfox = new FoxAdapter();
    polarwolf->beTarget();
    bool isTargetDead = polarwolf->isDead();
    cout<<"Is target dead? "<<isTargetDead<<endl;
    cout<<"-------------"<<endl;
    //fasada
    Map map;
    map.show(); 
    cout<<"-------------"<<endl; 
    //dekorator
    Person* p = new Person();
    p->show();
    cout<<"-------------"<<endl;
    Guide* g = new Guide(p);
    g->show();
    cout<<"-------------"<<endl;
    Guard* z = new Guard(g);
    z->show();
    cout<<"-------------"<<endl;
    Cosmetic* gel  = Cosmetic::getCosmetic("shower gel");
    cout<<gel->kind<<endl;
    Cosmetic* shampoo  = Cosmetic::getCosmetic("hair shampoo");
    cout<<shampoo->kind<<endl;




return 0;
}

