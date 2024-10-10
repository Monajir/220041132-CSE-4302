
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

using namespace std;

void randomassignment(coordinate c[], int size) {
    srand(time(0));

    for (int i = 0; i < size; ++i) {
        c[i].move_x(rand() * 0.9);
        c[i].move_y(rand() * 0.9);
    }
}

void sort(coordinate c[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (c[i].getdistance() > c[j].getdistance()) {
                coordinate temp;
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
}

int main()
{
    coordinate coord[10];
    randomassignment(coord, 10);
    sort(coord, 10);
    for (int i = 0; i < 10; i++)
    {
        coord[i].display();
    }

}