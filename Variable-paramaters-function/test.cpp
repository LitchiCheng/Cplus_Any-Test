#include <iostream>

using namespace std;

template<typename T>
void show(T value){
    cout << "value " << value << endl;
}

//... Args叫模板参数包
//args叫函数参数包
//show(args...)会以一个参数递归函数参数包
template<typename T, typename... Args>
void show(T value, Args... args){
    cout << "value " << value << endl;
    show(args...);
}


int main(int argc, char const *argv[])
{
    show("sdfsdfs");
    show(12);
    show(12.44);

    show(1231,444,"555");
    return 0;
}
