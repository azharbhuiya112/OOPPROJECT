#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include<unistd.h>



using namespace std;





class bus{

   string bus_no,bus_name,driver_name;
   int bus_seat;
   string *ebus_no,*dbus_name;
 public:
    void menu();
    void newbus();
    void view_bus();
    void single_bus_view();
    void all_bus_view();
    void updatebus();
    void deletebus();
    void routbus();
    void detail_bus();
    void booking();
    bus()
    {
        ebus_no=new string ;
        dbus_name=new string;
    }

};

class BusReservationSystem:public bus
{
public:
    friend ostream& operator<<(ostream& cout, BusReservationSystem &b);
};
ostream& operator<<(ostream& cout, BusReservationSystem &b)
{
    cout<<"\n\n";
    cout<<"\t\t\t\t\t<------------------------------------->\n";
    cout<<"\t\t\t\t\t   [  BUS RESERVATION SYSTEM  ]\n";
    cout<<"\t\t\t\t\t<------------------------------------->\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t   Developed by : AZHAR UDDIN 2007112   ";


}


 void bus::menu()
 {
        p:
        system("cls");


        int choice;
        cout<<"\n\t\t___________BUS MANAGEMENT________";
        cout<<"\n 1.ADD BUS RECORD";
        cout<<"\n 2.VIEW BUS DETAL ";
        cout<<"\n 3.UPDATE BUS DETAIL ";
        cout<<"\n 4.DELETE BUS DETAIL ";
        cout<<"\n 5.ROUTS BUSES ";
        cout<<"\n 6.BUS SEAT DETAIL ";
        cout<<"\n 7.BOOKING TICKET ";
        cout<<"\n 8.EXIT ";
        cout<<"\n\n";
        cout<<"\n ENTER YOUR CHOICE-._.->";
        cin>>choice;
        switch(choice)
        {
        case 1:
            newbus();
            break;
        case 2:
            view_bus();
            break;
        case 3:
            updatebus();
            break;
        case 4:
            deletebus();
            break;
        case 5:
            routbus();
            break;
        case 6:
            detail_bus();
            break;
        case 7:
             booking();
            break;
        case 8:
           exit(0);
        default:
            cout<<"/n/n invalid choice....please try again....";

        }
        getch();
        goto p;


 }



void bus::newbus()
   {
       p:
       system("cls");
       fstream file;
       string tbus_no,tbus_name,tdriver_name;
       int tbus_seat,found=0;
       cout<<"\n\t\t _____BUS MANAGEMENT____";
       cout<<"\n\n Bus NO :";
       cin>>bus_no;
       cout<<"\n\n Bus Name:";
       cin>>bus_name;
       cout<<"\n\n Total seats:";
       cin>>bus_seat;
       cout<<"\n\n Driver Name:";
       cin>>driver_name;
       file.open("bus.txt",ios::in);
       if(!file)
       {
           file.open("bus.txt",ios::app|ios::out);
           file<<bus_no<<" "<<bus_name<<" "<<bus_seat<<" "<<driver_name<<"\n";
           file.close();
       }
       else
       {
           file>>tbus_no>>tbus_name>>tbus_seat>>tdriver_name;
           while(!file.eof())
           {
               if(bus_no==tbus_no)
               {
                   found++;
               }
                file>>tbus_no>>tbus_name>>tbus_seat>>tdriver_name;
           }
           file.close();
           if(found==0)
           {
               file.open("bus.txt",ios::app|ios::out);
               file<<bus_no<<" "<<bus_name<<" "<<bus_seat<<" "<<driver_name<<"\n";
               file.close();
           }
           else
           {
               cout<<"\n\n Duplicate Record Found...";
               getch();
               goto p;
           }
       }
       cout<<"\n\n New Bus Inserted Successfully...";
   }




   void bus::view_bus()
   {
       p:
       system("cls");
       int choice;
       cout<<"\n\t\t _____BUS MANAGEMENT____";
       cout<<"\n\n 1. Single Bus View";
       cout<<"\n\n 2. All Bus View";
       cout<<"\n\n 3. Go Back";
       cout<<"\n\n Enter Your Choice";
       cin>>choice;

       switch(choice)
       {
           case 1:
                single_bus_view();
                break;
           case 2:
               all_bus_view();
               break;
           case 3:
               menu();
           default:
            cout<<"Invalid choice Plz Try Again";
       }
       getch();
       goto p;
   }

   void bus::single_bus_view()
   {
       system("cls");
       string tbus_no;
       fstream file;
       int found=0;
       //int choice;
       cout<<"\n\t\t _____BUS MANAGEMENT____";
       //cout<<"\n\n Bus no.";
       //cin>>tbus_no;
       file.open("bus.txt",ios::in);
       if(!file)
       {
          cout<<"\n\n File Openning Error...";
       }
       else
        {
            cout<<"\n\n Bus no: ";
            cin>>tbus_no;
            file>>bus_no>>bus_name>>bus_seat>>driver_name;
            while(!file.eof())
           {
               if(tbus_no==bus_no)
               {
                   system("cls");
                   cout<<"\n\t\t _____BUS MANAGEMENT____";
                   cout<<"\n\nBUS NO.\t\t\tBUS NAME\t\tNO. OF SEATS\tDRIVER NAME";
                   cout<<"\n"<<bus_no<<"\t\t"<<bus_name<<"\t\t"<<bus_seat<<"\t\t"<<driver_name;
                   found++;
               }
                file>>bus_no>>bus_name>>bus_seat>>driver_name;
           }
           file.close();
           if(found==0)
           {
               cout<<"\n\n Invalid Bus No...";
           }
        }

   }





