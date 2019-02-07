#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class PotentiallCorpse {
public:
  virtual int beTarget() = 0;
  virtual bool isDead() = 0;
};

class PolarWolf{
public:
  PolarWolf(){}
  int getTarget(){
    return 1;    
  }
  bool kill(){
    return 1;
  }
};

class PolarFox {
public:
  PolarFox(){}
  int infect(){
    return 1;
  }
  bool isdeadlyInfected(){
      return 1;
  }
};

class WolfAdapter : public PotentiallCorpse, private PolarWolf{
public:
  WolfAdapter(){}
  virtual int beTarget() {
    return getTarget();
  }
  virtual bool isDead() {
    return kill();
  }
};

class FoxAdapter : public PotentiallCorpse, private PolarFox{
public:
  FoxAdapter(){}
  int beTarget() {
    return infect();
  }
  virtual bool isDead(){
    return isdeadlyInfected();
  }
};
