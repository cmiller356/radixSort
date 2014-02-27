#include <stdio.h>

#define MAX 100000
#define SHOWPASS
void print(int a[],int n){
        int i;
        for(i=0;i<n;i++)
                printf("%d\t",a[i]);
                fflush(stdout);
}//print

void radixSort(int a[],int n){
        int i,b[MAX],m=0,exp=1;
        for(i=0;i<n;i++){
                if(a[i]>m)
                        m=a[i];
        }//for
        while(m/exp>0){
                int bucket[10]={0};
                for(i=0;i<n;i++)
                        bucket[a[i]/exp%10]++;
                for(i=1;i<10;i++)
                        bucket[i]+=bucket[i-1];
                for(i=n-1;i>=0;i--)
                        b[--bucket[a[i]/exp%10]]=a[i];
                for(i=0;i<n;i++)
                        a[i]=b[i];
                exp*=10;

                printf("\nPASS   : ");
                print(a,n);
                }//while
}//radixSort


int main(int argc, char *argv[]){
        int i, digit,size;
        FILE *input = fopen(argv[1], "r");
        fscanf(input,"%d", &size);
        fscanf(input,"%d", &digit);
        int arr[size];
        for(i=0;i<size;i++)
                fscanf(input, "%d",&arr[i]);
        printf("\nARRAY  : ");

        print(arr,size);
        radixSort(arr,size);
        printf("\nSORTED : ");
        print(arr,size);
        printf("\n");
        return 0;
}//main
