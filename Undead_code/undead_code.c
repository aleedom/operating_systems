// Author: John-Austen Francisco
// Date: 9 September 2015
//
// Preconditions: Appropriate C libraries
// Postconditions: Generates Segmentation Fault for
//                               signal handler self-hack

// Student name: Andrew Leedom
// Ilab machine used:  Personal Computer Running ubuntu 15.04

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void segment_fault_handler(int signum)
{

	char *p = (char *)&signum;
	//printf("0x%02x%02x%02x%02x\n", p[63],p[62],p[61],p[60]);
	/* running instructions
	 * for my laptop and vi.cs.rutgers.edu this needs to be 0x02
	 * for my Desktop running ubuntu 15.04 it needs to be 0x05
	 *
	 */
	p[60] += 0x02;
	//printf("0x%02x%02x%02x%02x\n", p[63],p[62],p[61],p[60]);
	printf("I am slain!\n");
	//exit(0);
	//Use the signnum to construct a pointer to flag on stored stack
	//Increment pointer down to the stored PC
	//Increment value at pointer by length of bad instruction


}


int main()
{
	int r2 = 0;
	signal(SIGSEGV, segment_fault_handler);

	r2 = *( (int *) 0 );

	printf("I live again!\n");

	return 0;
}
