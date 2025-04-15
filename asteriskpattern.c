# include <stdio.h>
char space = ' ';
int main(){
    for (int i=1;i<=6;i++){// loop for 5 rows
        for(int j=6 ;j>=i;j--){// loop for printing asterisks
            printf("*");
        }
        printf("\n");
        for (int k=1;k<=i;k++){// loop for adding the spacing
            printf("%c",space);
        }
    
    }
    return 0;
}