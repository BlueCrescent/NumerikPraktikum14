#!/bin/sh

gnuplot << EOT
set logscale
set grid

set title "Relative error of discrete vs continuous geometric fair prices."
set xlabel "M"
set ylabel "relative error"

plot "data_s3_04" using 1:2 with lp title "rel error"

pause mouse

set term gif
set output "sh3_task4_convergence_plot.gif"

plot "data_s3_04" using 1:2 with lp title "M = 10"

set term postscript eps color blacktext "Helvetica" 14
set output 'sh3_task4_convergence_plot.eps'

plot "data_s3_04" using 1:2 with lp title "M = 10"
EOT

