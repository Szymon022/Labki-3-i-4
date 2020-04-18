#include "IFile.h"
#include "FileFactory.h"
#include <iostream>
using namespace std;

int main()
{
    vector<Point> v;
    Point b[5];
    Point p;

    cout <<  "Writing 5 points to CSV File test\n";
    IFile * file = FileFactory::Open("test1.csv", "w");

    for(int i = 0; i < 5; i++)
    {
        b[i].x = i*10;
        b[i].y = i*10+1;
        b[i].z = i*10+2;
        v.push_back(b[i]);
    }

    int status = file -> Write(v);
    if (status == IFile::SUCCESS)
        cout<<"SUCCESS"<<endl;
    else if(status == IFile::ACCESS_DENIED)
        cout<<"ACCESS_DENIED"<<endl;

    delete file;

//---------------------------------------------------------
    cout <<  "\n\nReading 5 points from CSV test\n";

    file = FileFactory::Open("test1.csv", "r");

    status = file -> Read(v);

    if (status == IFile::SUCCESS)
    {
        for(int i = 0; i < 5; i++)
        {
            cout << v[i].x << " " << v[i].y << " " << v[i].z << endl;
        }
        cout<< "SUCCESS";
    }
    else if(status == IFile::ACCESS_DENIED)
        cout << "Access denied" << endl;
    else if(status == IFile::OUT_OF_BOUNDS)
        cout << "Out of bounds" << endl;



    cout<<"\n\nReading 3rd line of CSV file\n";
    file = FileFactory::Open("test1.csv", "r");

    status = file -> Read(p, 2);

    if (status == IFile::SUCCESS)
    {
        cout<<p.x<<" "<<p.y<<" "<<p.z<<"\n";
        cout<<"SUCCESS"<<endl;
    }
    else if(status == IFile::ACCESS_DENIED)
        cout<<"ACCESS_DENIED"<<endl;
    else if(status == IFile::OUT_OF_BOUNDS)
        cout<<"OUT OF BOUNDS"<<endl;



    cout<<"\n\nReading 7th line of CSV file\n";

    status = file -> Read(p, 6);

    if (status == IFile::SUCCESS)
    {
        cout<<p.x<<" "<<p.y<<" "<<p.z<<"\n";
        cout<<"SUCCESS"<<endl;
    }
    else if(status == IFile::ACCESS_DENIED)
        cout<<"ACCESS_DENIED"<<endl;
    else if(status == IFile::OUT_OF_BOUNDS)
        cout<<"OUT OF BOUNDS"<<endl;

    delete file;

//---------------------------------------------------------

    cout <<  "\n\nWriting 5 points to BINARY file test\n";

    file = FileFactory::Open("test1.bin", "w");
    v.clear();
    for(int i = 0; i < 5; i++)
    {
        b[i].x = i*100;
        b[i].y = i*100+1;
        b[i].z = i*100+2;
        v.push_back(b[i]);
    }

    status = file -> Write(v);
    if (status == IFile::SUCCESS)
        cout<<"SUCCESS"<<endl;
    else if(status == IFile::ACCESS_DENIED)
        cout<<"ACCESS_DENIED"<<endl;

    delete file;

//---------------------------------------------------------

    file = FileFactory::Open("test1.bin", "r");

    status = file -> Read(v);
    cout <<  "\n\nReading 5 points from BIN test\n";
    if (status == IFile::SUCCESS)
    {
        for(int i = 0; i < 5; i++)
        {
            cout << v[i].x << " " << v[i].y << " " << v[i].z << endl;
        }
        cout<< "SUCCESS";
    }
    else if(status == IFile::ACCESS_DENIED)
        cout << "Access denied" << endl;
    else if(status == IFile::OUT_OF_BOUNDS)
        cout << "Out of bounds" << endl;

//---------------------------------------------------------

    cout<<"\n\nReading 3rd line of BIN file\n";

    status = file -> Read(p, 3);

    if (status == IFile::SUCCESS)
    {
        cout<<p.x<<" "<<p.y<<" "<<p.z<<"\n";
        cout<<"SUCCESS"<<endl;
    }
    else if(status == IFile::ACCESS_DENIED)
        cout<<"ACCESS_DENIED"<<endl;
    else if(status == IFile::OUT_OF_BOUNDS)
        cout<<"OUT OF BOUNDS"<<endl;


    cout<<"\n\nReading 7th line of BIN file\n";

    status = file -> Read(p, 6);

    if (status == IFile::SUCCESS)
    {
        cout<<p.x<<" "<<p.y<<" "<<p.z<<"\n";
        cout<<"SUCCESS"<<endl;
    }
    else if(status == IFile::ACCESS_DENIED)
        cout<<"ACCESS_DENIED"<<endl;
    else if(status == IFile::OUT_OF_BOUNDS)
        cout<<"OUT OF BOUNDS"<<endl;

    delete file;

    return 0;
}
