#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#include <windows.h>  // Shell commands (Windows only)

#pragma comment(lib, "Shell32.lib")

int state;

char buff[512];
char vemo_fname[] = "vemo";
uint8_t vemo = 0;

FILE *fp;

int main() {

    fp = fopen(vemo_fname, "r");
    if (fp != NULL) {
        if (fscanf(fp, "%d", &state) == 1) {
            vemo = (uint8_t)state;
        }
        fclose(fp);
    }

    printf("OpenSource KarlX Project\n");

    while (1) {

        printf("/> ");

        if (!fgets(buff, sizeof(buff), stdin))
            break;

        buff[strcspn(buff, "\n")] = 0;

        for (int i = 0; buff[i] != '\0'; i++) {
            buff[i] = tolower((unsigned char)buff[i]);
        }

        if (vemo) {
            printf("  [VeMo] Processed input: %s\n", buff);
        }

        if (strcmp(buff, "exit") == 0) {
            printf("Exiting...\n");
            break;

        } else if (strcmp(buff, "vemo") == 0) {

            printf("Verbose Mode (-s to see status, -t to toggle)\n");

        } else if (strcmp(buff, "vemo -s") == 0) {

            fp = fopen(vemo_fname, "r");
            if (fp != NULL) {
                if (fscanf(fp, "%d", &state) == 1) {
                    vemo = (uint8_t)state;
                }
                fclose(fp);
            } else {
                printf("%s not found. Using default value (0/off).\n", vemo_fname);
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

            fp = fopen(vemo_fname, "w");
            if (fp != NULL) {
                fprintf(fp, "%d\n", vemo);
                fclose(fp);
            }

        } else if (strcmp(buff, "notepad") == 0) {

            ShellExecute(NULL, "open", "notepad", NULL, NULL, SW_SHOWNORMAL);

        } else if (strcmp(buff, "explorer") == 0) {

            ShellExecute(NULL, "open", "explorer", NULL, NULL, SW_SHOWNORMAL);

        } else if (strcmp(buff, "regedit") == 0) {

            ShellExecute(NULL, "open", "regedit", NULL, NULL, SW_SHOWNORMAL);

        } else if (strcmp(buff, "control") == 0) {

            ShellExecute(NULL, "open", "control", NULL, NULL, SW_SHOWNORMAL);

        } else if (strcmp(buff, "taskmgr") == 0) {

            ShellExecute(NULL, "open", "taskmgr", NULL, NULL, SW_SHOWNORMAL);
 
        }
    }

    return 0;
}