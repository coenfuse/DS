// Consists of code for CADS unit testing

#pragma once

// TODO : Fix all warnings
// TODO : Read the testing guide pdf at : https://docs.microsoft.com/en-us/visualstudio/test/unit-test-basics?view=vs-2019

#include <chrono>
#include <thread>
#include "util/ansi_color.h"
#include "../src/CADS.h"

namespace IO {
	static void log(std::string& to_print) { std::cout << to_print; }
	static void input_str(std::string* store_in) { std::getline(std::cin >> std::ws, *store_in); }
	static void input(void* store_in) { std::cin >> store_in; }
}

const static enum class TYPE {
	array,
	vector,
	string,
	pair,
	link,
	list,
	loop,
	block,
	chain,
	band,
	stack,
	Q,
	ring,
	priorityQ,
	leaf,
	tree,
	avl,
	set,
	map,
	multi_map,
	unordered_map,
	g_map,
	matrix,
	plane,
	cube,
	tesseract,
	node,
	d_graph,
	u_graph
};

const static enum class timer_type {
	nanoseconds,
	microseconds,
	milliseconds,
	seconds,
	minutes
};

class cus_dat_type {

	bool	var1;
	char	var2;
	short	var3;
	int		var4;
	double	var5;
	float	var6;

public:

	cus_dat_type() :
		var1(true),
		var2('c'),
		var3(6969),
		var4(696969),
		var5(69.7777),
		var6(69.3333f)
	{}

	// TODO : IMPORTANT. Add a datatype conversion constructor
	// TODO : Add operator overloads
	// TODO : Add copy constructor
};

class testing {

	static class Stopwatch {

		using time_type = std::chrono::time_point<std::chrono::steady_clock>;

		time_type m_start;
		time_type m_end;
		bool m_valid;

	public:

		Stopwatch() :
			m_start(std::chrono::high_resolution_clock::now()),
			m_end(std::chrono::high_resolution_clock::now()),
			m_valid(false)
		{}

		void start() {

			m_start = std::chrono::high_resolution_clock::now();
			m_valid = false;

		}

		void stop() {

			m_end = std::chrono::high_resolution_clock::now();
			m_valid = true;

		}

		unsigned int get_duration(timer_type type) {

			switch (type)
			{
			case timer_type::nanoseconds:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start).count());
				break;

			case timer_type::microseconds:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::microseconds>(m_end - m_start).count());
				break;

			case timer_type::milliseconds:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count());
				break;

			case timer_type::seconds:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::seconds>(m_end - m_start).count());
				break;

			case timer_type::minutes:
				return (unsigned int)(std::chrono::duration_cast<std::chrono::minutes>(m_end - m_start).count());
				break;
			}
		}

	};
	
	Stopwatch Timer;
	TYPE type;

private:

	void test_array();
	void test_vector();
	void test_string();
	void test_pair();
	void test_link();
	void test_list();
	void test_loop();
	void test_block();
	void test_chain();
	void test_band();
	void test_stack();
	void test_Q();
	void test_ring();
	void test_priorityQ();
	void test_leaf();
	void test_tree();
	void test_avl();
	void test_set();
	void test_map();
	void test_multi_map();
	void test_unordered_map();
	void test_g_map();
	void test_matrix();
	void test_plane();
	void test_cube();
	void test_tesseract();
	void test_node();
	void test_d_graph();
	void test_u_graph();

public:

	testing(TYPE _init_type) : type(_init_type) {}
	~testing(){}

	void run() {
		
		Timer.start();
		
		switch (type)
		{
		case TYPE::array: test_array();
			break;
		case TYPE::vector:
			break;
		case TYPE::string:
			break;
		case TYPE::pair:
			break;
		case TYPE::link:
			break;
		case TYPE::list:
			break;
		case TYPE::loop:
			break;
		case TYPE::block:
			break;
		case TYPE::chain:
			break;
		case TYPE::band:
			break;
		case TYPE::stack:
			break;
		case TYPE::Q:
			break;
		case TYPE::ring:
			break;
		case TYPE::priorityQ:
			break;
		case TYPE::leaf:
			break;
		case TYPE::tree:
			break;
		case TYPE::avl:
			break;
		case TYPE::set:
			break;
		case TYPE::map:
			break;
		case TYPE::multi_map:
			break;
		case TYPE::unordered_map:
			break;
		case TYPE::g_map:
			break;
		case TYPE::matrix:
			break;
		case TYPE::plane:
			break;
		case TYPE::cube:
			break;
		case TYPE::tesseract:
			break;
		case TYPE::node:
			break;
		case TYPE::d_graph:
			break;
		case TYPE::u_graph:
			break;
		default:
			break;
		}

		Timer.stop();

		std::cout <<"Total Test Duration : " << Timer.get_duration(timer_type::microseconds) <<"us"<< std::endl;

	}

};