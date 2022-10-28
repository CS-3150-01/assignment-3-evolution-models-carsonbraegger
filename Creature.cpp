#include <iostream>
#include <time.h>
using namespace std;

class World{
    private:
    void environment();
    void creatureSpawn();



};

class Creature: public World{
   private: 
    int numOfCreature;
    double environment;
    double deathRate;
    double rRate;

    public:
    void death(){
        if(environment < 0){
            numOfCreature = numOfCreature - (numOfCreature * deathRate)-(environment*numOfCreature);
        }else{
            numOfCreature = numOfCreature - (numOfCreature * deathRate);
        }

    }

    void reproduction(){
        if(environment > 0){
            numOfCreature = numOfCreature + (numOfCreature * rRate) + (environment* numOfCreature);
        }else{
            numOfCreature = numOfCreature + (numOfCreature * rRate);
        }
    }
    
    

    void setEnvironment(double env){
        environment = env;
    }
    int getNumOfCreature(){
        return numOfCreature;
    }
    void setCreature(int num){
        numOfCreature = num;
    }
    void setDeathRate(double dRate){
        deathRate = dRate;
    }
    void setRepRate(double r){
        rRate = r;
    }
    

    

};

class CreatureSpawn: private World{
    private:
    int rnd;
    void creatureSpawn(){
        //This piece of code, I got from online---makes a random number from 0 to 1;
        srand((unsigned)time(NULL));
        rnd = (float) rand()/RAND_MAX;
    }

    public:
    int getRnd(){
        creatureSpawn();
        return rnd;
    }
};

int main(){
    Creature c1;
    double rnd = 0;
    CreatureSpawn s;
    string newCreature;
    string list[] = {"C2", "C3", "C4", "C5","C6", "C7","C8", "C9", "C10"};
    Creature cList[10] = {};
    int itr = 0;
    c1.setCreature(5);
    c1.setEnvironment(.6);
    bool test = true;
    while(test){
        c1.setDeathRate(.03);
        c1.setRepRate(.04);
        c1.reproduction();
        c1.death();
        rnd = s.getRnd();
        if(rnd >= .90){
            if(itr != 11){
                newCreature = list[itr];
                Creature newCreature;
                newCreature.setDeathRate(rnd+.25);
                newCreature.setRepRate(rnd-.12);
                cList[itr] = newCreature;
                itr++;
                if(rnd >= .95){
                        newCreature.setEnvironment(-rnd);
                }
                if(rnd >= .90 && rnd < .95){
                        newCreature.setEnvironment(rnd);
                }
                
                for(int i = 0; i < itr; i++){
                    cList[i].reproduction();
                    cList[i].death();
                }
            }
        }
    }
}