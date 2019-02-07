#include <string>
#include <iostream>
#include <memory>
using namespace std;

// "Product"
class Outfit
{
public:
    void setPants(const string& pants){
        m_pants = pants;
    }
    void setJacket(const string& jacket){
        m_jacket = jacket;
    }
    void setShoes(const string& shoes){
        m_shoes = shoes;
    }
    void setWarmth(const int& warmth){
        m_warmth = warmth;
    }
    void show() const
    {
        cout<<"Outfit contains: "<<m_pants<<", "<< m_jacket<<", "<<m_shoes<<endl<<"Warmth level: "<<m_warmth<<endl;           
    }

private:
    string m_pants;
    string m_jacket;
    string m_shoes;
    int m_warmth;
};

// "Abstract Builder"
class OutfitBuilder
{
public:
    virtual ~OutfitBuilder() {};

    Outfit* getOutfit()
    {
        return m_outfit.release();
    }
    void createNewOutfitProduct()
    {
        m_outfit = make_unique<Outfit>();
    }
    virtual void buildPants() = 0;
    virtual void buildJacket() = 0;
    virtual void buildShoes() = 0;
    virtual void buildWarmth() = 0;
protected:
    unique_ptr<Outfit> m_outfit;
};

//----------------------------------------------------------------

class WarmOutfitBuilder : public OutfitBuilder
{
public:
    virtual ~WarmOutfitBuilder() {};

    virtual void buildPants(){
        m_outfit->setPants("shorts");
    }
    virtual void buildJacket(){
        m_outfit->setJacket("Denim Jacket");
    }
    virtual void buildShoes(){
        m_outfit->setShoes("Trainers");
    }
    virtual void buildWarmth(){
        m_outfit->setWarmth(1);
    } 
};

class ColdOutfitBuilder : public OutfitBuilder
{
public:
    virtual ~ColdOutfitBuilder() {};

    virtual void buildPants(){
        m_outfit->setPants("Thermoactive pants");
    }
    virtual void buildJacket(){
        m_outfit->setJacket("Membrane10000 Waterproof Jacket");
    }
    virtual void buildShoes(){
        m_outfit->setShoes("Trecking Shoes");
    }
    virtual void buildWarmth(){
        m_outfit->setWarmth(50);
    } 
};

//----------------------------------------------------------------

class Menager
{
public:
    void showOutfit()
    {
        m_outfitBuilder->getOutfit()->show();
    }
    void chooseOutfit(OutfitBuilder* pb)
    {
        m_outfitBuilder = pb;
        m_outfitBuilder->createNewOutfitProduct();
        m_outfitBuilder->buildPants();
        m_outfitBuilder->buildJacket();
        m_outfitBuilder->buildShoes();
        m_outfitBuilder->buildWarmth();
    }
private:
    OutfitBuilder* m_outfitBuilder;
};
