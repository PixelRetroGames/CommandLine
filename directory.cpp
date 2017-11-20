#include "directory.h"
#include <cstring>
#include <cstdio>

void Directory::Clear()
{
 std::vector<Directory_Element>().swap(elements);
 number_of_elements=0;
}

bool Directory::Load(char *path)
{
 char aux[NMAX];
 strcpy(aux,path);
 strcat(aux,".dir");
 FILE *where=fopen(aux,"r");
 if(where==NULL)
    return true;
 fscanf(where,"%d ",&number_of_elements);
 for(int i=0;i<number_of_elements;i++)
     {
      char aux[NMAX];
      int sq;
      fgets(aux,sizeof aux,where);
      sq=strlen(aux);
      if(aux[sq-1]=='\n')
         aux[sq-1]=NULL;
      Directory_Element aux_elem;
      aux_elem.Set_name(aux);
      elements.push_back(aux_elem);
     }
 fclose(where);
}

bool Directory::Check_if_dir_exists(char *name)
{
 for(int i=0;i<number_of_elements;i++)
     if(strcmp(name,elements[i].Get_name())==0)
        return true;
 return false;
}

int Directory::Get_number_of_elements()
{
 return number_of_elements;
}

Directory_Element *Directory::Get_element(int pos)
{
 return &elements[pos];
}
