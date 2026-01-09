clc;
clear;
close all;

% PASO 1: Leer el archivo CSV
datos = readtable('datos_graficos.csv');

disp('Archivo CSV leído correctamente');
disp(datos(1:5,:));   % muestra primeras filas

% PASO 2: Graficar
figure;
plot(datos.Ejecucion, datos.Intentos, '-o','LineWidth',2);
grid on;

xlabel('Número de ejecución');
ylabel('Número de intentos');
title('Intentos por ejecución - Problema de las 8 Reinas');
