/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:30:04 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/14 22:52:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void function(char **argv)
{
	int i = 1, j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isalpha(argv[i][j]))
				std::cout << (char)toupper(argv[i][j]);
			else
				std::cout << argv[i][j];
			j++;
		}
		std::cout<< " ";
		i++;		
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	function(argv);	

	return (0);
}