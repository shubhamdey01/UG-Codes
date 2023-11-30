#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
int i;
struct stat s;
if (argc < 2)
{
cout<<"\n enter filename in";
//exit();
}
for(i=1;i<argc; i++)
{
cout<<"File : "<<argv[i]<<"\n";
if(stat(argv[i],&s)<0)
cout<<"error in obtaining stats In";
else
{
cout<<"owner UID : "; cout<<s.st_uid; cout<<"\n";
cout<<"group ID :"; cout<<s.st_gid; cout<<"\n";
cout<<"Acess permissions : "; cout<<s.st_mode; cout<<"\n";
cout<<"Acess Time : ";cout<<s.st_atime; cout<<"\n";
cout<<"File Size : "; cout<<s.st_size; cout<<"\n";
cout<<"File Size(in blocks) : "; cout<<s.st_blksize; cout<<"\n";
}
}
return 0;
}