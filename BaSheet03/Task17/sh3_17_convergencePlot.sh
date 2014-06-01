#!/bin/sh

gnuplot << EOT
set grid

set logscale y

set xlabel "l"
set ylabel "relativ Error"

set title "convergence plot for d = 1, M = 64"
plot "data_s3_17_d=1" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17_d=1" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17_d=1" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17_d=1" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"
pause mouse

set title "convergence plot for d = 2, M = 64"
plot "data_s3_17_d=2" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17_d=2" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17_d=2" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17_d=2" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"
pause mouse

set title "convergence plot for d = 4, M = 64"
plot "data_s3_17_d=4" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17_d=4" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17_d=4" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17_d=4" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"
pause mouse

set title "convergence plot for d = 8, M = 64"
plot "data_s3_17_d=8" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17_d=8" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17_d=8" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17_d=8" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"
pause mouse


set term pdf

set output "sh3_task17_convergencePlotd1.pdf"
set title "convergence plot for d = 1, M = 64"
plot "data_s3_17_d=1" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17_d=1" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17_d=1" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17_d=1" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"

set output "sh3_task17_convergencePlotd2.pdf"
set title "convergence plot for d = 2, M = 64"
plot "data_s3_17_d=2" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17_d=2" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17_d=2" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17_d=2" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"

set output "sh3_task17_convergencePlotd4.pdf"
set title "convergence plot for d = 4, M = 64"
plot "data_s3_17_d=4" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17_d=4" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17_d=4" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17_d=4" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"

set output "sh3_task17_convergencePlotd8.pdf"
set title "convergence plot for d = 8, M = 64"
plot "data_s3_17_d=8" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_17_d=8" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_17_d=8" using 1:4 with l title "BrownBridge - Monte Carlo", \
 "data_s3_17_d=8" using 1:5 with l title "BrownBridge - Quasi Monte Carlo"
pause mouse

EOT
#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
