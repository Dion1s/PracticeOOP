#ifndef CTIME_H
#define CTIME_H
#include <iostream>
class CTime {
private:
    int hours;
    int minutes;
    int seconds;

public:
    CTime();
    CTime(int hours, int minutes, int seconds);

    void setHours(int hours);
    int getHours() const;

    void setMinutes(int minutes);
    int getMinutes() const;

    void setSeconds(int seconds);
    int getSeconds() const;

    void console_input();
    void console_output() const;

    void increaseTime(int seconds);
    CTime operator+(const CTime& other) const;
    int differenceInSeconds(const CTime& other) const;
    int compare(const CTime& other) const;

    operator int() const;
};

#endif 
