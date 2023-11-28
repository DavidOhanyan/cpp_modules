/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:10:31 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/28 20:33:15 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("example.txt");
    if (!file.is_open()) 
    {
        std::cerr << "Unable to open the file" << std::endl;
        return 1;
    }
    std::string line;
    std::getline(file, line);
    std::stringstream ss;
    ss << line;
    //std::cout << line<<std::endl;
    std::vector<std::string> tokens;
    std::string token;
    
    while (std::getline(ss, token, '-'))
    {
        tokens.push_back(token);
    }
    ss.str("");
    size_t i = 0;
    while (i < tokens.size()) {
        std::cout << tokens[i] << std::endl;
        ++i;
    }
    file.close(); 

    return 0;
}


//int main() {
//    std::string input = "Hello,world,this,is,a,test";

//    std::stringstream ss(input);
//    std::string token;
//    std::vector<std::string> tokens;

//    while (std::getline(ss, token, ',')) {
//        tokens.push_back(token);
//    }

//    for (size_t i = 0; i < tokens.size(); ++i) {
//        std::cout << tokens[i] << std::endl;
//    }

//    return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <string>

//int main() {
//    std::ifstream file("example.txt"); // Замените "example.txt" на имя вашего файла
//    if (!file.is_open()) {
//        std::cerr << "Unable to open the file" << std::endl;
//        return 1;
//    }

//    std::string line;
//    std::getline(file, line);
//    std::cout << getline(file, line, '-')<<std::endl;
//        //std::cout << line.size() << std::endl; // Вывод каждой строки файла
//        // Здесь вы можете выполнить любую обработку строки
//    //std::cout<<line.substr(0, '-')<<std::endl;

//    file.close(); // Не забудьте закрыть файл после использования

//    return 0;
//}