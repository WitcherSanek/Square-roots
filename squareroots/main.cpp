#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void writesquareroots(double* squareroots=new double[4]) //function that writes answers
{
    if (squareroots[0]==-1)
    {
        if (squareroots[0]==3)
        {
            cout<<"LINEAR EQUATION,X="<<squareroots[2];
        }
        cout<<"NO ROOTS";
    }
    if (squareroots[0]==0)
    {
        cout<<"NO ROOTS,BECAUSE DISCRIMINANT="<<squareroots[1]<<"<0";
    }
    if (squareroots[0]==1)
    {
        cout<<"SINGLE ROOT,D=0,  X="<<squareroots[2];
    }
    if (squareroots[0]==2)
    {
        cout<<"TWO ROOTS,D="<<squareroots[1]<<"  X1="<<squareroots[2]<<"  X2="<<squareroots[3];
    }
    if (squareroots[0]==3)
    {
        cout<<"LINEAR EQUATION,X="<<squareroots[2];
    }
    if (squareroots[0]==4)
    {
        cout<<"INFINITY AMOUNT OF ROOTS";
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




double* getsquareroots(double c, double b,double a)  //not (a,b,c) because variables are entered in reverse order
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
    return returnvalue;
}




int main()
{
    writesquareroots(getsquareroots(readdouble(),readdouble(),readdouble()));

    return 0;
}
