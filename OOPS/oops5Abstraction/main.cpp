#include <iostream>
#include "bird.h"
using namespace std;
//THis folder is an abstract design strategy
//in abstract design, implementation(bird.h) and interface(main.cpp) are seperated.


void birdDoesSomething(Bird *bird)
{
    bird->eat();
    bird->fly();
}
int main()
{
    // Bird *bird = new Sparrow();
    // Bird *bird = new Eagle();
    Bird *bird = new Pigeion();
    birdDoesSomething(bird);
    // interface same h but functionality alag ho skti h ya changes ho skte h humme code mai koi change nhi krna
    return 0;
}
