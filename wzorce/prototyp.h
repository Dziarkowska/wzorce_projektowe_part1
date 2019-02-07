#include <cstdio>
#include <cstring>

using namespace std;


class AnimalPrototype
{
public:
    virtual AnimalPrototype * clone() const = 0;
    virtual void display() const = 0;
    virtual ~AnimalPrototype() { }
    int age=10;
     int getAge()
    {
         return age;
    }
    void setAge(int newage)
    {
        age=newage;
    }
};

class PolarAnimalPrototype
    : public AnimalPrototype
{
private:
    char * c_fur;
public:
    PolarAnimalPrototype( const char * s_fur )
        : c_fur( new char[strlen(s_fur) + 1] )
    {
        strcpy(c_fur, s_fur);
    }
   
    PolarAnimalPrototype( const PolarAnimalPrototype & copy )
        : c_fur( new char[strlen(copy.c_fur)+1] )
    {
        strcpy(c_fur, copy.c_fur);
    }
   
    virtual ~PolarAnimalPrototype(){
        delete[] c_fur;
    }

    virtual AnimalPrototype * clone() const
    {
        return new PolarAnimalPrototype( * this );
    }

    virtual void display() const
    {
        cout<<"fur: "<<c_fur<<endl<<"age: "<<age<<endl;

    }
};

//class CMyPrototype2
 //   : public IPrototype //INFO: konkretny prototyp
//{
  //  virtual IPrototype * clone() const
    //{
      //  return NULL; //INFO: klonowanie obiektu zabronione
    //}
//};



