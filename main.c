#include <stdio.h>
#include <string.h>

#define C_EXIT "exit"
#define ASCII

char buff[512];

int main(){
    printf("OpenSource KarlX Project\n");
    while (1){
        printf("CMND/> ");
        fgets(buff, (sizeof(buff) - 2),stdin);
        buff[strcspn(buff,"\n")] = 0;

        if (strcmp(buff,C_EXIT) == 0) {
            printf("Exiting...");
            break;
        } else if (strcmp(buff,"echo") == 0) {

        }
        
    }
}