void bus::all_bus_view()
   {
       system("cls");
       //string tbus_no;
       fstream file;
       //int found=0;
       //int choice;
       cout<<"\n\t\t _____BUS MANAGEMENT____";
       //cout<<"\n\n Bus no.";
      //cin>>tbus_no;
       file.open("bus.txt",ios::in);
       if(!file)
       {
          cout<<"\n\n File Openning Error...";
       }
       else
        {
            //cout<<"\n\n Bus no";
            //cin>>tbus_no;
            cout<<"\n\nBUS NO.\t\tBUS NAME\t\tNO. OF SEATS\t\tDRIVER NAME";
            file>>bus_no>>bus_name>>bus_seat>>driver_name;
            while(!file.eof())
           {
                   cout<<"\n\n"<<bus_no<<"\t\t"<<bus_name<<"\t\t"<<bus_seat<<"\t\t"<<driver_name;
                   //found++;
                   file>>bus_no>>bus_name>>bus_seat>>driver_name;
           }
           file.close();
        }

   }

   void bus::updatebus()
   {
       system("cls");
       fstream file,file1;
       string tbus_no,no,tbus_name,tbus_seat,tdriver_name;
       int found=0;
        cout<<"\n\t\t _____BUS MANAGEMENT____";
        file.open("bus.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File Openning Error";
        }
        else
        {
            cout<<"\n\n Bus No.";
            cin>>tbus_no;
            file1.open("bus1.txt",ios::app|ios::out);
            file>>bus_no>>bus_name>>bus_seat>>driver_name;
            while(!file.eof())
            {
                if(tbus_no==bus_no)
                {
                      cout<<"\n\n New Bus No.:";
                      cin>>no;
                      cout<<"\n\n Bus Name.:";
                      cin>>tbus_name;
                      cout<<"\n\n No of Seat:";
                      cin>>tbus_seat;
                      cout<<"\n\nDriver Name.:";
                      cin>>tdriver_name;
                      file1<<no<<" "<<tbus_name<<" "<<tbus_seat<<" "<<tdriver_name<<"\n";
                     cout<<"\n\n\n Delet e Bus record successfully...";
                    found++;
                }
            else
                {

                    file1<<bus_no<<" "<<bus_name<<" "<<bus_seat<<" "<<driver_name<<"\n";

                }
                file>>bus_no>>bus_name>>bus_seat>>driver_name;
            }
            file.close();
            file1.close();
            remove("bus.txt");
            rename("bus1.txt","bus.txt");
            if(found==0)
            {
                cout<<"\n\n Bus No. Is Invalid";

            }
        }

   }





