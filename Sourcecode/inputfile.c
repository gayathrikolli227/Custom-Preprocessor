/* Header file inclusion */
#include <myheader.h>

/* Macro definitions */
#define MESSAGE HELLO
#define PI 3.14

/* Main function */
int main()
{
        /* Radius declaration */
        int r=5;

        // Single-line comment (for testing comment removal)

        /* Variable to store calculated area */
        float area;

        /* Multi-line comment (for testing comment removal)
           Area Formula:
           PI * r * r
        */

        /* Area calculation using macro substitution */
        area = PI * r * r;

        /* Display message using macro replacement */
        printf(MESSAGE);

        /* Program termination */
        return 0;
}
