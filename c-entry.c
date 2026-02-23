#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

char buff[512];
uint8_t vemo = 0;

int main(){
    printf("OpenSource KarlX Project\n");
    while (1){
        printf("/> ");
        fgets(buff, (sizeof(buff)),stdin);
        buff[strcspn(buff,"\n")] = 0;
        for (int i = 0; buff[i] != '\0'; i++) {
            buff[i] = tolower(buff[i]);
        }

        if (strcmp(buff,"exit") == 0) {
            printf("Exiting...\n");
            break;
        } else if (strcmp(buff,"vemo") == 0) {
            printf("Verbose Mode (-s to see status, -t to toggle)\n");
        } else if (strcmp(buff, "vemo -s") == 0) {

            switch (vemo) {
                
                case 0:
                    printf("Vemo is off.\n");
                break;

                case 1:
                    printf("Vemo is on.\n");
                break;

            }
            
        } else if (strcmp(buff,"vemo -t") == 0) {
            if (vemo == 0) {
                vemo = 1;
            } else if (vemo == 1) {
                vemo = 0;
            }

        }
    }
}