/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:53 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/14 21:53:45 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge (std::vector<int> &leftArray, std::vector<int> &rightArray, std::vector<int> &arr);

void mergeSort(std::vector<int> &arr)
{
	int lenght = arr.size();
	if (lenght <= 1)
		return ;
	int middle = arr.size() / 2;

	std::vector<int> leftArray(middle);
	std::vector<int> rightArray(arr.size() - middle);
	int i = 0;
	int j = 0;
	for (; i < lenght; i++)
	{
		if (i < middle)
			leftArray[i] = arr[i];
		else
		{
			rightArray[j] = arr[i];
			j++;
		}		
	}
	mergeSort(leftArray);
	mergeSort(rightArray);
	merge(leftArray, rightArray, arr);
}

void merge (std::vector<int> &leftArray, std::vector<int> &rightArray, std::vector<int> &arr)
{
	int leftSize = arr.size() / 2;
	int rightSize = arr.size() - leftSize;

	int l = 0;
	int r = 0;
	int i = 0;


	while (l < leftSize && r < rightSize)
	{
		if (leftArray[l] < rightArray[r])
		{
			arr[i] = leftArray[l];
			i++;
			l++;
		}
		else
		{
			arr[i] = rightArray[r];
			i++;
			r++;
		}
	}
	while (l < leftSize)
	{
		arr[i] = leftArray[l];
		i++;
		l++;
	}
	while (r < rightSize)
	{
		arr[i] = rightArray[r];
		i++;
		r++;
	}
}

void inertionSort(std::vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    
}

bool binarySearch(std::vector<int> &arr, int val)
{
	int size = arr.size();
	int low = 0;
	int height = size - 1;
	while (low <= height)
	{
		int mid = (low + height) / 2;
		if (val == arr[mid])
		{
			std::cout<<"tiv@ gtnvac e"<<arr[mid]<<std::endl;
			return (0);
		}
		else if(val > mid)
		{
			low = mid + 1; 
		}
		else
		{
			height = mid - 1;
		}	
	}
	return (1);
}

int main(int argc,  char **argv)
{
	//int arr[] = {1, -3, 33, 11, 56, 78};
	//std::vector<int> vec(arr, arr + 6);
	////mergeSort(vec);
    //inertionSort(vec);
	//binarySearch(vec, 11);
	////for (size_t i = 0; i < vec.size(); i++)
	////{
	////	std::cout<<vec[i]<<" ";
	////}
	//std::vector<std::pair<int, int> > pairs;
    
    //pairs.push_back(std::make_pair(1, 4));
    //pairs.push_back(std::make_pair(3, 4));
    //pairs.push_back(std::make_pair(5, 6));

	//std::cout << pairs[0].first<<std::endl;
	try
	{
		if (argc == 1)
			throw std::runtime_error("Bad argument!");
		std::vector<std::pair<int, int> > pair;
		PmergeMe::validateFill(argv);
		PmergeMe::fillCorrectPair(pair);

		for (size_t i = 0; i < pair.size(); i++)
		{
			std::cout<< pair[i].first << " "<<pair[i].second<<std::endl; 
		}
		std::cout<<"----------\n";
		PmergeMe::mergeSort(pair);
		for (size_t i = 0; i < pair.size(); i++)
		{
			std::cout<< pair[i].first << " "<<pair[i].second<<std::endl; 
		}
		//for (size_t i = 0; i < PmergeMe::vec.size(); i++)
		//{
		//	std::cout<<*PmergeMe::lst.begin()<<std::endl;
		//	PmergeMe::lst.pop_front();
		//}
		
	}
	catch(const std::exception& e)
	{
		PmergeMe::vec.clear();
		PmergeMe::lst.clear();
		std::cerr << e.what() << std::endl;
	}
	 

	return (0);
}
