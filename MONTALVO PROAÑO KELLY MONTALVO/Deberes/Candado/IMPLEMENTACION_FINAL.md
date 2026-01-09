# PROGRAMA CANDADO VORAZ - DOCUMENTACIÓN FINAL

## Descripción General
Se implementó un programa en **C++ basado en un algoritmo voraz** que genera una contraseña volátil de 4 dígitos y utiliza un diccionario de permutaciones para encontrarla mediante búsqueda secuencial.

## Requisitos Cumplidos ✅

### 1. **Contraseña Volátil** 
- ✅ La contraseña se genera **aleatoriamente** cada vez que se ejecuta el programa
- ✅ NO es quemada (hardcodeada) en el código
- ✅ Se regenera en cada ejecución con una permutación diferente
- ✅ Ejemplo: Primera ejecución = "1234", Segunda = "2341", Tercera = "3124", etc.

### 2. **Algoritmo Voraz**
- ✅ Implementado con búsqueda secuencial (1 a N)
- ✅ Compara carácter por carácter desde el diccionario
- ✅ Método: Rastreo exhaustivo hasta encontrar coincidencia
- ✅ Registra número de intentos y tiempo transcurrido

### 3. **Diccionario de 4 Dígitos**
- ✅ Se generan automáticamente **24 permutaciones** (4! = 24)
- ✅ Base: "1234" con todas sus permutaciones
- ✅ Se crea al inicializar el programa (no se lee de archivo)
- ✅ Todas las combinaciones válidas se cargan en memoria

### 4. **Sin Vectores, Struct, Linked List NI Arreglos []**
- ✅ **NO usa vector<>** 
- ✅ **NO usa struct**
- ✅ **NO usa Nodo* (linked list)**
- ✅ **NO usa [] para acceso a arrays**
- ✅ Usa: Solo punteros (*) y aritmética de punteros
- ✅ Funciones puras sin clases
- ✅ Acceso mediante *(puntero + índice) en lugar de [índice]

### 5. **Login y Mensaje de Éxito**
- ✅ Login automático con usuario "admin"
- ✅ Mensaje: "CANDADO DESBLOQUEADO EXITOSAMENTE"
- ✅ Muestra estadísticas: intentos, tiempo, eficiencia

## Componentes Clave

### Función `crearDiccionario()`
```cpp
- Genera 24 permutaciones de "1234"
- Usa recursión con aritmética de punteros
- Almacena en: char** diccionarioCombinaciones
- Acceso mediante *(puntero + índice)
```

### Función `generarPasswordVolatil()`
```cpp
- Selecciona índice aleatorio del diccionario
- Copia la permutación a passwordVolatil (char*)
- Se ejecuta cada vez que el programa inicia
- Usa aritmética de punteros, NO []
```

### Función `buscarPasswordVoraz()`
```cpp
- Recorre diccionario secuencialmente (1 a 24)
- Compara cada combinación con passwordVolatil
- Retorna número de intentos cuando encuentra coincidencia
- Algoritmo voraz: primer match que encuentra es la solución
- Implementado con *(puntero + índice) para acceso
```

## Flujo del Programa

1. **Autenticación**: Login automático como "admin"
2. **Inicialización**:
   - Crear diccionario (24 permutaciones)
   - Generar contraseña volátil aleatoria
3. **Menú Principal**:
   - Opción 1: Regenerar contraseña volátil
   - Opción 2: Ejecutar ataque detallado (muestra cada 3 intentos)
   - Opción 3: Ejecutar ataque silencioso (sin detalles)
   - Opción 4: Ver estadísticas del sistema
   - Opción 5: Salir

## Variables Globales

```cpp
char** diccionarioCombinaciones;  // Puntero a punteros (combinaciones)
int totalCombinaciones;           // Siempre 24
char* passwordVolatil;            // Puntero a contraseña (4 dígitos)
```

## Ejecución

### Compilar:
```bash
g++ -o candado.exe candado.cpp
```

### Ejecutar:
```bash
candado.exe
```

## Características Especiales

- **Volatilidad Real**: Cada ejecución genera contraseña diferente
- **Diccionario Automático**: No depende de archivo externo
- **Algoritmo Voraz Puro**: Búsqueda secuencial simple y eficiente
- **Sin Dependencias**: Solo usa iostream y ctime
- **Memoria Limpia**: Libera recursos al salir
- **Interfaz Visual**: Menú y estadísticas claras

## Algoritmo Voraz Explicado

Un algoritmo voraz es aquel que toma decisiones locales óptimas en cada paso, esperando encontrar la solución global óptima. En este caso:

- **Decisión Local**: Comparar con la siguiente permutación
- **Criterio**: ¿Coincide? → Si sí, retorna. Si no, continúa.
- **Optimidad**: Garantiza encontrar la solución en máximo 24 intentos

## Conclusión

El programa implementa correctamente:
✅ Contraseña volátil (aleatoria cada ejecución)
✅ Algoritmo voraz (búsqueda secuencial)
✅ Diccionario de 4 dígitos (24 permutaciones)
✅ Sin vectores, struct ni linked lists
✅ Login automático y mensaje de éxito
✅ Interfaz amigable con estadísticas

---
**Última actualización**: 8 de enero de 2026
**Estado**: ✅ IMPLEMENTADO Y COMPILADO
