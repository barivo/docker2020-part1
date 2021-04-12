#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Setting to allow fine-tuning the granularity of the readings */
#define INSERTS_PER_READING 1000

/* Take 60 readings */
#define NUM_READINGS 60


/*
*   Inserts a value into a dynamically allocated array of ints, returning 
*   a newly allocated array, and freeing the original array.
*
*   Prototype:
*   int *insert(int *array, int length, int index, int value);
*
*   Parameters:
*   array   The array of ints into which a new value should be inserted.
*   length  The number of elements in the array.
*   index   The location where the value should be inserted into the array.
*   value   The value that should be inserted into the array.
*
*   Return value:
*   A new array of ints containing the contents of the original array plus the new value
*   inserted at the given index. NULL will be returned should something goes wrong.
*/

/*
*   Overall Big-O performance of insert is 0(n)
*/
int *insert(int *array, int length, int index, int value)
{
    int *newArray = malloc(sizeof(*array) * length + 1);                        /* O(1) */

    if (newArray == NULL)                                                       /* O(1) */
    {
        fprintf(stderr, "Error: failed to allocate %i bytes.\n", length + 1);   /* O(1) */
        return NULL;                                                            /* O(1) */
    }

    if (length == 0)                                                            /* O(1) */
    {
        newArray[0] = value;                                                    /* O(1) */
    }
    else
    {
        for (int i = 0; i < index; i++)                                         /* O(n) */
        {
            newArray[i] = array[i];                                             /* O(1) */
        }

        newArray[index] = value;                                                /* O(1) */

        for (int i = index; i < length; i++)                                    /* O(n) */
        {
            newArray[i + 1] = array[i];                                         /* O(1) */
        }

        /* Free the old array */
        free(array);                                                            /* O(1) */
    }
    return newArray;                                                            /* O(1) */
}


int main()
{

    // FILE *output = fopen("outputHW1.txt", "w");
    clock_t startTicks;
    clock_t stopTicks;
    double elapsedSeconds;

    int *array = NULL;
    int length = 0;
    int readings = NUM_READINGS;
    int index = 0;
    int value = 0;

    printf("Array length\t\tSeconds per insert\n");

    while (readings--)
    {
        /* Get elapsed ticks prior to executing section of code */
        startTicks = clock();

        for (int i = 0; i < INSERTS_PER_READING; ++i)
        {
            /* Execute the section of code */

            if (length > 1)
            {
                index = rand() % (length + 1);
            }

            value = rand() % 101;
            array = insert(array, length, index, value);
            if (array == NULL)
            {
                fprintf(stderr, "Fatal: creating array failed");
                abort();
            }

            length++;
        }

        /* Get elapsed ticks after executing section of code */
        stopTicks = clock();

        /* Output time section of code took to complete */
        elapsedSeconds = (double)(stopTicks - startTicks) / CLOCKS_PER_SEC;
        // printf("Operation took %g seconds to complete.\n", elapsedSeconds);

        double t = elapsedSeconds / INSERTS_PER_READING;
        // fprintf(output, "%i, %f\n", length, t);
        /* Output reading in tabular format */
        printf("%10d\t%18.6f\n", length, t);   /* c */
    }
    // fclose(output);
}
