%% Comparación de métodos numéricos para resolver Ax = b
% Gauss con pivoteo parcial, LU e Inversa

clear; clc; close all;

% Tamaños de los sistemas
nValues = [3 10 30 100 200];

% Vectores para almacenar tiempos (en segundos)
tGauss   = zeros(size(nValues));
tLU      = zeros(size(nValues));
tInv     = zeros(size(nValues));

% (opcional) número de repeticiones para promediar tiempos
numRep = 5;

for k = 1:length(nValues)
    n = nValues(k);
    
    % Para que todos los métodos usen la misma matriz en cada repetición
    for r = 1:numRep
        A = rand(n);          % matriz aleatoria n x n
        b = rand(n,1);        % término independiente
        
        % --- Gauss con pivoteo parcial ---
        tic;
        xG = gaussParcial(A,b);
        tGauss(k) = tGauss(k) + toc;
        
        % --- LU ---
        tic;
        [L,U,P] = lu(A);          % descomposición LU con pivoteo
        y  = L\(P*b);
        xL = U\y;
        tLU(k) = tLU(k) + toc;
        
        % --- Inversa ---
        tic;
        xI = inv(A)*b;            % poco eficiente pero útil para comparar
        tInv(k) = tInv(k) + toc;
    end
    
    % Promedio de tiempos
    tGauss(k) = tGauss(k)/numRep;
    tLU(k)    = tLU(k)/numRep;
    tInv(k)   = tInv(k)/numRep;
end

%% Gráfica de eficiencia
figure;
plot(nValues, tGauss, '-o','LineWidth',1.2); hold on;
plot(nValues, tLU,    '-s','LineWidth',1.2);
plot(nValues, tInv,   '-^','LineWidth',1.2);
hold off;

title('Eficiencia de los métodos','FontSize',12);
xlabel('Número de variables','FontSize',11);
ylabel('t(s)','FontSize',11);
legend('Método de Gauss (pivoteo parcial)', ...
       'Método de descomposición LU', ...
       'Método de la inversa', ...
       'Location','northwest');
grid on;