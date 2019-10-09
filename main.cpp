#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "hanoi.h"

int main(int argc, char** argv)
{
	
    	std::ofstream fout("towerOfHanoi.txt");


	 //3 is number of disks, change this number to the desired number of disks
		Hanoi problem(3);
		problem.Solve(fout);	

  
	return 0;
}
