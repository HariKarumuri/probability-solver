#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float sum(int set[15], int k);
float sqSum(int set[15],int k);
int main(){
    int x[15],y[15],z[15];
    int k , i;
    float meanX,meanY,meanZ;
    float SDx,SDy,SDz;
    float FTx,FTy,FTz;
    float sqroot;
    float ReglineXterm,ReglineYterm;
    float ReglineX2ndterm,ReglineY2ndterm;
    float R;

    printf("enter number of elements in X and Y \n");
    scanf("%d",&k);
    printf("enter elements in X \n");
    for(i=0;i<k;i++){
        scanf("%d",&x[i]);
    }
    printf("the values of x entered are as follows\n\n");
    for(i=0;i<k;i++){
    printf("   %d.%d\n",i+1,x[i]);
    }
    printf("enter elements in Y \n");
    for(i=0;i<k;i++){
        scanf("%d",&y[i]);
    }
    printf("the values of y entered are as follows\n\n");
    for(i=0;i<k;i++){
    printf("   %d.%d\n",i+1,y[i]);
    }
    for(i=0;i<k;i++){
        z[i]= x[i]-y[i];
    }
    printf("the values of z are as follows\n ");
    for(i=0;i<k;i++){
        printf("   %d.%d\n",i+1,z[i]);
    }
    meanX = (sum(x,k)/k);
    meanY = (sum(y,k)/k);
    meanZ = (sum(z,k)/k);

    printf("the mean of x %.2f\n",meanX);
    printf("the mean of y %.2f\n",meanY);
    printf("the mean of z %.2f\n",meanZ);

    FTx = (sqSum(x,k)/k);
    FTy = (sqSum(y,k)/k);
    FTz = (sqSum(z,k)/k);

    SDx = FTx - (meanX*meanX);
    SDy = FTy - (meanY*meanY);
    SDz = FTz - (meanZ*meanZ);

    sqroot = sqrt((SDx)*(SDy));

    R = (SDx + SDy - SDz)/(2*sqroot);

    printf("the standard deviation of x is %f \n",SDx);
     printf("the standard deviation of y is %f \n",SDy);
      printf("the standard deviation of y is %f \n",SDz);

    printf("\n\nthe value of R is %.3f\n\n",R);

    ReglineXterm = ((R)* (sqrt((SDy)/(SDx))));
    ReglineYterm = ((R)* (sqrt((SDx)/(SDy))));
    ReglineX2ndterm = meanY - ReglineXterm*meanX;
    ReglineY2ndterm = meanX - ReglineYterm*meanY;

    printf("the lines of regression are Y = %.2fX + %.2f\n",ReglineXterm,ReglineX2ndterm);
    printf("the lines of regression are X = %.2fY + %.2f\n\n",ReglineYterm,ReglineY2ndterm);



    return 0;
}

float sum(int set[15], int k){
    int temp=0;
    int i;
    for(i=0;i<k;i++){
        temp = temp + set[i];
    }
    return temp;
}
float sqSum(int set[15],int k){
    int temp=0;
    int i;
    for(i=0;i<k;i++){
        temp = temp + set[i]*set[i];
    }
    return temp;
}
