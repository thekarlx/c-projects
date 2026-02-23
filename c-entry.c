#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

char buff[512];
char fname[] = "vemo.txt";
uint8_t vemo = 0;

FILE *fp;

int main() {
    printf("OpenSource KarlX Project\n");

    while (1) {
        printf("/> ");
        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = 0;

        for (int i = 0; buff[i] != '\0'; i++) {
            buff[i] = tolower(buff[i]);
        }

        if (vemo == 1) {
            printf("[Verbose] Entrada procesada: %s\n", buff);
        }

        if (strcmp(buff, "exit") == 0) {
            printf("Exiting...\n");
            break;

        } else if (strcmp(buff, "vemo") == 0) {
            printf("Verbose Mode (-s to see status, -t to toggle)\n");

        } else if (strcmp(buff, "vemo -s") == 0) {
            int state;

            fp = fopen(fname, "r");
            if (fp != NULL) {
                if (fscanf(fp, "%d", &state) == 1) {
                    vemo = (uint8_t)state;
                }
                fclose(fp);
            } else {
                printf("No se pudo abrir %s, usando valor por defecto.\n", fname);
            }

            switch (vemo) {
                case 0:
                    printf("Vemo is off.\n");
                    break;
                case 1:
                    printf("Vemo is on.\n");
                    break;
            }

        } else if (strcmp(buff, "vemo -t") == 0) {
            vemo = !vemo;

            fp = fopen(fname, "w");
            if (fp != NULL) {
                fprintf(fp, "%d\n", vemo);
                fclose(fp);
            }

            printf("Vemo toggled %s\n", vemo ? "on" : "off");
        }
    }

    return 0;
    
}