#include<iostream>

#include<string>

#include<ctime>

#include<windows.h>

#include<thread>

using namespace std;

class Travel//start of the base class
{
    public:

    time_t now=time(0);

    char *dt=ctime(&now);
    
    string Name;
    
    int Age=0;

    int IDno;

    int passengno;

    int dayno;

    int nightno;

    int cardno;

    int phonecount=0;

    long long int Phoneno;

    virtual void Accept()=0;

    virtual void Display()=0;

    virtual void FareDetails()=0;//Use of virtual functions in order to achieve Run time polymorphism
    
    long long int count_digit(long long int number)
    
    {
    
    int count = 0;
    
    while(number != 0) {
    
      number = number / 10;
    
      count++;
    
    }
    
    return count;
    
    }
    
    void EnterDetails()
    
    {
    
        system("cls"); //command to clear the screen
    
        cout<<"\nEnter your Name : ";
    
        cin>>Name;
    
        cout<<"\nEnter your age : ";
    
        cin>>Age;
    
        try
    
        {
    
        if (Age<18)
    
        {
    
         throw Age;
    
        }
    
        }
    
        catch (int x )
    
        {
    
        cout << "Sorry, you are not eligible!!";
    
        exit (0); //indicates successful termination
    
        }
    
        cout<<"\nEnter your Driving Licsense reference ID no. : ";
    
        cin>>IDno;

        while(phonecount==0)
    
        {
    
        cout<<"\nEnter your phone number : ";
    
        cin>>Phoneno;
    
        if (count_digit(Phoneno)==10)
    
        {
    
        (phonecount=10);
    
        }
    
        else
    
        {
    
        cout <<"Invalid Number"<< endl;
    
        phonecount=0;
    
        }
    
        }
    
    }
    
    void Show()
   {

    
    cout<<"";
    
    cout<<"";
    
    cout<<"";
    
    cout<<" Loading"; for(int i=0;i<6;i++)
 {

  cout<<".";
  
  Sleep(5000); 
 
 }
    system("cls");//clearscreen
    
    cout<<"\n_____\n\n";
    
    cout<<"\n\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    
    cout<<"\n\n\t\t\t\t\t J A Y P E E  T R A V E L L I N G  A G E N C Y \n";
    
    cout<<"\t\t\t\t\t\t\tSector 128 , Noida \n";
    
    cout<<"\n\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    
    cout<<"\t\t\t\t\t\tContact us at : 232476 , 554462\n\n\n\n ";
    
    cout<<"\t Time of Booking: "<<dt<<endl;
    
    cout<<"\t Name : "<< Name<<"\t\t\t Phone no. : "<< Phoneno<<"\n\n";
    
    cout<<"\t Age : "<< Age<<"\t\t\t Driving Licsense reference ID no. :"<<IDno<<"\n\n";
    
    }
};
//end of base class

class Bike : public Travel

{

    public:

    int bikechoice;

    float days, total;

    string BikeAvailable[5]={"Activa","Aviator","Avenger","Vespa","Bullet "};

    string sidecar;

    float Perdayrate[5]={900,1000,1350,1200,1500};

    void Accept()

    {

    cout<<"Looks like You have opted for Two wheeler service within the city.\n "<<"\n";

    EnterDetails();// Calling the function EnterDetails() from the base class for basic details of the customer

     cout<<"\nPlease Enter the no. of days you want the bike on rent : ";

    cin>>days;

    int ch, i;

    cout<<"\n\nYou can choose a ride from the following options : \n\n";


    cout<<"Choice no.\tVehicle\tPer Day Rate"<<"\n";

    for(i=0;i<5;i++)//prints the coices

    {
        cout<<i+1<<"\t\t"<<BikeAvailable[i]<<"\t\tRs."<<Perdayrate[i]<<"\n";
    }

    cout<<"\n\nPlease Enter the Choice no. : ";

    cin>>bikechoice;

    bikechoice=bikechoice-1;

    }

    void FareDetails()

