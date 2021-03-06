#include <stdio.h>
#include <math.h>
//Made by Александр Парамонов
//version 0.0.2 alpha
//changelog:no more returns array


void writesquareroots(double* squareroots=new double[4]) //function that writes answers
{
    if (squareroots[0]==-1)
    {
        if (squareroots[0]==3)
        {
            printf("LINEAR EQUATION,X=%lg",squareroots[2]);
        }
        printf("NO ROOTS");
    }
    if (squareroots[0]==0)
    {
        printf("NO ROOTS,BECAUSE DISCRIMINANT=%lg<0",squareroots[1]);
    }
    if (squareroots[0]==1)
    {
        printf("SINGLE ROOT,D=0,  X=%lg",squareroots[2]);
    }
    if (squareroots[0]==2)
    {
        printf("TWO ROOTS,D=%lg   X1=%lg  X2=%lg",squareroots[1],squareroots[2],squareroots[3]);
    }
    if (squareroots[0]==3)
    {
        printf("LINEAR EQUATION,X=%lg",squareroots[2]);
    }
    if (squareroots[0]==4)
    {
        printf("INFINITY AMOUNT OF ROOTS");
    }
}



double readdouble()//function to enter double variable,ignoring trash symbols
{
    double a;
    while (scanf("%lg",&a)==0)
    {
        scanf("%1S");
    }
    return a;
}




double getsquareroots(double c, double b,double a,double& disc, double& x1, double& x2)  //not (a,b,c) because variables are entered in inverted order
//returns array
//[0]=type of answer(0,1,2-roots amount,3-linear equation,-1-zero roots,4-infinity amount of roots)
//[1]=discriminant (not always returned,check [0] first)
//[2],[3]=roots;(not always returned)
{
    double* returnvalue=new double[4];//initialize variable that is returned
    returnvalue[0]=-1;
    returnvalue[1]=0;
    returnvalue[2]=0;
    returnvalue[3]=0;
    if (a==0)
    {
        if (b!=0)
        {
            returnvalue[0]=3;
            returnvalue[2]=-c/b;
        }
        else
        {
            if (c==0)
            {
                returnvalue[0]=4;
            }
            else
            {
                returnvalue[0]=-1;
            }
        }
    }
    else
    {
        returnvalue[1]=b*b-4*a*c;
        if (returnvalue[1]<0)
        {
            returnvalue[0]=0;
        }
        else
        {
            double sqrtd=sqrt(returnvalue[1]);
            if (returnvalue[1]==0)
            {
                returnvalue[0]=1;
                returnvalue[2]=-b/ (2*a);
            }
            else
            {
                returnvalue[0]=2;
                returnvalue[2]=(-b-sqrtd)/ (2*a);
                returnvalue[3]=(-b+sqrtd)/ (2*a);
            }


        }
    }
    disc=returnvalue[1];
    x1=returnvalue[2];
    x2=returnvalue[3];
    return returnvalue[0];
}




int main()
{
    double* squareroots=new double[4];
    squareroots[0]=-1;
    squareroots[1]=0;
    squareroots[2]=0;
    squareroots[3]=0;
    squareroots[0]=getsquareroots(readdouble(),readdouble(),readdouble(),squareroots[1],squareroots[2],squareroots[3]);
    writesquareroots(squareroots);

    return 0;
}
