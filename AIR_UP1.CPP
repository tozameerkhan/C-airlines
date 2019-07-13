#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;
class Inquiry
{
	public:
	void airportInformation()
	{
		int s;
		cout<<"\nPress 1 for Delhi Airport"<<endl;
		cout<<"Press 2 for Mumbai Airport"<<endl;
		cout<<"Press 3 for Hyderabad Airport"<<endl;
		cout<<"Press 4 for Dubai Airport"<<endl;
		cout<<"Press 5 for London Airport"<<endl;
		cout<<"Press 6 for Goa Airport"<<endl;
		cout<<"Press 7 for Lucknow Airport"<<endl;
		cin>>s;
		
		switch(s)
		{
			case 1:
			cout<<"\n1->Delhi"<<endl;
			cout<<"Todays India Lounge is available on payment basis to non-entitled passengers ";
			cout<<"lounge includes Wi-Fi, Drinks, TV, Snacks/Meals ";
			cout<<"Duty Free Shops, Food Outlets and Bars, Book Stores are also available."<<endl;
			break;
			
			case 2:
			cout<<"\n2->Mumbai"<<endl;
			cout<<"Effective from 1st October 2015 , Todays India commences Domestic Operations from Terminal 2 of the Mumbai International Airport."<<endl;
			cout<<"Todays India is the first Indian airline having both domestic & International from the same International Terminal 2"<<endl;
			break;
			
			case 3:
			cout<<"\n3->Hyderabad"<<endl;
			cout<<"Air-conditioned Buses [Pushpak Airport Liner] run by APSRTC are available ";
			cout<<"from 3 am until 11:30 pm. Normal APSRTC bus services are also available."<<endl;
			break;
			
			case 4:
			cout<<"\n4->Dubai"<<endl;
			cout<<" Five transfer desks available throughout the Concourse on the Arrivals level , ";
			cout<<" near Gates 22, 18, 14 and 8 and one at the Arrival Remote Gate."<<endl;
			break;
			
			case 5:
			cout<<"\n5->London"<<endl;
			cout<<"First class /Business class /Online Checked-in passengers - One and a half hours before departure ";
			cout<<"Economy Class Passengers- Three Hours before departure ";
			cout<<"Check in Counters close One Hour before departure"<<endl;
			break;
			
			case 6:
			cout<<"\n6->Goa"<<endl;
			cout<<"    No Transit Lounge and No Transfer Desk available."<<endl;
			break;
			
			case 7:
			cout<<"\n7->Lucknow"<<endl;
			cout<<"Duty free shop in Arrival & Departure Hall , No Internet Service , No Cyber Cafe , ";
			cout<<"No Todays India Lounge , No Transit Lounge, U.P. Roadways Service from Airport to Railway ";
			cout<<"Station & Inter State Bus Stand."<<endl;
			break;
			
			default:
			cout<<"Enter a valid choice.."<<endl;
		}
	}
	
	void routeMap()
	{
		cout<<"\nAvailable Routes & their Prices excluding GST::"<<endl;
		cout<<"1->Mumbai To Goa Flights       -->INR 4,000"<<endl;
		cout<<"2->Delhi to Hyderabad Flights  -->INR 12,000"<<endl;
		cout<<"3->Delhi to Mumbai Flights     -->INR 10,000"<<endl;
		cout<<"4->Chennai to Delhi Flights    -->INR 8,000"<<endl;
		cout<<"5->Delhi to Lucknow Flights    -->INR 5,000"<<endl;
		cout<<"6->Delhi to London Flights     -->INR 30,000"<<endl;
		cout<<"7->Delhi to Dubai Flights      -->INR 25,000"<<endl;
	}
	
	void healthSafety()
	{
		cout<<"\nHEALTH AND SAFETY"<<endl;
		cout<<"        Whether it's your first flight or one of many, at Todays India Airlines ";
		cout<<"your safety is of paramount importance to us. Our young, modern and well ";
		cout<<"maintained fleet and compliance to international safety standards ensures that";
		cout<<" your favourite airline is also continues to be a safe airline."<<endl;
	}
	
