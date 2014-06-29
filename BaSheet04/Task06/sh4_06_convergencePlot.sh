#!/bin/sh

gnuplot << EOT
set grid

set logscale 

set xlabel "Number of Nodes"
set ylabel "relativ Error"

set title "Convergence Plot: Fixed strike lookback options with underlying Brownian bridge (M = 128)"
plot "data_s4_06" using 1:2 with lp title "Monte Carlo", \
 "data_s4_06" using 1:3 with lp title "Quasi Monte Carlo"

pause mouse

set term pdf

set output "sh4_task06_convergencePlot.pdf"
set title "Convergence Plot: Fixed strike lookback options with underlying Brownian bridge (M = 128)"
plot "data_s4_06" using 1:2 with lp title "Monte Carlo", \
 "data_s4_06" using 1:3 with lp title "Quasi Monte Carlo"

EOT

#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
