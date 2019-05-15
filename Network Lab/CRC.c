#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
 
char t[100],cs[100],g[25];
int a,e,c,N;
void xor(){
    for(c = 1;c < N; c++)
    cs[c] = (( cs[c] == g[c])?'0':'1');
}
 
void crc(){
    for(e=0;e<N;e++)
        cs[e]=t[e];
    do{
        if(cs[0]=='1')
            xor();
        for(c=0;c<N-1;c++)
            cs[c]=cs[c+1];
        cs[c]=t[e++];
    }while(e<=a+N-1);
}
 
int main()
{
    srand(time(NULL));  
    printf("\nEnter data : ");
    scanf("%s",t);
    printf("\n----------------------------------------");
    printf("\n Enter length of generating Generatng polynomial : %s",g);
    scanf("%d",&N);
    for(c=0;c<N;c++){
        g[c]= rand()%2 + '0';
        //sprintf(g[c], "%d", rand()%2);
        }
    printf("\nGenerating polynomial is %s\n",g);
    a=strlen(t);
    for(e=a;e<a+N-1;e++)
        t[e]='0';
    printf("\n----------------------------------------");
    printf("\nModified data is : %s",t);
    printf("\n----------------------------------------");
    crc();
    printf("\nChecksum is : %s",cs);
    for(e=a;e<a+N-1;e++)
        t[e]=cs[e-a];
    printf("\n----------------------------------------");
    printf("\nFinal codeword is : %s",t);
    printf("\n----------------------------------------");
    printf("\nTest error detection 0(yes) 1(no)? : ");
    scanf("%d",&e);
    if(e==0)
    {
        do{
            printf("\nEnter the position where error is to be inserted : ");
            scanf("%d",&e);
        }while(e==0 || e>a+N-1);
        t[e-1]=(t[e-1]=='0')?'1':'0';
        printf("\n----------------------------------------");
        printf("\nErroneous data : %s\n",t);
    }
    crc();
    for(e=0;(e<N-1) && (cs[e]!='1');e++);
        if(e<N-1)
            printf("\nError detected\n\n");
        else
            printf("\nNo error detected\n\n");
            printf("\n----------------------------------------\n");
        return 0;
}

