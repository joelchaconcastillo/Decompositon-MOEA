#ifndef __COMMON_H_
#define __COMMON_H_

#include "global.h"

void minfastsort(vector<double> &x, vector<int> &idx, int n, int m)
{
    for(int i=0; i<m; i++)
	{
	    for(int j=i+1; j<n; j++)
			if(x[i]>x[j])
			{
			    double temp = x[i];
				x[i]        = x[j];
				x[j]        = temp;
				int id      = idx[i];
				idx[i]      = idx[j];
				idx[j]      = id;
			}
	}
}


double dist_vector(vector <double> &vec1, vector <double> &vec2)
{
	int dim = vec1.size();
    double sum = 0;
	for(int n=0; n<dim; n++)
	    sum+=(vec1[n] - vec2[n])*(vec1[n] - vec2[n]);
	return sqrt(sum);
}

bool   dominate(vector<double> &u, vector<double> &v, double epsilon)
{
    int dim = u.size();
	for(int i=0; i<dim; i++)
	{
	    if(u[i]<v[i]-epsilon)
		{
		    return false;
		}
	}
	return true;
}

double fitnessfunction(vector <double> &y_obj, vector <double> &namda)
{


//modified tchebycheff..
//
//  double t, s, vmax;
//	  int i, j;
//
//		  vmax = 0;
//			  s = 0;
//
//	for(j = 0; j <nobj; j++)
//					double x = fabs(y_obj[i]-idealpoint[i]);
//       s += x;
//  }
//	for(i = 0; i <nobj; i++) 
//	   {
//			double x = fabs(y_obj[i]-idealpoint[i]);
//		   t = namda[i] * (x + 0.01 * s);
//			  if(t > vmax)
//			    vmax = t;
//			}
//
//		return vmax;

//augmented tchebycheff
///
///  double t, s, vmax;
///	  int i;
///
///		  s = vmax = 0;
///
///			  for(i = 0; i < nobj; i++) {
///					double x = fabs(y_obj[i]-idealpoint[i]);
///				    t = namda[i] * x;  
///					  s += x; 
///								 
///						if(t > vmax)
///			       vmax = t;
///				   }
///
///	   return vmax;// + 0.005 * s;



//  double fmax = -INFINITY, s=0.0;
//   
//  for(int i = 0; i < nobj; i++)
//  {
//    double diff = fabs(y_obj[i]-idealpoint[i] );
//    //double w = max(0.0001, namda[i]);
//    double w = (namda[i]) ? namda[i]: 1e-10;
//    double t = diff/w;
//		s += diff;
//	if(t > fmax) fmax = t;
//  }
//   return fmax + 0.0001*s;

//   double norm = 0, d1 = 0, d2 = 0;
//  int i;
//
//  // Normalize the namdaeight vector (line segment)
//  for(i = 0; i < nobj; i++)
//  {
//    norm  += namda[i] * namda[i]; 
//    d1 += (( y_obj[i]-idealpoint[i])* namda[i] );
//  }
//  norm = sqrt(norm);
//  d1 = fabs(d1)/norm;
// 
//  //d1 = fabs(d1);
//  for(i = 0; i < nobj; i++)
//    d2  += pow( (y_obj[i] -  idealpoint[i] ) - d1  *(namda[i]/norm), 2.0); 
//    d2 = sqrt(d2);
//////cout << d1 + 5.0 * d2; getchar(); 
//  return (d1 + 5.0 * d2); 

//////////////////////////////
    // Chebycheff Scalarizing Function
	double max_fun = -1.0e+30;

	for(int n=0; n<nobj; n++)
	{
		//double diff = fabs(y_obj[n] - idealpoint[n] + 0.1);
		double diff = fabs(y_obj[n] - idealpoint[n]);
		double feval;
		if(namda[n]==0) 
			//feval = 0.0001*diff;
			feval = diff/0.0001;
			//feval = 1e-80*diff;
		else
			//feval = diff*namda[n];
			feval = diff/namda[n];
		if(feval>max_fun) max_fun = feval;
	}
	return max_fun;
}

void load_data(char filename[1024], vector< vector<double> > &data, int dim)
{
	std::ifstream readf(filename);
	vector<double> vect = vector<double>(dim, 0);
	while(!readf.eof())
	{
        for(int i=0; i<dim; i++)
		{
			readf>>vect[i];
			//printf(" %f ", vect[i]);
		}
		data.push_back(vect);
		//vect.clear();    // bug here. 
	}

	readf.close();    
}


#endif
