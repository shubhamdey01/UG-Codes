/**********************************************************
Name : Shubham Dey
Program :  Compute the distance between given coordinates.
Program No. : 1.11
***********************************************************/

#include<stdio.h>
#include<math.h>

void main()
{
    int x1,y1,x2,y2;
    float d;

    printf("Enter the coordinates (x1,y1) :\n");
    scanf("%d %d",&x1,&y1);
    printf("Enter the coordinates (x2,y2) :\n");
    scanf("%d %d",&x2,&y2);

    d = sqrt(pow((x2-x1),2)+pow((y2-y1),2));

    printf("\nDistance between (%d,%d) and (%d,%d) is %f.\n",x1,y1,x2,y2,d);
}