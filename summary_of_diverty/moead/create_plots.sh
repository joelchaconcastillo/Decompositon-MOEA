for i in data/variance*;
do 
  In=${i}
  Out=eps/${i}.ps
  gnuplot -c 'generator.plot' $In $Out
done
for i in data/euclidean*;
do 
  In=${i}
  Out=eps/${i}.ps
  gnuplot -c 'generator.plot' $In $Out
done
for i in data/dcn*;
do 
  In=${i}
  Out=eps/${i}.ps
  gnuplot -c 'generator.plot' $In $Out
done