void bus:: deletebus()
    {
        system("cls");
       fstream file,file1;
       string tbus_no;
        //string tbus_no,no,tbus_name,tbus_seat,tdriver_name;
        int found=0;
        cout<<"\n\t\t _____BUS MANAGEMENT____";
        file.open("bus.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File Openning Error";
        }
        else
        {
            cout<<"\n\n Bus No.";
            cin>>tbus_no;
            file1.open("bus1.txt",ios::app|ios::out);
            file>>bus_no>>bus_name>>bus_seat>>driver_name;
            while(!file.eof())
            {
                if(tbus_no==bus_no)
                {
//                    cout<<"\n\n New Bus No.:";
//                    cin>>no;
//                    cout<<"\n\n Bus Name.:";
//                    cin>>tbus_name;
//                    cout<<"\n\n No of Seat:";
//                    cin>>tbus_seat;
//                    cout<<"\n\nDriver Name.:";
//                    cin>>tdriver_name;
//                    file1<<no<<" "<<tbus_name<<" "<<tbus_seat<<" "<<tdriver_name<<"\n";
                    cout<<"\n\n\n Updata Bus record successfully...";
                    found++;
                }
            else
                {

                    file1<<bus_no<<" "<<bus_name<<" "<<bus_seat<<" "<<driver_name<<"\n";

                }
                file>>bus_no>>bus_name>>bus_seat>>driver_name;
            }
            file.close();
            file1.close();
            remove("bus.txt");
            rename("bus1.txt","bus.txt");
            if(found==0)
            {
                cout<<"\n\n Bus No. Is Invalid";

            }
        }

    }





void bus::routbus()
    {
        system("cls");
        int choice;
        cout<<"\n\t\t _____BUS MANAGEMENT____";
       // cout<<"\n\n___________";
        cout<<"\n\n 1.1st Rout Details";
        cout<<"\n\n 2.2nd Rout Details";
        cout<<"\n\n 3.3rd Rout Details";
        cout<<"\n\n 4.4th Rout Details";
        cout<<"\n\n 5.5th Rout Details";
        cout<<"\n\n Enter Your Choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            system("cls");
            cout<<"\n\t\t _____BUS MANAGEMENT____";
            cout<<"\n From Fulbarigate  to  Shibbarimor";
            cout<<"\n 8.00 am ............9.00 am";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 9.00 am ............11.00 am";
            cout<<"\n From Fulbarigate to  Shibarimor";
            cout<<"\n 10.00 am ............11.00 am";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 11.00 am ............2.00 pm";
            break;
        case 2:
            system("cls");
            cout<<"\n\t\t _____BUS MANAGEMENT____";
            cout<<"\n From Doulotpur  to  Shibbarimor";
            cout<<"\n 8.00 am ............9.00 am";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 9.00 am ............11.00 am";
            cout<<"\n From Doulotpur to  Shibarimor";
            cout<<"\n 10.00 am ............11.00 am";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 11.00 am ............2.00 pm";
            break;
        case 3:
            system("cls");
            cout<<"\n\t\t _____BUS MANAGEMENT____";
            cout<<"\n From Doulotpur  to  Shibbarimor";
            cout<<"\n 8.00 am ............9.00 am";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 9.00 am ............11.00 am";
            cout<<"\n From Doulotpur to  Shibarimor";
            cout<<"\n 10.00 am ............11.00 am";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 11.00 am ............2.00 pm";
            break;
        case 4:
            system("cls");
            cout<<"\n\t\t _____BUS MANAGEMENT____";
            cout<<"\n From Shiromoni  to  Shibbarimor";
            cout<<"\n 8.00 am ............9.00 am";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 9.00 am ............11.00 am";
            cout<<"\n From shirommoni to  Shibarimor";
            cout<<"\n 10.00 am ............11.00 am";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 11.00 am ............2.00 pm";
            break;
        case 5:
            system("cls");
            cout<<"\n\t\t _____BUS MANAGEMENT____";
            cout<<"\n From KUET to  Shibbarimor";
            cout<<"\n 5.00 pm ............6.00 pm";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 6.00 pm ............9.00 pm";
            cout<<"\n From KUET to  Shibarimor";
            cout<<"\n 6.00 pm ............7.00 pm";
            cout<<"\n  From shibbarimor to Dhaka ";
            cout<<"\n 7.00 pm ............10.00 pm";
            break;
        default:
            cout<<"\n\n Invalid Choice ..plz try again..";

        }




    }






