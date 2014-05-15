#!/bin/sh

gnuplot << EOT
set grid

set title "Halton vs. Uniform: Ultimate fight!! And battle!! Rock'n'Roll!!"
set xlabel "x"
set ylabel "y"

plot "data_s3_07_halton" using 1:2 with p title "Halton sequence", \
"data_s3_07_uniform" using 1:2 with p title "uniform random"

pause mouse

set term gif
set output "sh3_task7_point_plot.gif"

plot "data_s3_07_halton" using 1:2 with p title "Halton sequence", \
"data_s3_07_uniform" using 1:2 with p title "uniform random"

set term postscript eps color blacktext "Helvetica" 14
set output 'sh3_task7_point_plot.eps'

plot "data_s3_07_halton" using 1:2 with p title "Halton sequence", \
"data_s3_07_uniform" using 1:2 with p title "uniform random"
EOT

