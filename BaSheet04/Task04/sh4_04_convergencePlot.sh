#!/bin/sh

for Mval in 4 64 256 1024; do
gnuplot << EOT
set grid

set logscale 

set xlabel "Number of Nodes"
set ylabel "relativ Error"

set title "Convergence Plot: Barrier Down-Out Call options (M = $Mval)"
plot "data_s4_04_M=$Mval" using 1:2 with lp title "BB - Monte Carlo", \
 "data_s4_04_M=$Mval" using 1:3 with lp title "RW - Monte Carlo"

pause mouse

set term pdf

set output "sh4_task04_convergencePlot_M=$Mval.pdf"
set title "Convergence Plot: Barrier Down-Out Call options (M = $Mval)"
plot "data_s4_04_M=$Mval" using 1:2 with lp title "BB - Monte Carlo", \
 "data_s4_04_M=$Mval" using 1:3 with lp title "RW - Monte Carlo"

EOT
done

#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
