#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include "directory.h"

class Command_Line
{
 private:
 char path[NMAX],current_path[NMAX];
 bool quit=false;
 Directory current_directory;

 public:
 void Clear();
 void Start(char *_path);
 void Print_path();
 char *Read_string();
 char *Read_line();
 void Interpret_command(char *command_name);
 void Unknown_Command_prompt();
 void Inexistent_directory_prompt();
 void Dir_Command();
 void Print_directory_element(Directory_Element *element);
 void Change_Dir_Command();
 int Get_command_id(char *command_name);
};

#endif // COMMAND_LINE_H
