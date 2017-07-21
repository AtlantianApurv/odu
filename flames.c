#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct flames
{
char c;
struct flames *next;
}flames;

void main()
{
  char s1[20],s2[20],ch;
  int l1,l2,l3,count,match,unm=0,unms1=0,unms2=0,m=0;
  printf("Enter string s1\n");
    scanf("%s",s1);
  
  printf("Enter string s2\n");
    scanf("%s",s2);
  
  l1=strlen(s1);
  l2=strlen(s2);
  
  for(int i=0;i<l1;i++)
    for(int j=0;j<l2;j++)
      if(s1[i]==s2[j])
        {
            s1[i]=s2[j]='?';
            match=match+1;
            break;
        }
  
  printf("string s1 after cancellation %s\n",s1);
  printf("string s2 after cancellation %s\n",s2);
  
  for(int i=0;i<l1;i++)
    if(isalpha(s1[i])==0)
      unms1++;
  
  for(int i=0;i<l2;i++)
    if(isalpha(s2[i])==0)
      unms2++;
    
    unm=unms1+unms2;  
    
  strcat(s1,s2);
  l3=strlen(s1);
  unm=l3-unm;
  
  printf("total unmatched characters %d\n",unm);
  
  // Simple Approch
  if(unm == 2 ||unm== 4 || unm==7 ||unm==9 )
   printf("%s and %s FLAMES as ENEMY \n",s1,s2);
  else if( unm == 3 ||unm==5 || unm==14 ||unm==16 || unm==18 )
    printf("%s and %s FLAMES as FRIENDS\n",s1,s2);
  else if( unm == 8 || unm==12 || unm==17)
    printf("%s and %s FLAMES as AFFECTION\n ",s1,s2);
  else if( unm == 10)
    printf("%s and %s FLAMES as LOVE \n",s1,s2);
  else if( unm == 6 || unm==11 || unm==15)
    printf("%s and %s FLAMES as MARRIGE \n",s1,s2);
  else
   printf("%s and %s FLAMES as SIBLINGS\n ",s1,s2); 
  
  
  //Circular linked list Approch
  
  flames *head,*ne2,*ne3,*ne4,*ne5,*ne6,*temp,*present;
  
  head=(struct flames*)malloc(sizeof(struct flames));
  ne2=(struct flames*)malloc(sizeof(struct flames));
  ne3=(struct flames*)malloc(sizeof(struct flames));
  ne4=(struct flames*)malloc(sizeof(struct flames));
  ne5=(struct flames*)malloc(sizeof(struct flames));
  ne6=(struct flames*)malloc(sizeof(struct flames));

  head->c='f'; head->next=ne2;
  ne2->c='l'; ne2->next=ne3;
  ne3->c='a'; ne3->next=ne4;
  ne4->c='m'; ne4->next=ne5;
  ne5->c='e'; ne5->next=ne6;
  ne6->c='s'; ne6->next=head;
  
  temp=head;
  int i=0;
  while(i<6)
  {
    printf(" %c",temp->c-32);
    temp=temp->next;
    i++;
  }
  printf("\n");

  temp=head;
  while(m<5)
  { 
      for(i=0;i<unm-2;i++)
    
      temp=temp->next;
      printf("\nDeleting %c\n",temp->next->c);
    
      present=temp->next;
      
      temp->next=temp->next->next;
      
      temp=temp->next;
      free(present);
      m++;
  }
  ch=temp->c;
  switch(ch)
  {
    case 'f':
      printf("FRIENDS\n");
      break;


    case 'l':
      printf("LOVE\n");
      break;

    case 'a':
      printf("AFFECTION\n");
      break;

    case 'm':
      printf("MARRIAGE\n");
      break;

    case 'e':
      printf("ENEMY\n");
      break;

    case 's':
      printf("SIBLINGS\n");
      break;
    default: printf("invalid string match \n");
      break;
      
    
  } 
}
