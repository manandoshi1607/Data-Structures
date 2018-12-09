#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
int size,status[20],value[20],hash[20],val_count,i,j,pos,flag,num,x,collision;
for (i=0;i<20;i=i+1)
{
    value[i]=0;
    status[i]=0;
}   
printf("Enter size of table (prime no.):");
scanf("%d",&size);

val_count=0;
do{
    printf("\n\nEnter key %d:",val_count);
    scanf("%d",&num);
    pos = num%size;

    val_count+=1;
    flag=0;
    collision=0;
    do{
        if (status[pos]==0)
        {
            printf("Inserted value: ");
            value[pos]=num;
            status[pos]=1;
            flag=1;
            printf("%d",value[pos]);
            printf(" at position: %d",pos);
            printf(" after %d collisions.",collision);
            break;
        }
        else if (status[pos]==1)
        {
            pos=(pos+1)%size;
            collision+=1;
        }
    }while(flag==0);

}while(val_count<(size/2));
printf("%d\n",size);
printf("Array:\n");
for (i=0;i<size;i++)
{
printf("  %d  ",value[i]);
}

printf("\n\nEnter number to search:");
scanf("%d",&x);
pos=x%size;
flag=0;
collision=0;
do{
if (status[pos]==0)
    {
        printf("Not present !");
    }
else if (status[pos]==1)
    {
            if (value[pos]==x)
            {
                printf("Element found at %d",pos);
                printf("\nCollisions: %d",collision);
                flag=1;
            }
            else if (value[pos]!=x)
            {
                collision+=1;
                pos=(pos+1)%size;
            }
    }

}while(flag==0 && collision<(size/2));

}
