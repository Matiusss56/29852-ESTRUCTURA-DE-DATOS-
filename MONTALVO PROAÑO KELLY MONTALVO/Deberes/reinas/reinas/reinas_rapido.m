%% SCRIPT RÁPIDO - LAS 8 REINAS EN MATLAB
% Versión compacta y fácil de usar
% Ejecutar: >> reinas_rapido

clear all; close all; clc;

%% Búsqueda de soluciones
fprintf('\n╔═══════════════════════════════════════╗\n');
fprintf('║  LAS 8 REINAS - VISUALIZACIÓN RÁPIDA ║\n');
fprintf('╚═══════════════════════════════════════╝\n\n');

soluciones = [];
tablero = zeros(8, 8);
resolver(tablero, 1);

fprintf('✓ Soluciones encontradas: %d\n', size(soluciones, 3));

%% Seleccionar solución aleatoria
rng shuffle;
idx = randi(size(soluciones, 3));
tablero_final = soluciones(:, :, idx);

fprintf('✓ Solución seleccionada: #%d\n\n', idx);

%% Visualizar
figure('Name', sprintf('Solución #%d', idx), 'NumberTitle', 'off', 'Position', [200, 200, 600, 600]);
hold on; axis equal off;
xlim([-0.5, 8.5]); ylim([-0.5, 8.5]);

% Dibujar tablero
for i = 1:8
    for j = 1:8
        if mod(i+j, 2) == 0
            color = [0.95, 0.95, 0.85];
        else
            color = [0.2, 0.5, 0.1];
        end
        
        rectangle('Position', [j-1, 8-i, 1, 1], 'FaceColor', color, 'EdgeColor', 'k', 'LineWidth', 1.5);
        
        if tablero_final(i, j) == 1
            rectangle('Position', [j-0.4, 8-i+0.1, 0.8, 0.8], 'Curvature', [1,1], ...
                     'FaceColor', [1, 0.2, 0.2], 'EdgeColor', [0.8, 0, 0], 'LineWidth', 2);
            text(j-0.5, 8-i+0.5, '♛', 'FontSize', 40, 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle', 'Color', 'w');
        end
    end
end

% Etiquetas
for j = 1:8
    text(j-0.5, -0.2, char(96+j), 'FontSize', 12, 'HorizontalAlignment', 'center', 'FontWeight', 'bold');
end
for i = 1:8
    text(-0.2, 8-i+0.5, num2str(i), 'FontSize', 12, 'HorizontalAlignment', 'center', 'FontWeight', 'bold');
end

title(sprintf('Solución #%d de 92', idx), 'FontSize', 14, 'FontWeight', 'bold');
set(gca, 'Position', [0.1, 0.1, 0.8, 0.8]);

%% Guardar
saveas(gcf, sprintf('reinas_solucion_%d.png', idx));
fprintf('✓ Imagen guardada: reinas_solucion_%d.png\n\n', idx);

%% Función resolver
function resolver(tab, fila)
    global soluciones;
    if fila > 8
        soluciones(:, :, size(soluciones, 3) + 1) = tab;
        return;
    end
    
    for col = 1:8
        if valido(tab, fila, col, 8)
            tab(fila, col) = 1;
            resolver(tab, fila + 1);
            tab(fila, col) = 0;
        end
    end
end

%% Función validar
function res = valido(tab, fila, col, n)
    res = 1;
    for i = 1:fila-1
        if tab(i, col) == 1
            res = 0; return;
        end
    end
    
    i = fila - 1; j = col - 1;
    while i >= 1 && j >= 1
        if tab(i, j) == 1
            res = 0; return;
        end
        i = i - 1; j = j - 1;
    end
    
    i = fila - 1; j = col + 1;
    while i >= 1 && j <= n
        if tab(i, j) == 1
            res = 0; return;
        end
        i = i - 1; j = j + 1;
    end
end
