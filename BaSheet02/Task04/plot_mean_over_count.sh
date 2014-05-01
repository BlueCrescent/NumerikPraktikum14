#!/bin/sh

gnuplot << EOT
set logscale

set title "estimation of mean of call-option prices with different simulation counts"
set xlabel "N = #path in simulation"
set ylabel "mean call-option prices"


plot "data_sh2_4_run1" using 1:2 pt 2 ps 2 title "run 1", \
"data_sh2_4_run2" using 1:2 pt 2 ps 2 title "run 2", \
"data_sh2_4_run3" using 1:2 pt 2 ps 2 title "run 3", \
"data_sh2_4_run4" using 1:2 pt 2 ps 2 title "run 4", \
"data_sh2_4_run5" using 1:2 pt 2 ps 2 title "run 5"


pause mouse

set term gif
set output "sh2_task4_plot.gif"

plot "data_sh2_4_run1" using 1:2 pt 2 ps 2 title "run 1", \
"data_sh2_4_run2" using 1:2 pt 2 ps 2 title "run 2", \
"data_sh2_4_run3" using 1:2 pt 2 ps 2 title "run 3", \
"data_sh2_4_run4" using 1:2 pt 2 ps 2 title "run 4", \
"data_sh2_4_run5" using 1:2 pt 2 ps 2 title "run 5"

set term postscript eps color blacktext "Helvetica" 14
set output 'sh2_task4_plot.eps'

plot "data_sh2_4_run1" using 1:2 pt 2 ps 2 title "run 1", \
"data_sh2_4_run2" using 1:2 pt 2 ps 2 title "run 2", \
"data_sh2_4_run3" using 1:2 pt 2 ps 2 title "run 3", \
"data_sh2_4_run4" using 1:2 pt 2 ps 2 title "run 4", \
"data_sh2_4_run5" using 1:2 pt 2 ps 2 title "run 5"

EOT
