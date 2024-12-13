#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL){
        return 1;
    }

    //create buffer
    unsigned char buffer[512];

    int cnt = 0;
    FILE *img = NULL;
    char *file = malloc(8*sizeof(char));

    while (fread(buffer, sizeof(char), 512, input_file) == 512){
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            if (img != NULL){
                fclose(img);
            }
            sprintf(file, "%03i.jpg", cnt);
            img = fopen(file, "wb");
            cnt++;
        }
        if (img != NULL){
            fwrite(buffer, sizeof(char), 512, img);
        }
    }
    fclose(img);
    free(file);
    fclose(input_file);

    return 0;
}
