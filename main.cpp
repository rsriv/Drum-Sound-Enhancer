//'hears' kick and snare from 10s simulated audio input stream and creates drum objects with correct timestamp 
#include <iostream>
using namespace std;

#define MIN_BASS_FREQ 1 //tbd actual values
#define MAX_BASS_FREQ 2
#define MIN_SNARE_FREQ 1
#define MAX_SNARE_FREQ 2
int randBetween (int min, int max){
    return rand()%(max-min)+min;
}
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
        cout<<"Kick created";
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
        cout<<"Snare created";
    }
    void play (){
        cout<<"Snare"<<endl;
    }
};

int main() {
    
    //initialize 10 second simulated audio input stream - 0 is nothing, 1 is kick, 2 is snare
    int aInStream [10000];
    const clock_t start2 = clock();
    int j = 0;
    for (int i = 0; i<1E4;i++){
        const int currentTime = int(clock() - start2)/(CLOCKS_PER_SEC/1000);
        if (currentTime!=j){
            int n = randBetween(0, 2000);
            if  (n == 1){
                aInStream[i] = 1;
            }
            else if  (n == 2){
                aInStream[i] = 2;
            }
            else {
                aInStream[i] = 0;
            }
            j++;
        }
        
    }

    const clock_t start = clock();
    int i = 0;
    
    while (i<1E4){
        const int currentTime = int(clock() - start)/(CLOCKS_PER_SEC/1000);
        if (currentTime!=i){
            
            cout<<currentTime<<endl;
            
            //Equivalent to hearing kick
            if (aInStream[i] == 1){
                Kick kick (currentTime,MIN_BASS_FREQ,MAX_BASS_FREQ); // add to linked list
            }
            
            //Equivalent to hearing snare
            if (aInStream[i] == 2){
                Snare snare (currentTime,MIN_SNARE_FREQ,MAX_SNARE_FREQ); // add to linked list
            }
            i++;
        }
        
    }
    
    //Module to play kick and snare piano roll goes here
    
    return 0;
}
