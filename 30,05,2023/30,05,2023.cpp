
#include <iostream>
#include "CParallelepiped.h"
#include "CTime.h"

int main() {
    char sumbol{};
    std::cout << "Select the program \n(p - parallelepiped; t - time)\n";
    std::cin >> sumbol;
    if (sumbol == 'p') {
        CParallelepiped parallelepiped;

         int choice = 0;
         double factor = 0;
         do {
             std::cout << "------------------------------------\n";
             std::cout << "Enter the value to select" << '\n';
             std::cout << "1 - input sides: \n";
             std::cout << "2 - output all informations\n";
             std::cout << "3 - if you want to increase the value of all sides\n";
             std::cout << "4 - if you want to erase previous data\n";
             std::cout << "0 - exit\n";
             std::cout << "------------------------------------\n";
             std::cin >> choice;
             switch (choice)
             {
             case 1:
                 parallelepiped.console_input();
                 break;
             case 2:
                 parallelepiped.console_output();
                 break;
             case 3:
                 parallelepiped.increaseEdges();
                 break;
             case 4:
                 parallelepiped = CParallelepiped();
                 std::cout << "The operation is successful\n";
                 break;
             default:
                 std::cout << "Incorrect value entered, try again\n";
                 break;
             }
         } while (choice != 0);
    }
    else if (sumbol == 't') {

        CTime time1;
        CTime time2;
        CTime sum;

        int choice1;
        int choiceTime = 0;
        int upSecond = 0;
        int timeInSeconds = 0;
        int difference = 0;
        int comparison = 0;
        do {
            std::cout << "------------------------------------\n";
            std::cout << "Enter the value to select" << '\n';
            std::cout << "1 - input two times: \n";
            std::cout << "2 - output all informations\n";
            std::cout << "3 - if you want to increase the value of Time\n";
            std::cout << "4 - if you want to erase previous data\n";
            std::cout << "0 - exit\n";
            std::cout << "5 - sum time\n";
            std::cout << "6 - difference between first and second time\n";
            std::cout << "7 - time in second\n";
            std::cout << "8 - compare time\n";
            std::cout << "------------------------------------\n";
            std::cin >> choice1;
            switch (choice1)
            {
            case 1:
                std::cout << "\tTime 1: \n";
                time1.console_input();
                std::cout << "\tTime 2: \n";
                time2.console_input();
                break;
            case 2:
                std::cout << "\tTime 1: \n";
                time1.console_output();
                std::cout << "\tTime 2: \n";
                time2.console_output();
                break;
            case 3:
                std::cout << "Choose the exact time\t 1 - first time; 2 - second time;\n";
                std::cin >> choiceTime;
                if (choiceTime == 1) {
                    std::cout << "By how many seconds you want to increase?\n";
                    std::cin >> upSecond;
                    time1.increaseTime(upSecond);
                }
                if (choiceTime == 2) {
                    std::cout << "By how many seconds you want to increase?\n";
                    std::cin >> upSecond;
                    time2.increaseTime(upSecond);
                }
                break;
            case 4:
                std::cout << "Choose the exact time\t 1 - first time; 2 - second time;\n";
                std::cin >> choiceTime;
                if (choiceTime == 1)
                    time1 = CTime();
                if (choiceTime == 2)
                    time2 = CTime();

                std::cout << "The operation is successful\n";
                break;
            case 5:
                sum = time1 + time2;
                sum.console_output();
                std::cout << "The operation is successful\n";
                break;
            case 6:
                difference = time1.differenceInSeconds(time2);
                std::cout << "Difference in seconds: " << difference << std::endl;
                break;
            case 7:
                std::cout << "Choose the exact time\t 1 - first time; 2 - second time;\n";
                std::cin >> choiceTime;
                if (choiceTime == 1) {
                    timeInSeconds = static_cast<int>(time1);
                    std::cout << "Time in seconds: " << timeInSeconds << std::endl;
                }
                if (choiceTime == 2) {
                    timeInSeconds = static_cast<int>(time2);
                    std::cout << "Time in seconds: " << timeInSeconds << std::endl;
                }
                break;
            case 8:
                comparison = time1.compare(time2);
                if (comparison == -1)
                    std::cout << "Time2 > Time1\n";

                if (comparison == 1)
                    std::cout << "Time2 < Time1\n";

                if (comparison == 0)
                    std::cout << "Time2 == Time1\n";
                break;
            default:
                std::cout << "Incorrect value entered, try again\n";
                break;
            }
        } while (choice1 != 0);
    }
    return 0;
    
}


