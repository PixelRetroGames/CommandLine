#include "command_line.h"
#include <cstring>
#include <cstdio>

void Command_Line::Clear()
{
 current_directory.Clear();
 quit=false;
}

void Command_Line::Start(char *_path)
{
 strcpy(path,_path);
 strcpy(current_path,_path);
 current_directory.Load(current_path);
 while(!quit)
       {
        Print_path();
        char command_name[NMAX];
        strcpy(command_name,Read_string());
        Interpret_command(command_name);
       }
}

void Command_Line::Print_path()
{
 printf("%s>",current_path);
}

char *Command_Line::Read_string()
{
 char aux[NMAX];
 scanf("%s",aux);
 return aux;
}

char *Command_Line::Read_line()
{
 char aux[NMAX];
 gets(aux);
 int i=0;
 while(aux[i]==' ')
       i++;
 return aux+i;
}

void Command_Line::Interpret_command(char *command_name)
{
 int command_id=Get_command_id(command_name);
 switch(command_id)
        {
         case 1: quit=true;
                 break;
         case 2: Dir_Command();
                 break;
         case 3: Change_Dir_Command();
                 break;
         default: Unknown_Command_prompt();
        }
}

void Command_Line::Unknown_Command_prompt()
{
 printf("Unknown command. Type \"help\" to see the list of available commands.\n\n");
}

void Command_Line::Inexistent_directory_prompt()
{
 printf("The requested directory does not exist!\n\n");
}

void Command_Line::Dir_Command()
{
 printf("\nListing components of %s directory.\n\n",path);
 int number_of_elements=current_directory.Get_number_of_elements();
 for(int i=0;i<number_of_elements;i++)
     {
      Print_directory_element(current_directory.Get_element(i));
     }
 printf("\n");
}

void Command_Line::Print_directory_element(Directory_Element *element)
{
 int n=strlen(element->Get_name());
 char space[NMAX]={"                               "};
 printf("%s%s%s\n",element->Get_name(),space+n,element->Is_directory()?"DIR":"");
}

void Command_Line::Change_Dir_Command()
{
 char directory_name[NMAX];
 strcpy(directory_name,Read_line());
 if(strcmp(directory_name,"..")==0)
    {
     if(strcmp(current_path,path)==0)
        return;
     int i=strlen(current_path)-1;
     while(current_path[i]!='/' && current_path[i]!='\\')
           {
            current_path[i]=NULL;
            i--;
           }
     current_path[i]=NULL;
     i--;
     current_directory.Clear();
     current_directory.Load(current_path);
    }
 else
    {
     char aux[NMAX];
     strcpy(aux,current_path);
     strcat(aux,"/");
     strcat(aux,directory_name);
     Directory test;
     if(!test.Load(aux))
        {
         current_directory.Clear();
         current_directory=test;
         test.Clear();
         strcpy(current_path,aux);
        }
     else
        {
         Inexistent_directory_prompt();
        }
    }
}

const int number_of_supported_commands=3;
const char supported_commands[number_of_supported_commands][NMAX]={"exit","dir","cd"};

int Command_Line::Get_command_id(char *command_name)
{
 for(int i=0;i<number_of_supported_commands;i++)
     {
      if(strcmp(command_name,supported_commands[i])==0)
         return i+1;
     }
 return 0;
}
