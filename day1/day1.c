#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    char line[256];
    FILE *day1_p;
    day1_p = fopen(argv[1], "r");

    if (day1_p == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), day1_p) != NULL)
    {
        // printf("%s", line); // Process the line here
        int first_found = 0;
        int first = -1;
        int last = -1;

        for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++)
        {

            if (isdigit(line[i]))
            {
                int num = line[i] - '0';
                if (!first_found)
                {
                    first = num;
                    first_found = 1;
                }
                last = num;
            }
        }
        if (first_found)
        {
            int pow = 10;
            int combo = first * pow + last;
            int sum;
            sum += combo;
            //printf("%d", combo);
            //printf("\n");
            printf("%d", sum);
            printf("\n");
            // first_found = 0;
        }
    }

    fclose(day1_p);
    return 0;
}