    {

     total=Perdayrate[bikechoice]*days;

    cout<<"\nA side car is also available for all the bikes at an additional cost of RS.200 per day\n";

    cout<<"\nEnter yes if you want a side car else no : ";

    cin>>sidecar;

    if (sidecar=="yes"||sidecar=="Yes")

    {

    total =total+ 200*days;

    }

    }

    void Display()

    {

        Show();

    cout<<"\t You have selected the bike "<<BikeAvailable[bikechoice]<<" for "<<days<<" days\n\n\n";

    cout<<"\tBike Rent :\t\t\t\t"<<Perdayrate[bikechoice]<<" * "<<days<<" = "<<Perdayrate[bikechoice]*days<<"\n";

    if (sidecar=="yes"||sidecar=="Yes")

    cout<<"\tCharges for sidecar = \t\t\t200 * "<<days<<" = "<<200*days<<"\n";

    else

    cout<<"\tCharges for sidecar =\t\t\t\t 0.00"<<"\n";

    cout<<"\tTax (5% of the total Amount) =\t\t\t "<<0.05*total<<"\n\n\n";

    cout<<"\t \t\t\t\t\t---------------\n ";

    cout<<"\tTotal Amount payable :\t\t\tRs. "<<total+0.05*total<<" Only\n\n";

    cout<<"\t \t\t\t\t\t---------------\n ";

    cout<<"\tWe do accept payments through net banking, Cards or cash\n\n\n";

    cout<<"\tThank you for having us on board and be a part of your journey"<<"\n";

    cout<<"\t VISIT AGAIN\n";

    cout<<"_____"<<"\n";

    }
};

class Car: public Travel

{

    public:

    string status, choose, carChoice, Taxihiredays;

    int numberOfPassengers, numberOfNights, numberOfDays, Choiceno, cityChoice,ch;

    string CarCode[6]={"1","2","3","4","5","6"};

    string CarAvailable[6]={"Wagon-R", "SwiftDesire", "ToyotaEtios", "ToyotaInnova", "InnovaCrysta", "TempoTraveller"};

    string OutsideCity[5]={"Varanasi","Lucknow","Chandigarh","Ajmer","Merrut"};

    float Distance[5]={821.6, 512, 297.5, 414.8, 72.5};

    float pricePerKm[6]={9, 10, 11, 13, 15, 20};

    float OneWayRates[6]={12, 13, 15, 16, 18, 35};

    float DriverCharges[6]={250, 250, 250, 300, 300, 400};

    float TaxiFare[6]={1600, 1800, 2100 , 2500, 2500, 3500};

    float After80kms[6]={80, 100, 0, 150, 200, 0};

    void Accept()

    {

        EnterDetails();

    cout << "\nPlease choose the status: 'Outside', 'Inside' City = " ;

    cin >> status;

    cout << "\nPlease enter the number of passengers : " ;

    cin >> numberOfPassengers;

    if (numberOfPassengers>6)

    {

      cout <<"YOU SHOULD TAKE A BUS";

      exit (0);


    }

    }