	void feedback()
	{
		fflush(stdin);
		char ch[100];
		cout<<"\nWe'd love to here from you"<<endl;
		gets(ch);
	}
};

class PlanYourTravel
{
	public:
	int tickNum;
	long totalcost;
	int age;
	char name[20];
	char from[20];
	char to[20];
	int day,mon,year;
	int amount;
	int rem;
	
	PlanYourTravel()
	{
		tickNum=1000;
	}
	
	void bookticket()
	{
		char str[20];
		char s11[]="AIR";
		int s;
		int n;
		cout<<"\nSelect route from the available list"<<endl;
		cout<<"1)Mumbai To Goa Flights       -->INR 4,000"<<endl;
		cout<<"2)Delhi to Hyderabad Flights  -->INR 15,000"<<endl;
		cout<<"3)Delhi to Mumbai Flights     -->INR 10,000"<<endl;
		cout<<"4)Chennai to Delhi Flights    -->INR 8,000"<<endl;
		cout<<"5)Delhi to Lucknow Flights    -->INR 5,000"<<endl;
		cout<<"6)Delhi to London Flights     -->INR 25,000"<<endl;
		cout<<"7)Delhi to Dubai Flights      -->INR 11,000"<<endl;
		cin>>s;
		fflush(stdin);
	
		switch(s)
		{
			case 1:
			cout<<"\nTicket for Mumbai to Goa:"<<endl;
			cout<<"\nEnter your Name= ";
			gets(name);
			cout<<"Enter your age= ";
			cin>>age;
			cout<<"Enter date= ";
			cin>>day;
			cout<<"Enter month :: ";
			cin>>mon;
			cout<<"Enter year :: ";
			cin>>year;
			strcpy(from,"Mumbai");
			strcpy(to,"Goa");
			totalcost=(5*4000)/100+4000;
				cout<<"Total Cost = Fare + GST =INR "<<totalcost<<endl;
			cout<<"Please pay the Amount ::";
			cin>>amount;
			if(amount==totalcost)
			{
				cout<<"\nCongratulations! Your Ticket has been confirmed"<<endl;
				tickNum=tickNum+1;
				cout<<"\nKindly Check-in before 2 hours of departure"<<endl;
				cout<<"        Thank You! Have a safe Journey.."<<endl;
				print();
			}
			else
			{
				cout<<"ERROR! \n Please pay the remaining balance.."<<(rem=totalcost-amount)<<endl;
				cin>>rem;
				amount=amount+rem;
				if(amount==totalcost)
				{
					cout<<"\n``Congratulations`` Your Ticket has now been confirmed"<<endl;
					tickNum=tickNum+1;
					cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
					cout<<"        Thank You! Have a Happy Journey"<<endl;
					print();
				}
				else
				{
					cout<<"\nERROR! \n Transaction is declined. \nPLease try again.."<<endl;
					cout<<"INR "<<amount<<" is credit into your account"<<endl;
				}
			}
			break;
			
			case 2:
			cout<<"\nTickets for Delhi to Hyderabad"<<endl;
			cout<<"\nEnter your Name ::";
			gets(name);
			cout<<"\nEnter your age ::";
			cin>>age;
			cout<<"Enter date ::";
			cin>>day;
			cout<<"Enter month :: ";
			cin>>mon;
			cout<<"Enter year :: ";
			cin>>year;
			strcpy(from,"Delhi");
			strcpy(to,"Hydrabad");
			totalcost=(5*15000)/100+15000;
			cout<<"Total Cost = Fare + GST =INR "<<totalcost<<endl;
			cout<<"Please pay the Amount ::";
			cin>>amount;
			if(amount==totalcost)
			{
				cout<<"\nCongratulations! Your Ticket has been confirmed"<<endl;
				tickNum=tickNum+1;
				cout<<"\nKindly Check-in before 2 hours of departure"<<endl;
				cout<<"        Thank You! Have a safe Journey"<<endl;
				print();
			}
			else
			{
				cout<<"ERROR!! \n Please pay the remaining balance.."<<(rem=totalcost-amount)<<endl;
				cin>>rem;
				amount=amount+rem;
				if(amount==totalcost)
				{
					cout<<"\nCongratulations! Your Ticket has been confirmed"<<endl;
					tickNum=tickNum+1;
					cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
					cout<<"        Thank You! Have a safe Journey"<<endl;
					print();
				}
				else
				{
					cout<<"\nERROR! \nTransaction is declined. \nPLease try again.."<<endl;
					cout<<"INR "<<amount<<" is credit into your account"<<endl;
				}
			}
			break;
			
			case 3:
			cout<<"\nTickets for Delhi to Mumbai"<<endl;
			cout<<"\nEnter your Name ::";
			gets(name);
			cout<<"\nEnter your age ::";
			cin>>age;
			cout<<"Enter date ::";
			cin>>day;
			cout<<"Enter month :: ";
			cin>>mon;
			cout<<"Enter year ::";
			cin>>year;
			strcpy(from,"Delhi");
			strcpy(to,"Mumbai");
			totalcost=(5*10000)/100+10000;
			cout<<"Total Cost = Fare + GST =INR "<<totalcost<<endl;
			cout<<"Please pay the Amount ::";
			cin>>amount;
			if(amount==totalcost)
			{
				cout<<"\nCongratulations! Your Ticket has been booked"<<endl;
				tickNum=tickNum+1;
				cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
				cout<<"        Thank You! \nHave a safe Journey"<<endl;
				print();
			}
			else
			{
				cout<<"ERROR!! \n Please pay the remaining balance.."<<(rem=totalcost-amount)<<endl;
				cin>>rem;
				amount=amount+rem;
				if(amount==totalcost)
				{
					cout<<"\nCongratulations! Your Ticket has been booked"<<endl;
					tickNum=tickNum+1;
					cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
					cout<<"        Thank You! Have a safe Journey"<<endl;
					print();
				}
				else
				{
					cout<<"\nERROR! \nTransaction is declined. \nPLease try again.."<<endl;
					cout<<"INR "<<amount<<" is credit into your account"<<endl;
				}
			}
			break;
			
			case 4:
			cout<<"\nTickets for Chennai to Delhi"<<endl;
			cout<<"\nEnter your Name ::";
			gets(name);
			cout<<"\nEnter your age ::";
			cin>>age;
			cout<<"Enter date ::";
			cin>>day;
			cout<<"Enter month :: ";
			cin>>mon;
			cout<<"Enter year :: ";
			cin>>year;
			strcpy(from,"Chennai");
			strcpy(to,"Delhi");
			totalcost=(5*8000)/100+8000;
			cout<<"Total Cost = Fare + GST =INR "<<totalcost<<endl;
			cout<<"Please pay the Amount ::";
			cin>>amount;
			if(amount==totalcost)
			{
				cout<<"\nCongratulations! Your Ticket has been booked"<<endl;
				tickNum=tickNum+1;
				cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
				cout<<"        Thank You! Have a Happy Journey"<<endl;
				print();
			}
			else
			{
				cout<<"ERROR!! \n Please pay the remaining balance.."<<(rem=totalcost-amount)<<endl;
				cin>>rem;
				amount=amount+rem;
				if(amount==totalcost)
				{
					cout<<"\nCongratulations! Your Ticket has been booked"<<endl;
					tickNum=tickNum+1;
					cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
					cout<<"        Thank You! Have a Happy Journey"<<endl;
					print();
				}
				else
				{
					cout<<"\nERROR!! \nTransaction is declined. \nPLease try again.."<<endl;
					cout<<"INR "<<amount<<" is credit into your account"<<endl;
				}
			}
			break;
			
			case 5:
			cout<<"\nTickets for Delhi to Lucknow"<<endl;
			cout<<"\nEnter your Name ::";
			gets(name);
			cout<<"\nEnter your age ::";
			cin>>age;
			cout<<"Enter date ::";
			cin>>day;
			cout<<"Enter month :: ";
			cin>>mon;
			cout<<"Enter year :: ";
			cin>>year;
			strcpy(from,"Delhi");
			strcpy(to,"Lucknow");
			totalcost=(5*5000)/100+5000;
			cout<<"Total Cost = Fare + GST =INR "<<totalcost<<endl;
			cout<<"Please pay the Amount ::";
			cin>>amount;
			if(amount==totalcost)
			{
				cout<<"\nCongratulations! Your Ticket has been booked"<<endl;
				tickNum=tickNum+1;
				cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
				cout<<"        Thank You! \nHave a Happy Journey"<<endl;
				print();
			}
			else
			{
				cout<<"ERROR!! \n Please pay the remaining balance.."<<(rem=totalcost-amount)<<endl;
				cin>>rem;
				amount=amount+rem;
				if(amount==totalcost)
				{
					cout<<"\nCongratulations! Your Ticket has been booked"<<endl;
					tickNum=tickNum+1;
					cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
					cout<<"        Thank You! \nHave a Happy Journey"<<endl;
					print();
				}
				else
				{
					cout<<"\nERROR!! \n Transaction is declined. \nPLease try again.."<<endl;
					cout<<"INR "<<amount<<" is credit into your account"<<endl;
				}

			}
			break;
			
			case 6:
			cout<<"\nTickets for Delhi to London"<<endl;
			cout<<"\nEnter your Name ::";
			gets(name);
			cout<<"\nEnter your age ::";
			cin>>age;
			cout<<"Enter date ::";
			cin>>day;
			cout<<"Enter month :: ";
			cin>>mon;
			cout<<"Enter year :: ";
			cin>>year;
			strcpy(from,"Delhi");
			strcpy(to,"London");
			totalcost=(5*25000)/100+25000;
			cout<<"Total Cost = Fare + GST =INR "<<totalcost<<endl;
			cout<<"Please pay the Amount ::";
			cin>>amount;
			if(amount==totalcost)
			{
				cout<<"\nCongratulations! Your Ticket has been booked"<<endl;
				tickNum=tickNum+1;
				cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
				cout<<"        Thank You \n Have a Happy Journey"<<endl;
				print();
			}
			else
			{
				cout<<"ERROR!! \n Please pay the remaining balance.."<<(rem=totalcost-amount)<<endl;
				cin>>rem;
				amount=amount+rem;
				if(amount==totalcost)
				{
					cout<<"\nCongratulations Your Ticket has been booked"<<endl;
					tickNum=tickNum+1;
					cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
					cout<<"        Thank You \n Have a Happy Journey"<<endl;
					print();
				}
				else
				{
					cout<<"\nERROR!! \n Transaction is declined. \nPLease try again.."<<endl;
					cout<<"INR "<<amount<<" is credit into your account"<<endl;
				}
			}
			break;
			
			case 7:
			cout<<"\nTickets for Delhi to Dubai"<<endl;
			cout<<"\nEnter your Name ::";
			gets(name);
			cout<<"\nEnter your age ::";
			cin>>age;
			cout<<"Enter date ::";
			cin>>day;
			cout<<"Enter month :: ";
			cin>>mon;
			cout<<"Enter year :: ";
			cin>>year;
			strcpy(from,"Delhi");
			strcpy(to,"Dubai");
			totalcost=(5*11000)/100+11000;
			cout<<"Total Cost = Fare + GST =INR "<<totalcost<<endl;
			cout<<"Please pay the Amount ::";
			cin>>amount;
			if(amount==totalcost)
			{
				cout<<"\nCongratulations Your Ticket has been booked"<<endl;
				tickNum=tickNum+1;
				cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
				cout<<"        Thank You \n Have a Happy Journey"<<endl;
				print();
			}
			else
			{
				cout<<"ERROR!! \n Please pay the remaining balance.."<<(rem=totalcost-amount)<<endl;
				cin>>rem;
				amount=amount+rem;
				if(amount==totalcost)
				{
					cout<<"\nCongratulations !Your Ticket has been booked"<<endl;
					tickNum=tickNum+1;
					cout<<"\nPlease Check-in before 2 hours of departure"<<endl;
					cout<<"        Thank You \n Have a Happy Journey"<<endl;
					print();
				}
				else
				{
					cout<<"\n!!ERROR!! \nTransaction is declined. \nPLease try again.."<<endl;
					cout<<"INR "<<amount<<" is credit into your account"<<endl;
				}
			}
			break;
			}
		ofstream ofs,ofs1;
		ofs.open("ticket.txt",ios::out|ios::binary|ios::app);
		ofs.write((char*)this,sizeof(*this));
		ofs.close();
		sprintf(str,"%s-%d",s11,tickNum);
		strcat(str,".txt");
		ofs1.open(str);
		ofs1<<"\n--------------------------------------------------------------------------------"<<endl;
		ofs1<<"|                        ~~~~ Todays India Airlines ~~~~"<<endl;
		ofs1<<"|*******************************************************************************"<<endl;
		ofs1<<"|Ticket Number: "<<tickNum<<"                                       Date ::"<<day<<"-"<<mon<<"-"<<year<<endl;
		ofs1<<"|                           Passenger Name ::"<<name<<endl;
		ofs1<<"|                           Passenger age ::"<<age<<endl;
		ofs1<<"|"<<endl;			ofs1<<"|Destination: From "<<from<<"          ----->>                 To: "<<to<<"."<<endl;
		ofs1<<"|"<<endl;
		ofs1<<"|                         Total Amount Paid ::INR "<<totalcost<<endl;
		ofs1<<"|*******************************************************************************"<<endl;
		ofs1<<"|                         Have a Happy and Safe Journey"<<endl;
		ofs1<<"--------------------------------------------------------------------------------"<<endl;
		ofs1.close();
	}
	
