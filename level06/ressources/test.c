#include <stdio.h>

int main()
{
    int i;

    unsigned int local_14;
    char buffer[32] = "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHH";
    local_14 = ((int)buffer[3] ^ 4919) + 6221293;
    for (i = 0; i < 31; i++)
    {
        if (buffer[i] < ' ')
            return (1);
        local_14 += ((int)buffer[i] ^ local_14) % 1337;
    }
    printf("%u\n", local_14);
    return (0);
}