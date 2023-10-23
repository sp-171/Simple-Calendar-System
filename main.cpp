//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include "time.hpp"
#include "date.hpp"
#include <math.h>
using namespace std;

int main() {

  Date myDate;
  TimeRange myTime;
  
  // declaring variables 
  int month;
  int day;
  int beginHour;
  int beginMinute;
  int endHour;
  int endMinute;

  //myDate.printFreeTimeSlots();

  // explaining rules 
  cout << "\nCurrent calendar takes weekdays May 8th 2022 to August 8th 2022." << endl;
  cout << "When entering dates all months and days need to be entered in integer form." << endl;
  cout << "Times need to be booked as a 24 hour time clock (ex. 4 am = 4, 4pm = 16), and minutes entered as 0 or 30." << endl;
  cout << "Use ctrl+c to exit." << endl;

  cout << "\nWhat month would you like your booking? ";
            cin >> month; // user input
  cout << "\nWhat day would you like your booking? ";
            cin >> day;

  myDate.set_date(month,day); //set date

  int check = myDate.isValid(); //check if date is valid
  if (check == 0)
  {
    cout << "\nInvalid Date. Cannot book an appointment.\n";
  }

  if ((check == 1) || (check == 2))
  {
    cout << "Unavailable time slots are: " << endl;
    myDate.printAppointedTimeSlots(); // printing booked slots
    cout << "Available time slots are: " << endl;
    myDate.printFreeTimeSlots(); //printing free time slots for that date

    cout << "\nWhat hour would you like your booking to start? ";
    cin >> beginHour; // user input

    cout << "\nWhat minute would you like your booking tot start? ";
    cin >> beginMinute; // user input

    cout << "\nWhat hour would you like your booking to end? ";
    cin >> endHour; // user input

    cout << "\nWhat minute would you like your booking to end? ";
    cin >> endMinute; // user input

    myTime.set(beginHour, beginMinute, endHour, endMinute); // set time

    int check2 = myTime.isValid(); //check if time is valid
    if (check2 == 0)
      cout<< "\nInvalid time range. Cannot book appoinment.\n";

    if (check2==1){
      int index = myTime.TimeIndex(beginHour, beginMinute);
      myDate.set_appointed(index, 1);
      
      cout << "Appointment Booked for " << myDate.get_month() << "/" << myDate.get_day() << "/2022." << endl;
      
      cout << "Appointed Time Slots:" << endl;
      myDate.printAppointedTimeSlots();
    }
}
}  