	void print()
	{
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"|                        ~~~~ Todays India Airlines ~~~~"<<endl;
		cout<<"|*******************************************************************************"<<endl;
		cout<<"|Ticket Number: "<<tickNum<<"                                       Date ::"<<day<<"-"<<mon<<"-"<<year<<endl;
		cout<<"|                           Passenger Name ::"<<name<<endl;
		cout<<"|                           Passenger age ::"<<age<<endl;
		cout<<"|"<<endl;			cout<<"|Destination: From "<<from<<"          ----->>                 To: "<<to<<"."<<endl;
		cout<<"|"<<endl;
		cout<<"|                         Total Amount Paid ::INR "<<totalcost<<endl;
		cout<<"|*******************************************************************************"<<endl;
		cout<<"|                         Have a Happy and Safe Journey"<<endl;
		cout<<"--------------------------------------------------------------------------------"<<endl;
	}
	
	void viewAllTickets()
	{
		ifstream ifs("ticket.txt",ios::in|ios::binary);
		if(!ifs)
		{
			cout <<"File Not Found!" <<endl;
		}
		else
		{
			ifs.read((char*)this,sizeof(*this));
			while(!ifs.eof())
			{
				print();
				ifs.read((char*)this,sizeof(*this));
			}
		}
	}
	
