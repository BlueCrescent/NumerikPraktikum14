#!/bin/sh

gnuplot << EOT
set logscale
set grid

set title "Relative error of discrete vs continuous geometric fair prices."
set xlabel "M"
set ylabel "relative error"

plot "data_s3_04" using 1:2 with lp title "rel error"

pause mouse

set term pdf
set output 'sh3_task4_convergence_plot.pdf'

plot "data_s3_04" using 1:2 with lp title "rel error"
EOT

