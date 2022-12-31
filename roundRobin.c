#include<stdio.h>
int main()
{
    printf("Enter the number of Processes:\n");
    int processes=0,quant_time=0;
    scanf("%d",&processes);
    printf("Enter the Quant Time:\n");
    scanf("%d",&quant_time);
    printf("Enter the Burst Time for each Process:\n");
    int burst_time[100];
    for(int i=0;i<processes;i++)
    {
        scanf("%d",&burst_time[i]);
    }



    return 0;
}
