/********************************************8
 * Game Theory Simulations
 * 
 * True (1): Cooperate
 * False (0): Defect 
**********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool Random(){
    //randomly select true or false
    return rand() % 2;
}

bool Cooperative(){
    return true;
}

bool Defective(){
    return false;
}

bool TitForTat(bool prev){
    //initially cooperate
    //o/w follow opponents previous choice
    if ((!prev) || (prev == true)) {
        return true;
    } else {
        return false;
    }
}

tuple<int, int> results(bool a, bool b){
    int a_val = 0;
    int b_val = 0;
    //both cooperate
    if (a && b) {
        a_val = 10;
        b_val = 10;
    //a cooperates, b defects
    } else if (a && !b) {
        a_val = 0;
        b_val = 5;
    //a defects, b cooperates
    } else if (!a && b) {
        a_val = 5;
        b_val = 0;
    //both defect
    } else {
        a_val = 1;
        b_val = 1;
    }
    return {a_val, b_val};
}


int main() 
{
    //change val of random variable each iteration
    srand(time(NULL));

    //initialize player points
    int A = 0; 
    int B = 0;

    //run simulation for N iterations
    int N = 1000;
    for (int i = 0; i < N; i++) {
        bool prev;
        //assign players algorithms
        bool A_choice = Random();
        bool B_choice = TitForTat(prev);
        prev = A_choice;

        tuple result = results(A_choice, B_choice);
        
        //update player scores
        A += get<0>(result);
        B += get<1>(result);
    }

    //output results
    cout << "Total Points" << endl; 
    cout << "A (Rand): " << A << endl;
    cout << "B (T4T):  " << B << endl;

    return 0;
}