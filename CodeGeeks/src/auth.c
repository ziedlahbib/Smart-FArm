#include <stdio.h>
#include "auth.h" 

int verifier(char username[],char password[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];

f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{
if((strcmp(ch1,username)==0)&&(strcmp(ch2,password)==0))
trouve=1;
}
fclose(f);
}
return (trouve) ;
}
