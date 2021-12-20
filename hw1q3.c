#include <stdio.h>

#define MESSAGE1 "Hurray!"
#define MESSAGE2 "You Win!!"
#define MESSAGE3 "How do I get out of this rhombus?"

#define MESSAGE1_LEN 7
#define MESSAGE2_LEN 9
#define MESSAGE3_LEN 33

#define MIN_INDEX 1
#define MAX_INDEX 3

int main()
{
    printf("Please select message to print:\n");
    printf("Enter 1 for \"Hurray!\"\n");
    printf("Enter 2 for \"You Win!!\"\n");
    printf("Enter 3 for \"How do I get out of this rhombus?\"\n");
    int messageIndex = 0; // input index of chosen message
    scanf("%d", &messageIndex);
    while (messageIndex < MIN_INDEX || messageIndex > MAX_INDEX)
    {
        printf("Invalid message index, please enter an index between 1 and 3:\n");
        scanf("%d", &messageIndex);
    }

    int messageLength = 0; // length of chosen message
    switch (messageIndex)
    {
        case 1:
            messageLength = MESSAGE1_LEN;
            break;
        case 2:
            messageLength = MESSAGE2_LEN;
            break;
        case 3:
            messageLength = MESSAGE3_LEN;
            break;
    }

    printf("Please enter your favorite character:\n");
    char c = 0; // character used for rhombus edges
    scanf(" %c", &c);

    printf("Please enter edge length:\n");
    int edgeLength = 0; // number of characters in an edge
    scanf("%d", &edgeLength);
    while (2 * edgeLength - 1 < messageLength + 4)
    {
        printf("Invalid edge length, please enter a larger number:\n");
        scanf("%d", &edgeLength);
    }

    // Draw rhombus:
    int row_index = 0; // currently drawn raw index
    while (row_index < 2 * edgeLength - 1) // every iteration draws a single raw
    {
        int col_index = 0; // currently drawn col index
        // while the column index is in the rhombus:
        while (col_index <= edgeLength - 1 + row_index &&
               col_index <= 3 * (edgeLength - 1) - row_index)
        {
            // first check if it's time to print the message:
            if (row_index == edgeLength - 1 &&
                col_index == (2 * edgeLength - 1 - messageLength) / 2)
            {
                switch (messageIndex)
                {
                    case 1:
                        printf(MESSAGE1);
                        break;
                    case 2:
                        printf(MESSAGE2);
                        break;
                    case 3:
                        printf(MESSAGE3);
                        break;
                }
                col_index += messageLength;
            }
            // check if this location is an edge of the rhombus:
            else if (col_index == edgeLength - 1 - row_index ||
                     col_index == edgeLength - 1 + row_index ||
                     col_index == (-1) * (edgeLength - 1) + row_index ||
                     col_index == 3 * (edgeLength - 1) - row_index)
            {
                printf("%c", c);
                col_index++;
            }
            else // this location is not an edge and not the message
            {
                printf(" ");
                col_index++;
            }
        }
        printf("\n");
        row_index++;
    }

    return 0;
}

