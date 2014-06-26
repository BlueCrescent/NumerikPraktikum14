#!/bin/sh

mkdir -p Output/Data_s03
cd Output/Data_s03

../../Release/NumerikPraktikum14


sh ../../BaSheet03/Task03/sh3_03_convergence_plot.sh
mv sh3_task3_convergence_plot.pdf ../sh3_task3_convergence_plot.pdf

sh ../../BaSheet03/Task04/sh3_04_convergence_plot.sh
mv sh3_task4_convergence_plot.pdf ../sh3_task4_convergence_plot.pdf

sh ../../BaSheet03/Task07/sh3_07_point_plot.sh
mv sh3_task7_point_plot.pdf ../sh3_task7_point_plot.pdf

sh ../../BaSheet03/Task09/sh3_09_point_plot.sh
mv sh3_task9_point_plot_clenshawCurtis.pdf ../sh3_task9_point_plot_clenshawCurtis.pdf
mv sh3_task9_point_plot_gaussLegendre.pdf ../sh3_task9_point_plot_gaussLegendre.pdf
mv sh3_task9_point_plot_trapezoidal.pdf ../sh3_task9_point_plot_trapezoidal.pdf

sh ../../BaSheet03/Task11/sh3_11_point_plot.sh
mv sh3_task11_point_plot_clenshawCurtis_l=5.pdf ../sh3_task11_point_plot_clenshawCurtis_l=5.pdf
mv sh3_task11_point_plot_clenshawCurtis_l=7.pdf ../sh3_task11_point_plot_clenshawCurtis_l=7.pdf
mv sh3_task11_point_plot_trapezoidal_l=5.pdf ../sh3_task11_point_plot_trapezoidal_l=5.pdf
mv sh3_task11_point_plot_trapezoidal_l=7.pdf ../sh3_task11_point_plot_trapezoidal_l=7.pdf

sh ../../BaSheet03/Task12/sh3_12_num_of_points.sh
mv sh3_task12_num_of_nodes.pdf ../sh3_task12_num_of_nodes.pdf

sh ../../BaSheet03/Task13/sh3_13_convergencePlot.sh
mv sh3_task13_convergencePlotd1.pdf ../sh3_task13_convergencePlotd1.pdf
mv sh3_task13_convergencePlotd2.pdf ../sh3_task13_convergencePlotd2.pdf
mv sh3_task13_convergencePlotd4.pdf ../sh3_task13_convergencePlotd4.pdf
mv sh3_task13_convergencePlotd8.pdf ../sh3_task13_convergencePlotd8.pdf

sh ../../BaSheet03/Task16/sh3_16_convergencePlot.sh
mv sh3_task16_convergence_plot_rw.pdf ../sh3_task16_convergence_plot_rw.pdf
mv sh3_task16_convergence_plot_bb.pdf ../sh3_task16_convergence_plot_bb.pdf

sh ../../BaSheet03/Task17/sh3_17_convergencePlot.sh
mv sh3_task17_convergencePlot.pdf ../sh3_task17_convergencePlot.pdf


