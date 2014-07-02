#!/bin/sh

gnuplot << EOT
set grid

set logscale
set key left bottom

set xlabel "Number of Nodes"
set ylabel "relativ Error"

set title "convergence plot for M = 64"
plot "data_s3_17" using 1:2 with lp title "RandWalk - Monte Carlo", \
 "data_s3_17" using 1:3 with lp title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17" using 1:4 with lp title "BrownBridge - Monte Carlo", \
 "data_s3_17" using 1:5 with lp title "BrownBridge - Quasi Monte Carlo"
pause mouse

set term pdf

set output "sh3_task17_convergencePlot.pdf"
set title "convergence plot for M = 64"
plot "data_s3_17" using 1:2 with lp title "RandWalk - Monte Carlo", \
 "data_s3_17" using 1:3 with lp title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17" using 1:4 with lp title "BrownBridge - Monte Carlo", \
 "data_s3_17" using 1:5 with lp title "BrownBridge - Quasi Monte Carlo"

EOT
#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
