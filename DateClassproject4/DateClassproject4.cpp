#include <iostream>
#include "Date_Header.h"
using namespace std;

//The main function works by testing the constructor, and mutator for valid/invalid dates along with verifying the leap year.
//in addition, it displays the default constructor date.In addition, it tests the leap year one last time along with the get dates for
//the day, month and year. And it tests the get last day stored function again.
int main() {

    //1. Create a date object using the default constructor and display 
    //the date using the first date format.
    Date defaultDate;
    cout << "1. Test default constructor: " << defaultDate.printDate1() << endl << endl;

    //2. Create a date object using the constructor with parameters 
    //and display the date using the second date format.
    Date validDate(12, 28, 2021);
    cout << "2. Test constructor with parameters: " << validDate.printDate2() << endl << endl;

    //3. Use one of your date objects to test the setDate() function and 
    //display the result using the third date format. 
    defaultDate.setDate(6, 23, 1997);
    cout << "3. Test setDate with valid date: " << defaultDate.printDate3() << endl << endl;

    //4. Use setDate() to set the date to  13/45/2018 and verify that this date is not accepted.
    cout << "4. Test setDate with invalid date of 13/45/2018: ";
    Date testDate;
    testDate.setDate(13, 45, 2018);
    cout << endl << endl;

    //5. Use setDate() to set the date to 4 / 31 / 2000 and verify that this date is not accepted.
    cout << "5. Test setDate with invalid date of 4/31/2000: ";
    testDate.setDate(4, 31, 2000);
    cout << endl << endl;

    //6. Use setDate() to set the date to 2 / 29 / 2009 and verify that this date is not accepted.
    cout << "6. Test setDate with invalid date of 2/29/2009: ";
    testDate.setDate(2, 29, 2009);
    cout << endl << endl;

    //7. Set the first date object to 4/10/2014 and the second date object to 4/18/2014 
    //subtract the second date from the first date, the result should be 8 days.
    cout << "7. Test subtraction of two dates (result should be 8 days): " << endl;
    Date firstDate(4, 10, 2014);
    Date secondDate(4, 18, 2014);
    cout << firstDate.printDate1() << " - " << secondDate.printDate1() << " = "
        << (firstDate - secondDate) << " days" << endl << endl;

    //8. Set the first date to 2 / 2 / 2006 and the second date to 11 / 10 / 2003, 
    //subtract the second date from the first date, the result should be 815 days.
    cout << "8. Test subtraction of two dates (result should be 815 days): " << endl;
    firstDate.setDate(2, 2, 2006);
    secondDate.setDate(11, 10, 2003);
    cout << firstDate.printDate1() << " - " << secondDate.printDate1() << " = "
        << (firstDate - secondDate) << " days" << endl << endl;

    //9. Set the date to 2/29/2008, use the pre-decrement operator, and print the 
    //date using one of the print formats, and verify that the date is set to 1/31/2008.
    cout << "9. Test the pre-decrement operator: " << endl;
    testDate.setDate(2, 29, 2008);
    cout << testDate.printDate1() << " pre-decremented is now ";
    cout << (--testDate).printDate1() << endl << endl;

    //10. Use the pre - increment operator, print the date using one of the print 
    //formats, and verify that it is set to back to 2 / 29 / 2008.
    cout << "10. Test the pre-increment operator: The date is 2/29/2008 again " << endl;
    cout << (++testDate).printDate1() << endl << endl;

    //11. Repeat the previous two steps using the post - decrement and post - increment operators.
    cout << "11. Test the post-decrement and post-increment operators: " << endl;
    cout << "The incrementing/decrementing will happen post (after) the function (printing)." << endl;
    cout << testDate--.printDate1() << " post-decremented is now ";
    cout << (testDate++).printDate1() << endl;
    cout << "post-incremented, it is now " << (testDate++).printDate1() << endl << endl;

    //12. Set the date to 12 / 31 / 2024, use the post - increment operator, print
    //the date using one of the print formats, and verify that the date is set to 1 / 1 / 2025.
    cout << "12. Test the post-increment operator: " << endl;
    testDate.setDate(12, 31, 2024);
    cout << "The original date is: "<< (testDate++).printDate1() << endl;
    cout << " post-incremented, it is now " << testDate.printDate1() << endl << endl;

    //13. Use the post - decrement operator, print the date using one of the print 
    //formats, and verify that the date is set back to 12 / 31 / 2024.
    cout << "13. Test the post-decrement operator: " << endl;
    cout << "The current date is: " << (testDate--).printDate1() << endl;
    cout << "post-decremented, it is now " << testDate.printDate1() << endl << endl;

    //14. Repeat the previous two steps using the pre - increment and pre - decrement operators.
    cout << "14. Test the pre-decrement and pre-increment operators: " << endl;
    testDate.setDate(12, 31, 2024);
    cout << testDate.printDate1();
    ++testDate;
    cout << " pre-incremented is now " << testDate.printDate1() << endl;
    --testDate;
    cout << "pre-decremented is now " << testDate.printDate1() << endl << endl;

    //15. Use cin and the >> operator to read a date typed in at the keyboard.
    cout << "15. Test the >> operator: " << endl;
    Date cinDate;
    cin >> cinDate;
    cout << endl;

    //16. Use cout and the << operator to display the date that was read from the keyboard.
    cout << "16. Test the << operator: " << endl;
    cout << "You entered: " << cinDate << endl << endl;
}