	void getTicket()
	{
		cout<<"\nName ::"<<name<<endl;
		cout<<"Age ::"<<age<<endl;
		cout<<"Ticket Number ::"<<tickNum<<endl;
		cout<<"Date :: "<<day<<"-"<<mon<<"-"<<year<<endl;
		cout<<"From "<<from<<" To "<<to<<endl;
		cout<<"Total Cost ::"<<totalcost<<endl;
	}
	
	void status()
	{
		int flag=0;
		char name[20];
		fflush(stdin);
		cout<<"Enter the name of whom you want to search ticket status for: "<<endl;
		gets(name);
		ifstream ifs;
		ifs.open("ticket.txt",ios::binary);
		ifs.read((char*)this,sizeof(*this));
		while(!ifs.eof())
		{
			if(!strcmp(this->name,name))
			{
				cout<<"Ticket Found ::"<<endl;
				this->getTicket();
				flag=1;
				cout<<"\nDo you want to print Ticket?\n    If yes press 'p' or 'P'"<<endl;
				char p;
				cin>>p;
				if(p=='p'||'P')
				{
					print();
				}
				break;
			}
			ifs.read((char*)this,sizeof(*this));
		}
		if(flag==0)
		{
			cout<<"Searched Ticket could not be found "<<endl;
		}
	 }
	 
