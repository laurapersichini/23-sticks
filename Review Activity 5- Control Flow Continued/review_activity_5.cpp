//
//  main.cpp
//  Review Activity 5- Control Flow Continued
//
//  Created by Laura Persichini on 2020-10-17.
//  Copyright © 2020 Laura Persichini. All rights reserved.
//
// HOW TO TEST THE PROGRAM:
// to check that this game would work in a real game scneario, I
// ensured that the user would not be able to enter a value other than 1, 2, or 3.
// I also tested that the rules outlined for which actions the computer should take
// given different scenarios held true (i.e. ensuring that the computer entered 4 - X
// sticks when the number of sticks left was greater than 4. 
#include <iostream>

using namespace std;

// gets the number of sticks that the user wants
// inputs: N/A
// return: what the user chose (1, 2, 3)
// restrictions: input from user must be a number

int getting_input() { //
    int user_input;
    
    cout << " how many sticks do you want to take? (1,2,3): ";
    cin >> user_input;
    
    // continue prompting until input is 1 or 2 or 3
    while (user_input != 1 && user_input !=2 && user_input != 3) {
        cout << " you must pick 1,2,3: ";
        cin >> user_input;
    }
    
    return user_input; // returns what number of sticks the user inputs (123)
}

//  computes the number of sticks that the computer chooses
// inputs: sticks: how many sticks are left, user_choice: how many sticks the user chose in the most recent choice
// return: the choice for the computer
int getting_computer_input(int sticks_left, int user_input) {
    int computer_input = -1; // -1 is an arbitrary number, it will be changed later
    if (sticks_left > 4) {
        computer_input = 4 - user_input;
    } else if (sticks_left ==2 || sticks_left == 3 || sticks_left == 4) {
        if (sticks_left == 2) {
            computer_input = sticks_left - 1;
        }
        if (sticks_left == 3) {
            computer_input = sticks_left - 2;
        }
        if (sticks_left == 4) {
            computer_input = sticks_left - 3;
        }
        
    } else if (sticks_left == 1) {
        computer_input = 1;
    }
    return computer_input;
}


int main(int argc, const char * argv[]) {
    int sticks_left = 23;
    while (sticks_left > 0) {
        cout << "you have " << sticks_left << " sticks left" << endl;
        int user_input = getting_input();
        sticks_left = sticks_left - user_input;
        cout << "you took " << user_input << " sticks." << " there are now " << sticks_left << " sticks remaining." << endl;
        if (sticks_left <= 0) {
            cout << endl;
            cout << "################################################################" << endl;
            cout << "you lost! better luck next time!" << endl;
            cout << "################################################################" << endl;
            cout << endl;
            break;
        }
        
        int computer_input = getting_computer_input(sticks_left, user_input);
        cout << "i took " << computer_input << " sticks." << endl;
        sticks_left = sticks_left - computer_input;
        cout << " there are now " << sticks_left << " sticks remaining" << endl;
        if (sticks_left <= 0) {
            cout << endl;
            cout << "################################################################" << endl;
            cout << "you won!" << endl;
            cout << "################################################################" << endl;
            cout << endl;
            break;
        }
            }
    
    return 0;
}
