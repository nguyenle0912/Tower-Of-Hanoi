#include "hanoi.h"

Hanoi::Hanoi(unsigned int n) : m_Disks(n)
{ 
	//m_Pegs[0] is source
    //m_Pegs[1] is aux
    //m_Pegs[2] is dest
    
    //disks are numbered from 1 to n
    //fill source peg with n disks
    for(unsigned int disk = 0; disk < n; disk++)
    {
        unsigned int diskNumber = n - disk;
        m_Pegs[0].push(diskNumber); //largest number represents the largest disk
    }
    
}


void Hanoi::MakeMove(std::ostream& os, unsigned int peg1, unsigned int peg2)
{
	// TODO: move the disks between pegs appropriately
    // NOTE:  Make sure to call PrintMove for each disk movement!
    unsigned int pole1TopDisk;
    unsigned int pole2TopDisk;
    if(!(m_Pegs[peg1].empty()))
        pole1TopDisk = m_Pegs[peg1].top();
    
    if(!(m_Pegs[peg2].empty()))
        pole2TopDisk = m_Pegs[peg2].top();
    
    // When pole 1 is empty
           if (m_Pegs[peg1].empty())
           {
               m_Pegs[peg1].push(pole2TopDisk);
               m_Pegs[peg2].pop();
               PrintMove(os, pole2TopDisk, peg2, peg1);
           }
           // When pole2 pole is empty
           else if (m_Pegs[peg2].empty())
           {
               m_Pegs[peg2].push(pole1TopDisk);
               m_Pegs[peg1].pop();
               PrintMove(os, pole1TopDisk, peg1, peg2);
           }
           // When top disk of pole1 > top disk of pole2
           else if (pole1TopDisk > pole2TopDisk)
           {
               m_Pegs[peg1].push(pole2TopDisk);
               m_Pegs[peg2].pop();
               PrintMove(os, pole2TopDisk, peg2, peg1);
           }
           // When top disk of pole1 < top disk of pole2
           else
           {
               m_Pegs[peg2].push(pole1TopDisk);
               m_Pegs[peg1].pop();
               PrintMove(os, pole1TopDisk, peg1, peg2);
           }
}

