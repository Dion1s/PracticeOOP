#ifndef CPARALLELEPIPED_H
#define CPARALLELEPIPED_H
#include <iostream>
#include <cmath>
class CParallelepiped {
private:
    double length;
    double width;
    double height;

public:
    CParallelepiped();
    CParallelepiped(double length, double width, double height);
    
    ~CParallelepiped();

    void setLength(double length);
    double getLength() const;

    void setWidth(double width);
    double getWidth() const;

    void setHeight(double height);
    double getHeight() const;

    void console_input();
    void console_output() const;

    double calculateSurfaceArea() const;
    double calculateVolume() const;
    double calculateDiagonal() const;

    void increaseEdges();
    bool isCube() const;
};

#endif 
