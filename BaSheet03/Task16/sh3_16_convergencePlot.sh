#!/bin/sh

gnuplot << EOT
set grid

set logscale y

set xlabel "l"
set ylabel "relativ Error"

set title "convergence plot for d = 1"
plot "data_s3_16_d=1" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_16_d=1" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_16_d=1" using 1:4 with l title "RandWalk - Product - Trapez", \
 "data_s3_16_d=1" using 1:5 with l title "RandWalk - Product - Clensha Curtis", \
 "data_s3_16_d=1" using 1:6 with l title "RandWalk - Sparse Grid - Trapez", \
 "data_s3_16_d=1" using 1:7 with l title "RandWalk - Sparse Grid - Clensha Curtis", \
 "data_s3_16_d=1" using 1:8 with l title "BrownBridge - Monte Carlo", \
 "data_s3_16_d=1" using 1:9 with l title "BrownBridge - Quasi Monte Carlo", \
 "data_s3_16_d=1" using 1:10 with l title "BrownBridge - Product - Trapez", \
 "data_s3_16_d=1" using 1:11 with l title "BrownBridge - Product - Clensha Curtis", \
 "data_s3_16_d=1" using 1:12 with l title "BrownBridge - Sparse Grid - Trapez", \
 "data_s3_16_d=1" using 1:13 with l title "BrownBridge - Sparse Grid - Clensha Curtis"
pause mouse

set title "convergence plot for d = 2"
plot "data_s3_16_d=2" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_16_d=2" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_16_d=2" using 1:4 with l title "RandWalk - Product - Trapez", \
 "data_s3_16_d=2" using 1:5 with l title "RandWalk - Product - Clensha Curtis", \
 "data_s3_16_d=2" using 1:6 with l title "RandWalk - Sparse Grid - Trapez", \
 "data_s3_16_d=2" using 1:7 with l title "RandWalk - Sparse Grid - Clensha Curtis", \
 "data_s3_16_d=2" using 1:8 with l title "BrownBridge - Monte Carlo", \
 "data_s3_16_d=2" using 1:9 with l title "BrownBridge - Quasi Monte Carlo", \
 "data_s3_16_d=2" using 1:10 with l title "BrownBridge - Product - Trapez", \
 "data_s3_16_d=2" using 1:11 with l title "BrownBridge - Product - Clensha Curtis", \
 "data_s3_16_d=2" using 1:12 with l title "BrownBridge - Sparse Grid - Trapez", \
 "data_s3_16_d=2" using 1:13 with l title "BrownBridge - Sparse Grid - Clensha Curtis"
pause mouse

set title "convergence plot for d = 4"
plot "data_s3_16_d=4" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_16_d=4" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_16_d=4" using 1:4 with l title "RandWalk - Product - Trapez", \
 "data_s3_16_d=4" using 1:5 with l title "RandWalk - Product - Clensha Curtis", \
 "data_s3_16_d=4" using 1:6 with l title "RandWalk - Sparse Grid - Trapez", \
 "data_s3_16_d=4" using 1:7 with l title "RandWalk - Sparse Grid - Clensha Curtis", \
 "data_s3_16_d=4" using 1:8 with l title "BrownBridge - Monte Carlo", \
 "data_s3_16_d=4" using 1:9 with l title "BrownBridge - Quasi Monte Carlo", \
 "data_s3_16_d=4" using 1:10 with l title "BrownBridge - Product - Trapez", \
 "data_s3_16_d=4" using 1:11 with l title "BrownBridge - Product - Clensha Curtis", \
 "data_s3_16_d=4" using 1:12 with l title "BrownBridge - Sparse Grid - Trapez", \
 "data_s3_16_d=4" using 1:13 with l title "BrownBridge - Sparse Grid - Clensha Curtis"
pause mouse

set title "convergence plot for d = 8"
plot "data_s3_16_d=8" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_16_d=8" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_16_d=8" using 1:4 with l title "RandWalk - Product - Trapez", \
 "data_s3_16_d=8" using 1:5 with l title "RandWalk - Product - Clensha Curtis", \
 "data_s3_16_d=8" using 1:6 with l title "RandWalk - Sparse Grid - Trapez", \
 "data_s3_16_d=8" using 1:7 with l title "RandWalk - Sparse Grid - Clensha Curtis", \
 "data_s3_16_d=8" using 1:8 with l title "BrownBridge - Monte Carlo", \
 "data_s3_16_d=8" using 1:9 with l title "BrownBridge - Quasi Monte Carlo", \
 "data_s3_16_d=8" using 1:10 with l title "BrownBridge - Product - Trapez", \
 "data_s3_16_d=8" using 1:11 with l title "BrownBridge - Product - Clensha Curtis", \
 "data_s3_16_d=8" using 1:12 with l title "BrownBridge - Sparse Grid - Trapez", \
 "data_s3_16_d=8" using 1:13 with l title "BrownBridge - Sparse Grid - Clensha Curtis"
pause mouse


set term pdf

