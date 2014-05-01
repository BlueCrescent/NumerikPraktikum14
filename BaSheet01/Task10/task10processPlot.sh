#!/bin/sh

gnuplot << EOT
set title "SDE sample paths with mu = 0.1, sigma = 0.2, S(0) = 10"
set xlabel "time t"
set ylabel "S(t)"

plot "data10_sde_0.5_nr1"  using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.5_nr2"  using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.5_nr3"  using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.01_nr1" using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.01_nr2" using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.01_nr3" using 1:2 with lp pointtype 2 notitle

pause mouse

set term gif
set output "task10_process_plot.gif"

plot "data10_sde_0.5_nr1"  using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.5_nr2"  using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.5_nr3"  using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.01_nr1" using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.01_nr2" using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.01_nr3" using 1:2 with lp pointtype 2 notitle

set term postscript eps color blacktext "Helvetica" 14
set output 'task10_process_plot.eps'

plot "data10_sde_0.5_nr1"  using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.5_nr2"  using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.5_nr3"  using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.01_nr1" using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.01_nr2" using 1:2 with lp pointtype 2 notitle, \
     "data10_sde_0.01_nr3" using 1:2 with lp pointtype 2 notitle
EOT

gnuplot << EOT
set title "Wiener process sample paths"
set xlabel "time t"
set ylabel "W(t)"

plot "data10_wiener_0.5_nr1"  using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.5_nr2"  using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.5_nr3"  using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.01_nr1" using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.01_nr2" using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.01_nr3" using 1:2 with lp pointtype 2 notitle

pause mouse

set term gif
set output "task10_wiener_plot.gif"

plot "data10_wiener_0.5_nr1"  using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.5_nr2"  using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.5_nr3"  using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.01_nr1" using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.01_nr2" using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.01_nr3" using 1:2 with lp pointtype 2 notitle

set term postscript eps color blacktext "Helvetica" 14
set output 'task10_wiener_plot.eps'

plot "data10_wiener_0.5_nr1"  using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.5_nr2"  using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.5_nr3"  using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.01_nr1" using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.01_nr2" using 1:2 with lp pointtype 2 notitle, \
     "data10_wiener_0.01_nr3" using 1:2 with lp pointtype 2 notitle
EOT

