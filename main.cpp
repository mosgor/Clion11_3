#include <iostream>
#include <string>

std::string get_address_part(std::string ip, int part){
    int points = 0;
    std::string octet = "";
    for (int i = 0; i < ip.length(); ++i) {
        if (ip[i] == '.') points++;
        else if (points == part){
            octet += ip[i];
        }
        if (points > part) break;
    }
    return octet;
}

int string_to_int(std::string str){
    while(str.length() != 3) str = "0" + str;
    return (str[0] - '0') * 100 + (str[1] - '0') * 10 + str[2] - '0';
}

std::string checkIp(std::string ip){
    if  (ip.find("..") != -1) return "Invalid\n";
    std::string library = "12234567890.";
    int points = 0;
    for (int i = 0; i < ip.length(); ++i) {
        bool rightFormat = false;
        if (ip[i] == '.') points++;
        for (int j = 0; j < library.length(); ++j) {
            if (ip[i] == library[j]) {
                rightFormat = true;
                break;
            }
        }
        if (!rightFormat || points > 3) return "Invalid\n";
    }
    if (points < 3) return "Invalid";
    for (int i = 0; i < 4; ++i) {
        if (get_address_part(ip, i).length() > 1 && get_address_part(ip, i)[0] == '0') return "Invalid\n";
        if (string_to_int(get_address_part(ip, i)) < 0 || string_to_int(get_address_part(ip, i)) > 255) return "Invalid\n";
    }
    return "Valid\n";
}

int main() {
    while(true){
        std::cout << "Is your IP valid?" << std::endl;
        std::cout << "Input your IP address: ";
        std::string ip;
        std::cin >> ip;
        std::cout << checkIp(ip);
    }
}