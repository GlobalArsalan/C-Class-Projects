#include <iostream>
#include <cmath>

int main() {
    double input;
    double finalMark, midTermMark, project1Mark, project2Mark, project3Mark, project4Mark, project5Mark;
    int finalMax, midTermMax, project1Max, project2Max, project3Max, project4Max, project5Max;
    double finalGrade, midTermGrade, project1Grade, project2Grade, project3Grade, project4Grade, project5Grade;
    //////////////////////////////////////////////Enter Values//////////////////////////////////////////////////////////////////
    std::cout << "Enter the final max" << std::endl;
    std::cin >> input;
    finalMax = input;
    while(input != finalMax || input <= 0) {
        std::cout << "Enter the final max" << std::endl;
        std::cin >> input;
        finalMax = input;
    }
    std::cout << "Enter the final grade" << std::endl;
    std::cin >> finalGrade;
    while(finalGrade < 0 || finalGrade > finalMax ) {
        std::cout << "Enter the final grade" << std::endl;
        std::cin >> finalGrade;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "Enter the midterm max" << std::endl;
    std::cin >> input;
    midTermMax = input;
    while(input != midTermMax || input <= 0) {
        std::cout << "Enter the midTerm max" << std::endl;
        std::cin >> input;
        midTermMax = input;
    }
    std::cout << "Enter the midterm grade" << std::endl;
    std::cin >> midTermGrade;
    while(midTermGrade < 0 || midTermGrade > midTermMax) {
        std::cout << "Enter the midterm grade" << std::endl;
        std::cin >> midTermGrade;
    }
    ////////////////////////////////////////////////////////////////////////
    std::cout << "Enter the project 1 max" << std::endl;
    std::cin >> input;
    project1Max = input;
    while(input != project1Max || input <= 0) {
        std::cout << "Enter the project 1 max" << std::endl;
        std::cin >> input;
        project1Max = input;
    }
    std::cout << "Enter the project 1 grade" << std::endl;
    std::cin >> project1Grade;
    while(project1Grade < 0 || project1Grade > project1Max) {
        std::cout << "Enter the project1 grade" << std::endl;
        std::cin >> project1Grade;
    }
    ////////////////////////////////////////////////////////////////////
    std::cout << "Enter the project 2 max" << std::endl;
    std::cin >> input;
    project2Max = input;
    while(input != project2Max || input <= 0) {
        std::cout << "Enter the project2 max" << std::endl;
        std::cin >> input;
        project2Max = input;
    }
    std::cout << "Enter the project2 grade" << std::endl;
    std::cin >> project2Grade;
    while(project2Grade < 0 || project2Grade > project2Max) {
        std::cout << "Enter the project2 grade" << std::endl;
        std::cin >> project2Grade;
    }
    /////////////////////////////////////////////
    std::cout << "Enter the project 3 max" << std::endl;
    std::cin >> input;
    project3Max = input;
    while(input != project3Max || input <= 0) {
        std::cout << "Enter the project 3 max" << std::endl;
        std::cin >> input;
        project3Max = input;
    }
    std::cout << "Enter the project3 grade" << std::endl;
    std::cin >> project3Grade;
    while(project3Grade < 0 || project3Grade > project3Max) {
        std::cout << "Enter the project 3 grade" << std::endl;
        std::cin >> project3Grade;
    }
    ////////////////////////////////////////////////////////
    std::cout << "Enter the project 4 max" << std::endl;
    std::cin >> input;
    project4Max = input;
    while(input != project4Max || input <= 0) {
        std::cout << "Enter the project 4 max" << std::endl;
        std::cin >> input;
        project4Max = input;
    }
    std::cout << "Enter the project 4 grade" << std::endl;
    std::cin >> project4Grade;
    while(project4Grade < 0 || project4Grade > project4Max) {
        std::cout << "Enter the project 4 grade" << std::endl;
        std::cin >> project4Grade;
    }
    /////////////////////////////////////////////////////////////
    std::cout << "Enter the project 5 max" << std::endl;
    std::cin >> input;
    project5Max = input;
    while(input != project5Max || input <= 0) {
        std::cout << "Enter the project 5 max" << std::endl;
        std::cin >> input;
        project5Max = input;
    }
    std::cout << "Enter the project 5 grade" << std::endl;
    std::cin >> project5Grade;
    while(project5Grade < 0 || project5Grade > project5Max) {
        std::cout << "Enter the project 5 grade" << std::endl;
        std::cin >> project5Grade;
    }
    //////////////////////////////Calculate Marks////////////////////////////////////////////////////////
    finalMark = 100*(finalGrade / finalMax);
    midTermMark = 100*(midTermGrade / midTermMax);
    project1Mark = 100*(project1Grade / project1Max);
    project2Mark = 100*(project2Grade / project2Max);
    project3Mark = 100*(project3Grade / project3Max);
    project4Mark = 100*(project4Grade / project4Max);
    project5Mark = 100*(project5Grade / project5Max);
    ////////////////////////////////////////////Check Final Supremacy////////////////////////////////////////////////////////////////
    if(finalMark > midTermMark) {
        midTermMark = finalMark;
    } if (finalMark > project1Mark) {
        project1Mark = finalMark;
    } if (finalMark > project2Mark) {
        project2Mark = finalMark;
    } if (finalMark > project3Mark) {
        project3Mark = finalMark;
    } if (finalMark > project4Mark) {
        project4Mark = finalMark;
    } if (finalMark > project5Mark) {
        project5Mark = finalMark;
    }
    //////////////////////////////////////////Calculation of The Final Mark///////////////////////////////////
    double result = 0.75 * finalMark + 0.25 * midTermMark;
    double projectResult = (project1Mark + project2Mark + project3Mark + project4Mark + project5Mark) / 5.0;
    double finalResult;
    if (result <= 40) {
        finalResult = result;
    } else if (result >= 60) {
        finalResult = (2.0/3.0) * result + (1.0/3.0) * projectResult;
    } else {
        finalResult = projectResult * (1.0/3.0) * (((result-40)/20)) + result * (1 - (1.0/3.0)*(((result - 40)/20)));
    }
    finalResult = std::round(finalResult + 1e-12);
    std::cout << "Final grade: " << finalResult;   



    

    return 0;
}