void bus::detail_bus()
{
        system("cls");
       //int choice;
       fstream file;
       fstream file1;
       string tbus_no,seat_no,seat_bus_no;
       int cnt=0,found=0;
       cout<<"\n\t\t \t\t\t_____BUS MANAGEMENT____";
       file.open("bus.txt",ios::in);
       file1.open("seat.txt",ios::in);

      if(!file || !file1)
       {
           cout<<"\n\nfile openning error";
       }
       else
       {
           cout<<"\n\n Bus No";
           cin>>tbus_no;
           file1>>seat_bus_no>>seat_no;

           while(!file1.eof())
           {
               if(tbus_no==seat_bus_no)
               {
                   cnt++;
               }
                file1>>seat_bus_no>>seat_no;
           }
           file1.close();
           file>>bus_no>>bus_name>>bus_seat>>driver_name;
             while(!file.eof())
           {
               if(tbus_no==bus_no)
               {
                   system("cls");
                   cout<<"\n\t\t _____BUS MANAGEMENT____";
                   cout<<"\n\n Total no of seats:"<<bus_seat;
                   cout<<"\n\nReserved no of seats:"<<cnt;
                   cout<<"\n\n Empty no of seats:"<<bus_seat-cnt;
                   found++;

               }
            file>>bus_no>>bus_name>>bus_seat>>driver_name;
           }
           file.close();
           if(found==0)
           {
               cout<<"\n\n bus no is invalid";
           }
       }


}