	 void updateTicket()
	 {
		char ch,name[20];
		int tn,flag=0,age;
		int op;
		char n1[20];
		fflush(stdin);
		cout << "Enter Name whose Ticket Need to be Updated :: " <<endl;
		gets(name);
		cout<<"Your Searched Ticket Name :: " <<name <<endl;
		fflush(stdin);
		fstream fs;
		fs.open("ticket.txt",ios::in|ios::out|ios::binary|ios::ate);
		fs.seekg(0);
		fs.read((char*)this,sizeof(*this));
		while(!fs.eof())
		{
			//cout << "Inside Loop.." <<endl;
			if(!strcmp(this->name,name))
			{
			cout<<"\nTicket Found ::"<<endl;
			this->getTicket();
			flag=1;
			up:
			cout << "What Would You Like to Update ::" <<endl;
			cout << "Choose Your Options :: " <<endl;
			cout << "1. Name \t\t 2. Age"<<endl;
			cout << "3. Date Of Journey\t\t 4. Source"<<endl;
			cout << "5.Destination"<<endl;
			cin>>op;
			switch(op)
			{
			case 1 :
			cout << "You are Looking for Updation of Name!"<<endl;
			cout << " Enter Your New Name :: "<<endl;
			fflush(stdin);
			gets(n1);
			cout << "New Name You Have Entered Is :: "<<n1<<endl;
			strcpy(this->name,n1);
			fs.seekp(fs.tellp()-sizeof(*this));
			fs.write((char*)this,sizeof(*this));
			cout << "Name Updated Successfully..." <<endl;
			fs.close();
			break;
			case 2 :
			cout << "You are Looking for Updation of Age!"<<endl;
			cout << " Enter Your New Age :: "<<endl;
			cin >> age;
			cout << "New Age You Have Entered Is :: "<<age<<endl;
			this->age = age;
			fs.seekp(fs.tellp()-sizeof(*this));
			fs.write((char*)this,sizeof(*this));
			cout << "Age Updated Successfully..." <<endl;
			fs.close();
			break;
			case 3 :
			cout << "Warning!!"<<endl;
			cout << "Updation in Date Of Journey Might Cancel Your Ticket.." <<endl;
			cout << "Do You Agree ? (Press Y/N) :: " <<endl;
			cin >> ch;
			if(ch=='y' || ch=='Y')
			{
				fs.close();
				cancel();
				bookticket();
				break;
			}
			break;
			case 4 :
			cout << "Warning!!"<<endl;
			cout << "Updation in Source Might Cancel Your Ticket.." <<endl;
			cout << "Do You Agree ? (Press Y/N) :: " <<endl;
			cin >> ch;
			if(ch=='y' || ch=='Y')
			{
				fs.close();
				cancel();
				bookticket();
				break;
			}
			break;
			case 5 :
			cout << "Warning!!"<<endl;
			cout << "Updation in Destination Might Cancel Your Ticket.." <<endl;
			cout << "Do You Agree ? (Press Y/N) :: " <<endl;
			cin >> ch;
			if(ch=='y' || ch=='Y')
			{
				fs.close();
				cancel();
				bookticket();
				break;
			}
			break;
			default :
			cout << "You Have Choosen Wrong Option..."<<endl;
			cout << "Choose Right Option..." <<endl;
			goto up;
			}//end of switch
			}//end of if
			fs.read((char*)this,sizeof(*this));
		}//end of while
		fs.close();
		if(flag==0)
		{
			cout<<"Sorry!!Searched Ticket could not Found... "<<endl;
		}
		else
		{
			cout << "Your Data Updated Successfully..." <<endl;
		}

	 }
	
