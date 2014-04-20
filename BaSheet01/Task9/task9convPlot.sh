#!/bin/sh

gnuplot << EOT
set logscale

set title "estimation of sigma with mu = 2"
set xlabel "N"
set ylabel "estimation error"

f(x) = 1 / sqrt(x)

plot "data9_0.1" using 1:2 with l title "sigma = 0.1", \
"data9_1" using 1:2 with l title "sigma = 1.0", \
"data9_10" using 1:2 with l title "sigma = 10.0", \
f(x) title "N ^ (-1/2)"

pause mouse

set term gif
set output "task9_convergence_plot.gif"

plot "data9_0.1" using 1:2 with l title "sigma = 0.1", \
"data9_1" using 1:2 with l title "sigma = 1.0", \
"data9_10" using 1:2 with l title "sigma = 10.0", \
f(x) title "N ^ (-1/2)"

set term postscript eps color blacktext "Helvetica" 24
set output 'task9_convergence_plot.eps'

plot "data9_0.1" using 1:2 with l title "sigma = 0.1", \
"data9_1" using 1:2 with l title "sigma = 1.0", \
"data9_10" using 1:2 with l title "sigma = 10.0", \
f(x) title "N ^ (-1/2)"
EOT


# plot "data9" using 1:2 w lp
# set style line default

#"data9_10" using 1:2 smooth unique title "sigma = 10.0"
