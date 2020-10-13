#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    BYTE buffer[BLOCK_SIZE];
    int n = 0;
    char filename[FILE_NAME_SIZE];

    FILE *img;

    while (fread(buffer, 1, BLOCK_SIZE, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (n != 0)
            {
                fclose(img);
            }
            snprintf(filename, sizeof(filename), "%03i.jpg", n++);
            img = fopen(filename, "w");
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
        else if (n > 0)
        {
            snprintf(filename, sizeof(filename), "%03i.jpg", n);
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }

    }

    fclose(file);
    fclose(img);
    return 0;
}
