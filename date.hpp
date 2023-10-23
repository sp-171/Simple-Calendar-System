#include <iostream>
using namespace std;

//header file date.hpp to declare your class
class Date {
    public:
        Date();
        //default constructor

        Date(int month, int day);
        //sets to month and day

        void set_appointed(int index, bool appt_val);
        //sets appointed index equal to apt val

        void set_date(int month, int day);
        //sets month and day

        bool get_available(int index);
        //checks if no appt is booked

        int get_month();
        // gets month

        int get_day();
        // gets day

        int isValid();
        // checks if user input is valid

        int isHoliday();
        // checks if holiday

        int isWeekend();
        // checks if holiday

        void output(ostream &outs);
        // print out member variables
        // print if weekday, weekend, holiday

        void printFreeTimeSlots();
        // prints out all free time slots

        void printAppointedTimeSlots();
        // prints all appointed time slots

        friend bool equal(const Date one, const Date two);
        // seeing if equal dates

        void TimePrint(int index, ostream &outs);
        // Prints the time for the appointment at index, to outs

    private:
        int month, day;

        bool appointed[48];
        // even indexes are the first half hour, odd are the second
        // if even, divide by 2 and put it as that hour
        // if odd, divide by 2 and put it as that hour and then add 30 min
    };

