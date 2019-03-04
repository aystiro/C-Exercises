#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double bisect(double xleft, double xright, double epsilon, double f(double fargs));
double g(double x);
double h(double x);

int main()
{
    double leftend, rightend;
    double tolerance;

    printf("Enter interval endpoints> ");
    scanf("%lf %lf",&leftend, &rightend);
    printf("\nEnter tolerance> ");
    scanf("%lf", &tolerance);

    printf("\n\nFunction g");
    double root = bisect(leftend,rightend,tolerance,g);
    if(root == 0)
        printf("\nMay be no root in [%f, %f]", leftend, rightend);
    else
        printf("\n  g(%f) = %f",root,g(root));

    printf("\n\n\nFunction h");
    root = bisect(leftend,rightend,tolerance,h);
    if(root == 0)
        printf("\nMay be no root in [%f, %f]", leftend, rightend);
    else
        printf("\n  h(%f) = %f",root,h(root));


    return 0;
}

double bisect(double xleft, double xright, double epsilon, double f(double fargs))
{
    if((f(xright)>0 && f(xleft)>0) || (f(xright)<0 && f(xleft)<0))
            return 0;
    double xmid;
    double res = 0;


    while((xright-xleft) >=  epsilon)
    {
        xmid = (xright + xleft)/2;
        res = xmid;
        if((f(xmid)) == 0) {
            printf("\nSolution.");
            break;
        }
        else if( (f(xmid)) > 0){
            xright = xmid;
        }
        else if( (f(xmid)) < 0){
            xleft = xmid;
        }
        printf("\nNew interval is [%.7f, %.7f]",xleft,xright);
    }
    return res;
}
double g(double x)
{
    return ((5*(pow(x,3))) - (2*(pow(x,2))) + 3);
}
double h(double x)
{
    return ((pow(x,4)) - 3*(pow(x,2)) - 8);
}
