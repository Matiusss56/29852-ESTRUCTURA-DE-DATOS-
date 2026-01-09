clc;
clear;
close all;

% Leer archivo generado por C++
datos = readtable('datos_suma.csv');

disp('Datos leídos correctamente');
disp(datos(1:5,:));

% Graficar
figure;
plot(datos.Iteracion, datos.SumaAcumulada, '-o', 'LineWidth', 2);
grid on;

xlabel('Iteración');
ylabel('Suma acumulada');
title('Crecimiento de la suma automática');
