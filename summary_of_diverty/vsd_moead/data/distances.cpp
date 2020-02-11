#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
int nvar, nss, npop;
using namespace std;
vector <string> ff;
vector<string> getfiles(char *pattern)
{
  //look for a list of files given a pattern...
  char tt[500];
  strcpy(tt, "/bin/ls ");
  strcat(tt, pattern);
  //cout << tt <<endl;
//  strcat(tt, "\"");
  FILE *proc = popen(tt,"r");
  char buf[1024];
   vector<string> files;
  while ( !feof(proc) && fgets(buf,sizeof(buf),proc) )

  {
    string line(buf);
    line.pop_back();
//    cout << line <<endl;
    files.push_back(line);
  }     
   return files;
}
double hypot(vector<double> &A, vector<double> &B)
{
   double dist = 0.0;
   for(int i = 0; i < A.size(); i++)// -- all
   {
	dist += (A[i]-B[i])*(A[i]-B[i]);
   }
   return sqrt(dist);
}
void mean_dcn()
{

  vector< vector<double> > dcn_run(ff.size(), vector<double> (nss, 0.0));
   for(int i = 0; i < ff.size(); i++)
  {
	FILE *summary = fopen(ff[i].c_str(), "r");
        for(int k = 0; k < nss; k++) //current population..
        {
	   vector< vector< double> > information( npop, vector< double> ( nvar, 0.0)  );
	if(summary==NULL)
	{
		cout <<"The file "<< ff[i].c_str()<<" cann't be opened.. "<<endl;
		exit(0);
	}
	  for(int l = 0; l < npop; l++)
	  {
	    for(int o = 0; o < nvar; o++)
	    {
		fscanf(summary, "%lf ",&information[l][o]);	
	//	if( o > 1)
	//	{
	//	   information[l][o] =  (information[l][o]+2.0)/4.0;
	//	}
			
	     //   information[l][o] /= (2.0*(o+1.0));
	    //    information[l][o] =  (information[l][o]-100.0)/200.0;// (2.0*(o+1.0));
	    }
	  }
	  double mean = 0.0;
	  for(int j = 0; j < npop; j++)
	  {
	     priority_queue<double> pq;
	     double mean1=0.0;
	     for(int q = 0; q < npop; q++)
	     {
		if(j == q) continue;
		//pq.push(-hypot(information[j], information[q]));
	        mean1 += hypot(information[j], information[q]);
	     }
	     mean += mean1/(npop-1);
	    // mean += -pq.top();
	  }
	  mean /=npop;
	 dcn_run[i][k] = mean;	
	}
	  fclose(summary);
  }
  vector<double> mean( nss, 0.0);
  for(int i = 0; i < dcn_run.size(); i++)
  {
     for(int j = 0 ;j < dcn_run[i].size(); j++)
	 mean[j] +=dcn_run[i][j];	
  }
 for(int i = 0; i < nss; i++)
  {
	printf("%d %lf\n",i+1, mean[i]/ff.size());
  }
}
void mean_variance()
{
  vector< vector< vector<double> > > variance_variable_run(ff.size(), vector< vector<double> > (nss,vector<double> (nvar ,0.0) ) );
   for(int i = 0; i < ff.size(); i++)
  {
	FILE *summary = fopen(ff[i].c_str(), "r");
        for(int k = 0; k < nss; k++) //current population..
        {
	   vector< vector< double> > information( npop, vector< double> ( nvar, 0.0)  );
	if(summary==NULL)
	{
		cout <<"The file "<< ff[i].c_str()<<" cann't be opened.. "<<endl;
		exit(0);
	}
	  for(int l = 0; l < npop; l++)
	  {
	    for(int o = 0; o < nvar; o++)
	    {
		fscanf(summary, "%lf ",&information[l][o]);	
	    }
	  }
         for(int nv = 0; nv < nvar; nv++) //get the variance in each variable..
         {
	    double variance = 0.0, E = 0.0;
	    for(int p = 0; p < npop; p++)
		     E += information[p][nv];
	    E /= npop;
	    for(int p = 0; p < npop; p++)
		    variance += (information[p][nv] - E)*(information[p][nv] - E);
	    variance /= npop;
	    variance_variable_run[i][k][nv] = variance;
	 }
	}
	  fclose(summary);
  }
  vector< vector< double > > mean_variance( nss, vector<double> ( nvar, 0.0 ));
  for(int i = 0; i < variance_variable_run.size(); i++)
  {
     for(int j = 0 ;j < variance_variable_run[i].size(); j++)
	     for(int k = 0; k < variance_variable_run[i][j].size(); k++)
	 mean_variance[j][k] +=variance_variable_run[i][j][k];	
  }
 for(int i = 0; i < nss; i++)
  {
     printf("%d ", i+1);
     for(int j = 0; j < nvar; j++)
	printf("%lf ", mean_variance[i][j]/ff.size());
     printf("\n");
  }
}
void mean_dcn_variable()
{
  vector< vector< vector<double> > > variance_variable_run(ff.size(), vector< vector<double> > (nss,vector<double> (nvar ,0.0) ) );
   for(int i = 0; i < ff.size(); i++)
  {
	FILE *summary = fopen(ff[i].c_str(), "r");
        for(int k = 0; k < nss; k++) //current population..
        {
	   vector< vector< double> > information( npop, vector< double> ( nvar, 0.0)  );
	if(summary==NULL)
	{
		cout <<"The file "<< ff[i].c_str()<<" cann't be opened.. "<<endl;
		exit(0);
	}
	  for(int l = 0; l < npop; l++)
	  {
	    for(int o = 0; o < nvar; o++)
	    {
		fscanf(summary, "%lf ",&information[l][o]);	
	    }
	  }
         for(int nv = 0; nv < nvar; nv++) //get the variance in each variable..
         {
           double mean = 0.0;
 	   for(int j = 0; j < npop; j++)
	   {
	        double minv = DBL_MAX;
	        for(int q = 0; q < npop; q++)
	        {
	   	if(j == q) continue;
		   minv = min(minv, fabs(information[j][nv] - information[q][nv]));
	        }
	        mean += minv;
	   }
	     mean /=npop;
	    variance_variable_run[i][k][nv] = mean;
	 }
	}
	  fclose(summary);
  }
  vector< vector< double > > mean_variance( nss, vector<double> ( nvar, 0.0 ));
  for(int i = 0; i < variance_variable_run.size(); i++)
  {
     for(int j = 0 ;j < variance_variable_run[i].size(); j++)
	     for(int k = 0; k < variance_variable_run[i][j].size(); k++)
	 mean_variance[j][k] +=variance_variable_run[i][j][k];	
  }
 for(int i = 0; i < nss; i++)
  {
     printf("%d ", i+1);
     for(int j = 0; j < nvar; j++)
	printf("%lf ", mean_variance[i][j]/ff.size());
     printf("\n");
  }
}
int main(int argc, char **argv)
{
  ff = getfiles(argv[1]);
  nss= atoi(argv[2]);
  npop = atoi(argv[3]);
  nvar = atoi(argv[4]);
// cout << nss << npop << nvar<<endl;
  //cout << ff.size() <<endl;
 // mean_dcn();
 //  mean_variance();
  mean_dcn_variable();
  
}
