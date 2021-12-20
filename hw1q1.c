#include <stdio.h>

#define EXIT_GRADE -1
#define TEN_PERCENT 10 / 100
#define CONST_BONUS 2
#define ROUND_GRADE_BONUS 1
#define MAX_GRADE 100
#define MIN_GRADE 0

int main()
{
    int gradesSum = 0; // sum of grades so far, for average calculation
    int gradesNumber = 0; // number of grades so far, for average calculations
    int grade = 0; // used for the input and output grade
    printf("Please enter grade:\n");
    scanf("%d",&grade);

    // while grade is out of range:
    while ((grade < MIN_GRADE || grade > MAX_GRADE) && grade != EXIT_GRADE)
    {
        printf("Invalid grade. Please enter grade:\n");
        scanf("%d",&grade);
    }

    // calculate & print grade after factor and read a new grade in every iteration
    while (grade != EXIT_GRADE)
    {
        // Add 10% to the grade, round up if needed:
        if (grade % 10 != 0)
        {
            // 10% of the grade is a fraction, need to add 1 to round up
            grade += (double)grade * TEN_PERCENT;
            grade++;
        }
        else
        {
            // 10% of the grade is a whole number no need to add 1 to round up
            grade += (double)grade * TEN_PERCENT;
        }

        grade += CONST_BONUS; // Add constant bonus
        if (grade % 10 == 0) // Add round grade bonus if needed
        {
           grade += ROUND_GRADE_BONUS;
        }

        if (grade > MAX_GRADE) // check if grade is out of range
        {
            grade = MAX_GRADE;
        }
        gradesSum += grade;
        gradesNumber++;

        printf("Final grade: %d\n", grade);
        printf("Current average after factor: %.2f\n\n", (double)gradesSum / gradesNumber);

        printf("Please enter grade:\n");
        scanf("%d",&grade);
        // while grade is out of range:
        while ((grade < MIN_GRADE || grade > MAX_GRADE) && grade != EXIT_GRADE)
        {
            printf("Invalid grade. Please enter grade:\n");
            scanf("%d",&grade);
        }
    }
    return 0;
}
