#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "directory_element.h"
#include <vector>

class Directory
{
 private:
 int number_of_elements;
 std::vector<Directory_Element> elements;

 public:
 void Clear();
 bool Load(char *path);
 bool Check_if_dir_exists(char *name);
 int Get_number_of_elements();
 Directory_Element *Get_element(int pos);
};

#endif //DIRECTORY_H
