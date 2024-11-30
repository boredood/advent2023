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
    int sum = 0;
    while (fgets(line, sizeof(line), day1_p) != NULL)
    {
        // printf("%s", line); // Process the line here
        int first_found = 0;
        int first = -1;
        int last = -1;
        char *words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++)
        {
            if (isdigit(line[i]))
            {
                // handles digits
                int num = line[i] - '0';
                if (!first_found)
                {
                    first = num;
                    first_found = 1;
                }
                last = num;
            }
            else
            {
                // handles word numbers
                for (int j = 0; j < 10; j++)
                {
                    if (strncmp(&line[i], words[j], strlen(words[j])) == 0)
                    {
                        int num = j;
                        if (!first_found)
                        {
                            first = num;
                            first_found = 1;
                        }
                        last = num;

                        //i += strlen(words[j]) - 1;
                        break;
                    }
                }
            }
        }
        if (first_found)
        {
            int combo = first * 10 + last;
            sum += combo;
            printf("First: %d, Last: %d, Combo: %d, Sum: %d\n", first, last, combo, sum);
        }
    }

    fclose(day1_p);
    return 0;
}