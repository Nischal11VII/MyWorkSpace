// WAP to find the largest element in a dynamucally allocated arrray annd then compute the average of an array elements


#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n;
    printf("Enter the number of element in dma array : ");
    scanf("%d",&n);
    printf("\n");
    
    int* ptr = calloc(n , sizeof(int));
    printf("Enter the elements in array:\n");
    for(int i = 0 ; i < n ; i++)
        {
            printf("Array element index [%d] = " , i);
            scanf("%d" , (ptr+i));
        }
        
    // find the largest elements. and average
    
    int large = 0;
    int sum = 0;
    int largestElement;
    for(int i = 0 ; i < n ; i++)    
        {
            if(large < *(ptr+i))
                {
                    large = *(ptr+i);
                    largestElement = i;
                     
                }
                   sum+= *(ptr+i);
        }
    
    float average = (float)sum/n;
//    printf("\n%d\n", sum);
    printf("\nLargest element is %d at index %d \nAverage of the array : %.2f\n" , large , largestElement , average);
    
    free(ptr);
    
        

    return 0;
}

