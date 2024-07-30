
#include <mysql.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>		// std::chrono::seconds

using namespace std;
class Inquiry
{
public:
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;

	void airportInformation()
	{
		char s;
	label1:
		cout << "***************************************************" << endl;
		cout << "\nPress [1] For Delhi Airport" << endl;
		cout << "Press [2] For Mumbai Airport" << endl;
		cout << "Press [3] For Hyderabad Airport" << endl;
		cout << "Press [4] For Dubai Airport" << endl;
		cout << "Press [5] For London Airport" << endl;
		cout << "Press [6] For Goa Airport" << endl;
		cout << "Press [7] For Lucknow Airport" << endl;
		cout << "***************************************************" << endl;
		char buff[BUFSIZ];
		fgets(buff, sizeof buff, stdin);
		cout << "-> ";
		scanf("%c", &s);

		for (int i = 1; i > 0; --i) 
		{
			cout << "...................................................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";

		switch (s)
		{
		case 49:
			cout << "***************************************************" << endl;
			cout << "\n1->Delhi :-" << endl;
			cout << "-----------" << endl;
			cout << "           Todays India Lounge is available on payment basis to non-entitled ";
			cout << "passengers lounge includes Wi-Fi, Drinks, TV, Snacks/Meals, Duty ";
			cout << "Free Shops, Food Outlets and Bars, Book Stores are also available." << endl;
			cout << "\n***************************************************" << endl;
			break;

		case 50:
			cout << "***************************************************" << endl;
			cout << "\n2->Mumbai :-" << endl;
			cout << "------------ " << endl;
			cout << "            Effective from 1st October 2015 , Todays India commences Domestic ";
			cout << "Operations from Terminal 2 of the Mumbai International Airport." << endl;
			cout << "Todays India is the first Indian airline having both domestic & ";
			cout << "International from the same International Terminal 2." << endl;
			cout << "\n***************************************************" << endl;
			break;

		case 51:
			cout << "***************************************************" << endl;
			cout << "\n3->Hyderabad :-" << endl;
			cout << "---------------" << endl;
			cout << "               Air-conditioned Buses [Pushpak Airport Liner] run by APSRTC are ";
			cout << "available from 3 am until 11:30 pm. Normal APSRTC bus services are ";
			cout << "also available." << endl;
			cout << "\n***************************************************" << endl;
			break;

		case 52:
			cout << "***************************************************" << endl;
			cout << "\n4->Dubai :-" << endl;
			cout << "------------" << endl;
			cout << "            Five transfer desks available throughout the Concourse on the ";
			cout << "Arrivals level, near Gates 22, 18, 14 and 8 and one at the Arrival ";
			cout << "Remote Gate." << endl;
			cout << "\n***************************************************" << endl;
			break;

		case 53:
			cout << "***************************************************" << endl;
			cout << "\n5->London :-" << endl;
			cout << "------------" << endl;
			cout << "            First class /Business class /Online Checked-in passengers - One ";
			cout << "and a half hours before departure Economy Class Passengers- Three ";
			cout << "Hours before departure Check in Counters close One Hour before departure." << endl;
			cout << "\n***************************************************" << endl;
			break;

		case 54:
			cout << "***************************************************" << endl;
			cout << "\n6->Goa :-" << endl;
			cout << "-----------" << endl;
			cout << "           No Transit Lounge and No Transfer Desk available." << endl;
			cout << "\n***************************************************" << endl;
			break;

		case 55:
			cout << "***************************************************" << endl;
			cout << "\n7->Lucknow :-" << endl;
			cout << "---------------" << endl;
			cout << "               Duty free shop in Arrival & Departure Hall , No Internet Service ,";
			cout << "No Cyber Cafe , No Todays India Lounge , No Transit Lounge, ";
			cout << " U.P. Roadways Service from Airport to Railway Station & Inter";
			cout << " State Bus Stand." << endl;
			cout << "\n***************************************************" << endl;
			break;

		default:
			cout << "***************************************************" << endl;
			cout << "Error !" << endl;
			cout << "      Please select from Given Airport ::" << endl;
			goto label1;
			cout << "***************************************************" << endl;
		}
	}


	void dbconnect()
	{
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "12345", "airlines", 3306, NULL, 0);
	}


	void routeMap()
	{
		dbconnect();
		char query[50] = "SELECT * FROM flightdata";
		char from[20] = { '\0' };
		char to[20] = { '\0' };
		char price[20] = { '\0' };
		int i = 1, a = 1;

		a = mysql_query(conn, query);
		if (!a)
		{
			res = mysql_store_result(conn);
			cout << "***************************************************" << endl;
			cout << "\nAvailable Routes & their Prices excluding GST  ::" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

			while (row = mysql_fetch_row(res))
			{
				strcpy(from, row[1]);
				strcpy(to, row[2]);
				strcpy(price, row[3]);
				cout << "~" << i << "->[" << from << " To " << to << " Flights]";
				cout << " [Price --> INR " << price << "]." << endl;
				i++;

			}
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
		}
		else
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
	}


	void healthSafety()
	{
		cout << "***************************************************" << endl;
		cout << "\nHEALTH AND SAFETY" << endl;
		cout << "        Whether it's your first flight or one of many, at Todays India Airlines ";
		cout << "your safety is of paramount importance to us. Our young, modern and well ";
		cout << "maintained fleet and compliance to international safety standards ensures that";
		cout << " your favourite airline is also continues to be a safe airline." << endl;
		cout << "***************************************************" << endl;
	}


	void feedback()
	{
		dbconnect();
		char o;
		int a = 1;
		char ch[150];
		char name[20] = { '\0' };
		char s[100] = { '\0' };
		char buff[BUFSIZ];
		cout << "[1] See feedback :: " << endl;
		cout << "[2] Give Feedback :: " << endl;
		cout << "-> ";
		cin >> o;
		for (int i = 1; i > 0; --i) 
		{
			cout << "...................................................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		switch (o)
		{
		case 49:
			strcpy(s, "select * from feedback");
			a = mysql_query(conn, s);
			if (!a)
			{
				res = mysql_store_result(conn);
				while (row = mysql_fetch_row(res))
				{
					strcpy(name, row[0]);
					strcpy(ch, row[1]);
					cout << "Name -> " << name << "  Feedback --> " << ch << endl;
				}
			}
			else
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Server Down!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
			}
			break;

		case 50:
			cout << "***************************************************" << endl;
			cout << "\nWe'd love to hear from you" << endl;
			cout << "Enter Your Name :: ";
			fgets(buff, sizeof buff, stdin);
			cin.getline(name, 20);
			cout << "Enter Feedback :: ";
			cin.getline(ch, 99);
			dbconnect();
			strcpy(s, "INSERT INTO feedback VALUES('");
			strcat(s, name);
			strcat(s, "', '");
			strcat(s, ch);
			strcat(s, "')");
			a = mysql_query(conn, s);
			for (int i = 1; i > 0; --i) 
			{
				cout << "...................................................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			if (!a)
			{
				mysql_commit(conn);
				cout << "Feedback Submited!!" << endl;
			}
			else
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Server Down!!" << endl;
				cout << "Feedback not Submited!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			}
			cout << "***************************************************" << endl;
			break;
		}
	}
};


class PlanYourTravel
{
public:
	int tickNum;
	char buff[BUFSIZ];
	int totalcost = 0;
	char age[20] = { '\0' };
	char name[20] = { '\0' };
	char from[20];
	char fcode[11] = { '\0' };
	char to[20];
	char day[20];
	char seatNo[4] = { '\0' };
	char mon[20] = { '\0' };
	char year[20] = { '\0' };
	char amt[20] = { '\0' };
	int amount = 0;
	int total = 0, booked = 0;
	char ext[20] = { '\0' };
	int rem = 0, price = 0;
	int l = 0, flag1 = 0, a = 1;
	int flag = 0, seat = 0, pass = 1;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;

	PlanYourTravel()
	{
		dbconnect();
	}


	void dbconnect()
	{
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "12345", "airlines", 3306, NULL, 0);
	}


