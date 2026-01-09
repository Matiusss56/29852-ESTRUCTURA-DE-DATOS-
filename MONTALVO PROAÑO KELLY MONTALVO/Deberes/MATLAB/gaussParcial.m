function x = gaussParcial(A,b)
% Resuelve Ax = b usando eliminación de Gauss con pivoteo parcial
[n,~] = size(A);

% Construir matriz aumentada
Ab = [A b];

% Eliminación hacia adelante
for k = 1:n-1
    % Pivoteo parcial: buscar el mayor en la columna k desde la fila k
    [~, idx] = max(abs(Ab(k:n,k)));
    idx = idx + k - 1;
    
    % Intercambiar filas si es necesario
    if idx ~= k
        temp    = Ab(k,:);
        Ab(k,:) = Ab(idx,:);
        Ab(idx,:) = temp;
    end
    
    % Si el pivote es cero, el sistema es singular o casi singular
    if abs(Ab(k,k)) < eps
        error('Pivote cercano a cero. El sistema puede ser singular.');
    end
    
    % Eliminación
    for i = k+1:n
        m = Ab(i,k)/Ab(k,k);
        Ab(i,k:end) = Ab(i,k:end) - m*Ab(k,k:end);
    end
end

% Sustitución hacia atrás
x = zeros(n,1);
x(n) = Ab(n,end)/Ab(n,n);
for i = n-1:-1:1
    x(i) = (Ab(i,end) - Ab(i,i+1:n)*x(i+1:n)) / Ab(i,i);
end
end