#include <iostream>
#include <string>
#include "learn\learn.h"
#include"include/ds.h"
#include <chrono>
#include <list>
#define log(x) std::cout<<x;

int main() {
	std::cout << "Driver Code" << std::endl;
	//CADS::List<int> list = { 5,6,8 };
	learn::List<int>sll;
	std::list<int> std_list;
	size_t counter = 0;
	while (counter < 1000) {
		//list.push_back(rand());
		std_list.push_back(rand());
		counter++;
	}
	
	auto sum = 0;
	for (size_t i = 0; i < 100; i++) {
		auto beg = std::chrono::high_resolution_clock::now();
		//std_list.reverse();
		std_list.sort();
		auto fin = std::chrono::high_resolution_clock::now();
		auto std_dur = std::chrono::duration_cast<std::chrono::milliseconds>(fin - beg);
		sum += std_dur.count();
		std::system("cls");
		log("Sorting STL: ");
		log((int)i);
		log(" %");
	}
	log("\n\nSTL sort test complete now. Proceed to test sort of CADS?")
	
	std_list.clear();

	counter = 0;
	while (counter < 1000) {
		//list.push_back(1000000 - counter);
		sll.insert(rand());

		//std_list.push_back(rand());
		counter++;
	}
	std::cin.get();

	auto sums = 0;
	for (size_t i = 0; i < 100; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		//list.reverse();
		sll.sort();
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		sums += duration.count();
		std::system("cls");
		log("Sorting Learn: ");
		log((int)i);
		log(" %");
	}
	log("\n\nAverage time  by stl::list (in Microseconds) to sort a list of length 1 Million:");
	log((float)sum / 100);
	log("\nAverage time  by CADS::List (in Microseconds) to sort a list of length 1 Million:");
	log((float)sums / 100);
}

// Pause current thread
// std::chrono::milliseconds dur(10);
// std::this_thread::sleep_for(dur);

// Test for execution time between list.add() and list.join()

/*
List <int> newList, secondList, thirdList, fourthList;
	for (int i = 0; i < 5; i++) {
		newList.insert(rand() % 100);
		secondList.insert(rand() & 100);
	}
	//std::cout << (newList.size() * 0.000001) << " Megabytes" << std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	newList.add(secondList);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Addition of two lists took time of: "<<duration.count()<<" milliseconds"<<std::endl;
	newList.clear();
	secondList.clear();

	for (int i = 0; i < 1000000; i++) {
		thirdList.insert(rand() & 100);
		fourthList.insert(rand() & 100);
	}

	auto start2 = std::chrono::high_resolution_clock::now();
	thirdList.join(fourthList);
	auto end2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
	std::cout << "Joining of two lists took time of: " << duration2.count() << " milliseconds" << std::endl;

	std::cout << (thirdList.size() * 0.000001) << " Megabytes" << std::endl;
*/