#include<stdio.h>
int main()
{
    int i;
    for(i=1;i<=10;i++){
        printf("%d:Arsenal is the best team in the English Premier League\n",i);
    }
    do{
        printf("%d:Arsenal is the best team in the English Premier League\n",i);
        i++;
    }
        while(i<=20); 
    
    return 0;
}