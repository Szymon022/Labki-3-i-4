#include "IFile.h"
#include "FileFactory.h"
#include <iostream>
using namespace std;

int main()
{
    IFile *file = FileFactory::Open("test.bin", "r");

    vector<Point> v;
    Point p;

    file -> Read(p, 0);

    cout<<p.x<<endl;
    cout<<p.y<<endl;
    cout<<p.z<<endl;



    return 0;
}
