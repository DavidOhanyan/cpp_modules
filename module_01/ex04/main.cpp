/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:47:55 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/19 17:11:47 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "ERROR" <<std::endl;
		return (1);
	}
	std::string name = argv[1];
	size_t pos = 0;
	std::string line;

	std::ifstream inFile(argv[1]);
	if (!inFile)
	{
		std::cout << "cant open the file "<< std::endl;
		return(1);
	}
	std::ofstream outFile(name + ".reverce");
	
	while(getline(inFile, line))
	{
		while ((pos = line.find(argv[2], pos)) != std::string::npos)
		{
			line.erase(pos, strlen(argv[2]));
			line.insert(pos, argv[3]);
			pos += strlen(argv[3]);
		}
		outFile << line << std::endl;
		pos = 0;
	} 
	return (0);
}