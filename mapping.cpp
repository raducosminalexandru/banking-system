#include "mapping.h"

std::map<std::string,std::pair<std::string,int>> user_details(const std::string user ,const std::string pass ,const std::string funds){
    std::ifstream username_file(user);
    std::ifstream password_file(pass);
    std::ifstream funds_file(funds);

    if(!username_file || !password_file || !funds_file){
        exit(1);
    }

    std::string username;
    std::string password;
    std::string fund_text;
    float fund;

    std::map<std::string,std::pair<std::string,int>> data_map;

    while(getline(username_file,username)){
        getline(password_file,password);
        getline(funds_file,fund_text);

        fund = std::stof(fund_text);

        data_map[username] = std::make_pair(password,fund);
    }

    username_file.close();
    password_file.close();
    funds_file.close();

    return data_map;
}
