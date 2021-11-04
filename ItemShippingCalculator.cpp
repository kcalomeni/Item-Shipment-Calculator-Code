#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<fstream>
using namespace std;

void main()
{
    for(int i=0;i<60;i++)
       cout<<".";
    cout<<"\n ITCS 2530 - Week #3 Programming Assignment"<<endl;
    for(int i=0;i<60;i++)
       cout<<".";
    string itemName;
    string shippingDestination;
    double shippingCharge=0.0;
    double orderTotal;
    cout<<"\n\n\nPlease enter the item name (no spaces)..............";
    cin>>itemName;
    char itemType;
    cout<<"\n Is the item fragile? (y=yes/n=no)..................";
    cin>>itemType;
    if(itemType=='Y'|| itemType=='y')
    {
        shippingCharge = shippingCharge+2;
    }
    else if (itemType=='n' || itemType=='N')
       shippingCharge=0.0;
    else
    {
     cout<<"Invalid Entry, exiting "<<endl;
     system("pause");
     exit(0);
    }
    cout<<"Please enter your order total........................";
    cin>>orderTotal;
    cout<<"Please enter your destination. (usa/can/aus/euro).......................";
    cin>>shippingDestination;

    transform(shippingDestination.begin(),shippingDestination.end(),shippingDestination.begin(),::toupper);
    transform(itemName.begin(),itemName.end(),itemName.begin(),::toupper);
    /*if(shippingDestination!="AUS" || shippingDestination!="CAN" || shippingDestination!="USA" || shippingDestination!="EURO")
    {
        cout<<"\nWrong Destination! Exiting..........."<<endl;
        system("pause");
        exit(0);    
    }*/
    if(shippingDestination=="USA")
    {
        if(orderTotal<50.00)
           shippingCharge=shippingCharge+6.00;
        else if(orderTotal>50.00 || orderTotal<100.01)
           shippingCharge=shippingCharge+9.00;
        else if(orderTotal>100.00 || orderTotal<150.01)
           shippingCharge=shippingCharge+12.00;
        else
           shippingCharge=0.0;
    }
    if(shippingDestination=="CAN")
    {
        if(orderTotal<50.00)
           shippingCharge=shippingCharge+8.00;
        else if(orderTotal>50.00 || orderTotal<100.01)
           shippingCharge=shippingCharge+12.00;
        else if(orderTotal>100.00 || orderTotal<150.01)
           shippingCharge=shippingCharge+15.00;
        else
           shippingCharge=0.0;
    }
    if(shippingDestination=="AUS")
    {
        if(orderTotal<50.00)
           shippingCharge=shippingCharge+10.00;
        else if(orderTotal>50.00 || orderTotal<100.01)
           shippingCharge=shippingCharge+14.00;
        else if(orderTotal>100.00 || orderTotal<150.01)
           shippingCharge=shippingCharge+17.00;
        else
           shippingCharge=0.0;
    }
    if(shippingDestination=="EURO")
    {
        if(orderTotal<50.00)
           shippingCharge=shippingCharge+12.00;
        else if(orderTotal>50.00 || orderTotal<100.01)
           shippingCharge=shippingCharge+16.00;
        else if(orderTotal>100.00 || orderTotal<150.01)
           shippingChagre=shippingCharge+20.00;
        else
           shippingCharge=0.0; 
    }
    
    freopen("Order.txt","a+",stdout);//to store output in a file
      cout<<"\n\nYour item is............................. "<<itemName<<endl;
      cout<<"Your shipping cost is........................$"<<shippingCharge<<endl;
      cout<<"You are shipping to.......................... "<<shippingDestination<<endl;
      double total=shippingCharge+orderTotal;
      cout<<"Your total shipping costs are.................$"<<fixed<<setprecision(2)<<total<<endl;
      cout<<"----------------------------------------------Thank you!"<<endl;
      system("pause");


}
