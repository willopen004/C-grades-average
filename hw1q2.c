#include <stdio.h>

#define UPPER_CASE_OFFSET ('A' - 'a')
#define MAX_ASCII 1000000000 // Maximal value of concatenated ASCIIs in the password
#define THREE_CHARS_MULTIPLIER 1000
#define TWO_CHARS_MULTIPLIER 100
#define FALSE 0
#define TRUE 1

int main()
{
    printf("Welcome to the Password Generator!\n");
    printf("Please enter your first name (lower-case):\n");
    char inputChar = 0; // input character, assumed lowercased
    scanf(" %c", &inputChar);
    int caseOffset = UPPER_CASE_OFFSET; // "case converter", converts to upper case or doesn't convert (0)

    long ASCII = 0; // contains ASCIIs concatenation
    int ASCIIMultiplier = 0; // concatenated ASCIIs multiplier, so that the next ASCII can be concatenated by addition
    int noMoreASCII = FALSE; // 0 if we can keep concatenate ASCIIs, 1 else.

    printf("Your Password: ");

    while (inputChar != '.')
    {
        inputChar += caseOffset; // convert to upper-case if needed

        ASCIIMultiplier = (inputChar >= 100) ? (THREE_CHARS_MULTIPLIER) : (TWO_CHARS_MULTIPLIER);
        // check if concatenating the next ASCII is possible.
        // note: multiplication isn't used here to avoid overflow.
        if (ASCII <= (MAX_ASCII - inputChar) / ASCIIMultiplier && noMoreASCII == FALSE)
        {
            ASCII *= ASCIIMultiplier;
            ASCII += inputChar;
        }
        else // can't concatenate any more ASCIIs
        {
            noMoreASCII = TRUE;
        }

        printf("%c", inputChar);

        if (caseOffset == 0)
        {
            caseOffset = UPPER_CASE_OFFSET;
        }
        else // caseOffset is 'A' - 'a'
        {
            caseOffset = 0;
        }
        scanf("%c", &inputChar);
    }
    // check if the first 2 chars of "TheMighty" should be concatenated:
    if (ASCII <= MAX_ASCII / TWO_CHARS_MULTIPLIER && noMoreASCII == FALSE)
    {
        ASCII = ASCII * TWO_CHARS_MULTIPLIER + 'T';
    }
    if (ASCII <= MAX_ASCII / THREE_CHARS_MULTIPLIER && noMoreASCII == FALSE)
    {
        ASCII = ASCII * THREE_CHARS_MULTIPLIER + 'h';
    }
    if (ASCII <= MAX_ASCII / THREE_CHARS_MULTIPLIER && noMoreASCII == FALSE)
    {
        ASCII = ASCII * THREE_CHARS_MULTIPLIER + 'e';
    }
    printf("TheMighty%ld\n", ASCII);

    return 0;
}