    void FareDetails()
    {

        if(status == "inside" || status == "Inside" || status == "INSIDE")

        {

        cout << "\nWe usually follow 8 hour and 80 kms package." << endl;

        cout << "\nDo you want to hire a taxi for full day?(Yes/No)" << endl;

        cin >> Taxihiredays;


        if(numberOfPassengers<=4)
        {

            for(int i=0; i<2; i++)

            {
                cout << "\nCar Code: " << CarCode[i]<< endl;

                cout << "\nCar Available: " << CarAvailable[i] << endl;

                cout << "\n5 seater car: 4 passengers + driver" << endl;

                cout << "\nTaxi fare for full day hire: Rs." << TaxiFare[i] << endl;

                cout << "\nFare after 8 hours: Rs." << pricePerKm[i] << endl;

                cout << "\nFare after 80 kms: Rs." << After80kms[i] << endl;

                cout << "\n___" << endl;

            }
        }

        else if(numberOfPassengers==5 || numberOfPassengers==6)

        {

            for(int i=3; i<5; i++)

            {

                cout << "\nCar Code: " << CarCode[i]<< endl;

                cout << "\nCar Available: " << CarAvailable[i] << endl;

                cout << "\n\n7 seater car: 6 passengers + driver" << endl;

                cout << "Taxi fare for full day hire: Rs." << TaxiFare[i] << endl;

                cout << "Fare after 8 hours: Rs." << pricePerKm[i] << endl;

                cout << "Fare after 80 kms: Rs." << After80kms[i] << endl;

                cout << "\n___" << endl;

            }

        }

        }

        else if(status == "Outside" || status == "outside" || status == "OUTSIDE")

        {

            cout<<"\nPlease enter that whether you want to travel 'One-way' [Enter 1] or 'Roundtrip'[Enter 2] : ";

            cin>>ch;

            cout<<"\nWe provide the facilities of travelling outside Noida to the following cities \n"<<endl;

        for(int i=0;i<5;i++)

        cout<<i+1<<" "<<OutsideCity[i]<<"\n";

        cout<<"\nPlease enter the choice no. respective to the city you want to travel : ";

        cin>>cityChoice;

        cityChoice-=1;

        cout << "\nPlease enter the number of days you want to spend : " ;

        cin >> numberOfDays;

        if(numberOfPassengers<=4)

        {

            for(int i=0; i<2; i++)

            {

                cout << "\nCar Code: " << CarCode[i]<< endl;

                cout << "\nCar Available: " << CarAvailable[i] << endl;

                cout << "\n5 seater car: 4 passengers + driver" << endl;

                cout << "\nPrice per km: Rs." << pricePerKm[i] << endl;

                cout << "\nOne way rates: Rs." << OneWayRates[i] << endl;

                cout << "\nDriver charges per day: Rs." << DriverCharges[i] << endl;

                cout << "\n_" << endl;

            }

        }

        else if(numberOfPassengers==5)

        {

            for(int i=2; i<3; i++)

            {

                cout << "\nCar Code: " << CarCode[i]<< endl;

                cout << "\nCar Available: " << CarAvailable[i] << endl;

                cout << "\n6 seater car: 5 passengers + driver" << endl;

                cout << "\nPrice per km: Rs." << pricePerKm[i] << endl;

                cout << "\nOne way rates: Rs." << OneWayRates[i] << endl;

                cout << "\nDriver charges per day: Rs." << DriverCharges[i] << endl;

                cout << "\n_" << endl;

            }

        }

        else if(numberOfPassengers==6)

        {

            for(int i=3; i<5; i++)

            {

                cout << "\nCar Code: " << CarCode[i]<< endl;

                cout << "\nCar Available: " << CarAvailable[i] << endl;

                cout << "\n7 seater car: 6 passengers + driver" << endl;

                cout << "\nPrice per km: Rs." << pricePerKm[i] << endl;

                cout << "\nOne way rates: Rs." << OneWayRates[i] << endl;

                cout << "\nDriver charges per day: Rs." << DriverCharges[i] << endl;

                cout << "\n_" << endl;

            }

        }



        else

        {

            for(int i=5; i<6; i++)

            {

            cout << "\nCar Code: " << CarCode[i]<< endl;

            cout << "\nCar Available: " << CarAvailable[i] ;

            cout << "\n15 seater car: 14 passengers + driver" ;

            cout << "\nPrice per km: Rs." << pricePerKm[i] ;

            cout << "\nOne way rates: Rs." << OneWayRates[i] ;

            cout << "\nDriver charges per day: Rs." << DriverCharges[i] ;

            cout << "\n_" << endl;

            }



        }

        }

        cout << "\nPlease enter your car choice : " ;

        cin >> carChoice;

    }



    void Display()

