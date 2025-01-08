#include <pthread>
#include <iostream>
#include <stdlib>

class Guard{
    pthread_mutex_t &mut;


    explicit Guard(pthread_mutex_t &mutex): mut(mutex){
        pthread_mutex_lock(&mut);
    } 

    ~Guard() { 
        pthread_mutex_unlock(&mut)
    }

    Guard(const Guard&) = delete;
    Guard& operator=(const Guard&) = delete;
}

void doSomething(int[] arr){
    for(i = 0 ; i<arr.size() ; i++){
        arr[i] += 1;
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10}
    pthread_mutex_t mutex;
    // we opened 4 threads 

    
    {
        Guard A(mutex);
        // Critical section 

        // end 

        // ~A
    } 
        
}