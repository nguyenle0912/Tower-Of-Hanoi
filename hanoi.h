#ifndef __HANOI_H__
#define __HANOI_H__

#include <array>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>

class Hanoi
{
private:
	unsigned int m_Disks;
	std::array<std::stack<unsigned int>, 3> m_Pegs;

	void PrintMove(std::ostream& os, unsigned int disk, unsigned int from, unsigned int to)
	{
		os << "Moving Disk " << disk << " from peg " << from << " to peg " << to << std::endl;
	}

	void MakeMove(std::ostream& os, unsigned int from, unsigned int to);

public:
	Hanoi(unsigned int n);

	void Solve(std::ostream& os)
	{
		unsigned int number_of_moves = std::pow(2, m_Disks) - 1;

		unsigned int src = 0;
		unsigned int aux = 1;
		unsigned int dst = 2;

		// if the number of disks are even, swap the aux and dest pegs
		if (m_Disks % 2 == 0)
		{
			std::swap(aux, dst);
		}

		for (int i = 1; i <= number_of_moves; ++i)
		{
			if (i % 3 == 1)
			{
				MakeMove(os, src, dst);
			}
			else if (i % 3 == 2)
			{
				MakeMove(os, src, aux);
			}
			else
			{
				MakeMove(os, aux, dst);
			}
		} 
	}
};


#endif // __HANOI_H__