    {

        Show();

        if(status == "inside" || status == "Inside" || status == "INSIDE")

        {

        for(int i=0; i<6; i++)

        {

            if(carChoice == CarCode[i])

            {

                cout << "\n\tYour car choice: " << CarAvailable[i] << endl;

                if(Taxihiredays == "Yes" || Taxihiredays == "yes" || Taxihiredays == "YES")

                {

                    cout << "\n\tTotal amount payable: Rs. " << TaxiFare[i];

                    cout<<"\n\n\n\tTotal amount =\t\t\t\t\t Rs."<<TaxiFare[i]<<"\n";



                    cout<<"\tTax (5% on total amount excluding Driver charges) = Rs."<<0.05*TaxiFare[i]<<endl;

                    cout<<"\n\n\t \t\t\t\t\t\t---------------\n ";

                    cout<<"\tTotal Amount payable :\t\t\t\tRs. "<<TaxiFare[i]+0.05*TaxiFare[i]+DriverCharges[i]<<" Only\n";

                    cout<<"\t \t\t\t\t\t\t---------------\n ";

                }

                else if(Taxihiredays == "NO" || Taxihiredays == "no" || Taxihiredays == "No")

                {

                    cout << "\n\tTotal amount payable: Rs. " << After80kms[i] << " + " <<"(" <<pricePerKm[i] << " * kms travelled )\n";

                    cout<<"\n\tYou have to pay the Amount as per the no. of Km the car\n -travelled on the completion of your journey"<<endl;

                }

            }

        }

        }


        else if(status == "Outside" || status == "outside" || status == "OUTSIDE")

        {

            float total;

            for(int i=0; i<6; i++)

            {

               if(carChoice == CarCode[i])

               {



            cout << "\n\tYour choice car: " << CarAvailable[i] << endl;

            cout << "\n\tprice per km: Rs. " << pricePerKm[i] << endl;

            cout << "\n\tone way rates: Rs. " << OneWayRates[i] << endl;

            cout << "\n\tDriver charges per day: Rs. " << DriverCharges[i] << endl;

            cout << "\n\tDistance between Noida and " << OutsideCity[cityChoice] << " is " << Distance[cityChoice] << " Kms " << endl;



            if (ch==1)

            {

                total= OneWayRates[i]*Distance[cityChoice];

            }

            else

            {

                total= pricePerKm[i]*Distance[cityChoice]*2;

            }



            cout<<"\n\n\n\tTotal amount =\t\t\t\t\t Rs."<<total<<"\n";

            cout<<"\tDriver charges for "<< numberOfDays <<" days =\t\t\t Rs."<<DriverCharges[i]*numberOfDays<<endl;

            cout<<"\tTax (5% on total amount excluding Driver charges) = Rs."<<0.05*total<<endl;

            cout<<"\n\n\t \t\t\t\t\t\t---------------\n ";

            cout<<"\tTotal Amount payable :\t\t\t\tRs. "<<total+0.05*total+DriverCharges[i]*numberOfDays<<" Only\n";

            cout<<"\t \t\t\t\t\t\t---------------\n ";



            }

        }

        cout<<"\n\tWe do accept payments through net banking, Cards or cash\n\n\n";

        cout<<"\tThank you for having us onboard and be a part of your journey"<<"\n";

        cout<<"\t VISIT AGAIN\n";

        cout<<"_____"<<"\n";

    }

    }

};

int main()

{

    //time_t now=time(0);

    //char *dt=ctime(&now);

    int i,x=0;

    system("cls");

    cout<<"Welcome To JAYPEE TRAVELLING SERVICES.\nWe are thankful to you for choosing us as a partner in your journey."<<"\n";




    cout<<"We provide bikes on rent for travelling within the city and cars on rent for travelling inside as well as outside the city"<<"\n";

    cout<<"\n\nPress 1 if you want a bike on rent \nPress 2 if you want a car on rent"<<"\n";

    while(x==0)

    {

    cin>>i;

    if(i==1)

    {

        Bike obj;

        obj.Accept();


        obj.FareDetails();

        obj.Display();

        exit (0);

    }

    if(i==2)
    {

       Car ob;
       ob.Accept();

       ob.FareDetails();

       ob.Display();

       exit (0);

    }

    else


        {

        cout <<"\nInvalid Number"<< endl;

        cout <<"Enter again: ";

        }

    }

return 0;

}
