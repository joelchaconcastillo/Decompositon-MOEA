#for n in DTLZ1 DTLZ2 DTLZ3 DTLZ4 DTLZ5 DTLZ6 DTLZ7;
#do
#  for obj in 2 3
#   do
#     for i in 50 100 250 500;
#     do
#        ./euclidean \"\"../POS_middle/POS_MOEAD_"${n}"\*nobj_"${obj}"\*_nvar_"${i}"\"\" 11 100 "$i" > euclidean_dcn_${n}_${obj}_${i}_middle &
#     done
#   done
#   wait
#done
#
#for n in DTLZ1 DTLZ2 DTLZ3 DTLZ4 DTLZ5 DTLZ6 DTLZ7;
#do
#  for obj in 2 3
#   do
#     for i in 50 100 250 500;
#     do
#        ./euclidean \"\"../POS/POS_MOEAD_"${n}"\*nobj_"${obj}"\*_nvar_"${i}"\"\" 11 100 "$i" > euclidean_dcn_${n}_${obj}_${i}_long &
#     done
#   done
#   wait
#done
###########################33
#for n in DTLZ1 DTLZ2 DTLZ3 DTLZ4 DTLZ5 DTLZ6 DTLZ7;
#do
#  for obj in 2 3
#   do
#     for i in 50 100 250 500;
#     do
#        ./variance \"\"../POS_middle/POS_MOEAD_"${n}"\*nobj_"${obj}"\*_nvar_"${i}"\"\" 11 100 "$i" > variance_${n}_${obj}_${i}_middle &
#     done
#   done
#   wait
#done
#
#for n in DTLZ1 DTLZ2 DTLZ3 DTLZ4 DTLZ5 DTLZ6 DTLZ7;
#do
#  for obj in 2 3
#   do
#     for i in 50 100 250 500;
#     do
#        ./variance \"\"../POS/POS_MOEAD_"${n}"\*nobj_"${obj}"\*_nvar_"${i}"\"\" 11 100 "$i" > variance_${n}_${obj}_${i}_long &
#     done
#   done
#   wait
#done
######################################DCN variable
for n in DTLZ1 DTLZ2 DTLZ3 DTLZ4 DTLZ5 DTLZ6 DTLZ7;
do
  for obj in 2 3
   do
     for i in 50 100 250 500;
     do
        ./dcn_variable \"\"../POS_middle/POS_MOEAD_"${n}"\*nobj_"${obj}"\*_nvar_"${i}"\"\" 11 100 "$i" > dcn_${n}_${obj}_${i}_middle &
     done
   done
   wait
done

for n in DTLZ1 DTLZ2 DTLZ3 DTLZ4 DTLZ5 DTLZ6 DTLZ7;
do
  for obj in 2 3
   do
     for i in 50 100 250 500;
     do
        ./dcn_variable \"\"../POS/POS_MOEAD_"${n}"\*nobj_"${obj}"\*_nvar_"${i}"\"\" 11 100 "$i" > dcn_${n}_${obj}_${i}_long &
     done
   done
   wait
done
