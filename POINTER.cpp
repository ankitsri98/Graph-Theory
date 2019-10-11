
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=10   ;
    cout<<&i<<endl;//means ADDRESS 0x69feec 0x = shows hexadecimal
    //POINTERS ARE VATRIABLES THAT STORE ADDRESS\

    int * p=&i;
    cout<<"p:  "<<p<<endl;

    float f=10.2;
    float * pf= &f;

    double d=122.32;
    double* pd=&d;

    cout<<"pf:  "<<pf<<"   "<<"pd:  "<<pd<<endl;

    //NOW IF YOU WANT TO ACCESS VALUE FROM POINTER
    //SIMPLY ACCESS IT BY USING STAR BEFORE POINTER

    cout<<"VALUE FROM POINTER *PD AND *PF: "<<*pd<<"   "<<*pf<<endl;

    //finding the size of variable and pointers

    cout<<"SIZE OF POINTER: "<<sizeof(p)<<"   "<<sizeof(i)<<endl;

    cout<<"i: "<<i<<"  pointer *p : "<<*p<<endl;

    i++;//SO BOTH PRINTS SAME VALUE
    cout<<"i: "<<i<<"  pointer *p : "<<*p<<endl;

    ////////////////////////////////////////
    int a=*p;
    a++;
    cout<<"a: "<<a<<endl;
    cout<<"*p "<<*p<<endl;
    //look at this

    //*p and i same cheese hai kisi me bhi change karoge dono change honge

    //////////////////////////////////////////

    //NEVER INCREMENT A POINTER LIKE (*p)++
    // SO FOR THAT USE
    int * pointer =0;
    //so now if you increment it will f=give error
}
