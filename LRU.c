#include <stdio.h>

int main()
{
    int fsize = 0, rsize, flag = 0, rflag = 0, pf = 0;
    printf("Enter the Frame Size:\n");
    scanf("%d", &fsize);
    printf("Enter the Reference String Size:\n");
    scanf("%d", &rsize);
    int frames[fsize];
    int priority[fsize];
    int counter=0;
    int refstring[rsize];
    int index = 0;
    for (int i = 0; i < fsize; i++)
    {
        frames[i] = -1;
    }

    printf("Enter the Reference String:\n");
    for (int i = 0; i < rsize; i++)
    {
        scanf("%d", &refstring[i]);
    }

    for (int i = 0; i < rsize; i++)
    {
        rflag = 0, flag = 0;
        for (int j = 0; j < fsize; j++)
        {
            if (refstring[i] == frames[j])
            {
                flag = 1;
                priority[j]=counter;
                counter++;
                break;
            }
        }
        if (flag == 0)
        {
            pf++;
            for (int j = 0; j < fsize; j++)
            {
                if (frames[j] == -1)
                {
                    frames[j] = refstring[i];
                    priority[j]=counter;
                    counter++;
                    rflag = 1;
                    break;
                }
            }
            if (rflag == 0)
            {
                int min=priority[0];
                for(int j=0;j<fsize;j++)
                {
                    if(priority[j]<min)
                    {
                        index=j;
                    }
                }
                frames[index] = refstring[i];
                if (index == fsize)
                    index = 0;
            }
        }
        printf("%d :", refstring[i]);
        for (int j = 0; j < fsize; j++)
        {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Page Faults: %d", pf);
    return 0;
}