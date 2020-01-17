for i in variance*;
do 
  In=${i}
  Out=${i}.ps
  gnuplot -c 'generator.plot' $In $Out
done
for i in euclidean*;
do 
  In=${i}
  Out=${i}.ps
  gnuplot -c 'generator.plot' $In $Out
done
for i in dcn*;
do 
  In=${i}
  Out=${i}.ps
  gnuplot -c 'generator.plot' $In $Out
done