	 void cancel()
	 {
		cout<<"\nWARNING!! \nIf you cancel your ticket 6% of the total amount won't be refunded"<<endl;
		int flag=0;
		char name[20];
		int charge;
		fflush(stdin);
		cout<<"\nEnter the Name whose ticket you want to cancel : "<<endl;
		gets(name);
		ifstream ifs;
		ifs.open("ticket.txt",ios::binary);
		ofstream ofs("ticket1.txt",ios::binary|ios::ate);
		ifs.read((char*)this,sizeof(*this));
		while(!ifs.eof())
		{
			if(!strcmp(this->name,name))
			{
				cout<<"\nTicket Found ::"<<endl;
				this->getTicket();
				cout<<"\nAmount deducted ::INR "<<(totalcost*6)/100<<"."<<endl;
				cout<<"-->INR "<<totalcost-(totalcost*6)/100<<" is credit into your account."<<endl;
				flag=1;
			}
			else
			{
				ofs.write((char*)this,sizeof(*this));
			}
			ifs.read((char*)this,sizeof(*this));
		}
		ofs.close();
		ifs.close();
		remove("ticket.txt");
		rename("ticket1.txt","ticket.txt");
		if(flag==0)
		{
			cout<<"Searched Ticket could not be found "<<endl;
		}
		else
		{
			cout << "Ticket Cancelled Successfully..." <<endl;
		}
	 }
};