void bus:: booking()
{
     p:
     system("cls");
     fstream file;
     string tbus_no,seat_bus_no,Customer_Name,phone,from,to;
     int found=0,seat_no,seat,cnt=0,seat_seat_no,ss_no[20],i=0,s_amount;
     int total_amount=0,receive_amount=0;
     char x;
     cout<<"\n\t\t _____BUS MANAGEMENT____";
     file.open("bus.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n file opening error";
     }
     else

     {
         cout<<"\n\n Bus No.";
         cin>>tbus_no;
         file.close();
         file.open("seat.txt",ios::in);
         if(file)
         {

         file>>seat_bus_no>>seat_seat_no;
         while(!file.eof())
         {

             if(tbus_no==seat_bus_no)
             {
                 cnt++;
             }

          file>>seat_bus_no>>seat_seat_no;
         }

         file.close();

         }

         file.open("bus.txt",ios::in);
         file>>bus_no>>bus_name>>bus_seat>>driver_name;

         while(!file.eof())
         {

             if(tbus_no==bus_no)
             {
                 seat=bus_seat;
                 found++;
             }

         file>>bus_no>>bus_name>>bus_seat>>driver_name;

         }

         file.close();

         if(seat-cnt==0)
         {
             cout<<"All seat is reserved already";
         }

          else  if(found==1)
         {
             do
             {
            h:
            cout<<"Enter seat no:";
            cin>>seat_no;
            if(seat_no>seat)
            {

                cout<<"seat no is invalid..plz try again..";
                goto h;


            }

            file.open("seat.txt",ios::in);
            if(!file)
               {
                   file.open("seat.txt",ios::app|ios::out);
                    file<<tbus_no<<" "<<seat_no<<"\n";
                    file.close();
               }
            else
            {
                  file>>seat_bus_no>>seat_seat_no;
                  while(!file.eof())
                  {
                      if(tbus_no==seat_bus_no && seat_no==seat_seat_no)
                      {
                          cout<<"\n\n seat is already reserved..try again plz";
                          goto h;
                      }
                      file>>seat_bus_no>>seat_seat_no;
                  }
                   file.close();
                   file.open("seat.txt",ios::app|ios::out);
                   file<<tbus_no<<" "<<seat_no<<"\n";
                   file.close();
            }

            ss_no[i]=seat_no;
            i++;
            cout<<"\n\n Booking Another seat(Y,N)";
            cin>>x;

            }while(x=='y'||x=='Y');

            system("cls");
            cout<<"\n\t\t _____BUS MANAGEMENT____";
            cout<<"\n\n Customer Name:";
            cin>>Customer_Name;
            cout<<"\n\n Customer Phn No:";
            cin>>phone;
            cout<<"\n\n From:";
            cin>>from;
            cout<<"\n\n To:";
            cin>>to;
            cout<<"\n\n Single seat amount:";
            cin>>s_amount;
            total_amount=s_amount*i;
            cout<<"\n\n Total amount:"<<total_amount;

            cout<<"\n\n Receive amount:";
            cin>>receive_amount;

            file.open("customer.txt",ios::app|ios::in);
            file<<Customer_Name<<" "<<tbus_no<<" "<<phone<<" "<<i<<" "<<total_amount<<" ";
            file.close();
            system("cls");
            cout<<"\n\n\t\t\t\t\t  _____BUS MANAGEMENT____";
            //cout<<"\n\n\t\t\t\t\t   **********************";
            cout<<"\n\n\t\t\t\t\t_______BOOKING INFORMATION______";
            cout<<"\n\n\t\t\t\t\t     **********************";
            cout<<"\n\n\t\t\t\t\tNAME                 :"<<Customer_Name;
            cout<<"\n\n\t\t\t\t\tFROM                 :" <<from;
            cout<<"\n\n\t\t\t\t\tTO                   :" <<to;
            cout<<"\n\n\t\t\t\t\tTotal reserved seats :";
            for(int a=0;a<i;a++)
            {
               if(a!=0)
                   cout<<",";
                cout<<ss_no[a];
            }
            cout<<"\n\n\t\t\t\t\tSingle seat amount   :"<<s_amount;
            cout<<"\n\n\t\t\t\t\tTotal amount         :"<<total_amount;
            cout<<"\n\n\t\t\t\t\tReceived amount      :"<<receive_amount;
            cout<<"\n\n\t\t\t\t\tReturn amount        :"<<receive_amount-total_amount;
            cout<<"\n\n";
            cout<<"\n\n\t\t\t\t\t     **********************";
            cout<<"\n\n\t\t\t\t\t  | Thank You So Much For Booking... |";
            cout<<"\n\n\t\t\t\t\t     **********************";




         }

         else
         {
             cout<<"Bus no is invalid .. plz try again..";
             getch();
             goto p;
         }
     }


}

class Azhar:public bus{



public:
void welcome_msg(){
cout << "Welcome to our Admin Panel" << endl;

}


};







int main()
{

     Azhar wel;
     wel.welcome_msg();

       bus b;

   p:
       //system("cls");
       string email,pass;
       char ch;

    BusReservationSystem a;
    cout<<a;

    cout<<"\n\n";
    cout<<"\nENTER YOUR EMAIL:"<<endl;
    cin>>email;
    cout<<"\n ENTER YOUR PASSWORD:";
    for(int i=0;i<6;i++)
   {
       ch=getch();
       pass+=ch;
       cout<<"*";
   }

    if(email=="josephiteazharuddin@gmail.com" && pass=="aazhar")
   {
       cout<<"\n\n\n\t\t Loading..";
//       for(int i=1;i<=100;i++)
//      {
//           sleep(200);
//           cout<<".";
//      }

       b.menu();
   }
   else
   {
       cout<<"\n\n\t\t Your Email or Password is wrong...";
       getch();
       goto p;
   }

    return 0;
}



