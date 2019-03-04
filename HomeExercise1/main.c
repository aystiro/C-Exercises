#include <stdio.h>

#define EFFIENCY 0.90
#define G 9.80

int main()
{
    double height, flowwater, work;
    //Prompt the user
    printf("Enter the height of dam > ");
    scanf("%lf", &height);
    printf("Enter the number of cubic meters of water that are projected to flow per second > ");
    scanf("%lf", &flowwater);
    //Computing work
    work = (((flowwater * 1000) * G * height)* EFFIENCY) * 0.000001;
    /*
    work = work * EFFIENCY;
    //Converting to Megawatts from Watts
    work = work * 0.000001;
    */
    printf("\nProduced electrical energy = %f MW", work);

    return 0;
}
