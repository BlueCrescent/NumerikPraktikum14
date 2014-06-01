#!/bin/sh

gnuplot << EOT
set grid

set logscale y

set xlabel "l"
set ylabel "relativ Error"

set title "convergence plot for M = 64"
plot "data_s3_17" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"
pause mouse

set term pdf

set output "sh3_task17_convergencePlot.pdf"
set title "convergence plot for M = 64"
plot "data_s3_17" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"

EOT
#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
