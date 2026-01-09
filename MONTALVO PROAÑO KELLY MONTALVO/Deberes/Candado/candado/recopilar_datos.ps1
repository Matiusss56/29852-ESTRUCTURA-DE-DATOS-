# Script para recopilar datos de multiples ejecuciones
# Guardar en formato CSV para MATLAB

$resultados = @()

Write-Host "Ejecutando 10 veces el programa..."
Write-Host ""

for ($i = 1; $i -le 10; $i++) {
    # Ejecutar sin interfaz interactiva (silencioso)
    $output = .\candado.exe 3>&1 4>&1 | Out-String
    
    # Extraer posicion en diccionario
    $posicion = 0
    if ($output -match 'Posici[o]n en diccionario:\s+(\d+)\s+de') {
        $posicion = [int]$matches[1]
    }
    
    # Extraer intentos realizados
    $intentos = 0
    if ($output -match 'Intentos realizados:\s+(\d+)\s+de') {
        $intentos = [int]$matches[1]
    }
    
    # Extraer eficiencia
    $eficiencia = 0
    if ($output -match 'Eficiencia:\s+([\d.]+)%') {
        $eficiencia = [float]$matches[1]
    }
    
    # Agregar a resultados
    $resultados += New-Object PSObject -Property @{
        Ejecucion = $i
        Posicion = $posicion
        Intentos = $intentos
        Eficiencia = [math]::Round($eficiencia, 2)
    }
    
    Write-Host "[$i/10] Posicion: $posicion, Intentos: $intentos, Eficiencia: $($eficiencia)%"
}

# Guardar en CSV para MATLAB
$resultados | Select-Object Ejecucion, Posicion, Intentos, Eficiencia | Export-Csv -Path 'datos_graficos.csv' -NoTypeInformation -Encoding UTF8

Write-Host ""
Write-Host "============================================"
Write-Host "Datos guardados en: datos_graficos.csv"
Write-Host "============================================"
Write-Host ""
Write-Host "Contenido:"
Get-Content datos_graficos.csv

Write-Host ""
Write-Host "Resumen estadistico:"
Write-Host "Intentos promedio: $($resultados | Measure-Object -Property Intentos -Average | Select-Object -ExpandProperty Average)"
Write-Host "Intentos minimo: $($resultados | Measure-Object -Property Intentos -Minimum | Select-Object -ExpandProperty Minimum)"
Write-Host "Intentos maximo: $($resultados | Measure-Object -Property Intentos -Maximum | Select-Object -ExpandProperty Maximum)"
