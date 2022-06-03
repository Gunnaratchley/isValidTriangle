#include <iostream>

#include "triangle.h"

namespace nwacc
{
	/*!
	*\brief
	* Summary
	*
	*\param
	*\return
	*/
	double apparent_hypot(const double side_one, const double side_two, const double side_three, double app_hyp)
	{
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
		return app_hyp;
	}

	void validity_check(const double side_one, const double side_two, const double side_three)
	{
		bool valid_triangle = false;
		do
		{
			if (side_one + side_two < side_three || side_two + side_three < side_one || side_three + side_one < side_two)
			{
				std::cout << "Sides do not form a triangle" << std::endl;
			}//else they do form a triangle, do_nothing();
		} while (valid_triangle == false);
	}

}