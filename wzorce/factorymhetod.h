#include <iostream>
#include <string>

class Cosmetic
{
    public:
        Cosmetic() :kind(""){
        }
        std::string kind;
        /* This is the factory method. */
        static Cosmetic* getCosmetic(std::string kind);
};

class Gel : public Cosmetic
{
    public:
        Gel(){
            kind = "shower gel";
        }
};

class Shampoo : public Cosmetic
{
    public:
        Shampoo(){
            kind = "hair shampoo";
        }
};

class Conditioner : public Cosmetic
{
    public:
        Conditioner(){
            kind = "conditioner";
        }
};

Cosmetic* Cosmetic::getCosmetic(std::string kind)
{
    if (kind == "shower gel")
        return new Gel();
    else if (kind == "hair shampoo")
        return new Shampoo();
    else if (kind == "conditioner")
        return new Conditioner();
    else
        return 0;
}
//----------------------------------------------------------------------------------abstract factory
