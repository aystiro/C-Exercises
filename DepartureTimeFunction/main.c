#include <stdio.h>
#include <stdlib.h>

int find_departure(int arrival, int distance, int avg_speed);
int main()
{
    int arrival;
    int distance;
    int avg_speed;
    int departure;

    printf("Enter arrival time as integer on a 24 hour clock. For example, 8:30 PM would be entered as 2030.\n");

    printf("Arrival time> ");
    scanf("%d", &arrival);
    printf("Enter the distance in km> ");
    scanf("%d", &distance);
    printf("Enter anticipated average speed (including stops) in km/h> ");
    scanf("%d", &avg_speed);

    departure = find_departure(arrival, distance, avg_speed);

    printf("You need to leave at %d.", departure);

    return 0;
}
int find_departure(int arrival, int distance, int avg_speed)
{
    if(((distance*60/avg_speed)%60) == 0)
        return (arrival - (40*(((distance*60/avg_speed)/60) + (1*((distance*60/avg_speed)%60)))) - (distance*60/avg_speed));
    else
        return (arrival - (40*(((distance*60/avg_speed)/60)+1)) - (distance*60/avg_speed));
}
