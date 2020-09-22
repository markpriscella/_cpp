/****************************************************************
          Author: Mark Priscella
          Date: 1/30/2018
          Effort: 30 minutes
          Purpose: To create a binary flagging system using 
          unsigned binary integers. 
 ****************************************************************/

#include <stdio.h>


// FUNCTION DEFINITONS
void set_flag( unsigned int* flag_holder, int flag_position );
void unset_flag( unsigned int * flag_holder, int flag_position );
int check_flag( unsigned int flag_holder, int flag_position );
void display_32_flags( unsigned int flag_holder );

int main( int argc, char* argv[] )
{
  unsigned int flag_holder = 0;
  
  set_flag(&flag_holder, 3);
  set_flag(&flag_holder, 16);
  set_flag(&flag_holder, 31);
  
  display_32_flags(flag_holder);
  
  unset_flag(&flag_holder, 31);
  unset_flag(&flag_holder, 3);
  set_flag(&flag_holder, 9);
  
  display_32_flags(flag_holder);

  return 0;
}

// set a flag at flag_position in flag_holder
void set_flag( unsigned int* flag_holder, int flag_position )
{
  unsigned int setNum = 1;
  setNum = setNum << flag_position;

  *flag_holder = (*flag_holder|setNum);
}

/* This function will invert flag_holder making all 0's to 1's and 
all 1's to 0's. Then it will use check_flag to see if the bit at 
flag_position is equal to 0. Remember since we inverted flag_holder, 
if there is a 0 at flag_position, then it was originally a 1. The 
function will then set the 0 to a 1 using set_flag and finally will 
invert flag_holder again to get the original flags back minus 
the removed flag */
void unset_flag( unsigned int * flag_holder, int flag_position )
{
  /* invert every bit in flag_holder */
  *flag_holder = ~(*flag_holder);

  /* check to see if there is a 0 at position i, and if
     there is then set the 0 at flag_position to 1 */
  if( check_flag(*flag_holder, flag_position ) == 0 )
    set_flag( flag_holder, flag_position );
  
  /* invert flag_holder again to get original number */
  *flag_holder = ~(*flag_holder);
}

/*  check flag_position in flag holder and return 1 if a flag
    is at flag_position and a 0 if no flag is found
*/
int check_flag( unsigned int flag_holder, int flag_position )
{
  unsigned int checkNum = 1;
  checkNum = checkNum << flag_position;

  if( flag_holder&checkNum )
    return 1;
  else
    return 0;
}

// display all flags by printing all bits of flag_holder
void display_32_flags( unsigned int flag_holder )
{
  /* create a for loop so you can print bit by bit using check_flag */
  int i;
  for( i = 31; i >= 0; i-- )
    {
      /* check the bit at position i and print value */
      printf( "%d", check_flag(flag_holder, i) );

      /* after every four bits print a space to make 
	 it easier on the eyes while reading */
      if( i%4 == 0 )
	{
	  printf( " " );
	}
    }

  /* print line for ease of reading */
  printf( "\n" );
  
}