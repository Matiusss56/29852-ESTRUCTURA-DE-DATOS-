clc;
clear;
close all;

% Leer archivo CSV generado automáticamente por C++
datos = readtable('datos_energia.csv');

disp('Archivo leído correctamente');
disp(datos(1:5,:));

% Contar intentos totales
total_intentos = height(datos);

% Extraer intentos válidos
intentos_validos = datos.Valida == 1;

% Graficar
figure;
plot(1:total_intentos, intentos_validos, '.', 'MarkerSize', 8);
grid on;

xlabel('Intento');
ylabel('Solución válida (1 = Sí, 0 = No)');
title('Búsqueda exhaustiva de combinaciones de energía');
