#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>

using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/**
 * Compute the cube root of a positive integer.
 * @param x where to store the Out.
 * @param a the number whose cube root to compute.
 */
void cube_root(mpf_t& x, const mpf_t a);

/***** Add more functions as necessary. *****/

/**
 * The main.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits

    mpf_t pi,x,a,r,s,t,u,v,w,One,Two,Three,Nine,TwentySeven,EqualToStore,zero; // Declaration of iterating variables and numbers for arithmetic operations
    mpf_t SquareRoot3,SquareRoot3MinusOne,rSquare,rCube,OneMinusrCube,TwoMulr,rIntor,OnePlusr,uFunction,Niner,uFunction1,tSquare,uIntoT,uSquare,vFunction,sSquare,OnePlusS,wFunction,wFunction1,wA,OnePlusW,a22,aMinusr,sFunction,sFunction0,TwoU,sFunction1,sFunction2,sSquare1,sCube1,rFunction,a32,OnePlusThree,aFunction; // Declaring functions that use iterating variables
    mpf_init(pi); // Initializing declared variables
    mpf_init(One);
    mpf_init(Two);
    mpf_init(Three);
    mpf_init(Nine);
    mpf_init(TwentySeven);
    mpf_init(EqualToStore);
    mpf_init(zero);
	mpf_init(x);
	mpf_init(a);
    mpf_init(r);
    mpf_init(s);
    mpf_init(t);
    mpf_init(u);
    mpf_init(v);
    mpf_init(w);
    mpf_init(SquareRoot3);
    mpf_init(SquareRoot3MinusOne);
    mpf_init(rSquare);
	mpf_init(rCube);
	mpf_init(OneMinusrCube);
	mpf_init(TwoMulr);
	mpf_init(rIntor);
	mpf_init(OnePlusr);
	mpf_init(uFunction);
	mpf_init(Niner);
	mpf_init(uFunction1);
	mpf_init(tSquare);
	mpf_init(uIntoT);
	mpf_init(uSquare);
	mpf_init(vFunction);
	mpf_init(sSquare);
	mpf_init(OnePlusS);
	mpf_init(wFunction);
	mpf_init(wFunction1);
	mpf_init(wA);
	mpf_init(OnePlusW);
	mpf_init(a22);
	mpf_init(aMinusr);
	mpf_init(sFunction);
	mpf_init(sFunction0);
	mpf_init(TwoU);
	mpf_init(sFunction1);
	mpf_init(sFunction2);
	mpf_init(sSquare1);
	mpf_init(sCube1);
	mpf_init(rFunction);
	mpf_init(a32);
	mpf_init(OnePlusThree);
	mpf_init(aFunction);
	
	mpf_set_d(One,1); // Setting required values to variables 
    mpf_set_d(Two,2);
    mpf_set_d(Three,3);
    mpf_set_d(Nine,9);
    mpf_set_d(TwentySeven,27);
    mpf_set_d(zero,0);
    
	mpf_div(a,One,Three); // Performing Arithmetic operations
	mpf_sqrt(SquareRoot3,Three);
	mpf_sub(SquareRoot3MinusOne,SquareRoot3,One);
	mpf_div(r,SquareRoot3MinusOne,Two);
	mpf_mul(rSquare,r,r);
    mpf_mul(rCube,rSquare,r);
    mpf_sub(OneMinusrCube,One,rCube);
 	cube_root(s,OneMinusrCube); // Calling cube root function

	for(int n=0;n<MAX_ITERATIONS;n++) // Iterating loop for MAX_ITERATIONS
    {
    	mpf_t i;
    	mpf_init(i);
    	mpf_set_d(i,n);
    	int TwoNMinusOne=2*n-1; // Setting TwoMinusOne for calculating Power
    	mpf_mul(TwoMulr,Two,r);
    	mpf_add(t,One,TwoMulr);
		mpf_mul(rIntor,r,r);
   		mpf_add(OnePlusr,One,r);
   		mpf_add(uFunction,rIntor,OnePlusr);
   		mpf_mul(Niner,Nine,r);
   		mpf_mul(uFunction1,Niner,uFunction);
   		cube_root(u,uFunction1);
   		mpf_mul(tSquare,t,t);
   		mpf_mul(uIntoT,t,u);
   		mpf_mul(uSquare,u,u);
   		mpf_add(vFunction,tSquare,uIntoT);
   		mpf_add(v,vFunction,uSquare);
   		mpf_mul(sSquare,s,s);
 		mpf_add(OnePlusS,One,s);
   		mpf_add(wFunction,OnePlusS,sSquare);
   		mpf_mul(wFunction1,TwentySeven,wFunction);
   		mpf_div(w,wFunction1,v);
  		mpf_mul(wA,w,a);
    	mpf_sub(OnePlusW,One,w);
    	if(n==0)// Power value when n=0
    	{
        	mpf_div(OnePlusThree,One,Three);
    	}
    	else
    	{
        	mpf_pow_ui(OnePlusThree,Three,TwoNMinusOne);
   		}
 		mpf_mul(aFunction,OnePlusThree,OnePlusW);
   		mpf_add(a,wA,aFunction);
    	if(mpf_cmp(EqualToStore,a)==0) // Making function efficient by using mpf_cmp. Reducing loops by comparing with previous value
    	{
        	break; 
    	}
   		mpf_sub(aMinusr,One,r);
   		mpf_mul(sFunction,aMinusr,aMinusr);
   		mpf_mul(sFunction0,sFunction,aMinusr);
   		mpf_mul(TwoU,Two,u);
   		mpf_add(sFunction1,t,TwoU);
   		mpf_mul(sFunction2,sFunction1,v);
   		mpf_div(s,sFunction0,sFunction2);
    	mpf_mul(sSquare1,s,s);
   		mpf_mul(sCube1,sSquare1,s);
   		mpf_sub(rFunction,One,sCube1);
   		cube_root(r,rFunction);
    	mpf_add(EqualToStore,a,zero);
    }
    
	mpf_div(pi,One,a); // Getting Pi value by dividing when the iterations are completed
	
   	char *piFunction = (char *) malloc(1002*sizeof(char));     // Digits that should be printed in output
 	mp_exp_t powerFunction;		
 	mpf_get_str(piFunction, &powerFunction, 10, 1001, pi);
    cout << piFunction[0] << "." ;                             

    for ( int iterate = 0; iterate < PLACES; iterate++)			    // Iterate for 1000 values
    {	
    	if(iterate != 0)
    	{
			if(iterate % BLOCK_SIZE == 0)
	    		cout << " ";
	    		
	    	if(iterate % LINE_SIZE == 0)
            	cout << endl << "  ";
            	
			if(iterate % (GROUP_SIZE * LINE_SIZE) == 0)
            	cout << endl << "  ";
            	
        }
  
        cout << piFunction[iterate+1];
       
    }
	cout<<"\n";
	
}

void cube_root(mpf_t& x, const mpf_t a) // Finding Cube root of a given value 
{
	mpf_set_default_prec(BIT_COUNT*PRECISION);
	mpf_t xSquare, aDivxSquare, Out, Addition, Addition1,TwoVal,ThreeVal; // Declaring values for Arithmetic operations
	mpf_init (xSquare); // Initializing variables
	mpf_init (aDivxSquare); 
	mpf_init (Out); 
	mpf_init (Addition); 
	mpf_init (Addition1);
	mpf_init(TwoVal);
	mpf_set_d(TwoVal, 2); // Setting required values
	mpf_init(ThreeVal);
	mpf_set_d(ThreeVal, 3);
	mpf_init_set(x,a);
	for(int i=0;i<MAX_ITERATIONS;i++) // Iterating loop for MAX_ITERATIONS
	{
		mpf_mul(xSquare,x,x); // Performing Arithmetic operations
		mpf_div(aDivxSquare,a,xSquare);
		mpf_mul(Out,x,TwoVal);
		mpf_add(Addition,Out,aDivxSquare);
		mpf_div(Addition1,Addition,ThreeVal);
		
    	if(mpf_cmp(x,Addition1)==0) // Making function efficient by using mpf_cmp. Reducing loops by comparing with previous value
    	{
        	break;
    	}
    	
		mpf_init_set(x,Addition1);
    }
}
