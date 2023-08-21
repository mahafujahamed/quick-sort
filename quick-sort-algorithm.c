#include<stdio.h>
void printArray(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int Partition(int *a,int left,int right)
{
    int pivot=a[left],temp;
    while(left!=right)
    {
        if(pivot==a[left])
        {
            if(a[right]>pivot)
            {
                right--;
            }else if(a[right]<=pivot)
            {
                temp=a[left];
                a[left]=a[right];
                a[right]=temp;
                pivot=a[right];
                left++;
            }
        }else if(pivot==a[right])
        {
            if(a[left]<pivot)
            {
                left++;
            }else if(a[left]>=pivot)
            {
                temp=a[left];
                a[left]=a[right];
                a[right]=temp;
                pivot=a[left];
                right--;
            }
        }
    }
    return left;
}
void quickSort(int *a,int left,int right)
{
    int pivot;
    if(left<right)
    {
        pivot=Partition(a,left,right);
        quickSort(a,left,pivot-1);
        quickSort(a,pivot+1,right);
    }
}
int main()
{
    int i,n;
    printf("Enter array size:");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    printArray(a,n);
}

/*#include<stdio.h>
void printArray(int *a,int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
}
int Partition(int *a,int left,int right)
{
    int pivot=a[left],temp;
    while(left!=right)
    {
        if(pivot==a[left])
        {
            if(a[right]>pivot)
            {
                right--;
            }else if(a[right]<=pivot)
            {
                temp=a[left];
                a[left]=a[right];
                a[right]=temp;
                pivot=a[right];
                left++;
            }
        }else if(pivot==a[right])
        {
            if(a[left]<pivot)
            {
                left++;
            }else if(a[left]>=pivot)
            {
                temp=a[left];
                a[left]=a[right];
                a[right]=temp;
                pivot=a[left];
                right--;
            }
        }
    }
    return left;
}
void quickSort(int *a,int left,int right)
{
    int pivot;
    if(left<right)
    {
        pivot=Partition(a,left,right);
        quickSort(a,left,pivot-1);
        quickSort(a,pivot+1,right);
    }
}
int main()
{
    int i,n;
    printf("Enter array size:");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    printArray(a,n);
}*/