#ifndef DIRECTORY_ELEMENT_H
#define DIRECTORY_ELEMENT_H

const int NMAX=100;

class Directory_Element
{
 private:
 char name[NMAX],extension[NMAX];

 public:
 void Set_name(char *_name);
 void Extract_extension();
 char *Get_name();
 char *Get_extension();
 bool Is_directory();
};

#endif //DIRECTORY_ELEMENT_H
