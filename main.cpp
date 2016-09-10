
#include <unistd.h>
#include <iostream>
#include <thread>

using namespace std;

class Drum {
    public:
    unsigned int elapsedTime;
    
    //Frequency range
    unsigned int min;
    unsigned int max;

    Drum (unsigned int elapsedTime, unsigned int min, unsigned int max){
        this->min = min;
        this->max = max;
        this->elapsedTime = elapsedTime;
    }
    Drum(){}
    virtual void play(){}
};

void abc (){
    
}

class Kick : public Drum {
public:
    Kick (unsigned int elapsedTime, unsigned int min, unsigned int max){
        this->min = min;
        this->max = max;
        this->elapsedTime = elapsedTime;
    }
    void play (){
        cout<<"Kick"<<endl;
    }
};

class Snare : public Drum {
public:
    Snare (unsigned int elapsedTime, unsigned int min, unsigned int max){
        this->min = min;
        this->max = max;
        this->elapsedTime = elapsedTime;
    }
    void play (){
        cout<<"Snare"<<endl;
    }
};

int main() {
    
    Kick kick (0,1,2);
    kick.play();
    kick.play();
    const clock_t start = clock();
    int i = 0;

    while (true){
        const int currentTime = int(clock() - start)/(CLOCKS_PER_SEC/1000);
        if (currentTime!=i){
            cout<<currentTime<<endl;
            i++;
            // insert code here to be executed every millisecond
        }
        
    }
    
    return 0;
}
