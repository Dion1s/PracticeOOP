
#include "CParallelepiped.h"

CParallelepiped::CParallelepiped() {
    length = 0.0;
    width = 0.0;
    height = 0.0;
}

CParallelepiped::CParallelepiped(double length, double width, double height) {
    this->length = length;
    this->width = width;
    this->height = height;
}

CParallelepiped::~CParallelepiped(){

}

void CParallelepiped::setLength(double length) {
    this->length = length;
}

double CParallelepiped::getLength() const {
    return length;
}

void CParallelepiped::setWidth(double width) {
    this->width = width;
}

double CParallelepiped::getWidth() const {
    return width;
}

void CParallelepiped::setHeight(double height) {
    this->height = height;
}

double CParallelepiped::getHeight() const {
    return height;
}

void CParallelepiped::console_input() {
    double l, w, h;

    do {
        std::cout << "Enter length: ";
        std::cin >> l;
        if (l <= 0)
            std::cout << "Invalid input! Side length must be a positive number." << std::endl;
    } while (l <= 0);
    setLength(l);

    do {
        std::cout << "Enter width: ";
        std::cin >> w;
        if (w <= 0)
            std::cout << "Invalid input! Side length must be a positive number." << std::endl;
    } while (w <= 0);
    setWidth(w);

    do {
        std::cout << "Enter height:  ";
        std::cin >> h;
        if (h <= 0)
            std::cout << "Invalid input! Side length must be a positive number." << std::endl;
    } while (h <= 0);
    setHeight(h);
}

void CParallelepiped::console_output() const {
    try {
        if (getLength() <= 0 || getHeight() <= 0 || getWidth() <= 0) {
            throw std::invalid_argument("Invalid side lengths,must be a positive number");
        }
        std::cout << "Length: " << length << std::endl;
        std::cout << "Width: " << width << std::endl;
        std::cout << "Height: " << height << std::endl;

        double surfaceArea = calculateSurfaceArea();
        double volume = calculateVolume();
        double diagonal = calculateDiagonal();

        std::cout << "Surface Area: " << surfaceArea << std::endl;
        std::cout << "Volume: " << volume << std::endl;
        std::cout << "Diagonal: " << diagonal << std::endl;

        bool IsCube = isCube();

        std::cout << "Is Cube: " << (IsCube ? "Yes" : "No") << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

double CParallelepiped::calculateSurfaceArea() const {
    return 2 * (length * width + length * height + width * height);
}

double CParallelepiped::calculateVolume() const {
    return length * width * height;
}

double CParallelepiped::calculateDiagonal() const {
    return std::sqrt(length * length + width * width + height * height);
}

void CParallelepiped::increaseEdges() {
    double increaseValue;
    std::cout << "Enter the value to increase the sides: ";
    std::cin >> increaseValue;

    try {
        setLength(getLength() * increaseValue);
        setHeight(getHeight() * increaseValue);
        setWidth(getWidth() * increaseValue);
        std::cout << "Parallelepiped sides increased by " << increaseValue << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

bool CParallelepiped::isCube() const {
    return (length == width) && (length == height);
}
