gnuplot << EOT

set title "estimation of example integral"
set xrange [1:11]
set yrange [0:0.04]
set xlabel "level"
set ylabel "relative error"
set grid

set term gif
set output "task9_convergence_plot.gif"

plot "data_example_Trapezodial" using 1:2 with l title "Trapezodial", \
"data_example_GaussLegendre" using 1:2 with l title "Gauss Legendre", \
"data_example_Clenshaw" using 1:2 with l title "Clenshaw", \
"data_example_MonteCarlo" using 1:2 with l title "Monte Carlo"

EOT
