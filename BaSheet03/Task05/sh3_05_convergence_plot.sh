#!/bin/sh

gnuplot << EOT
set grid

set title "Integrand of discrete arithmetic average"
set xlabel "s"
set ylabel "arithmetic payoff"

plot "data_s3_05" using 1:2 with l title "integrand"

pause mouse

set term gif
set output "sh3_task5_arithmetic_payoff.gif"

plot "data_s3_05" using 1:2 with l title "integrand"

set term postscript eps color blacktext "Helvetica" 14
set output 'sh3_task5_arithmetic_payoff.eps'

plot "data_s3_05" using 1:2 with l title "integrand"
EOT

