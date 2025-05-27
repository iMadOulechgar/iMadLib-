#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <ctime>

using namespace std;

class clsQueueLine{

private:

    short _TotalTickets = 0;
    short _AverageServeTime = 0;
    string _Prefix = "";

public:

clsQueueLine(string Pre , int Min){
    _TotalTickets = 0;
    _AverageServeTime = Min;
    _Prefix = Pre;
}

class clsTicket
{
    private:

        short _Number = 0;
        string _Prefix;
        string _TicketTime;
        short _WaitingClients = 0;
        short _AverageServeTime = 0;
        short _ExpectedServeTime = 0;
    
    public:

    clsTicket(string Pre , short Num , short WaitingClients , short averageSavTime){
        _Prefix = Pre;
        _Number = Num;
        _TicketTime = GetSystemDateTimeString();
        _AverageServeTime = averageSavTime;
        _WaitingClients = WaitingClients;
    }

    string Prefix(){
        return _Prefix;
    }

    short Number(){
        return _Number;
    }

    string FullNumber(){
        return _Prefix + to_string(_Number);
    }

    string TimeAndDate(){
        return _TicketTime;
    }

    short ExspectedTime(){
        return _AverageServeTime * _WaitingClients;
    }

    short WaitingClient(){
        return _WaitingClients;
    }

     void Print()
        {
            cout << "\n\t\t\t  _______________________\n";
            cout << "\n\t\t\t\t    " << FullNumber();
            cout << "\n\n\t\t\t    " << _TicketTime;
            cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
            cout << "\n\t\t\t      Serve Time In";
            cout << "\n\t\t\t       " << ExspectedTime() << " Minutes.";
            cout << "\n\t\t\t  _______________________\n";
            

        }
};

queue<clsTicket>QueueLine;

static string GetSystemDateTimeString(){
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

}

void issueTicket(){
    _TotalTickets++;
    clsTicket Ticket(_Prefix,_TotalTickets,WaitingClient(),_AverageServeTime);
    QueueLine.push(Ticket);
}

short WaitingClient(){
    return QueueLine.size();
}

string WhosNext(){

    if (QueueLine.empty())
        return "No One Is Next";
    else
        return QueueLine.front().FullNumber();
}

bool ServeNextClient(){

    if (QueueLine.empty())
        return false;    

    QueueLine.pop();
    return true;
}

short ServedClients(){
    return _TotalTickets - WaitingClient();
}

void PrintInfo()
{
    cout << "\n\t\t\t _________________________\n";
    cout << "\n\t\t\t\tQueue Info";
    cout << "\n\t\t\t _________________________\n";
    cout << "\n\t\t\t    Prefix   = " << _Prefix;
    cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets ;
    cout << "\n\t\t\t    Served Clients  = " << ServedClients();
    cout << "\n\t\t\t    Wating Clients  = " << WaitingClient(); ;
    cout << "\n\t\t\t _________________________\n";
    cout << "\n";
}

void PrintTciketsRTL(){

    if (QueueLine.empty())
        cout << "\n\t\tTickets: No Tickets.";
    else
        cout << "\n\t\tTickets: ";
    
    queue<clsTicket>TicketsNum = QueueLine;

    while (!TicketsNum.empty())
    {
        clsTicket Num = TicketsNum.front();
        cout<<" "<<Num.FullNumber()<<" <--- ";
        TicketsNum.pop();
    }
    cout<<"\n";
}

void PrintTciketsLTR(){

      if (QueueLine.empty())
            cout << "\n\t\tTickets: No Tickets.";
        else
            cout << "\n\t\tTickets: ";

        queue <clsTicket> TempQueueLine = QueueLine;
        stack <clsTicket> TempStackLine;

        while (!TempQueueLine.empty())
        {
            TempStackLine.push(TempQueueLine.front());
            TempQueueLine.pop();
        }

        while (!TempStackLine.empty())
        {
            clsTicket Ticket = TempStackLine.top();

            cout << " " << Ticket.FullNumber() << " --> ";

            TempStackLine.pop();
        }
    cout<<"\n";
}

void PrintAllTickets(){

   cout << "\n\n\t\t\t       ---Tickets---";

        if (QueueLine.empty())
        cout << "\n\n\t\t\t     ---No Tickets---\n";

        queue <clsTicket> TempQueueLine= QueueLine;

        while (!TempQueueLine.empty())
        {
            TempQueueLine.front().Print();
            TempQueueLine.pop();
        }
}

};