class SelectOption
{
	public:
	void option()
	{
		char ch;
		Inquiry in;
		PlanYourTravel p;
		int a;
		do
		{
			cout<<"\nKindly :"<<endl;
			cout<<"Press 1 for Travel Information :: "<<endl;
			cout<<"Press 2 to Plan Your Journey :: "<<endl;
			cout<<"Press 3 to Check your Ticket Status :: "<<endl;
			cout<<"Press 4 to Cancel your Ticket :: "<<endl;
			cout<<"Press 5 to Update Your Booked Ticket :: " <<endl;
			cout <<"Press 6 to Print All Tickets :: " <<endl;
			cin>>a;
			switch(a)
			{
				case 1:
				int b;
				cout<<"\nSelect whose information you desire:"<<endl;
				cout<<"1) Airport Information"<<endl;
				cout<<"2) Route Map"<<endl;
				cout<<"3) Health and Safety"<<endl;
				cout<<"4) Feedback"<<endl;
				cin>>b;
				switch(b)
				{
					case 1:
						in.airportInformation();
					break;
		
					case 2:
					  	in.routeMap();
					break;
		
					case 3:
						in.healthSafety();
					break;
		
					case 4:
						in.feedback();
					break;
		
					default:
						cout<<"Error!"<<endl;
					break;
				 }
				 break;
		
				 case 2:
				 	p.bookticket();
				 break;
		
				 case 3:
				 	p.status();
				 break;
		
				 case 4:
				 	p.cancel();
				 break;
		
				 case 5:
				 	p.updateTicket();
				 break;
		
				 case 6:
				 	p.viewAllTickets();
				 break;
		
				 default:
				 cout<<"Error!"<<endl;
			}
			cout<<"\n\nDo you want to Continue"<<endl;
			cin>>ch;
		}while(ch=='Y'|| ch=='y');
	}
};

int main()
{
	//clrscr();
	cout<<"CODE BY :-ZAMEER KHAN"<<endl;
	cout<<"                                      ------------------------Welcome to The Indian Airlines--------------------------"<<endl;
	cout<<"                                                             **Where will tomorrow take you**"<<endl;
	SelectOption op;
	op.option();
	//getch();
}
