#include "modify_files.h"


void modify_funds(std::string funds, std::string auxiliary){
    std::ifstream input(funds);
    std::ofstream intermediate(auxiliary);

    if(!input.is_open()){
        exit(1);
    }

    if(!intermediate.is_open()){
        exit(1);
    }


    std::string line;
    int counter = 0;

    while(std::getline(input,line)){
        if(counter == g_position - 1){
            intermediate << std::fixed << std::setprecision(4) << g_funds << std::endl;
        }

        else intermediate << line << std::endl;
        counter++;
    }

    input.close();
    intermediate.close();

    std::ifstream intermediate_input(auxiliary);
    std::ofstream input_final(funds);

    if(!intermediate_input.is_open()){
        exit(1);
    }

    if(!input_final.is_open()){
        exit(1);
    }


    while(std::getline(intermediate_input,line)){
        input_final << line << std::endl;
    }

    intermediate_input.close();
    input_final.close();

    std::ofstream clear_auxiliary(auxiliary, std::ios::trunc);
    clear_auxiliary.close();
}