	void seatAvailability(char* fno)
	{
		a = 1;
		char s[100] = { '\0' };
		char ttotal[10] = { '\0' };
		char tbooked[10] = { '\0' };
		seat = 0;
		strcpy(s, "SELECT * FROM flightdata where flightno ='");
		strcat(s, fno);
		strcat(s, "'");
		a = mysql_query(conn, s);
		if (!a)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				flag = 1;
				total = 0;
				booked = 0;
				strcpy(ttotal, row[4]);
				strcpy(tbooked, row[5]);
				l = strlen(ttotal);
				for (int i = 0; i < l; i++)
				{
					int j = ttotal[i];
					j = j - 48;
					total = total * 10 + j;
				}
				l = strlen(tbooked);
				for (int i = 0; i < l; i++)
				{
					int j = tbooked[i];
					j = j - 48;
					booked = booked * 10 + j;
				}
				if (total > booked)
				{
					seat = 1;
				}
				else
				{
					seat = 0;
				}
			}
		}
		else
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			pass = 0;
		}

	}


	void settickNum()
	{
		dbconnect();
		string query = "SELECT * FROM ticketsdata";
		const char* q = query.c_str();
		int z = 0;
		int p = 0;
		a = 1;
		a = mysql_query(conn, q);
		if (!a)
		{
			res = mysql_store_result(conn);
			p = 0;
			char temp[5] = { '\0' };

			while (row = mysql_fetch_row(res))
			{
				z = 1;
				int ttemp = 0;
				strcpy(temp, row[0]);
				l = strlen(temp);

				for (int i = 0; i < l; i++)
				{
					int j = temp[i];
					j = j - 48;
					ttemp = ttemp * 10 + j;
				}

				if (p < ttemp)
				{
					p = ttemp;;
				}
			}

			if (z == 1)
			{
				p = p + 1;
				tickNum = p;
			}
			else
			{
				tickNum = 1001;
			}
		}
		else
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			pass = 0;
		}
	}


	void availFlight()
	{
		dbconnect();
		a = 1;
		char query[50] = "SELECT * FROM flightdata";
		char from[20] = { '\0' };
		char to[20] = { '\0' };
		char price[20] = { '\0' };
		int i = 1;
		a = mysql_query(conn, query);
		if (!a)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				strcpy(from, row[1]);
				strcpy(to, row[2]);
				strcpy(price, row[3]);
				cout << "~[" << i << "] " << from << " To " << to << " Flights";
				cout << " ---{Price --> INR " << price << " }." << endl;
				i++;
			}
		}
		else
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			pass = 0;
		}
		cout << "*******************************************************" << endl;
	}


	void details()
	{
	namel:
		cout << "\nEnter your Name :: ";
		//fgets(buff, sizeof buff, stdin);
		cin.getline(name, 20);

		if (name[0] == 0 && name[1] == 0 && name[2] == 0 && name[3] == 0 && name[4] == 0 && name[5] == 0)
		{
			goto namel;
		}

	agel:
		fflush(stdin);
		cout << "Enter your Age :: ";
		cin.getline(age, 20);

		if (age[0] == 0 && age[1] == 0 && age[2] == 0 && age[3] == 0)
		{
			goto agel;
		}

		flag = 0;
		l = strlen(age);
		if (l > 3)
		{
			cout << "Incorrect Age !!" << endl;
			for (int i = 0; i < l; i++)
			{
				age[i] = '\0';
			}
			goto agel;
		}
		for (int i = 0; i < l; i++)
		{
			if (47 > age[i] || age[i] > 57)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 1)
		{
			cout << "Error!";
			cout << "Please enter Valid Age..." << endl;

			for (int i = 0; i < l; i++)
			{
				age[i] = '\0';
			}
			fflush(stdin);
			goto agel;
		}

	dayl:
		fflush(stdin);
		cout << "Enter DD :: ";
		cin.getline(day, 20);
		if (day[0] == 0 && day[1] == 0 && day[2] == 0 && day[3] == 0)
		{
			goto dayl;
		}
		flag = 0;
		l = strlen(day);
		if (l > 2)
		{
			cout << "Incorrect DD!!" << endl;
			for (int i = 0; i < l; i++)
			{
				day[i] = '\0';
			}
			goto dayl;
		}
		for (int i = 0; i < l; i++)
		{
			if (47 > day[i] || day[i] > 57)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 1)
		{
			cout << "Error!";
			cout << "Please enter Valid Day..." << endl;
			for (int i = 0; i < l; i++)
			{
				day[i] = '\0';
			}
			fflush(stdin);
			goto dayl;
		}

	monl:
		fflush(stdin);
		cout << "Enter MM :: ";
		cin.getline(mon, 20);
		if (mon[0] == 0 && mon[1] == 0 && mon[2] == 0 && mon[3] == 0)
		{
			goto monl;
		}
		flag = 0;
		l = strlen(mon);
		if (l > 2)
		{
			cout << "Incorrect Month!" << endl;
			for (int i = 0; i < l; i++)
			{
				mon[i] = '\0';
			}
			goto monl;
		}
		for (int i = 0; i < l; i++)
		{
			if (47 > mon[i] || mon[i] > 57)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			cout << "Error!";
			cout << "Please enter Valid Month..." << endl;
			for (int i = 0; i < l; i++)
			{
				mon[i] = '\0';
			}
			fflush(stdin);
			goto monl;
		}

	yearl:
		fflush(stdin);
		cout << "Enter YY :: ";
		cin.getline(year, 20);
		if (year[0] == 0 && year[1] == 0 && year[2] == 0 && year[3] == 0 && year[4] == 0)
		{
			goto yearl;
		}
		flag = 0;
		l = strlen(year);
		if (l > 4)
		{
			cout << "Incorrect Year!!" << endl;
			for (int i = 0; i < l; i++)
			{
				year[i] = '\0';
			}
			goto yearl;
		}
		for (int i = 0; i < l; i++)
		{
			if (47 > year[i] || year[i] > 57)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			cout << "Error!";
			cout << "Please enter Valid Year..." << endl;
			for (int i = 0; i < l; i++)
			{
				year[i] = '\0';
			}
			fflush(stdin);
			goto yearl;
		}


	}


	void payment()
	{
	amtl:
		cout << "Please pay the Amount :: ";
		cin.getline(amt, 20);
		if (amt[0] == 0 && amt[1] == 0 && amt[2] == 0 && amt[3] == 0 && amt[4] == 0)
		{
			goto amtl;
		}
		l = strlen(amt);
		flag = 0;
		for (int i = 0; i < l; i++)
		{
			if (47 > amt[i] || amt[i] > 57)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			cout << "Error!";
			cout << "Please enter Valid Amount..." << endl;
			for (int i = 0; i < l; i++)
			{
				amt[i] = '\0';
			}
			fflush(stdin);
			goto amtl;
		}
		amount = 0;
		for (int i = 0; i < l; i++)
		{
			int j = amt[i];
			j = j - 48;
			amount = amount * 10 + j;
		}
	}


	void extra(char* c)
	{
		dbconnect();
		a = 1;
		int i = 0, j = 1;
		char query[50] = "SELECT * FROM flightdata";
		char p[10] = { '\0' };
		a = mysql_query(conn, query);
		if (!a)
		{
			res = mysql_store_result(conn);
			i = (*c) - 48;
			while (row = mysql_fetch_row(res))
			{
				if (j == i)
				{
					strcpy(fcode, row[0]);
					strcpy(from, row[1]);
					strcpy(to, row[2]);
					strcpy(p, row[3]);
				}
				j++;

			}
			price = 0;
			for (int i = 0; i < strlen(p); i++)
			{
				int j = p[i];
				j = j - 48;
				price = price * 10 + j;
			}
		}
		else
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			pass = 0;
		}
	}


	void bookticket(char username[])
	{
		pass = 1;
		char str[20];
		char s11[] = "AIR";
		int con = 1;
		char s[2] = { '\0' };
		int n;
		//fgets(buff, sizeof buff, stdin);
	label:
		fgets(buff, sizeof buff, stdin);
		cout << "***************************************************" << endl;
		cout << "\nSelect route from the available list :: " << endl;
		cout << "\n***************************************************" << endl;
		availFlight();
		if (pass == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Try after Some time !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto endl;
		}
		cout << "Enter Route Number :: ";
		//fgets(buff, sizeof buff, stdin);
		cin.getline(s, 2);

		for (int i = 1; i > 0; --i) {
			cout << "...................................................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		cout << "***************************************************" << endl;
		fflush(stdin);

		switch (s[0])
		{
		case 49:
			extra(s);
			cout << "***************************************************" << endl;
			cout << "\nTicket for " << from << " to " << to << ":" << endl;
			seatAvailability(fcode);
			if (pass == 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Try after Some time !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto endl;
			}
			if (seat == 1)
			{
				settickNum();
				if (pass == 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Try after Some time !!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto endl;
				}
				details();
				totalcost = (5 * price) / 100 + price;
				cout << "Total Cost = Fare + GST =INR " << totalcost << endl;
				payment();
				flag1 = 1;
				break;
			}
			else
			{
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << "!!SORRY!!" << endl;
				cout << "         All seats are already booked." << endl;
				cout << "         Choose another Flight." << endl;
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				flag1 = 0;
				break;
			}

		case 50:
			extra(s);
			cout << "***************************************************" << endl;
			cout << "\nTicket for " << from << " to " << to << ":" << endl;
			seatAvailability(fcode);
			if (pass == 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Try after Some time !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto endl;
			}
			if (seat == 1)
			{
				settickNum();
				if (pass == 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Try after Some time !!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto endl;
				}
				details();
				totalcost = (5 * price) / 100 + price;
				cout << "Total Cost = Fare + GST =INR " << totalcost << endl;
				payment();
				flag1 = 1;
				break;
			}
			else
			{
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << "!!SORRY!!" << endl;
				cout << "         All seats are already booked." << endl;
				cout << "         Choose another Flight." << endl;
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				flag1 = 0;
				break;
			}

		case 51:
			extra(s);
			cout << "***************************************************" << endl;
			cout << "\nTicket for " << from << " to " << to << ":" << endl;
			seatAvailability(fcode);
			if (pass == 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Try after Some time !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto endl;
			}
			if (seat == 1)
			{
				settickNum();
				if (pass == 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Try after Some time !!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto endl;
				}
				details();
				totalcost = (5 * price) / 100 + price;
				cout << "Total Cost = Fare + GST =INR " << totalcost << endl;
				payment();
				flag1 = 1;
				break;
			}
			else
			{
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << "!!SORRY!!" << endl;
				cout << "         All seats are already booked." << endl;
				cout << "         Choose another Flight." << endl;
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				flag1 = 0;
				break;
			}

		case 52:
			extra(s);
			cout << "***************************************************" << endl;
			cout << "\nTicket for " << from << " to " << to << ":" << endl;
			seatAvailability(fcode);
			if (pass == 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Try after Some time !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto endl;
			}
			if (seat == 1)
			{
				settickNum();
				if (pass == 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Try after Some time !!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto endl;
				}
				details();
				totalcost = (5 * price) / 100 + price;
				cout << "Total Cost = Fare + GST =INR " << totalcost << endl;
				payment();
				flag1 = 1;
				break;
			}
			else
			{
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << "!!SORRY!!" << endl;
				cout << "         All seats are already booked." << endl;
				cout << "         Choose another Flight." << endl;
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				flag1 = 0;
				break;
			}

		case 53:
			extra(s);
			cout << "***************************************************" << endl;
			cout << "\nTicket for " << from << " to " << to << ":" << endl;
			seatAvailability(fcode);
			if (pass == 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Try after Some time !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto endl;
			}
			if (seat == 1)
			{
				settickNum();
				if (pass == 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Try after Some time !!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto endl;
				}
				details();
				totalcost = (5 * price) / 100 + price;
				cout << "Total Cost = Fare + GST =INR " << totalcost << endl;
				payment();
				flag1 = 1;
				break;
			}
			else
			{
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << "!!SORRY!!" << endl;
				cout << "         All seats are already booked." << endl;
				cout << "         Choose another Flight." << endl;
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				flag1 = 0;
				break;
			}

		case 54:
			extra(s);
			cout << "***************************************************" << endl;
			cout << "\nTicket for " << from << " to " << to << ":" << endl;
			seatAvailability(fcode);
			if (pass == 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Try after Some time !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto endl;
			}
			if (seat == 1)
			{
				settickNum();
				if (pass == 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Try after Some time !!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto endl;
				}
				details();
				totalcost = (5 * price) / 100 + price;
				cout << "Total Cost = Fare + GST =INR " << totalcost << endl;
				payment();
				flag1 = 1;
				break;
			}
			else
			{
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << "!!SORRY!!" << endl;
				cout << "         All seats are already booked." << endl;
				cout << "         Choose another Flight." << endl;
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				flag1 = 0;
				break;
			}

		case 55:
			extra(s);
			cout << "***************************************************" << endl;
			cout << "\nTicket for " << from << " to " << to << ":" << endl;
			seatAvailability(fcode);
			if (pass == 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Try after Some time !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto endl;
			}
			if (seat == 1)
			{
				settickNum();
				if (pass == 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Try after Some time !!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto endl;
				}
				details();
				totalcost = (5 * price) / 100 + price;
				cout << "Total Cost = Fare + GST =INR " << totalcost << endl;
				payment();
				flag1 = 1;
				break;
			}
			else
			{
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << "!!SORRY!!" << endl;
				cout << "         All seats are already booked." << endl;
				cout << "         Choose another Flight." << endl;
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				flag1 = 0;
				break;
			}

		default:
			cout << "***************************************************" << endl;
			cout << "!!No Flight Available For This Route!!" << endl;
			cout << "***************************************************" << endl;
			fgets(buff, sizeof buff, stdin);
		}
		//END OF SWITCH-CASE
	endl:
		if (flag1 == 1)
		{
			for (int i = 1; i > 0; --i) 
			{
				cout << "...................................................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			if (amount == totalcost)
			{
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "``Congratulations!`` Your Ticket has been confirmed" << endl;
				cout << "\nKindly Check-in before 2 hours of departure" << endl;
				cout << "        Thank You! Have a safe Journey.." << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
				con = 0;
			}
			else if (amount < totalcost)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "ERROR! \n Please pay the remaining balance -> " << (totalcost - amount) << endl;
			extl:
				cout << "Enter Balance :: ";
				cin.getline(ext, 20);
				if (ext[0] == 0 && ext[1] == 0 && ext[2] == 0 && ext[3] == 0 && ext[4] == 0)
				{
					goto extl;
				}
				l = strlen(ext);
				flag = 0;
				for (int i = 0; i < l; i++)
				{
					if (47 > ext[i] || ext[i] > 57)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					cout << "Error!";
					cout << "Please enter Valid Amount..." << endl;
					for (int i = 0; i < l; i++)
					{
						ext[i] = '\0';
					}
					fflush(stdin);
					goto extl;
				}
				rem = 0;
				for (int i = 0; i < l; i++)
				{
					int j = ext[i];
					j = j - 48;
					rem = rem * 10 + j;
				}
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				amount = amount + rem;
				if (amount == totalcost)
				{
					for (int i = 1; i > 0; --i) 
					{
						cout << "...................................................";
						this_thread::sleep_for(std::chrono::seconds(1));
					}
					cout << "\n";
					cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "``Congratulations`` Your Ticket has now been confirmed" << endl;
					cout << "\nPlease Check-in before 2 hours of departure" << endl;
					cout << "        Thank You! Have a Happy Journey" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
					con = 0;
				}
				else if (amount < totalcost)
				{
					con = 1;
					for (int i = 1; i > 0; --i) 
					{
						cout << "...................................................";
						this_thread::sleep_for(std::chrono::seconds(1));
					}
					cout << "\n";
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "ERROR! \n Transaction is declined. \nPLease try again.." << endl;
					cout << "INR " << amount << " is credit into your account" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
				}
				else
				{
					for (int i = 1; i > 0; --i) 
					{
						cout << "...................................................";
						this_thread::sleep_for(std::chrono::seconds(1));
					}
					cout << "\n";
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "You pay the extra amount -> " << (amount - totalcost) << endl;
					cout << "INR " << (amount - totalcost) << " is credit into your account" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
					cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "``Congratulations`` Your Ticket has now been confirmed" << endl;
					cout << "\nPlease Check-in before 2 hours of departure" << endl;
					cout << "        Thank You! Have a Happy Journey" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
					con = 0;
				}
			}
			else
			{

				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "You pay the extra amount -> " << (amount - totalcost) << endl;
				cout << "INR " << (amount - totalcost) << " is credit into your account" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "``Congratulations`` Your Ticket has now been confirmed" << endl;
				cout << "\nPlease Check-in before 2 hours of departure" << endl;
				cout << "        Thank You! Have a Happy Journey" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
				con = 0;
			}
		}

		//LOGIC FOR DATA INSERTION IN DATABASE
		if (con == 0)
		{
			char s[200] = { '\0' };
			char t[5] = { '\0' }; //lates add { '\0' }
			char cost[10];
			char s1[100] = { '\0' };
			char s2[100] = { '\0' };
			int tavail = 0;
			char temp[10] = { '\0' };
			strcpy(s, "INSERT INTO ticketsdata VALUES('");
			strcpy(s1, "update flightdata set bookedseat ='");
			strcpy(s2, "SELECT bookedseat FROM flightdata where flightno ='");
			strcat(s2, fcode);
			strcat(s2, "'");
			a = mysql_query(conn, s2);

			if (!a)
			{
				res = mysql_store_result(conn);
				while (row = mysql_fetch_row(res))
				{
					tavail = 0;
					strcpy(temp, row[0]);
					l = strlen(temp);
					for (int i = 0; i < l; i++)
					{
						int j = temp[i];
						j = j - 48;
						tavail = tavail * 10 + j;
					}
					tavail = tavail + 1;
				}

				snprintf(seatNo, 4, "%d", (tavail + 100));
				snprintf(temp, 10, "%d", tavail);
				snprintf(t, 5, "%d", tickNum);
				snprintf(cost, 10, "%d", totalcost);
				strcat(s1, temp);
				strcat(s1, "' where flightno='");
				strcat(s1, fcode);
				strcat(s1, "'");
				strcat(s, t);
				strcat(s, "','");
				strcat(s, name);
				strcat(s, "','");
				strcat(s, age);
				strcat(s, "','");
				strcat(s, day);
				strcat(s, "','");
				strcat(s, mon);
				strcat(s, "','");
				strcat(s, year);
				strcat(s, "','");
				strcat(s, from);
				strcat(s, "','");
				strcat(s, to);
				strcat(s, "','");
				strcat(s, cost);
				strcat(s, "','");
				strcat(s, fcode);
				strcat(s, "','");
				strcat(s, seatNo);
				strcat(s, "','");
				strcat(s, username);
				strcat(s, "')");
				int b = 1, c = 1;
				b = mysql_query(conn, s);
				if (b != 0)
				{
					goto end1;
				}
				mysql_commit(conn);
				c = mysql_query(conn, s1);
				if (c != 0)
				{
					strcpy(s, "DELETE FROM ticketsdata WHERE tickno='");
					strcat(s, t);
					strcat(s, "'");
					mysql_query(conn, s);
					mysql_commit(conn);
					goto end1;
				}
				mysql_commit(conn);
				ofstream ofs1;
				sprintf(str, "%s-%d", s11, tickNum);
				strcat(str, ".txt");

				ofs1.open(str);
				ofs1 << "\n--------------------------------------------------------------------------------" << endl;
				ofs1 << "|                        ~~~~ Todays India Airlines ~~~~" << endl;
				ofs1 << "|*******************************************************************************" << endl;
				ofs1 << "|Ticket Number :: " << tickNum << "                                       Date :: " << day << "-" << mon << "-" << year << endl;
				ofs1 << "|Flight Number :: " << fcode << "                                 Seat Number :: " << seatNo << endl;
				ofs1 << "|                           Passenger Name ::" << name << endl;
				ofs1 << "|                           Passenger age ::" << age << endl;
				ofs1 << "|" << endl;
				ofs1 << "|Destination :: From " << from << "          ----->>                 To :: " << to << "." << endl;
				ofs1 << "|" << endl;
				ofs1 << "|                         Total Amount Paid :: INR " << totalcost << endl;
				ofs1 << "|*******************************************************************************" << endl;
				ofs1 << "|                         Have a Happy and Safe Journey" << endl;
				ofs1 << "--------------------------------------------------------------------------------" << endl;
				ofs1.close();

				for (int i = 1; i > 0; --i) 
				{
					cout << "...................................................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
				print();
			}
			else
			{
				goto end1;
			}
		}
		else if (con == 1 && flag1 == 1)
		{
		end1:
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "ERROR! \n Due to some problems your Ticket is not booked. \nPLease try again.." << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		}
	}


	void print()
	{
		cout << "\n--------------------------------------------------------------------------------" << endl;
		cout << "|                        ~~~~ Todays India Airlines ~~~~" << endl;
		cout << "|*******************************************************************************" << endl;
		cout << "|Ticket Number :: " << tickNum << "                                       Date :: " << day << "-" << mon << "-" << year << endl;
		cout << "|Flight Number :: " << fcode << "                                 Seat Number :: " << seatNo << endl;
		cout << "|                           Passenger Name ::" << name << endl;
		cout << "|                           Passenger age ::" << age << endl;
		cout << "|" << endl;
		cout << "|Destination :: From " << from << "          ----->>                 To :: " << to << "." << endl;
		cout << "|" << endl;
		cout << "|                         Total Amount Paid :: INR " << totalcost << endl;
		cout << "|*******************************************************************************" << endl;
		cout << "|                         Have a Happy and Safe Journey" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
	}


	void viewAllTickets()
	{
		int flag = 0;
		a = 1;
		char temp[4] = { '\0' };
		char tcost[6] = { '\0' };
		dbconnect();
		string query = "SELECT * FROM ticketsdata";
		const char* q = query.c_str();
		a = mysql_query(conn, q);
		if (!a)
		{
			flag = 2;
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				flag = 1;
				int ttemp = 0;
				strcpy(temp, row[0]);
				l = strlen(temp);
				for (int i = 0; i < l; i++)
				{
					int j = temp[i];
					j = j - 48;
					ttemp = ttemp * 10 + j;
				}
				tickNum = ttemp;
				strcpy(name, row[1]);
				strcpy(age, row[2]);
				strcpy(day, row[3]);
				strcpy(mon, row[4]);
				strcpy(year, row[5]);
				strcpy(from, row[6]);
				strcpy(to, row[7]);
				strcpy(tcost, row[8]);
				strcpy(fcode, row[9]);
				strcpy(seatNo, row[10]);
				l = strlen(tcost);
				totalcost = 0;

				for (int i = 0; i < l; i++)
				{
					int j = tcost[i];
					j = j - 48;
					totalcost = totalcost * 10 + j;
				}
				print();
			}
		}
		else
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			pass = 0;
		}
		if (flag == 2)
		{
			cout << "\n***************************************************" << endl;
			cout << "No Ticket Found!!" << endl;
			cout << "***************************************************\n" << endl;
		}
	}


	void getTicket()
	{
		cout << "\n***************************************************" << endl;
		cout << "Name ::" << name << endl;
		cout << "Age ::" << age << endl;
		cout << "Ticket Number ::" << tickNum << endl;
		cout << "Flight Number ::" << fcode << endl;
		cout << "Seat Number ::" << seatNo << endl;
		cout << "Date :: " << day << "-" << mon << "-" << year << endl;
		cout << "From " << from << " To " << to << endl;
		cout << "Total Cost ::" << totalcost << endl;
		cout << "***************************************************\n" << endl;
	}


	void status(char username[])
	{
		int flag = 0;
		a = 1;
		char t[10] = { '\0' };
		char tNum[10] = { '\0' };
		char temp[10] = { '\0' }, tcost[10] = { '\0' };
		char buff[BUFSIZ];
		char user[20] = { '\0' };
		fgets(buff, sizeof buff, stdin);
		cout << "***************************************************" << endl;
		cout << "Enter the Ticket Number you want to search :: ";
		cin.getline(tNum, 10);
		cout << "***************************************************\n" << endl;

		dbconnect();
		char query[50] = "SELECT * FROM ticketsdata where tickno='";
		strcat(query, tNum);
		strcat(query, "'");
		a = mysql_query(conn, query);
		for (int i = 1; i > 0; --i) 
		{
			cout << "...................................................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
			int ttemp = 0;
			strcpy(temp, row[0]);
			l = strlen(temp);
			for (int i = 0; i < l; i++)
			{
				int j = temp[i];
				j = j - 48;
				ttemp = ttemp * 10 + j;
			}
			tickNum = ttemp;
			strcpy(name, row[1]);
			strcpy(age, row[2]);
			strcpy(day, row[3]);
			strcpy(mon, row[4]);
			strcpy(year, row[5]);
			strcpy(from, row[6]);
			strcpy(to, row[7]);
			strcpy(tcost, row[8]);
			strcpy(fcode, row[9]);
			strcpy(seatNo, row[10]);
			strcpy(user, row[11]);
			l = strlen(tcost);
			totalcost = 0;
			for (int i = 0; i < l; i++)
			{
				int j = tcost[i];
				j = j - 48;
				totalcost = totalcost * 10 + j;
			}
		}
		if (flag == 1)
		{
			if (strcmp(username, user) != 0)
			{
				cout << "***************************************************" << endl;
				cout << "ERROR!!" << endl;
				cout << "        Ticket Number '" << tickNum << "' is booked from different Username." << endl;
				goto exitl;
			}
			cout << "Ticket Found with Ticket_Number :: " << tickNum << endl;
			this->getTicket();
			cout << "Do you want to print Ticket?\n    If yes press 'p' or 'P' :: ";
			char p;
			cin >> p;
			cout << "***************************************************\n\n" << endl;
			if (p == 'p' || p == 'P')
			{
				for (int i = 1; i > 0; --i) 
				{
					cout << "...................................................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
				fgets(buff, sizeof buff, stdin);
				print();
			}
		}
		else
		{
			cout << "\n***************************************************" << endl;
			cout << "Searched Ticket could not be found " << endl;
		exitl:
			cout << "***************************************************\n\n" << endl;
		}
	}


	void updateTicket(char username[])
	{
		char ch;
		a = 1;
		char qstr[100] = { '\0' };
		int flag = 0, i = 0;
		char op;
		char n1[20] = { '\0' }, age1[5] = { '\0' };
		char t[10] = { '\0' };
		char tNum[10] = { '\0' };
		char temp[10] = { '\0' }, tcost[10] = { '\0' };
		char buff[BUFSIZ];
		char user[20] = { '\0' };
		fgets(buff, sizeof buff, stdin);
		cout << "***************************************************" << endl;
		cout << "Enter Ticket Number to be Updated :: ";
		cin.getline(tNum, 10);
		cout << "***************************************************" << endl;
		dbconnect();
		char query[50] = "SELECT * FROM ticketsdata where tickno='";
		strcat(query, tNum);
		strcat(query, "'");
		a = mysql_query(conn, query);
		for (int i = 2; i > 0; --i) 
		{
			cout << ".........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
			int ttemp = 0;
			strcpy(temp, row[0]);
			l = strlen(temp);
			for (int i = 0; i < l; i++)
			{
				int j = temp[i];
				j = j - 48;
				ttemp = ttemp * 10 + j;
			}
			tickNum = ttemp;
			strcpy(name, row[1]);
			strcpy(age, row[2]);
			strcpy(day, row[3]);
			strcpy(mon, row[4]);
			strcpy(year, row[5]);
			strcpy(from, row[6]);
			strcpy(to, row[7]);
			strcpy(tcost, row[8]);
			strcpy(fcode, row[9]);
			strcpy(seatNo, row[10]);
			strcpy(user, row[11]);
			l = strlen(tcost);
			totalcost = 0;
			for (int i = 0; i < l; i++)
			{
				int j = tcost[i];
				j = j - 48;
				totalcost = totalcost * 10 + j;
			}
		}
		if (flag == 1)
		{
			int r = 10;
			if (strcmp(username, user) != 0)
			{
				cout << "***************************************************" << endl;
				cout << "ERROR!!" << endl;
				cout << "        Ticket Number '" << tickNum << "' is booked from different Username." << endl;
				goto exitl;
			}
			cout << "\nTicket Found for Updation :: " << endl;
			this->getTicket();
		up:
			cout << "What Would You Like to Update :: " << endl;
			cout << "Choose Your Options :: " << endl;
			cout << "***************************************************" << endl;
			cout << "1. Name \t\t\t 2. Age" << endl;
			cout << "3. Date Of Journey\t\t 4. Source" << endl;
			cout << "5. Destination" << endl;
			cout << "---------------------------------------------------" << endl;
			cout << "Enter Option Number :: ";
			cin >> op;
			cout << "***************************************************" << endl;
			for (int i = 1; i > 0; --i) 
			{
				cout << "...................................................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			switch (op)
			{
			case 49:
				cout << "You are Looking for Updation of Name!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Enter Your New Name :: ";
				fgets(buff, sizeof buff, stdin);
				cin.getline(n1, 20);
				for (i = 0; i < strlen(n1); i++)
				{
					name[i] = n1[i];
				}
				name[i] = '\0';
				cout << "***************************************************" << endl;
				cout << "New Name You Have Entered Is :: " << n1 << endl;
				cout << "***************************************************\n" << endl;
				strcpy(qstr, "UPDATE ticketsdata SET name = '");
				strcat(qstr, n1);
				strcat(qstr, "'");
				strcat(qstr, "WHERE tickno = '");
				strcat(qstr, tNum);
				strcat(qstr, "'");
				a = 1;
				a = mysql_query(conn, qstr);
				if (a != 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Server Down!!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					flag = 2;
					goto exitl;
				}
				mysql_commit(conn);
				updation();
				cout << "Name Updation is in processing..." << endl;
				for (int i = 4; i > 0; --i) 
				{
					cout << ".............";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
				break;

			case 50:
				cout << "You are Looking for Updation of Age!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Enter Your New Age :: ";
				fgets(buff, sizeof buff, stdin);
				cin.getline(age1, 5);
				for (i = 0; i < strlen(age1); i++)
				{
					age[i] = age1[i];
				}
				age[i] = '\0';
				cout << "***************************************************" << endl;
				cout << "\nNew Age You Have Entered Is :: " << age1 << endl;
				cout << "***************************************************\n" << endl;
				strcpy(qstr, "UPDATE ticketsdata SET age = '");
				strcat(qstr, age1);
				strcat(qstr, "'");
				strcat(qstr, "WHERE tickno = '");
				strcat(qstr, tNum);
				strcat(qstr, "'");
				a = 1;
				a = mysql_query(conn, qstr);
				if (a != 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Server Down!!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					flag = 2;
					goto exitl;
				}
				mysql_commit(conn);
				strcpy(age, age1);
				updation();
				cout << "Age Updation is in  processing..." << endl;
				for (int i = 4; i > 0; --i) 
				{
					cout << ".............";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
				break;

			case 51:
				cout << "" << endl;
				cout << "Updation in Date Of Journey Might Cancel Your Ticket.." << endl;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "\nWARNING!!" << endl;
				cout << "         If your ticket will be cancel than 6% of the total amount won't be refunded.." << endl;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Do You Agree ? (Press Y/N) :: ";
				fgets(buff, sizeof buff, stdin);
				cin >> ch;
				cout << "\n*****************************************************" << endl;
				for (int i = 1; i > 0; --i) 
				{
					cout << "...................................................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
				if (ch == 'y' || ch == 'Y')
				{
					r = cancel1(tNum);
					if (r == 0)
					{
						cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
						cout << "Failed::" << endl;
						cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
						flag = 2;
						goto exitl;
					}
					bookticket(username);
					break;
				}
				else
				{
					flag = 2;
				}
				break;

			case 52:
				cout << "" << endl;
				cout << "Updation in Source Might Cancel Your Ticket.." << endl;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "\nWARNING!!" << endl;
				cout << "         If your ticket will be cancel than 6% of the total amount won't be refunded.." << endl;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Do You Agree ? (Press Y/N) :: ";
				fgets(buff, sizeof buff, stdin);
				cin >> ch;
				cout << "\n*****************************************************" << endl;
				for (int i = 1; i > 0; --i) 
				{
					cout << "...................................................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
				if (ch == 'y' || ch == 'Y')
				{
					r = cancel1(tNum);
					if (r == 0)
					{
						cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
						cout << "Failed::" << endl;
						cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
						flag = 2;
						goto exitl;
					}
					bookticket(username);
					break;
				}
				else
				{
					flag = 2;
				}
				break;

			case 53:
				cout << "" << endl;
				cout << "Updation in Destination Might Cancel Your Ticket.." << endl;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "\nWARNING!!" << endl;
				cout << "         If your ticket will be cancel than 6% of the total amount won't be refunded.." << endl;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Do You Agree ? (Press Y/N) :: ";
				fgets(buff, sizeof buff, stdin);
				cin >> ch;
				cout << "\n*****************************************************" << endl;
				for (int i = 1; i > 0; --i) 
				{
					cout << "...................................................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
				if (ch == 'y' || ch == 'Y')
				{
					r = cancel1(tNum);
					if (r == 0)
					{
						cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
						cout << "Failed::" << endl;
						cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
						flag = 2;
						goto exitl;
					}
					bookticket(username);
					break;
				}
				else
				{
					flag = 2;
				}
				break;

			default:
				cout << "\n***************************************************" << endl;
				cout << "You Have Choosen Wrong Option..." << endl;
				cout << "Choose Right Option..." << endl;
				cout << "***************************************************\n" << endl;
				goto up;
			}
		}

		if (flag == 0)
		{
			cout << "\n***************************************************" << endl;
			cout << "Sorry!!Searched Ticket could not Found... " << endl;
			cout << "***************************************************\n" << endl;
		}
		else if (flag == 2)
		{
			cout << "\n***************************************************" << endl;
			cout << "Ticket Data is not updated!! " << endl;
			cout << "***************************************************\n" << endl;
		}
		else
		{
			cout << "\n***************************************************" << endl;
			cout << "Your Data Updated Successfully..." << endl;
		exitl:
			cout << "***************************************************\n" << endl;
		}
	}


	void updation()
	{
		char s11[] = "AIR";
		char str[20];
		sprintf(str, "%s-%d", s11, tickNum);
		strcat(str, ".txt");
		remove(str);
		ofstream ofs1;
		ofs1.open(str);
		ofs1 << "\n--------------------------------------------------------------------------------" << endl;
		ofs1 << "|                        ~~~~ Todays India Airlines ~~~~" << endl;
		ofs1 << "|*******************************************************************************" << endl;
		ofs1 << "|Ticket Number :: " << tickNum << "                                       Date :: " << day << "-" << mon << "-" << year << endl;
		ofs1 << "|Flight Number :: " << fcode << "                                 Seat Number :: " << seatNo << endl;
		ofs1 << "|                           Passenger Name ::" << name << endl;
		ofs1 << "|                           Passenger age ::" << age << endl;
		ofs1 << "|" << endl;
		ofs1 << "|Destination :: From " << from << "          ----->>                 To :: " << to << "." << endl;
		ofs1 << "|" << endl;
		ofs1 << "|                         Total Amount Paid :: INR " << totalcost << endl;
		ofs1 << "|*******************************************************************************" << endl;
		ofs1 << "|                         Have a Happy and Safe Journey" << endl;
		ofs1 << "--------------------------------------------------------------------------------" << endl;
		ofs1.close();
	}


	void cancel(char username[])
	{
		a = 1;
		char s11[] = "AIR";
		char str[20];
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "WARNING!! " << endl;
		cout << "        If you cancel your ticket 6% of the total amount won't be refunded." << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		int flag = 0;
		int charge;
		char t[10] = { '\0' };
		char tNum[10] = { '\0' };
		char temp[10] = { '\0' }, tcost[10] = { '\0' };
		char buff[BUFSIZ];
		char user[20] = { '\0' };
		fgets(buff, sizeof buff, stdin);
		cout << "***************************************************" << endl;
		cout << "Enter the Ticket Number to cancel Ticket :: ";
		cin.getline(tNum, 10);
		cout << "***************************************************" << endl;
		for (int i = 1; i > 0; --i) 
		{
			cout << "...................................................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		dbconnect();
		char query[50] = "SELECT * FROM ticketsdata where tickno='";
		strcat(query, tNum);
		strcat(query, "'");
		a = 1;
		a = mysql_query(conn, query);
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
			int ttemp = 0;
			strcpy(temp, row[0]);
			l = strlen(temp);
			for (int i = 0; i < l; i++)
			{
				int j = temp[i];
				j = j - 48;
				ttemp = ttemp * 10 + j;
			}
			tickNum = ttemp;
			sprintf(str, "%s-%d", s11, tickNum);
			strcat(str, ".txt");
			strcpy(name, row[1]);
			strcpy(age, row[2]);
			strcpy(day, row[3]);
			strcpy(mon, row[4]);
			strcpy(year, row[5]);
			strcpy(from, row[6]);
			strcpy(to, row[7]);
			strcpy(tcost, row[8]);
			strcpy(fcode, row[9]);
			strcpy(seatNo, row[10]);
			strcpy(user, row[11]);
			l = strlen(tcost);
			totalcost = 0;
			for (int i = 0; i < l; i++)
			{
				int j = tcost[i];
				j = j - 48;
				totalcost = totalcost * 10 + j;
			}
		}
		if (flag == 1)
		{
			if (strcmp(username, user) != 0)
			{
				cout << "***************************************************" << endl;
				cout << "ERROR!!" << endl;
				cout << "        Ticket Number '" << tickNum << "' is booked from different Username." << endl;
				cout << "***************************************************" << endl;
				goto exitl;
			}
			cout << "\nTicket Found for Deletion -> " << tickNum << endl;
			this->getTicket();
			char d;
			cout << "For confirm Deletion Enter ('d' OR 'D') :: ";
			cin >> d;
			cout << "\n***************************************************" << endl;
			for (int i = 2; i > 0; --i) 
			{
				cout << ".........................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			if (d == 'd' || d == 'D')
			{
				char qstr[50] = { '\0' };
				char q[200] = { '\0' };
				char q1[200] = { '\0' };
				int tavail = 0;
				strcpy(q1, "SELECT bookedseat FROM flightdata where flightno ='");
				strcat(q1, fcode);
				strcat(q1, "'");
				a = 1;
				a = mysql_query(conn, q1);
				if (a != 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Server Down!!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto exitl;
				}
				res = mysql_store_result(conn);
				while (row = mysql_fetch_row(res))
				{
					tavail = 0;
					strcpy(temp, row[0]);
					l = strlen(temp);
					for (int i = 0; i < l; i++)
					{
						int j = temp[i];
						j = j - 48;
						tavail = tavail * 10 + j;
					}
				}
				tavail = tavail - 1;
				snprintf(temp, 10, "%d", tavail);
				strcpy(q, "update flightdata set bookedseat ='");
				strcat(q, temp);
				strcat(q, "' where flightno='");
				strcat(q, fcode);
				strcat(q, "'");
				a = 1;
				a = mysql_query(conn, q);
				if (a != 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Server Down!!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto exitl;
				}
				mysql_commit(conn);
				strcpy(qstr, "DELETE FROM ticketsdata WHERE tickno='");
				strcat(qstr, tNum);
				strcat(qstr, "'");
				a = 1;
				a = mysql_query(conn, qstr);
				if (a != 0)
				{
					cout << "Server Down!!" << endl;
					tavail = tavail + 1;
					snprintf(temp, 10, "%d", tavail);
					strcpy(q, "update flightdata set bookedseat ='");
					strcat(q, temp);
					strcat(q, "' where flightno='");
					strcat(q, fcode);
					strcat(q, "'");
					mysql_query(conn, q);
					mysql_commit(conn);
					goto exitl;
				}
				mysql_commit(conn);
				cout << "Amount deducted :: INR " << (totalcost * 6) / 100 << "." << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "-->INR " << totalcost - (totalcost * 6) / 100 << " is credit into your account." << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				remove(str);
				flag = 2;
			}
		}
		if (flag == 0)
		{
			cout << "\n***************************************************" << endl;
			cout << "Searched Ticket could not be found " << endl;
			cout << "***************************************************\n" << endl;
		}
		else if (flag == 2)
		{
			cout << "\n***************************************************" << endl;
			cout << "Ticket Cancelled Successfully..." << endl;
			cout << "***************************************************\n" << endl;
		}
		else
		{
			cout << "\n***************************************************" << endl;
			cout << "Searched Ticket found but not deleted." << endl;
		exitl:
			cout << "***************************************************\n" << endl;
		}
	}


	int cancel1(char* tNum)
	{
		a = 1;
		char s11[] = "AIR";
		char str[20];
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "\nTicket Number will going to be Canceled :: " << tNum << endl;
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		for (int i = 3; i > 0; --i) 
		{
			cout << ".................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		int flag = 0;
		int charge;
		char temp[10] = { '\0' };
		dbconnect();
		char query[50] = "SELECT * FROM ticketsdata where tickno='";
		strcat(query, tNum);
		strcat(query, "'");
		a = 1;
		a = mysql_query(conn, query);
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			return 0;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
			int ttemp = 0;
			strcpy(temp, row[0]);
			l = strlen(temp);
			for (int i = 0; i < l; i++)
			{
				int j = temp[i];
				j = j - 48;
				ttemp = ttemp * 10 + j;
			}
			tickNum = ttemp;
			sprintf(str, "%s-%d", s11, tickNum);
			strcat(str, ".txt");
		}
		if (flag == 1)
		{
			char qstr[50] = { '\0' };
			char q[100] = { '\0' };
			char q1[100] = { '\0' };
			int tavail = 0;
			strcpy(qstr, "DELETE FROM ticketsdata WHERE tickno='");
			strcpy(q, "update flightdata set bookedseat ='");
			strcpy(q1, "SELECT bookedseat FROM flightdata where flightno ='");
			strcat(q1, fcode);
			strcat(q1, "'");
			a = 1;
			a = mysql_query(conn, q1);
			if (a != 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Server Down!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				return 0;
			}
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				tavail = 0;
				strcpy(temp, row[0]);
				l = strlen(temp);
				for (int i = 0; i < l; i++)
				{
					int j = temp[i];
					j = j - 48;
					tavail = tavail * 10 + j;
				}
			}
			tavail = tavail - 1;
			snprintf(temp, 10, "%d", tavail);
			strcat(q, temp);
			strcat(q, "' where flightno='");
			strcat(q, fcode);
			strcat(q, "'");
			a = 1;
			a = mysql_query(conn, q);
			if (a != 0)
			{
				cout << "Server Down!!" << endl;
				return 0;
			}
			mysql_commit(conn);
			strcat(qstr, tNum);
			strcat(qstr, "'");
			a = 1;
			a = mysql_query(conn, qstr);
			if (a != 0)
			{
				cout << "Server Down!!" << endl;
				strcpy(q, "update flightdata set bookedseat ='");
				tavail = tavail + 1;
				snprintf(temp, 10, "%d", tavail);
				strcat(q, temp);
				strcat(q, "' where flightno='");
				strcat(q, fcode);
				strcat(q, "'");
				mysql_query(conn, q);
				mysql_commit(conn);
				return 0;
			}
			mysql_commit(conn);
			cout << "\nAmount deducted ::INR " << (totalcost * 6) / 100 << "." << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "-->INR " << totalcost - (totalcost * 6) / 100 << " is credit into your account." << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			remove(str);
			flag = 2;
		}
		if (flag == 0)
		{
			cout << "\n***************************************************" << endl;
			cout << "Ticket could not be found " << endl;
			cout << "***************************************************\n" << endl;
			return 0;
		}
		else if (flag == 2)
		{
			cout << "\n***************************************************" << endl;
			cout << "Ticket Cancelled Successfully..." << endl;
			cout << "***************************************************\n" << endl;
			return 1;
		}
		else
		{
			cout << "\n***************************************************" << endl;
			cout << "Ticket found but not deleted." << endl;
			cout << "***************************************************\n" << endl;
			return 0;
		}
	}
};


class SelectOptionUser
{
public:

	void option(char username[])
	{
		char ch;
		char buff[BUFSIZ];
		Inquiry in;
		PlanYourTravel p;
		char a;
		do
		{
		again:
			cout << "\n***************************************************" << endl;
			cout << "Kindly :" << endl;
			cout << "Press [1] for Travel Information :: " << endl;
			cout << "Press [2] To Plan Your Journey   :: " << endl;
			cout << "Press [3] To Check your Ticket Status  :: " << endl;
			cout << "Press [4] To Cancel your Ticket  :: " << endl;
			cout << "Press [5] To Update Your Booked Ticket :: " << endl;
			cout << "Press [6] For Logout :: " << endl;
			cout << "***************************************************" << endl;
			cout << "-> ";
			scanf("%c", &a);
			for (int i = 1; i > 0; --i) 
			{
				cout << "...................................................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			switch (a)
			{
			case 49:
				char b;
			first:
				cout << "***************************************************" << endl;
				cout << "Select whose information you desire:" << endl;
				cout << "[1] Airport Information" << endl;
				cout << "[2] Route Map" << endl;
				cout << "[3] Health and Safety" << endl;
				cout << "[4] Feedback" << endl;
				cout << "***************************************************" << endl;
				fgets(buff, sizeof buff, stdin);
				cout << "-> ";
				scanf("%c", &b);
				for (int i = 1; i > 0; --i) 
				{
					cout << "...................................................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";

				switch (b)
				{
				case 49:
					in.airportInformation();
					break;

				case 50:
					in.routeMap();
					break;

				case 51:
					in.healthSafety();
					break;

				case 52:
					in.feedback();
					break;

				default:
					cout << "Error!" << endl;
					cout << "     Wrong Input!" << endl;
					cout << "		Please Select from Given Options!" << endl;
					goto first;
					break;
				}
				break;

			case 50:
				p.bookticket(username);
				break;

			case 51:
				p.status(username);
				break;
			case 52:
				p.cancel(username);
				break;

			case 53:
				p.updateTicket(username);
				break;

			case 54:
				cout << "Logout Sucessfully!!" << endl;
				ch = '\0';
				goto exitl;
				break;

			default:
				cout << "Error!!" << endl;
				cout << "Try Again!!" << endl;
				cout << "Please Select Correct Option..!!" << endl;
				fgets(buff, sizeof buff, stdin);
				goto again;
			}

			cout << "***************************************************" << endl;
			ch = '\0';
			cout << "Do you want to Continue ? (Press Y/N) :: " << endl;
			scanf("  %c", &ch);
			while (getchar() != '\n');
			cout << "***************************************************" << endl;
		} while (ch == 'Y' || ch == 'y');

	exitl:
		cout << "***************************************************" << endl;
	}

};

class AdminWork
{
public:
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	char fcode[20] = { '\0' };
	char from[20] = { '\0' };
	char to[20] = { '\0' };
	char price[20] = { '\0' };
	char total[5] = { '\0' };
	char book[5] = { '\0' };
	char q[100] = { '\0' };
	char uname[100] = { '\0' };
	char upass[100] = { '\0' };
	char hint[100] = { '\0' };
	int totalcost = 0;
	char age[20] = { '\0' };
	char name[20] = { '\0' };
	char day[20];
	char seatNo[4] = { '\0' };
	char mon[20] = { '\0' };
	char year[20] = { '\0' };
	char amt[20] = { '\0' };
	int tickNum;
	char buff[BUFSIZ];
	char c;
	int a = 1, l = 0;

	void dbconnect()
	{
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "12345", "airlines", 3306, NULL, 0);
	}


	void routeMap()
	{
		dbconnect();
		a = 1;
		char query[50] = "SELECT * FROM flightdata";
		int i = 1;
		a = mysql_query(conn, query);
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		cout << "\n***************************************************" << endl;
		cout << "Available Flights ::" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
		while (row = mysql_fetch_row(res))
		{
			strcpy(fcode, row[0]);
			strcpy(from, row[1]);
			strcpy(to, row[2]);
			strcpy(price, row[3]);
			strcpy(total, row[4]);
			strcpy(book, row[5]);
			cout << "~" << i << "->[Flight Number " << fcode << "],  [From " << from << "],  [To " << to;
			cout << "],  [Price --> INR " << price << "],  [Total_Seats :: " << total << "], [Booked_Seat :: " << book << "]." << endl;
		exitl:
			i++;
		}
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}


	void updateFlight()
	{
		a = 1;
		int flag = 0;
		char fno[20] = { '\0' };
		char fcode1[20] = "Indian-";
		cout << "\n***************************************************" << endl;
		cout << "Welcome to Flight Updation Page !!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		dbconnect();
		Inquiry i;
		routeMap();
		cout << "Enter Flight Number For Updation :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(fno, 20);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		strcat(fcode1, fno);
		strcpy(fcode, fcode1);
		strcpy(q, "SELECT * FROM flightdata WHERE flightno = '");
		strcat(q, fcode);
		strcat(q, "'");
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Flight Not Found!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
			goto exitl;
		}
	first:
		cout << "\n***************************************************" << endl;
		cout << "Select What you want to Update :: " << endl;
		cout << "[1] Source :: " << endl;
		cout << "[2] Destination :: " << endl;
		cout << "[3] Price :: " << endl;
		cout << "[4] TotalSeat :: " << endl;
		cout << "***************************************************" << endl;
		cout << "-> ";
		cin >> c;
		for (int i = 2; i > 0; --i) 
		{
			cout << ".........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		switch (c)
		{
		case 49:
			sourceUpdate();
			break;
		case 50:
			destinationUpdate();
			break;
		case 51:
			priceUpdate();
			break;
		case 52:
			seatsUpdate();
			break;
		default:
			cout << "Error!" << endl;
			cout << "     Wrong Input!" << endl;
			cout << "		Please Select from Given Options!" << endl;
			goto first;
		exitl:
			break;
		}
	}


	void sourceUpdate()
	{
		a = 1;
		char fno[20] = { '\0' };
		char fcode1[20] = "Indian-";
		cout << "\n***************************************************" << endl;
		cout << "Welcome to Source Updation Page !!" << endl;
		cout << "***************************************************" << endl;

		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter New Source :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(from, 20);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		strcpy(q, "UPDATE flightdata SET source ='");
		strcat(q, from);
		strcat(q, "'");
		strcat(q, " WHERE flightno ='");
		strcat(q, fcode);
		strcat(q, "'");
		a = mysql_query(conn, q);
		cout << "\nUpdating...";

		for (int i = 2; i > 0; --i) 
		{
			cout << "....................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			cout << "Updation Failed!!" << endl;
			cout << "Try After Some Time." << endl;
			goto exitl;
		}
		mysql_commit(conn);
		cout << "\n***************************************************" << endl;
		cout << "Updated Sucessfully." << endl;
	exitl:
		cout << "***************************************************" << endl;
	}


	void destinationUpdate()
	{
		a = 1;
		char fno[20] = { '\0' };
		char fcode1[20] = "Indian-";
		cout << "\n***************************************************" << endl;
		cout << "Welcome to Destination Updation Page !!" << endl;
		cout << "***************************************************" << endl;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter New Destination :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(to, 20);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		strcpy(q, "UPDATE flightdata SET destination ='");
		strcat(q, to);
		strcat(q, "'");
		strcat(q, " WHERE flightno ='");
		strcat(q, fcode);
		strcat(q, "'");
		a = mysql_query(conn, q);
		cout << "\nUpdating...";
		for (int i = 2; i > 0; --i) 
		{
			cout << "....................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			cout << "Updation Failed!!" << endl;
			cout << "Try After Some Time." << endl;
			goto exitl;
		}
		mysql_commit(conn);
		cout << "\n***************************************************" << endl;
		cout << "Updated Sucessfully!" << endl;
	exitl:
		cout << "**************************************************" << endl;
	}


	void priceUpdate()
	{
		a = 1;
		cout << "\n***************************************************" << endl;
		cout << "Welcome to Price Updation Page !!" << endl;
		cout << "***************************************************" << endl;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter New Price :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(price, 20);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		strcpy(q, "UPDATE flightdata SET price ='");
		strcat(q, price);
		strcat(q, "'");
		strcat(q, " WHERE flightno ='");
		strcat(q, fcode);
		strcat(q, "'");
		a = mysql_query(conn, q);
		cout << "\nUpdating...";
		for (int i = 2; i > 0; --i) 
		{
			cout << "....................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			goto exitl;
		}
		mysql_commit(conn);
		cout << "\n*****************************************************" << endl;
		cout << "Updated Sucessfully :: " << endl;
	exitl:
		cout << "*****************************************************" << endl;
	}


	void seatsUpdate()
	{
		a = 1;
		cout << "\n***************************************************" << endl;
		cout << "Welcome to Seats Updation Page !!" << endl;
		cout << "***************************************************" << endl;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter New Seats Number :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(total, 20);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		strcpy(q, "UPDATE flightdata SET totalseat ='");
		strcat(q, total);
		strcat(q, "'");
		strcat(q, " WHERE flightno ='");
		strcat(q, fcode);
		strcat(q, "'");
		a = mysql_query(conn, q);
		cout << "\nUpdating...";
		for (int i = 2; i > 0; --i)
		{
			cout << "....................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			cout << "Updation Failed!!" << endl;
			cout << "Try After Some Time." << endl;
			goto exitl;
		}
		mysql_commit(conn);
		cout << "\n*********************************************" << endl;
		cout << "Updated Sucessfully :: " << endl;
	exitl:
		cout << "*********************************************" << endl;
	}


	void checkUser()
	{
		cout << "\n***************************************************" << endl;
		cout << "All Registered Users are :: " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
		dbconnect();
		a = 1;
		char query[50] = "SELECT * FROM userlogin";
		int i = 1;
		a = mysql_query(conn, query);
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			strcpy(uname, row[0]);
			strcpy(upass, row[1]);
			strcpy(hint, row[2]);
			cout << "->(" << i << ") [Username :: " << uname << "],    [Password :: " << upass << "],    ";
			cout << "[Hint :: " << hint << "]." << endl;
			i++;
		}
	exitl:
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}


	void updateUser()
	{
		a = 1;
		checkUser();
		int flag = 0;
		cout << "\n***************************************************" << endl;
		cout << "Welcome to User Updation Page !!" << endl;
		cout << "***************************************************" << endl;
		cout << "\n###################################################" << endl;
		cout << "Enter Username Whose you want to update  :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(uname, 20);
		strcpy(q, "SELECT * FROM userlogin WHERE username = '");
		strcat(q, uname);
		strcat(q, "'");
		a = mysql_query(conn, q);
		for (int i = 2; i > 0; --i)
		{
			cout << ".........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Username Not Found!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
			goto exitl;
		}
	firstu:
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Select What you want to Update :: " << endl;
		cout << "[1] Username :: " << endl;
		cout << "[2] Password :: " << endl;
		cout << "[3] Hint :: " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "-> ";
		cin >> c;
		switch (c)
		{
		case 49:
			nameUpdate();
			break;
		case 50:
			passUpdate();
			break;
		case 51:
			hintUpdate();
			break;
		default:
			cout << "Error!" << endl;
			cout << "     Wrong Input!" << endl;
			cout << "		Please Select from Given Options!" << endl;
			goto firstu;
		exitl:
			break;
		}
	}


	void nameUpdate()
	{
		a = 1;
		int flag = 0, c = 0;
		char temp[20] = { '\0' };
		cout << "\n***************************************************" << endl;
		cout << "Welcome to UserName Updation Page !!" << endl;
		cout << "***************************************************" << endl;
		int count = 0;
		strcpy(q, "SELECT * FROM userlogin WHERE username = '");
		strcat(q, uname);
		strcat(q, "'");
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Invalid Username!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		}
		else if (flag == 1)
		{
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Enter New Username :: ";
			fgets(buff, sizeof buff, stdin);
		exitl:
			cin.getline(temp, 20);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			strcpy(q, "update userlogin set username ='");
			strcat(q, temp);
			strcat(q, "' where username = '");
			strcat(q, uname);
			strcat(q, "'");
			a = 1;
			a = mysql_query(conn, q);
			cout << "\nUpdating...";
			for (int i = 2; i > 0; --i) 
			{
				cout << "....................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			if (a != 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Username Already Exists!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Enter Unique Username :: ";
				goto exitl;
			}
			mysql_commit(conn);
			cout << "\n***************************************************" << endl;
			cout << "Username Updated Sucessfully." << endl;
			cout << "***************************************************\n" << endl;
		}
	}


	void passUpdate()
	{
		a = 1;
		int flag = 0, c = 0;
		char temp[20] = { '\0' };
		cout << "\n***************************************************" << endl;
		cout << "Welcome to Password Updation Page !!" << endl;
		cout << "***************************************************" << endl;
		int count = 0;
		strcpy(q, "SELECT * FROM userlogin WHERE username = '");
		strcat(q, uname);
		strcat(q, "'");
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "Try After Some Time!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Invalid Username!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (flag == 1)
		{
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Enter New Password :: ";
			c = getPassword();
			for (int i = 2; i > 0; --i) 
			{
				cout << "..........................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			if (c == 0)
			{
				goto exitl;
			}
			strcpy(q, "update userlogin set password ='");
			strcat(q, upass);
			strcat(q, "' where username = '");
			strcat(q, uname);
			strcat(q, "'");
			a = 1;
			a = mysql_query(conn, q);
			cout << "\nUpdating...";
			for (int i = 2; i > 0; --i) {
				cout << "....................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			if (a != 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Server Down!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto exitl;
			}
			mysql_commit(conn);
			cout << "\n***************************************************" << endl;
			cout << "Password Updated Sucessfully." << endl;
			cout << "***************************************************\n" << endl;
		}
	exitl:
		cout << " ";
	}


	int getPassword()
	{
		int u = 0, l = 0, s = 0;
		int i = 0, count = 0;
	passv:
		u = 0;
		l = 0;
		s = 0;
		i = 0;
		int done = 0;
		upass[0] = _getch();
		while (upass[i] != '\r')
		{
			if (upass[i] == '\b')
			{
				i--;
				printf("\b");
				printf(" ");
				printf("\b");
				upass[i] = _getch(); //12
			}
			else
			{
				printf("*");
				i++;
				upass[i] = _getch();
			}
		}
		upass[i] = '\0';
		if (strlen(upass) > 7 && strlen(upass) < 17)
		{
			for (int i = 0; i < strlen(upass); i++)
			{
				if (isupper(upass[i]))
				{
					u = 1;
				}
				if (islower(upass[i]))
				{
					l = 1;
				}
				if (!isalnum(upass[i]))
				{
					s = 1;
				}
			}
		}
		if (u == 1 && l == 1 && s == 1)
		{
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "\nPassword Meets All Requirements." << endl;
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			done = 1;
			return 1;
		}
		else
		{
			count++;
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "\nPassword Does Not Meet Following Requirements." << endl;
			cout << "\n=====================================================" << endl;
			if (u == 0)
				cout << "Password without Uppercase." << endl;
			if (l == 0)
				cout << "Password without lowercase." << endl;
			if (s == 0)
				cout << "Password without special character." << endl;
			if (strlen(upass) < 8)
				cout << "Password length is less than 8 character" << endl;
			if (strlen(upass) > 16)
				cout << "Password length is greater than 16 character." << endl;
			cout << "=====================================================" << endl;
			if (count > 2)
			{
				cout << "Failed !!" << endl;
				return 0;
				goto exitl;
			}
			cout << "Attempt Remaining :: " << (3 - count) << endl;
			cout << "=====================================================" << endl;
			done = 0;
		}
		if (done == 0)
		{
			cout << "\nEnter Password Again :: ";
			goto passv;
		exitl:
			cout << " ";
		}
	}


	void hintUpdate()
	{
		a = 1;
		int flag = 0, c = 0;
		char temp[20] = { '\0' };
		cout << "\n***************************************************" << endl;
		cout << "Welcome to Security Question Updation Page !!" << endl;
		cout << "***************************************************" << endl;
		int count = 0;
		strcpy(q, "SELECT * FROM userlogin WHERE username = '");
		strcat(q, uname);
		strcat(q, "'");
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Invalid Username!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (flag == 1)
		{
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Enter New Security Question :: ";
			fgets(buff, sizeof buff, stdin);
			cin.getline(temp, 20);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			strcpy(q, "update userlogin set hint ='");
			strcat(q, temp);
			strcat(q, "' where username = '");
			strcat(q, uname);
			strcat(q, "'");
			a = 1;
			a = mysql_query(conn, q);
			cout << "\nUpdating...";
			for (int i = 2; i > 0; --i)
			{
				cout << "....................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			if (a != 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Server Down!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto exitl;
			}
			mysql_commit(conn);
			cout << "\n***************************************************" << endl;
			cout << "Security Question Updated Sucessfully!" << endl;
			cout << "***************************************************\n" << endl;
		}
	exitl:
		cout << " ";
	}


	void removeUser()
	{
		dbconnect();
		a = 1;
		char q1[100] = { '\0' };
		int flag = 0;
		cout << "\n***************************************************" << endl;
		cout << "Welcome to User Deletion Page !!" << endl;
		cout << "***************************************************" << endl;
		int count = 0;
		checkUser();
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter Username For Deletion :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(uname, 20);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		strcpy(q, "SELECT * FROM userlogin WHERE username = '");
		strcat(q, uname);
		strcat(q, "'");
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
		}
		for (int i = 2; i > 0; --i) 
		{
			cout << ".........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (flag == 1)
		{
			strcpy(q1, "DELETE FROM  userlogin WHERE username ='");
			strcat(q1, uname);
			strcat(q1, "'");
			a = 1;
			dbconnect();
			a = mysql_query(conn, q1);
			cout << "\nDeleting...";
			if (a != 0)
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Server Down!!" << endl;
				cout << "Failed to Delete User!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				goto exitl;
			}
			mysql_commit(conn);
			flag = 2;
		}
		if (flag == 0)
		{
			cout << "\n***************************************************" << endl;
			cout << "Searched User could not be found!" << endl;
			cout << "***************************************************\n" << endl;
		}
		else if (flag == 2)
		{
			cout << "\n***************************************************" << endl;
			cout << "User Deleted Successfully!!" << endl;
			cout << "***************************************************\n" << endl;
		}
		else
		{
			cout << "\n***************************************************" << endl;
			cout << "User found but not deleted." << endl;
		exitl:
			cout << "***************************************************\n" << endl;
		}
	}


	void getTicket()
	{
		cout << "\n***************************************************" << endl;
		cout << "Name ::" << name << endl;
		cout << "Age ::" << age << endl;
		cout << "Ticket Number ::" << tickNum << endl;
		cout << "Flight Number ::" << fcode << endl;
		cout << "Seat Number ::" << seatNo << endl;
		cout << "Date :: " << day << "-" << mon << "-" << year << endl;
		cout << "From " << from << " To " << to << endl;
		cout << "Total Cost ::" << totalcost << endl;
		cout << "***************************************************\n" << endl;
	}


	void viewAllTickets()
	{
		int flag = 0;
		int count = 0;
		a = 1;
		char temp[5] = { '\0' };
		char tcost[6] = { '\0' };
		dbconnect();
		string query = "SELECT * FROM ticketsdata";
		const char* q = query.c_str();
		a = mysql_query(conn, q);
		if (!a)
		{
			flag = 2;
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				flag = 1;
				count++;
				int ttemp = 0;
				strcpy(temp, row[0]);
				l = strlen(temp);
				for (int i = 0; i < l; i++)
				{
					int j = temp[i];
					j = j - 48;
					ttemp = ttemp * 10 + j;
				}
				tickNum = ttemp;
				strcpy(name, row[1]);
				strcpy(age, row[2]);
				strcpy(day, row[3]);
				strcpy(mon, row[4]);
				strcpy(year, row[5]);
				strcpy(from, row[6]);
				strcpy(to, row[7]);
				strcpy(tcost, row[8]);
				strcpy(fcode, row[9]);
				strcpy(seatNo, row[10]);
				l = strlen(tcost);
				totalcost = 0;
				for (int i = 0; i < l; i++)
				{
					int j = tcost[i];
					j = j - 48;
					totalcost = totalcost * 10 + j;
				}
				cout << "=============================================================================" << endl;
				cout << "[ " << count << " ] :-" << endl;
				//this->getTicket();
				this->print();
				for (int i = 3; i > 0; --i) 
				{
					cout << ".........................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
			}
		}
		else
		{
			cout << "Server Down !!" << endl;
		}
		if (flag == 2)
		{
			cout << "\n***************************************************" << endl;
			cout << "No Ticket Found!!" << endl;
			cout << "***************************************************\n" << endl;
		}
	}


	void print()
	{
		cout << "\n--------------------------------------------------------------------------------" << endl;
		cout << "|                        ~~~~ Todays India Airlines ~~~~" << endl;
		cout << "|*******************************************************************************" << endl;
		cout << "|Ticket Number :: " << tickNum << "                                       Date :: " << day << "-" << mon << "-" << year << endl;
		cout << "|Flight Number :: " << fcode << "                                 Seat Number :: " << seatNo << endl;
		cout << "|                           Passenger Name ::" << name << endl;
		cout << "|                           Passenger age ::" << age << endl;
		cout << "|" << endl;
		cout << "|Destination :: From " << from << "          ----->>                 To :: " << to << "." << endl;
		cout << "|" << endl;
		cout << "|                         Total Amount Paid :: INR " << totalcost << endl;
		cout << "|*******************************************************************************" << endl;
		cout << "|                         Have a Happy and Safe Journey" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
	}


	void cancel()
	{
		a = 1;
		char s11[] = "AIR";
		char str[20];
		int flag = 0;
		int charge;
		char t[10] = { '\0' };
		char tNum[10] = { '\0' };
		char temp[10] = { '\0' }, tcost[10] = { '\0' };
		char buff[BUFSIZ];
		cout << "\n***************************************************" << endl;
		cout << "Welcome to Ticket Cancellation Page !!" << endl;
		cout << "***************************************************\n" << endl;
		fgets(buff, sizeof buff, stdin);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter the Ticket Number to Cancel Ticket :: ";
		cin.getline(tNum, 10);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		dbconnect();
		char query[50] = "SELECT * FROM ticketsdata where tickno='";
		strcat(query, tNum);
		strcat(query, "'");
		a = 1;
		a = mysql_query(conn, query);
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
			int ttemp = 0;
			strcpy(temp, row[0]);
			l = strlen(temp);
			for (int i = 0; i < l; i++)
			{
				int j = temp[i];
				j = j - 48;
				ttemp = ttemp * 10 + j;
			}
			tickNum = ttemp;
			sprintf(str, "%s-%d", s11, tickNum);
			strcat(str, ".txt");
			strcpy(name, row[1]);
			strcpy(age, row[2]);
			strcpy(day, row[3]);
			strcpy(mon, row[4]);
			strcpy(year, row[5]);
			strcpy(from, row[6]);
			strcpy(to, row[7]);
			strcpy(tcost, row[8]);
			strcpy(fcode, row[9]);
			strcpy(seatNo, row[10]);
			l = strlen(tcost);
			totalcost = 0;
			for (int i = 0; i < l; i++)
			{
				int j = tcost[i];
				j = j - 48;
				totalcost = totalcost * 10 + j;
			}
		}
		if (flag == 1)
		{
			cout << "\n***************************************************" << endl;
			cout << "\nTicket Found for Deletion...." << tickNum << endl;
			this->getTicket();
			char d;
			cout << "For confirm Deletion Enter ('d' OR 'D') :: ";
			cin >> d;
			cout << "\n***************************************************" << endl;
			if (d == 'd' || d == 'D')
			{
				char qstr[50] = { '\0' };
				char q[200] = { '\0' };
				char q1[200] = { '\0' };
				int tavail = 0;
				strcpy(q1, "SELECT bookedseat FROM flightdata where flightno ='");
				strcat(q1, fcode);
				strcat(q1, "'");
				a = 1;
				a = mysql_query(conn, q1);
				if (a != 0)
				{
					cout << "Server Down!!" << endl;
					goto exitl;
				}
				res = mysql_store_result(conn);
				while (row = mysql_fetch_row(res))
				{
					tavail = 0;
					strcpy(temp, row[0]);
					l = strlen(temp);
					for (int i = 0; i < l; i++)
					{
						int j = temp[i];
						j = j - 48;
						tavail = tavail * 10 + j;
					}
				}
				tavail = tavail - 1;
				snprintf(temp, 10, "%d", tavail);
				strcpy(q, "update flightdata set bookedseat ='");
				strcat(q, temp);
				strcat(q, "' where flightno='");
				strcat(q, fcode);
				strcat(q, "'");
				a = 1;
				a = mysql_query(conn, q);
				if (a != 0)
				{
					cout << "Server Down!!" << endl;
					goto exitl;
				}
				mysql_commit(conn);
				strcpy(qstr, "DELETE FROM ticketsdata WHERE tickno='");
				strcat(qstr, tNum);
				strcat(qstr, "'");
				a = 1;
				a = mysql_query(conn, qstr);
				if (a != 0)
				{
					cout << "Server Down!!" << endl;
					tavail = tavail + 1;
					snprintf(temp, 10, "%d", tavail);
					strcpy(q, "update flightdata set bookedseat ='");
					strcat(q, temp);
					strcat(q, "' where flightno='");
					strcat(q, fcode);
					strcat(q, "'");
					mysql_query(conn, q);
					mysql_commit(conn);
					goto exitl;
				}
				mysql_commit(conn);
				cout << "\nDeleting...";
				for (int i = 2; i > 0; --i) 
				{
					cout << "....................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Amount deducted :: INR " << (totalcost * 6) / 100 << "." << endl;
				cout << "-->INR " << totalcost - (totalcost * 6) / 100 << " is credit into user account." << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				remove(str);
				flag = 2;
			}
		}
		if (flag == 0)
		{
			cout << "\n***************************************************" << endl;
			cout << "Searched Ticket could not be found " << endl;
			cout << "***************************************************\n" << endl;
		}
		else if (flag == 2)
		{
			cout << "\n***************************************************" << endl;
			cout << "Ticket Cancelled Successfully..." << endl;
			cout << "***************************************************\n" << endl;
		}
		else
		{
			for (int i = 2; i > 0; --i) 
			{
				cout << ".........................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			cout << "\n***************************************************" << endl;
			cout << "Searched Ticket found but not deleted." << endl;
		exitl:
			cout << "***************************************************\n" << endl;
		}
	}


	void updateTicket()
	{
		char ch;
		a = 1;
		char qstr[200] = { '\0' };
		int flag = 0, i = 0;
		char op;
		char n1[20] = { '\0' }, age1[5] = { '\0' };
		char t[10] = { '\0' };
		char tNum[10] = { '\0' };
		char temp[10] = { '\0' }, tcost[10] = { '\0' };
		char buff[BUFSIZ];
		fgets(buff, sizeof buff, stdin);
		cout << "\n***************************************************" << endl;
		cout << "Welcome to Ticket Updation Page !!" << endl;
		cout << "***************************************************\n" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter Ticket Number to be Updated :: ";
		cin.getline(tNum, 10);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
		dbconnect();
		char query[50] = "SELECT * FROM ticketsdata where tickno='";
		strcat(query, tNum);
		strcat(query, "'");
		a = mysql_query(conn, query);
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			flag = 1;
			int ttemp = 0;
			strcpy(temp, row[0]);
			l = strlen(temp);
			for (int i = 0; i < l; i++)
			{
				int j = temp[i];
				j = j - 48;
				ttemp = ttemp * 10 + j;
			}
			tickNum = ttemp;
			strcpy(name, row[1]);
			strcpy(age, row[2]);
			strcpy(day, row[3]);
			strcpy(mon, row[4]);
			strcpy(year, row[5]);
			strcpy(from, row[6]);
			strcpy(to, row[7]);
			strcpy(tcost, row[8]);
			strcpy(fcode, row[9]);
			strcpy(seatNo, row[10]);
			l = strlen(tcost);
			totalcost = 0;
			for (int i = 0; i < l; i++)
			{
				int j = tcost[i];
				j = j - 48;
				totalcost = totalcost * 10 + j;
			}
		}
		for (int i = 2; i > 0; --i) 
		{
			cout << ".........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (flag == 1)
		{
			int r = 10;
			cout << "***************************************************" << endl;
			cout << "\nTicket Found for Updation :: " << endl;
			this->getTicket();
		up:
			cout << "\n===================================================" << endl;
			cout << "What Would You Like to Update :: " << endl;
			cout << "Choose Your Options :: " << endl;
			cout << "***************************************************" << endl;
			cout << "1. Name :: " << endl;
			cout << "2. Age :: " << endl;
			cout << "-> ";
			cin >> op;
			cout << "***************************************************" << endl;
			switch (op)
			{
			case 49:
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "You are Looking for Updation of Name!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
				cout << "Enter Your New Name :: ";
				fgets(buff, sizeof buff, stdin);
				cin.getline(n1, 20);
				for (i = 0; i < strlen(n1); i++)
				{
					name[i] = n1[i];
				}
				name[i] = '\0';
				cout << "\n***************************************************" << endl;
				cout << "New Name You Have Entered Is :: " << n1 << endl;
				cout << "***************************************************\n" << endl;
				strcpy(qstr, "UPDATE ticketsdata SET name = '");
				strcat(qstr, n1);
				strcat(qstr, "'");
				strcat(qstr, "WHERE tickno = '");
				strcat(qstr, tNum);
				strcat(qstr, "'");
				a = 1;
				a = mysql_query(conn, qstr);
				if (a != 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Server Down!!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto exitl;
				}
				mysql_commit(conn);
				updation();
				cout << "Updating...";
				for (int i = 2; i > 0; --i) 
				{
					cout << "....................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				break;

			case 50:
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "You are Looking for Updation of Age!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << " Enter Your New Age :: ";
				fgets(buff, sizeof buff, stdin);
				cin.getline(age1, 5);
				for (i = 0; i < strlen(age1); i++)
				{
					age[i] = age1[i];
				}
				age[i] = '\0';
				cout << "\n***************************************************" << endl;
				cout << "New Age You Have Entered Is :: " << age1 << endl;
				cout << "***************************************************\n" << endl;
				strcpy(qstr, "UPDATE ticketsdata SET age = '");
				strcat(qstr, age1);
				strcat(qstr, "'");
				strcat(qstr, "WHERE tickno = '");
				strcat(qstr, tNum);
				strcat(qstr, "'");
				a = 1;
				a = mysql_query(conn, qstr);
				if (a != 0)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Server Down!!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					goto exitl;
				}
				mysql_commit(conn);
				strcpy(age, age1);
				updation();
				cout << "Updating...";
				for (int i = 2; i > 0; --i) 
				{
					cout << "....................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				break;

			default:
				cout << "\n***************************************************" << endl;
				cout << "You Have Choosen Wrong Option..." << endl;
				cout << "Choose Right Option..." << endl;
				cout << "***************************************************\n" << endl;
				goto up;
			}
		}

		if (flag == 0)
		{
			cout << "\n***************************************************" << endl;
			cout << "Sorry!!Searched Ticket could not Found... " << endl;
			cout << "***************************************************\n" << endl;
		}
		else
		{
			cout << "\n***************************************************" << endl;
			cout << "Your Data Updated Successfully..." << endl;
		exitl:
			cout << "***************************************************\n" << endl;
		}
	}


	void updation()
	{
		char s11[] = "AIR";
		char str[20];
		sprintf(str, "%s-%d", s11, tickNum);
		strcat(str, ".txt");
		remove(str);
		ofstream ofs1;
		ofs1.open(str);
		ofs1 << "\n--------------------------------------------------------------------------------" << endl;
		ofs1 << "|                        ~~~~ Todays India Airlines ~~~~" << endl;
		ofs1 << "|*******************************************************************************" << endl;
		ofs1 << "|Ticket Number :: " << tickNum << "                                       Date :: " << day << "-" << mon << "-" << year << endl;
		ofs1 << "|Flight Number :: " << fcode << "                                 Seat Number :: " << seatNo << endl;
		ofs1 << "|                           Passenger Name ::" << name << endl;
		ofs1 << "|                           Passenger age ::" << age << endl;
		ofs1 << "|" << endl;
		ofs1 << "|Destination :: From " << from << "          ----->>                 To :: " << to << "." << endl;
		ofs1 << "|" << endl;
		ofs1 << "|                         Total Amount Paid :: INR " << totalcost << endl;
		ofs1 << "|*******************************************************************************" << endl;
		ofs1 << "|                         Have a Happy and Safe Journey" << endl;
		ofs1 << "--------------------------------------------------------------------------------" << endl;
		ofs1.close();
	}

};


class SelectOptionAdmin
{
public:

	void option()
	{
		char ch;
		char buff[BUFSIZ];
		Inquiry in;
		AdminWork aw;
		PlanYourTravel p;
		char a;
		do
		{
		again:
			cout << "\n***************************************************" << endl;
			cout << "Kindly :" << endl;
			cout << "Press [1] To Check Available Flight   :: " << endl;
			cout << "Press [2] To Update Available Flight  :: " << endl;
			cout << "Press [3] To Check All register users :: " << endl;
			cout << "Press [4] To Update Any Register User :: " << endl;
			cout << "Press [5] To Remove Any Register User :: " << endl;
			cout << "Press [6] To Show All Booked Ticket   :: " << endl;
			cout << "Press [7] To Cancel Any Ticket        :: " << endl;
			cout << "Press [8] To Update Any Booked Ticket :: " << endl;
			cout << "Press [9] For Logout :: " << endl;
			cout << "***************************************************" << endl;
			cout << "-> ";
			scanf("%c", &a);
			for (int i = 2; i > 0; --i) 
			{
				cout << ".........................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";

			switch (a)
			{
			case 49:
				in.routeMap();
				break;

			case 50:
				aw.updateFlight();
				break;

			case 51:
				aw.checkUser();
				break;
			case 52:
				aw.updateUser();
				break;

			case 53:
				aw.removeUser();
				break;

			case 54:
				aw.viewAllTickets();
				break;

			case 55:
				aw.cancel();
				break;

			case 56:
				aw.updateTicket();
				break;

			case 57:
				cout << "Thanks!!" << endl;
				ch = '\0';
				goto exitl;
				break;

			default:
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Error!!" << endl;
				cout << "Try Again!!" << endl;
				cout << "Please Select Correct Option..!!" << endl;
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				fgets(buff, sizeof buff, stdin);
				goto again;
			}

			cout << "\n***************************************************" << endl;
			ch = '\0';
			cout << "Do you want to Continue ? (Press Y/N) :: ";
			scanf("  %c", &ch);
			while (getchar() != '\n');
		exitl:
			cout << "***************************************************" << endl;
		} while (ch == 'Y' || ch == 'y');

	}

};


class SelectUser
{
public:
	char username[20] = { '\0' };
	char pass[20] = { '\0' };
	char pass1[20] = { '\0' };
	char hint[20] = { '\0' };
	char q[60] = { '\0' };
	char mob[14] = { '\0' };
	char buff[BUFSIZ];
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int a = 1;

	void dbconnect()
	{
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "12345", "airlines", 3306, NULL, 0);
		if (conn) {
			//puts("Successful connection to database!");
		}
		else
		{
			//cout << "Failed!!" << endl;
		}
	}


	void selectUSer()
	{
		dbconnect();
		char ch;
		int flag = 0, equal = 1;
		int count = 0;
		//char s[2] = { '\0' };
		char s, u;
		//char u[2] = { '\0' };
	selectl:
		cout << "\n***************************************************" << endl;
		cout << "Select User Type :: " << endl;
		cout << "---------------------- " << endl;
		cout << "Press [1] For User  :: " << endl;
		cout << "Press [2] For Admin  :: " << endl;
		cout << "Press [3] Close App :: " << endl;
		cout << "\n***************************************************" << endl;
		cout << "-> ";
		cin >> s;
		for (int i = 2; i > 0; --i) 
		{
			cout << ".........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		switch (s)
		{

		case 49:
			fgets(buff, sizeof buff, stdin);
		userl:
			cout << "\n***************************************************" << endl;
			cout << "Select :: " << endl;
			cout << "Press [1] For Old User  :: " << endl;
			cout << "Press [2] For New User  :: " << endl;
			cout << "Press [3] To Update Password :: " << endl;
			cout << "Press [4] To Forget Password :: " << endl;
			cout << "Press [5] To Remove Account  :: " << endl;
			cout << "Press [6] For Exit :: " << endl;
			cout << "\n***************************************************" << endl;
			cout << "-> ";
			cin >> u;
			for (int i = 1; i > 0; --i) 
			{
				cout << "...................................................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			switch (u)
			{
			case 49:
				login();
				break;

			case 50:
				signup();
				break;

			case 51:
				updatePassword();
				break;

			case 52:
				forgetPassword();
				break;

			case 53:
				removeAccount();
				break;

			case 54:
				goto exitl;
				break;

			default:
				cout << "Deafult.." << endl;
				break;
			}
			goto userl;
		exitl:
			break;

		case 50:
			adminLogin();
			break;

		case 51:
			goto exits;
			break;

		default:
			break;
		}
		//fgets(buff, sizeof buff, stdin);
		goto selectl;
	exits:
		;
	}


	void login()
	{
		cout << "\n***************************************************" << endl;
		a = 1;
		int flag = 0;
		cout << "Welcome to Login Page !!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		int count = 0;
		cout << "Enter your Username :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(username, 20);
		strcpy(q, "SELECT password FROM userlogin WHERE username = '");
		strcat(q, username);
		strcat(q, "'");
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			strcpy(pass1, row[0]);
			flag = 1;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter Your Password :: ";
	passl:
		getPassword1();
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		for (int i = 1; i > 0; --i) 
		{
			cout << "...................................................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Invalid Username !" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		}
		else if (flag == 1)
		{
			if (strcmp(pass, pass1) == 0)
			{
				cout << "\n***************************************************" << endl;
				cout << "Login Successfully!!" << endl;
				cout << "***************************************************\n" << endl;
				SelectOptionUser s;
				s.option(username);
			}
			else
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Wrong Password!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
				count++;
				if (count < 3)
				{
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "Attempt Remaining  :: " << (3 - count) << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "Enter Correct Password  :: ";
					goto passl;
				}
				else
				{
				exitl:
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Login Failed!!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
				}
			}
		}
	}


	void signup()
	{
		int flag = 0, c = 0, count = 0, uc = 0;
		a = 1;
		cout << "Welcome to Signup Page !!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter a username :: ";
		fgets(buff, sizeof buff, stdin);
	us:
		cin.getline(username, 20);
		strcpy(q, "SELECT username FROM userlogin WHERE username = '");
		strcat(q, username);
		strcat(q, "'");
		a = mysql_query(conn, q);
		uc = 0;
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			uc = 1;
		}
		if (uc == 1)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "User with username { " << username << " } already Registered ::" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "\nEnter Unique Username :: ";
			goto us;
		}
		count = 0;
		cout << "\n****************************************************" << endl;
		cout << "\nEnter a Password :: " << endl;;
		cout << "\n####################################################" << endl;
		cout << "Conditions for password ::\n1-> Length should be in between 8 and 16." << endl;
		cout << "2-> Should have one lowercase and one uppercase alphabet." << endl;
		cout << "3-> Should have one Numeric Digit." << endl;
		cout << "4-> Should have one special character." << endl;
		cout << "####################################################" << endl;
		cout << " -> ";
		c = getPassword();
		if (c == 0)
		{
			goto fail;
		}
		strcpy(pass1, pass);
	passm:
		cout << "Enter Password Again :: ";
		getPassword();
		for (int i = 2; i > 0; --i) 
		{
			cout << "..........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (strcmp(pass, pass1) == 0)
		{
			cout << "\nPassword Accepted." << endl;
			cout << "***************************************************" << endl;

			flag = 1;
		}
		else
		{
			cout << "\nPassword Not Match!!" << endl;
			count++;
			if (count < 3)
			{
				cout << "Please Enter Same Password." << endl;
				cout << "\n***************************************************" << endl;
				cout << "Attempts remaining  :: " << (3 - count) << endl;
				cout << "***************************************************" << endl;
				goto passm;
			}
			else
			{
			fail:
				cout << "Signup Failed!!" << endl;
				flag = 0;
			}
		}
		if (flag != 0)
		{
			cout << "\nEnter Your Mobile Number :: ";
			cin.getline(mob, 15);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Enter a Security Keyword To forget Password :: ";
			cin.getline(hint, 20);
			strcpy(q, "INSERT INTO userlogin VALUES('");
			strcat(q, username);
			strcat(q, "','");
			strcat(q, pass);
			strcat(q, "','");
			strcat(q, mob);
			strcat(q, "','");
			strcat(q, hint);
			strcat(q, "')");
			int a = 1;
			a = mysql_query(conn, q);
			for (int i = 2; i > 0; --i) 
			{
				cout << "..........................";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << "\n";
			if (a == 0)
			{
				mysql_commit(conn);
				cout << "\nCongratulation!" << endl;
				cout << "                User with username { " << username << " } Registered Sycessfully!!" << endl;
			}
			else
			{
				cout << "ERROR!!" << endl;
				cout << "      Sign up Failed!!" << endl;
				cout << "Try After Some Time" << endl;
			}
		}
	exitl:
		cout << "" << endl;
	}


	void adminLogin()
	{
		a = 1;
		int flag = 0;
		cout << "\n***************************************************" << endl;
		cout << "\nWelcome To Admin Login Page!!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		int count = 0;
		cout << "Enter Admin Username :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(username, 20);
		strcpy(q, "SELECT password FROM adminlogin WHERE username = '");
		strcat(q, username);
		strcat(q, "'");
		//cout << q << endl;
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			strcpy(pass1, row[0]);
			flag = 1;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter Admin Password :: ";
	passl1:
		getPassword1();
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		for (int i = 1; i > 0; --i) 
		{
			cout << "...................................................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Invalid Username!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		}
		else if (flag == 1)
		{
			if (strcmp(pass, pass1) == 0)
			{
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Login Sucessfully!!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
				SelectOptionAdmin so;
				so.option();
			}
			else
			{
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Wrong Password!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
				count++;
				if (count < 3)
				{
					cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "Attempt Remaining :: " << (3 - count) << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "Enter Correct Password  :: ";
					goto passl1;
				}
				else
				{
				exitl:
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Login Failed!!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
				}
			}
		}
	}


	int getPassword()
	{
		int u = 0, l = 0, s = 0;
		int i = 0, count = 0, d = 0;
	passv:
		u = 0;
		l = 0;
		s = 0;
		i = 0;
		d = 0;
		int done = 0;
		pass[0] = _getch();
		while (pass[i] != '\r')
		{
			if (pass[i] == '\b')
			{
				i--;
				printf("\b");
				printf(" ");
				printf("\b");
				pass[i] = _getch(); //12
			}
			else
			{
				printf("*");
				i++;
				pass[i] = _getch();
			}
		}
		pass[i] = '\0';
		if (strlen(pass) > 7 && strlen(pass) < 17)
		{
			for (int i = 0; i < strlen(pass); i++)
			{
				if (isupper(pass[i]))
				{
					u = 1;
				}
				if (islower(pass[i]))
				{
					l = 1;
				}
				if (!isalnum(pass[i]))
				{
					s = 1;
				}
				if (isdigit(pass[i]))
				{
					d = 1;
				}
			}
		}
		else
		{
			count++;
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "\n=====================================================" << endl;
			if (strlen(pass) < 8)
				cout << "->Password length is less than 8 character" << endl;
			if (strlen(pass) > 16)
				cout << "->Password length is greater than 16 character." << endl;
			cout << "=====================================================" << endl;
			if (count > 2)
			{
				cout << "Failed !!" << endl;
				return 0;
				goto exitl;
			}
			cout << "Attempt Remaining :: " << (3 - count) << endl;
			cout << "=====================================================" << endl;
			done = 0;
			if (done == 0)
			{
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "\nEnter Password Again :: ";
				goto passv;
			}
		}
		if (u == 1 && l == 1 && s == 1 && d == 1)
		{
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "\nPassword Meets All Requirements." << endl;
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			done = 1;
			return 1;
		}
		else
		{
			count++;
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "\nPassword Does Not Meet Following Requirements." << endl;
			cout << "\n=====================================================" << endl;
			if (u == 0)
				cout << "->Password without Uppercase." << endl;
			if (l == 0)
				cout << "->Password without lowercase." << endl;
			if (s == 0)
				cout << "->Password without special character." << endl;
			if(d == 0)
				cout << "->Password without Numeric digit." << endl;
			if (strlen(pass) < 8)
				cout << "->Password length is less than 8 character" << endl;
			if (strlen(pass) > 16)
				cout << "->Password length is greater than 16 character." << endl;
			cout << "=====================================================" << endl;
			if (count > 2)
			{
				cout << "Failed !!" << endl;
				return 0;
				goto exitl;
			}
			cout << "Attempt Remaining :: " << (3 - count) << endl;
			cout << "=====================================================" << endl;
			done = 0;
		}
		if (done == 0)
		{
			cout << "\nEnter Password Again :: ";
			goto passv;
		exitl:
			cout << " ";
		}
	}


	void getPassword1()
	{
		int i = 0;
		pass[0] = _getch();
		while (pass[i] != '\r')
		{
			if (pass[i] == '\b')
			{
				i--;
				printf("\b");
				printf(" ");
				printf("\b");
				pass[i] = _getch(); //12
			}
			else
			{
				printf("*");
				i++;
				pass[i] = _getch();
			}
		}
		pass[i] = '\0';
	}


	void forgetPassword()
	{
		a = 1;
		int flag = 0;
		char hint1[20] = { '\0' };
		char mob1[14] = { '\0' };
		int count = 0;
		cout << "\nWelcome to Password Forget Page !!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "===================================================" << endl;
		cout << "Enter Your Username :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(username, 20);
		strcpy(q, "SELECT password, mobilenumber, hint FROM userlogin WHERE username = '");
		strcat(q, username);
		strcat(q, "'");
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "Server Down!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			strcpy(pass1, row[0]);
			strcpy(hint1, row[2]);
			strcpy(mob1, row[1]);
			flag = 1;
		}
		cout << "===================================================" << endl;
		for (int i = 2; i > 0; --i) 
		{
			cout << "..........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		if(flag == 0)
		{
			cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Username is not registered!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
			goto exitl;
		}
		cout << "\n===================================================" << endl;
		cout << "\nEnter Your Registered Mobile Number :: ";
	hintm:
		cin.getline(mob, 14);
		cout << "===================================================" << endl;
		cout << "Enter Your Security Keyword :: ";
	hintl:
		cin.getline(hint, 20);
		cout << "===================================================\n" << endl;
		for (int i = 2; i > 0; --i) 
		{
			cout << "..........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (flag == 1)
		{
			count++;
			if (strcmp(mob1, mob) != 0)
			{
				cout << "\n\n===================================================" << endl;
				cout << "Mobile Number is not registered!!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				if (count < 3)
				{
					cout << "Attempt left :: " << (3 - count) << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "===================================================" << endl;
					cout << "Enter Mobile Number again :: ";
					goto hintm;
				}
				else
				{
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Password is not forgetted ::" << endl;
				}
			}
			if (strcmp(hint, hint1) == 0)
			{
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Password for Username { " << username << " } is :: " << pass1 << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
				for (int i = 2; i > 0; --i) 
				{
					cout << "..........................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
			}
			else
			{
				cout << "\n\n===================================================" << endl;
				cout << "Security Keyword is not match!!" << endl;
				if (count < 3)
				{
					cout << "Attempt left :: " << (3 - count) << endl;
					cout << "===================================================" << endl;
					cout << "Enter Security Keyword again :: ";
					goto hintl;
				}
				else
				{
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Password is not forgetted ::" << endl;
				}
			}
		}
	exitl:
		cout << "************************************************" << endl;
	}


	void updatePassword()
	{
		a = 1;
		int flag = 0, c = 0;
		cout << "\nWelcome to Updation Page !!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		int count = 0;
		cout << "Enter your Username :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(username, 20);
		strcpy(q, "SELECT password FROM userlogin WHERE username = '");
		strcat(q, username);
		strcat(q, "'");
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "\nServer Down!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			strcpy(pass1, row[0]);
			flag = 1;
		}

		if (flag == 0)
		{
			cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Username Not Found." << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (flag == 1)
		{
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Enter Your Password :: ";
		passl:
			getPassword1();
			if (strcmp(pass, pass1) == 0)
			{
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Enter New Password :: ";
				c = getPassword();
				for (int i = 2; i > 0; --i) 
				{
					cout << "..........................";
					this_thread::sleep_for(std::chrono::seconds(1));
				}
				cout << "\n";
				if (c == 0)
				{
					goto ext;
				}
				if (strcmp(pass, pass1) == 0)
				{
					cout << "\nError! You have Enter Same Old Password." << endl;
					cout << "Password is not updated!!" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				}
				else
				{
					strcpy(q, "update userlogin set password ='");
					strcat(q, pass);
					strcat(q, "' where username = '");
					strcat(q, username);
					strcat(q, "'");
					a = 1;
					a = mysql_query(conn, q);
					if (a != 0)
					{
						cout << "Server Down!!" << endl;
						goto exitl;
					}
					mysql_commit(conn);
					cout << "Password Sucessfully Updated!!" << endl;
					for (int i = 2; i > 0; --i) 
					{
						cout << "..........................";
						this_thread::sleep_for(std::chrono::seconds(1));
					}
					cout << "\n";
				}
			}
			else
			{
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Wrong Password!!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				count++;
				if (count < 3)
				{
					cout << "Attempt remaining  :: " << (3 - count) << endl;
					cout << "Enter Correct Password :: ";

					goto passl;
				}
				else
				{
				exitl:
					cout << "Login Failed!!" << endl;
				ext:
					cout << " ";
				}

			}
		}
	}


	void removeAccount()
	{
		a = 1;
		int flag = 0;
		cout << "\nWelcome to Account Deletion Page !!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		int count = 0;
		cout << "Enter your Username :: ";
		fgets(buff, sizeof buff, stdin);
		cin.getline(username, 20);
		strcpy(q, "SELECT password FROM userlogin WHERE username = '");
		strcat(q, username);
		strcat(q, "'");
		a = mysql_query(conn, q);

		for (int i = 2; i > 0; --i) 
		{
			cout << "..........................";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		if (a != 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Server Down!!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			goto exitl;
		}
		res = mysql_store_result(conn);

		while (row = mysql_fetch_row(res))
		{
			strcpy(pass1, row[0]);
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Invalid Username!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (flag == 1)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Enter Your Password :: ";
		passl:
			getPassword1();

			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			if (strcmp(pass, pass1) == 0)
			{
				deleteData(username);
			}
			else
			{
				cout << "\n===================================================" << endl;
				cout << "Password not matched!!" << endl;
				count++;
				if (count < 3)
				{
					cout << "Attempt remaining  :: " << (3 - count) << endl;
					cout << "===================================================" << endl;
					cout << "Enter Correct Password  :: ";
					goto passl;
				}
				else
				{
				exitl:
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "Login Failed!!" << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				}
			}
		}
	}


	void deleteData(char* user)
	{
		a = 1;
		cout << "\n\nRemoving account";
		for (int i = 3; i > 0; --i) 
		{
			cout << "............";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "\n";
		strcpy(q, "DELETE FROM userlogin WHERE username='");
		strcat(q, user);
		strcat(q, "'");
		a = mysql_query(conn, q);
		if (a != 0)
		{
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Server Down!!" << endl;
			cout << "Failed To Remove Account !!" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			goto exitl;
		}

		mysql_commit(conn);
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Account Removed Sucessfully!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	exitl:
		cout << " ";
	}
};


int main()
{

	cout << "CODE BY :- ZAMEER KHAN |" << endl;
	cout << "------------------------" << endl;
	cout << "                                      ------------------------Welcome To The Indian Airlines--------------------------" << endl;
	cout << "                                                             **Where Will Tomorrow Take You**" << endl;
	SelectOptionUser op;
	SelectUser s;
	s.selectUSer();
	SelectOptionAdmin sa;
	//sa.option();
	//op.option();
	return 0;
}
