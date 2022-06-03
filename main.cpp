#include <cmath>
#include <iostream>

/*!
* Constant min_length is the minimum length allowed for any side of the triangle.
*/
const double min_length = 0.1;
/*!
* Constant max_length is the maximum length allowed for any side of the triangle.
*/
const double max_length = 100.0;
/*!
* constant newline is the newline charachter.
*/
const char newline = '\n';
/*!
* constant tab is the tab charachter.
*/
const char tab = '\t';
/*!
* constant compare_test is the maximum difference that is allowed between two lengths
* are considered the same.
*/
const double compare_test = 0.001;

int main()
{	
	bool valid_triangle = false;
	auto side_one = 0.0;
	auto side_two = 0.0;
	auto side_three = 0.0;
	while (valid_triangle == false)
	{
		std::cout << "Please enter the length of the triangle's first side: ";
		std::cin >> side_one;

		while (std::cin.fail() || side_one < min_length || side_one > max_length)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), newline);
			std::cout << "Invalid input. Enter length between 0.1 and 100.0: ";
			std::cin >> side_one;
		}

		std::cout << "Please enter the length of the triangle's second side: ";
		std::cin >> side_two;

		while (std::cin.fail() || side_two < min_length || side_two > max_length)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), newline);
			std::cout << "Invalid input. Enter length between 0.1 and 100.0: ";
			std::cin >> side_two;
		}

		std::cout << "Please enter the length of the triangle's third side: ";
		std::cin >> side_three;

		while (std::cin.fail() || side_three < min_length || side_three > max_length)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), newline);
			std::cout << "Invalid input. Enter length between 0.1 and 100.0: ";
			std::cin >> side_three;
		}

		if (side_one + side_two > side_three && side_two + side_three > side_one && side_three + side_one > side_two)
		{
			valid_triangle = true;
		}
		else
		{
			std::cout << "Not a Triangle" << std::endl;
		}

	}

	auto app_hyp = 0.0;
	if (side_one > side_two && side_one > side_three)
	{
		app_hyp = side_one;
	}
	else if (side_two > side_one && side_two > side_three)
	{
		app_hyp = side_two;
	}
	else
	{
		app_hyp = side_three;
	}

	auto sq_ex_hyp = 0.0;
	auto exp_hyp = 0.0;
	if (app_hyp == side_one)
	{
		sq_ex_hyp = side_two * side_two + side_three * side_three;
		exp_hyp = sqrt(sq_ex_hyp);
	}
	else if (app_hyp == side_two)
	{
		sq_ex_hyp = side_one * side_one + side_three * side_three;
		exp_hyp = sqrt(sq_ex_hyp);
	}
	else
	{
		sq_ex_hyp = side_one * side_one + side_two * side_two;
		exp_hyp = sqrt(sq_ex_hyp);
	}

	if (side_one == side_two && side_two == side_three)
	{
		std::cout << "This is an Equilateral triangle" << newline << std::endl;
	}
	else if (side_one == side_two || side_two == side_three || side_three == side_one)
	{
		std::cout << "This is an Isoscelese triangle" << newline <<std::endl;
	}
	else
	{
		std::cout << "This is a Scalene triangle" << newline << std::endl;
	}

	std::cout << "Side One =" << side_one << tab << "Side Two =" << side_two << tab << "Side Three =" << side_three << std::endl;
	std::cout << "Apparent Hypotenuse =" << app_hyp << tab << "Expected Hypotenuse=" << std::endl;

	if (exp_hyp - app_hyp <= compare_test && app_hyp - exp_hyp <= compare_test)
	{
		std::cout << "The triangle IS a right triangle." << std::endl;
	}
	else
	{
		std::cout << "The triangle is NOT a right triangle" << std::endl;
	}
	
	return 0;
}