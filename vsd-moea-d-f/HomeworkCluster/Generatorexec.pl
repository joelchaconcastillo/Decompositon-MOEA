#Con este script se genera la lista de ejecuciones....
#!/usr/bin/perl
use strict;
use warnings;
use Getopt::Long;
my $file = "Scalability2";
my $fout;
open($fout, '>' ,$file);
my $Path=  `cd ..; pwd`;
chomp $Path;
my $Sed=0;
my $NEjecutions=35;

my @problems = ("UF1", "UF2", "UF3", "UF4", "UF5", "UF6", "UF7", "DTLZ1", "DTLZ2", "DTLZ3", "DTLZ4", "DTLZ5", "DTLZ6", "DTLZ7");
my @NVariables = ("50", "100", "250", "500");
#my @Df = ("0.1", "0.2", "0.3", "0.4");
my @Df = ("0.1", "0.2");#, "0.5");
my $max_nfes = 25000000;
my $Di = 0.4;


foreach my $df(@Df) 
{
   @problems = ("UF1", "UF2", "UF3", "UF4", "UF5", "UF6", "UF7", "DTLZ1", "DTLZ2", "DTLZ3", "DTLZ4", "DTLZ5", "DTLZ6", "DTLZ7");
   foreach my $Instance(@problems) 
   {
   	foreach my $var(@NVariables) 
   	{
   	 for( my $Sed =1; $Sed <=35; $Sed++)
   	  {
         	   	print $fout "~$Path/Ejecutable $Path $Instance $Sed 2 100 $max_nfes $var $Di $df\n";
   	  }
   	}
   }
   @problems = ("UF8", "UF9", "UF10", "DTLZ1", "DTLZ2", "DTLZ3", "DTLZ4", "DTLZ5", "DTLZ6", "DTLZ7");
   foreach my $Instance(@problems) 
   {
   	foreach my $var(@NVariables) 
   	{
   	  for( my $Sed =1; $Sed <=35; $Sed++)
   	  {
         	     print $fout "~$Path/Ejecutable $Path $Instance $Sed 3 100 $max_nfes $var $Di $df\n";
   	  }
   	}
   }
   #@problems = ("WFG1");#, "WFG2","WFG3", "WFG4","WFG5", "WFG6","WFG7", "WFG8", "WFG9");
   @problems = ("WFG1", "WFG2","WFG3", "WFG4","WFG5", "WFG6","WFG7", "WFG8", "WFG9");
   for( my $obj =2; $obj <=3; $obj++)
   {
     foreach my $Instance(@problems) 
     {
     	foreach my $var(@NVariables) 
     	{
     	 for( my $Sed =1; $Sed <=35; $Sed++)
     	  {
                   my $k = int((4.0/24.0)*$var);
                   $k = $k-(($var-$k)%2);
                   my $l = $var-$k;
     		print $fout "~$Path/Ejecutable $Path $Instance $Sed $obj 100 $max_nfes $l $k $Di $df\n";
     	  }
     	}
     }
   }
}
