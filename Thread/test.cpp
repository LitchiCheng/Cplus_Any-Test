#include <iostream>
#include <vector>
#include <thread>

#include <mutex>
#include <shared_mutex>

#include <boost/thread/mutex.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/lock_types.hpp>
#include <boost/thread/lock_guard.hpp>

using namespace std;

std::vector<uint32_t> error_code_vector;
using readLock = boost::shared_lock<boost::shared_mutex>;                       
using writeLock = boost::unique_lock<boost::shared_mutex>;

boost::shared_mutex mutex1;
// boost::mutex mutex1;

void set(){
    printf("sssssssssssss \r\n");
    writeLock lock(mutex1);
    //boost::mutex::scoped_lock lock(mutex1);
    uint32_t code = 50444;
    error_code_vector.push_back(code);
}

void setErrCode()
{   
    while(1){
        set();
        // usleep(1000);
    }
        
}

void clear(){
    printf("ttttttttttttt \r\n");
    uint32_t code = 50444;
    readLock lock(mutex1);
    //boost::mutex::scoped_lock lock(mutex1);
    for (std::vector<uint32_t>::iterator iter = error_code_vector.begin(); iter != error_code_vector.end();iter++) {
        if (*iter == code){
            iter = error_code_vector.erase(iter);
            iter--;
        }
    }  
}

void clearErrCode()
{
    while(1){
        clear();
        //usleep(1001);
    }
}

int main(){
    std::thread t1(setErrCode);
    t1.detach();
    for (size_t i = 0; i < 2; i++)
    {
        std::thread tt(clearErrCode);
        tt.detach();
    }
    while(1){
        usleep(100000);
    }
    return 0;
}

//export LIBRARY_PATH=/usr/local/lib/boost_1_67_0/lib/:$LIBRARY_PATH
//g++ -o test test.cpp -I /usr/local/lib/boost_1_67_0/include -lpthread -lboost_thread -lboost_system
//3个线程，1个写容器，2个用容器（但也会修改容器），会崩溃


