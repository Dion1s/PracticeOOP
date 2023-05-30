
#include "CTime.h"

CTime::CTime() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

CTime::CTime(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

void CTime::setHours(int hours) {
    this->hours = hours;
}

int CTime::getHours() const {
    return hours;
}

void CTime::setMinutes(int minutes) {
    this->minutes = minutes;
}

int CTime::getMinutes() const {
    return minutes;
}

void CTime::setSeconds(int seconds) {
    this->seconds = seconds;
}

int CTime::getSeconds() const {
    return seconds;
}

void CTime::console_input() {
    double h, m, s;

    do {
        std::cout << "Enter hourse: ";
        std::cin >> h;
        if (h < 0)
            std::cout << "Invalid input! Side length must be a positive number." << std::endl;
    } while (h < 0);
    setHours(h);

    do {
        std::cout << "Enter minutes: ";
        std::cin >> m;
        if (m <0)
            std::cout << "Invalid input! Side length must be a positive number." << std::endl;
    } while (m < 0);
    setMinutes(m);

    do {
        std::cout << "Enter seconds:  ";
        std::cin >> s;
        if (s < 0)
            std::cout << "Invalid input! Side length must be a positive number." << std::endl;
    } while (s < 0);
    setSeconds(s);
    
}

void CTime::console_output() const {
    try {
        if (getHours() < 0 || getMinutes() < 0 || getSeconds() < 0) {
            throw std::invalid_argument("Invalid side lengths,must be a positive number");
        }
            std::cout << "Hours: " << hours << std::endl;
            std::cout << "Minutes: " << minutes << std::endl;
            std::cout << "Seconds: " << seconds << std::endl;

        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
}

void CTime::increaseTime(int seconds) {
    int totalSeconds = hours * 3600 + minutes * 60 + this->seconds;
    totalSeconds += seconds;

    if (totalSeconds < 0)
        totalSeconds = 0;

    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    this->seconds = (totalSeconds % 3600) % 60;
}

CTime CTime::operator+(const CTime& other) const {
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    totalSeconds += other.hours * 3600 + other.minutes * 60 + other.seconds;

    int newHours = totalSeconds / 3600;
    int newMinutes = (totalSeconds % 3600) / 60;
    int newSeconds = (totalSeconds % 3600) % 60;

    // Обчислення залишку годин без днів
    if (newHours > 23) 
        newHours %= 24;
    

    return CTime(newHours, newMinutes, newSeconds);
}

int CTime::differenceInSeconds(const CTime& other) const {
    int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
    int totalSeconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;

    return std::abs(totalSeconds1 - totalSeconds2);
}

int CTime::compare(const CTime& other) const {
    int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
    int totalSeconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;

    if (totalSeconds1 < totalSeconds2)
        return -1;
    else if (totalSeconds1 > totalSeconds2)
        return 1;
    else
        return 0;
}

CTime::operator int() const {
    return hours * 3600 + minutes * 60 + seconds;
}
