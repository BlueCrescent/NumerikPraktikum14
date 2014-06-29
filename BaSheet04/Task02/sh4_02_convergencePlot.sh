#!/bin/sh

gnuplot << EOT
set grid

set logscale x

set xlabel "Number of Nodes (M = 128)"
set ylabel "relativ Error"

set title "convergence Plot: Barrier Down-Out Call options"
plot "data_s4_02" using 1:2 with lp title "BB - Monte Carlo", \
 "data_s4_02" using 1:3 with lp title "RW - Monte Carlo", \
 "data_s4_02" using 1:4 with lp title "BB - Quasi Monte Carlo", \
 "data_s4_02" using 1:5 with lp title "RW - Quasi Monte Carlo"

pause mouse

set term pdf

set output "sh4_task02_convergencePlot.pdf"
set title "convergence Plot: Barrier Down-Out Call options"
plot "data_s4_02" using 1:2 with lp title "BB - Monte Carlo", \
 "data_s4_02" using 1:3 with lp title "RW - Monte Carlo", \
 "data_s4_02" using 1:4 with lp title "BB - Quasi Monte Carlo", \
 "data_s4_02" using 1:5 with lp title "RW - Quasi Monte Carlo"

EOT
#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14