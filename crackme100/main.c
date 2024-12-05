#include <stdio.h>
#include <string.h>

void decode_password(char *buf, int len)
{
    int i = 0;
    int j;

    unsigned int pattern;
    int temp;

    for (; i < 3; i++) // this just runs the same thing 3 times
    {
        for (j = 0; j < len; j++) // for each char in buf
        {
            pattern = (j % 0xff >> 1 & 0x55U) + (j % 0xff & 0x55U);
            pattern = ((int)pattern >> 2 & 0x33U) + (pattern & 0x33); // same 2 lines as the encoder

            int shift = pattern >> 4;
            int and = pattern & 0xf;

            temp = buf[j] - 'a';
            temp = temp + 0x1a * (temp < 0);
            temp = temp - shift - and;
            buf[j] = temp + 0x61;
        }
    }
}

int main()
{
    char encoded_password[] = "ztqittwtxtieyfrslgtzuxovlfdnbrsnlrvyhhsdxxrfoxnjbl";

    decode_password(encoded_password, strlen(encoded_password));

    printf("%s\n", encoded_password);
}