#include <iostream>
#include <string>
#include <pthread.h>
#include <mutex>

/// Singelton class example

class SingeltonAbstract
{

    static SingeltonAbstract *instance;
    static pthread_mutex_t mutex;
    static void init_Instance() {
        if (instance ==  nullptr) { 
            instance = new SingeltonAbstract();
        }
    };


protected:
    SingeltonAbstract();
    virtual ~SingeltonAbstract();
    virtual void makeAbstract() = 0;

public:
    static SingeltonAbstract* getInstance(){
        if(instance == nullptr){
            pthread_mutex_lock(&mutex);
            if(instance == nullptr)
                {
                    init_Instance();
                }
            
            pthread_mutex_unlock(&mutex);
        } 

        return instance;
    };
};

SingeltonAbstract* SingeltonAbstract::instance = nullptr;
pthread_mutex_t SingeltonAbstract::mutex = PTHREAD_MUTEX_INITIALIZER;
