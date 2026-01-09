% ==============================
% LECTURA AUTOMATICA DE CSV
% ALGORITMO VORAZ - FUERZA BRUTA
% ==============================

% Leer el archivo CSV
datos = readtable('datos_graficos.csv');

% Extraer columnas
ejecucion  = datos.Ejecucion;
posicion   = datos.Posicion;
intentos   = datos.Intentos;
eficiencia = datos.Eficiencia;

% Verificacion
disp(datos);

% ------------------------------
% GRAFICA 1: INTENTOS vs EFICIENCIA
% ------------------------------
figure
plot(intentos, eficiencia, '-o', 'LineWidth', 2)
xlabel('Número de intentos')
ylabel('Eficiencia (%)')
title('Intentos vs Eficiencia del algoritmo voraz')
grid on

% ------------------------------
% GRAFICA 2: EJECUCION vs INTENTOS
% ------------------------------
figure
plot(ejecucion, intentos, '-s', 'LineWidth', 2)
xlabel('Número de ejecución')
ylabel('Intentos realizados')
title('Ejecuciones vs Intentos')
grid on

% ------------------------------
% GRAFICA 3: POSICION vs INTENTOS
% ------------------------------
figure
plot(posicion, intentos, '-^', 'LineWidth', 2)
xlabel('Posición en el diccionario')
ylabel('Intentos realizados')
title('Posición de la contraseña vs Intentos')
grid on
