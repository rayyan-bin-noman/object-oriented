#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;
    int daysOfMonth(const Date& d) const; // Returns the number of days in a month
    static const int daysInMonth[]; // Array containing the 12 month’s days
    bool leapYear(int) const; // Tells whether the year is a leap year or not
public:
    Date(int d = 1, int m = 1, int y = 1900); // Constructor with default arguments
    void setDate(int, int, int); // Set the date with given arguments
    void display() const; // Display the date on the screen

    // Operator prototypes
    Date operator ++ (); // Pre-increment operator used as ++date1
    Date operator + (int); // Plus operator used as date1 + 5
};

// The implementation of the date class.
const int Date::daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Displaying the date on the screen
void Date::display() const {
    std::cout << "\nDate: " << (day < 10 ? "0" : "") << day
              << "-" << (month < 10 ? "0" : "") << month
              << "-" << year;
}

// Constructor of the Date
Date::Date(int d, int m, int y) {
    setDate(d, m, y);
}

// Setting the date as given arguments
void Date::setDate(int d, int m, int y) {
    year = y;

    // If month is wrong, set it to 1
    if (m < 1 || m > 12) 
        month = 1;
    else
        month = m;

    // Handle February with leap year logic
    if (month == 2 && leapYear(y)) {
        if (d >= 1 && d <= 29)
            day = d;
        else
            day = 1;
    }
    else if (d >= 1 && d <= daysInMonth[month]) // Validate days in other months
        day = d;
    else
        day = 1;
}

// This function returns the number of days in a month
int Date::daysOfMonth(const Date& d) const {
    if (d.month == 2 && leapYear(d.year)) // If leap year then Feb is 29
        return 29;
    else
        return daysInMonth[d.month];
}

// Testing if the year is a leap year
bool Date::leapYear(int y) const {
    return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

// + operator overloaded for the date. Used as date1 + 5
Date Date::operator + (int numberOfDays) {
    for (int i = 1; i <= numberOfDays; i++) {
        ++(*this); // Calling the pre-increment operator
    }
    return *this;
}

// Pre-increment operator
Date Date::operator ++ () {
    if (day == daysOfMonth(*this) && month == 12) { // End of year
        day = 1;
        month = 1;
        ++year;
    }
    else if (day == daysOfMonth(*this)) { // End of month
        day = 1;
        ++month;
    }
    else {
        ++day; // Not the last day of the month
    }
    return *this; // Return the updated Date object
}

int main() {
    Date d1(26, 12, 2002), d2(28, 2, 2000), d3;
    d1.display();
    ++d1;
    std::cout << "\nAfter adding 1 day, the date is ";
    d1.display();
    std::cout << std::endl;
    d2.display();
    d2 = d2 + 5;
    std::cout << "\nAfter adding 5 days to the above date";
    d2.display();
    return 0;
}
