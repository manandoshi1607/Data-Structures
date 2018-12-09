#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
int size,status[20],value[20],hash[20],val_count,i,j,pos,flag,num,x,collision,square,original;
for (i=0;i<20;i=i+1)
{
    value[i]=0;
    status[i]=0;
}   
printf("Enter size of table (prime no.):");
scanf("%d",&size);
square=0;
val_count=0;
do{
    printf("\nEnter key %d:",val_count);
    scanf("%d",&num);
    pos = num%size;

    val_count+=1;
    collision=0;
    original = 0;
    flag=0;
    do{
        if (status[pos]==0)
        {
            printf("Inserted value: ");
            value[pos]=num;
            //original = pos;
            status[pos]=1;
            flag=1;
            printf("%d",value[pos]);
            printf(" at position: %d",pos);
            printf(" after %d collisions.",collision);
            break;
        }
        else if (status[pos]==1)
        {
            if (collision==0)
            {
                original=pos;
            }
            collision+=1;   
            square = collision*collision;
            //printf("%d",square);
            pos=(original+square)%size;
            //printf("Jumping to %d",pos);

        }
    }while(flag==0 && collision<=size);

if (collision > size)
{
    printf("\nNo empty address for this key (%d)\n",num);
}
}while(val_count<=size);
if (val_count > size){
printf("Table is full !!");
}
printf("%d\n",size);
printf("\nArray:\n");
for (i=0;i<size;i++)
{
printf("%d  ",value[i]);
}

printf("\nEnter number to search:");
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
                if (collision==0)
            {
                original=pos;
            }
            collision+=1;   
            square = collision*collision;
            //printf("%d",square);
            pos=(original+square)%size;
            }
    }

}while(flag==0 && collision<=size);

if (collision > size)
{
    printf("\nKey not found !!");
}

}
