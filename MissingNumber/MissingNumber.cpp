#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    // VARIABLE DECLARATION
    int max_number;
    int counter;
    int counter_extra;
    int placeholder;
    int break_loops = 0;
    vector<int> given_number_list;
    vector<int> all_number_list;
    // GET THE FIRST NUMBER
    scanf("%d", &max_number);
    // GET THE OTHER NUMBERS AND STORE IN A VECTOR
    for(counter = 1; counter < max_number; counter++){
        scanf("%d", &placeholder);
        given_number_list.push_back(placeholder);
    }
    // RESET THE EXTRA VARIABLE
    placeholder = 0;
    // GENERATE A LIST WITH ALL NUMBERS IN THIS INTERVAL
    for(counter = 0; counter < max_number; counter++){
        placeholder++;
        all_number_list.push_back(placeholder);
    }
    // CREATE A LOOP THAT IS GONNA BREAK ONLY WHEN THE ALL NUMBERS LIST HAD ONE ELEMENT
    while(all_number_list.size() != 1){
        for(counter_extra = 0; counter_extra <= all_number_list.size(); counter_extra++){ // LOOP WITH THE ALL NUMBERS LIST (A.N.L)
            if(break_loops == 1){ // BREAK THIS FOR IF THE FOR BELOW HAS BREAKED
                break_loops = 0;
                break;
            }
            for(counter = 0; counter <= given_number_list.size(); counter++){ // LOOP WITH THE GIVEN NUMBERS LIST
                if(all_number_list[counter_extra] == given_number_list[counter]){ // IF THE ELEMENTS ARE EQUAL, REMOVE FROM A.N.L
                    all_number_list.erase(all_number_list.begin() + counter_extra);
                    break_loops = 1;
                    break; // AND BREAK
                }
            }
        }
    }
    // PRINT THE ANSWER
    printf("%d", all_number_list.front());
    return 0;
}