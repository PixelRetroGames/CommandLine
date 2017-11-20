#include "directory_element.h"
#include <cstring>
#include <cstdio>

void Directory_Element::Set_name(char *_name)
{
 strcpy(name,_name);
 memset(extension,0,sizeof extension);
 Extract_extension();
}

void Directory_Element::Extract_extension()
{
 int n=strlen(name),i=0;
 while(i<n && name[i]!='.')
       i++;
 int j=0;
 while(i<n)
       extension[j++]=name[i++];
}

char *Directory_Element::Get_name()
{
 return name;
}

char *Directory_Element::Get_extension()
{
 return extension;
}

bool Directory_Element::Is_directory()
{
 return strlen(extension)==0;
}
