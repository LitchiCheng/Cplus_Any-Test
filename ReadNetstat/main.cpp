#include <iostream>
#include "../Utils/getCmdResult.h"

using namespace std;


int main(int argc, char const *argv[])
{
    int32_t _last_speed_val = 0;
    if(_last_speed_val == 0){
        string rt = getCmdResult("netstat -anp | egrep 'udp'");
        cout << rt << endl;
    }
    return 0;
}
