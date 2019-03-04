/* Flat Washer Program */
/*
* Computes the weight of a batch of flat washers.
*/

#include <stdio.h>
#define PI 3.14159

double find_area(double edge_diameter, double hole_diameter);
double find_unit_weight(double rim_area, double thickness, double density);

int main(void)
{
    double hole_diameter; /* input - diameter of hole */
    double edge_diameter;/* input - diameter of outer edge */
    double thickness;   /* input - thickness of washer */
    double density;     /* input - density of material used */
    double quantity;    /* input - number of washers made */
    double weight;      /* output - weight of washer batch */
    //double hole_radius; /* radius of hole */
    //double edge_radius; /* radius of outer edge */
    double rim_area;    /* area of rim */
    double unit_weight; /* weight of 1 washer */

    /* Get the inner diameter, outer diameter, and thickness.*/
    printf("Inner diameter in centimeters> ");
    scanf("%lf", &hole_diameter);
    printf("Outer diameter in centimeters> ");
    scanf("%lf", &edge_diameter);
    printf("Thickness in centimeters> ");
    scanf("%lf", &thickness);

    /* Get the material density and quantity manufactured. */
    printf("Material density in grams per cubic centimeter> ");
    scanf("%lf", &density);
    printf("Quantity in batch> ");
    scanf("%lf", &quantity);

    rim_area = find_area(edge_diameter, hole_diameter);

    weight = find_unit_weight(rim_area, thickness, density) * quantity;

    /* Display the weight of the batch of washers. */
    printf("\nThe expected weight of the batch is %.2f grams. \n", weight);

    return 0;
}

double find_area(double edge_diameter, double hole_diameter)
{
    return (PI * (edge_diameter / 2.0) * (edge_diameter / 2.0) - PI * (hole_diameter / 2.0) * (hole_diameter / 2.0));
}

double find_unit_weight(double rim_area, double thickness, double density)
{
   return (rim_area * thickness * density);
}


