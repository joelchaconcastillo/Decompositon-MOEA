Entrada=ARG1; Salida=ARG2
set term post enh color eps
#set view 70,80
set output Salida
plot for[i=2:500] Entrada u 1:i w l title ""
