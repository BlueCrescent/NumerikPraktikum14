gnuplot << EOT

set title "estimation of example integral"
set xrange [1:11]
set yrange [8.5:8.9]
set xlabel "level"
set ylabel "relative error"
set grid

set term gif
set output "task10_convergence_plot.gif"

plot "data_callF_Trapezodial" using 1:2 with l title "Trapezodial", \
"data_callF_GaussLegendre" using 1:2 with l title "Gauss Legendre", \
"data_callF_Clenshaw" using 1:2 with l title "Clenshaw", \
"data_callF_MonteCarlo" using 1:2 with l title "Monte Carlo"

EOT
