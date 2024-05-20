#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    else
    {
        FILE *file = fopen(argv[1], "r");

        char *fileName = argv[1];

        if (file == NULL)
        {
            printf("Error: cannot open %s\n", fileName);
            return 2;
        }

        uint8_t buffer[512];

        FILE *newImg = NULL;

        char newImgName[8];

        int newImg_counter = 0;

        while (fread(&buffer, 1, 512, file) == 512)
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if (newImg != NULL)
                {
                    fclose(newImg);
                }

                sprintf(newImgName, "%03i.jpg", newImg_counter);
                newImg = fopen(newImgName, "w");
                ++newImg_counter;
            }
            if (newImg != NULL)
            {
                fwrite(&buffer, 1, 512, newImg);
            }
        }

        fclose(newImg);
        fclose(file);
    }
}
