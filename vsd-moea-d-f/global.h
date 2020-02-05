#ifndef __GLOBAL_H_
#define __GLOBAL_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <memory.h>
#include <vector>
#include <cassert>
#include <algorithm>


using namespace std;

#include "random.h"


//------------- Parameters in test instance ------------------

int     nvar,  nobj;                    //  the number of variables and objectives
int param_k, param_l;

double  lowBound = 0,   uppBound = 1;   //  lower and upper bounds of variables
double  vlowBound[2000] ,   vuppBound[2000];   //  lower and upper bounds of variables

char    strTestInstance[256];
char    strpath[800];


//------------- Parameters in random number ------------------
int     seed    = 177;
long    rnd_uni_init;        


//------------- Parameters in MOEA/D -------------------------

vector <double> idealpoint;
double          scale[100];  


int		etax    = 20, 	etam    = 50;   // distribution indexes of crossover and mutation

double  realx,  realm,  realb = 0.9;    // crossover, mutation, selection probabilities

double Di, prob, Df; // distance available of the hypersphere...
int pops, niche;
long long max_nfes;

#endif
