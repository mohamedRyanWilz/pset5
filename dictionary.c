/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <ctype.h>
#include<stdlib.h>
#include<string.h>
#include "dictionary.h"


node * arr[27]; 
int hash(char * word){
 int num=toupper(word[0])-'A';
return num;
 }
/**
 * Returns true if word is in dictionary else false.
 */

int digo(char* word){
int sum=0;
for(int i=0;word[i]!='\0';i++)
sum++;
return sum;
}

 bool comp(char *x,char *y,int sum){
 int c=0,si=0;
 si=digo(x);
 si--; 
 if(si==sum||si==43){
 if(si==43)
 si++;
 for(int i=0;i<si;i++){
 if(toupper(x[i])==toupper(y[i])){

 c++;
 continue;
 
 }
 c=0;
 break;
 }
 
 if(c==0){
 return false;
 }
 else{
 return true;
 }
 }
 return false;
 }

bool check(const char* word)
{
int sum=digo((char *)word);
if(sum<1||sum>46){
return false;
}
    int pos=hash((char*)word);
   node * ptr=arr[pos];
   while(ptr!=NULL){
  bool k=comp(ptr->words,(char*)word,sum);
   if(k)
   {
   return true;
   }
  
  ptr=ptr->next;
   }
   return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 
 
bool load(const char* dictionary)
{
  FILE* doc=fopen(dictionary,"r");
  int position=0;
 
  for(int x=0;x<27;x++){
  arr[x]=NULL;
  }
  char word[46];
   if (doc == NULL)
    {
        return false;
    }
    
  else{
  int i=0;
   while(fgets(word,LENGTH,doc)!=NULL){
  position=hash(word); 
   node * new=(node*)malloc(sizeof(node));
   if(new==NULL){
   return false;
   }
   strcpy(new->words,word);
   siz=i+1;
   new->next=arr[position];
   arr[position]=new;
   i++;
   }
   return true;
   
   }
   
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    unsigned int size=siz;
    //printf("the size:%u\n",size);
    return size;
    
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
     node * ptr;
     int x=0;
    for(int i=0;i<27;i++){
    ptr=arr[i];
    while(ptr!=NULL){
    ptr=arr[i]->next;
    free(arr[i]);
    arr[i]=ptr;
    }
    x++;
    }
    if(x!=0){
    return true;
    }
    return false;
}