set output "sh3_task16_convergencePlotd1.pdf"
set title "convergence plot for d = 1"
plot "data_s3_16_d=1" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_16_d=1" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_16_d=1" using 1:4 with l title "RandWalk - Product - Trapez", \
 "data_s3_16_d=1" using 1:5 with l title "RandWalk - Product - Clensha Curtis", \
 "data_s3_16_d=1" using 1:6 with l title "RandWalk - Sparse Grid - Trapez", \
 "data_s3_16_d=1" using 1:7 with l title "RandWalk - Sparse Grid - Clensha Curtis", \
 "data_s3_16_d=1" using 1:8 with l title "BrownBridge - Monte Carlo", \
 "data_s3_16_d=1" using 1:9 with l title "BrownBridge - Quasi Monte Carlo", \
 "data_s3_16_d=1" using 1:10 with l title "BrownBridge - Product - Trapez", \
 "data_s3_16_d=1" using 1:11 with l title "BrownBridge - Product - Clensha Curtis", \
 "data_s3_16_d=1" using 1:12 with l title "BrownBridge - Sparse Grid - Trapez", \
 "data_s3_16_d=1" using 1:13 with l title "BrownBridge - Sparse Grid - Clensha Curtis"

set output "sh3_task16_convergencePlotd2.pdf"
set title "convergence plot for d = 2"
plot "data_s3_16_d=2" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_16_d=2" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_16_d=2" using 1:4 with l title "RandWalk - Product - Trapez", \
 "data_s3_16_d=2" using 1:5 with l title "RandWalk - Product - Clensha Curtis", \
 "data_s3_16_d=2" using 1:6 with l title "RandWalk - Sparse Grid - Trapez", \
 "data_s3_16_d=2" using 1:7 with l title "RandWalk - Sparse Grid - Clensha Curtis", \
 "data_s3_16_d=2" using 1:8 with l title "BrownBridge - Monte Carlo", \
 "data_s3_16_d=2" using 1:9 with l title "BrownBridge - Quasi Monte Carlo", \
 "data_s3_16_d=2" using 1:10 with l title "BrownBridge - Product - Trapez", \
 "data_s3_16_d=2" using 1:11 with l title "BrownBridge - Product - Clensha Curtis", \
 "data_s3_16_d=2" using 1:12 with l title "BrownBridge - Sparse Grid - Trapez", \
 "data_s3_16_d=2" using 1:13 with l title "BrownBridge - Sparse Grid - Clensha Curtis"

set output "sh3_task16_convergencePlotd4.pdf"
set title "convergence plot for d = 4"
plot "data_s3_16_d=4" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_16_d=4" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_16_d=4" using 1:4 with l title "RandWalk - Product - Trapez", \
 "data_s3_16_d=4" using 1:5 with l title "RandWalk - Product - Clensha Curtis", \
 "data_s3_16_d=4" using 1:6 with l title "RandWalk - Sparse Grid - Trapez", \
 "data_s3_16_d=4" using 1:7 with l title "RandWalk - Sparse Grid - Clensha Curtis", \
 "data_s3_16_d=4" using 1:8 with l title "BrownBridge - Monte Carlo", \
 "data_s3_16_d=4" using 1:9 with l title "BrownBridge - Quasi Monte Carlo", \
 "data_s3_16_d=4" using 1:10 with l title "BrownBridge - Product - Trapez", \
 "data_s3_16_d=4" using 1:11 with l title "BrownBridge - Product - Clensha Curtis", \
 "data_s3_16_d=4" using 1:12 with l title "BrownBridge - Sparse Grid - Trapez", \
 "data_s3_16_d=4" using 1:13 with l title "BrownBridge - Sparse Grid - Clensha Curtis"

set output "sh3_task16_convergencePlotd8.pdf"
set title "convergence plot for d = 8"
plot "data_s3_16_d=8" using 1:2 with l title "RandWalk - Monte Carlo", \
 "data_s3_16_d=8" using 1:3 with l title "RandWalk - Quasi Monte Carlo", \
 "data_s3_16_d=8" using 1:4 with l title "RandWalk - Product - Trapez", \
 "data_s3_16_d=8" using 1:5 with l title "RandWalk - Product - Clensha Curtis", \
 "data_s3_16_d=8" using 1:6 with l title "RandWalk - Sparse Grid - Trapez", \
 "data_s3_16_d=8" using 1:7 with l title "RandWalk - Sparse Grid - Clensha Curtis", \
 "data_s3_16_d=8" using 1:8 with l title "BrownBridge - Monte Carlo", \
 "data_s3_16_d=8" using 1:9 with l title "BrownBridge - Quasi Monte Carlo", \
 "data_s3_16_d=8" using 1:10 with l title "BrownBridge - Product - Trapez", \
 "data_s3_16_d=8" using 1:11 with l title "BrownBridge - Product - Clensha Curtis", \
 "data_s3_16_d=8" using 1:12 with l title "BrownBridge - Sparse Grid - Trapez", \
 "data_s3_16_d=8" using 1:13 with l title "BrownBridge - Sparse Grid - Clensha Curtis"
pause mouse

EOT
#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
