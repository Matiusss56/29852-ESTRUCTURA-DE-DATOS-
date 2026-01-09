╔════════════════════════════════════════════════════════════════╗
║         PROGRAMA CANDADO INTELIGENTE - VERSIÓN INTERACTIVA     ║
║             Algoritmo de Fuerza Bruta con Listas Enlazadas      ║
╚════════════════════════════════════════════════════════════════╝

=== DESCRIPCIÓN DEL PROYECTO ===

Este es un programa en C++ que simula un ataque de fuerza bruta contra 
un candado digital con contraseña volátil. El programa es completamente 
interactivo con menú de opciones y está diseñado para Visual Studio.

=== ARCHIVOS INCLUIDOS ===

✓ candado.cpp              - Código fuente principal interactivo
✓ candado.exe              - Ejecutable compilado (listo para usar)
✓ demo_auto.cpp            - Versión de demostración automática
✓ diccionario.txt          - 147 palabras para el ataque
✓ INSTRUCCIONES.txt        - Guía completa de uso
✓ README.md                - Este archivo

=== CARACTERÍSTICAS IMPLEMENTADAS ===

✓ LOGIN AUTOMÁTICO
  └─ Usuario: admin (validación automática)
  └─ No requiere entrada manual

✓ CONTRASEÑA VOLÁTIL
  └─ Se genera aleatoriamente del diccionario
  └─ Diferente en cada ejecución
  └─ NO quemada en el código
  └─ Se mantiene oculta durante el ataque

✓ LISTAS ENLAZADAS (NO vectores ni arrays)
  └─ Estructura: struct Nodo con punteros
  └─ Gestión dinámica de memoria
  └─ Funciones para operaciones: crearNodo(), agregarAlFinal(), etc.

✓ DICCIONARIO INTELIGENTE
  └─ 147 palabras cargadas dinámicamente
  └─ Carga automática en lista enlazada
  └─ Búsqueda exhaustiva (fuerza bruta)

✓ MENÚ INTERACTIVO CON 5 OPCIONES
  1. Generar nueva contraseña volátil
  2. Ejecutar ataque (DETALLADO - muestra progreso)
  3. Ejecutar ataque (SILENCIOSO - sin progreso)
  4. Ver estadísticas del sistema
  5. Salir

✓ INTERFAZ COLORIDA Y AMIGABLE
  └─ Código de colores para diferentes secciones
  └─ Líneas separadoras para mejor legibilidad
  └─ Limpiar pantalla entre operaciones
  └─ Mensajes claros y organizados

✓ ESTADÍSTICAS Y RESULTADOS
  └─ Contraseña encontrada
  └─ Número de intentos realizados
  └─ Porcentaje de eficiencia
  └─ Tiempo de ejecución

=== CÓMO USAR ===

OPCIÓN 1: EJECUCIÓN INTERACTIVA (Recomendado)

1. Abre PowerShell
2. Navega a la carpeta del programa:
   cd "c:\Users\darla\OneDrive\Escritorio\Candado\candado"

3. Ejecuta el programa:
   .\candado.exe

4. Presiona ENTER en la pantalla de bienvenida

5. Selecciona una opción del menú (1-5):
   - Opción 2: Ejecutar ataque completo (RECOMENDADO PARA PRIMERA VEZ)
   - Opción 4: Ver estadísticas
   - Opción 5: Salir

6. Después de cada acción, presiona ENTER para continuar

OPCIÓN 2: DEMOSTRACIÓN AUTOMÁTICA

1. Ejecuta: .\demo.exe
2. El programa ejecuta automáticamente una demostración
3. Muestra cómo funciona sin intervención del usuario

=== FUNCIONES PRINCIPALES ===

ESTRUCTURA DE DATOS:
  • struct Nodo - Nodo para lista enlazada

FUNCIONES DE UTILIDAD:
  • setColor()        - Cambia color de consola
  • limpiarPantalla() - Borra pantalla
  • linea()          - Imprime línea separadora

OPERACIONES EN LISTA:
  • crearNodo()        - Crea un nuevo nodo
  • agregarAlFinal()   - Agrega elemento a la lista
  • contarElementos()  - Cuenta elementos de la lista
  • liberarLista()     - Libera memoria

FUNCIONES DE ATAQUE:
  • validarUsuario()          - Valida usuario (admin)
  • generarPasswordVolatil()  - Genera contraseña aleatoria
  • buscarEnLista()          - Ejecuta fuerza bruta
  • romperCandadoConLista()  - Ejecuta ataque completo

INTERFAZ:
  • mostrarMenuPrincipal() - Muestra menú
  • mostrarEstadisticas()  - Muestra estadísticas

=== TÉCNICAS UTILIZADAS ===

ALGORITMO:     Fuerza Bruta (Diccionario)
COMPLEJIDAD:   O(n) - donde n = cantidad de palabras
ESTRUCTURA:    Listas Enlazadas (Linked List)
MEMORIA:       Gestión Dinámica (new/delete)
LENGUAJE:      C++ estándar
LIBRERÍAS:     iostream, fstream, string, ctime, cstdlib, Windows.h

=== REQUISITOS ===

• Windows (para SetConsoleTextAttribute)
• PowerShell o CMD
• g++ o compilador compatible (para recompilar)

=== EJEMPLO DE EJECUCIÓN ===

usuario@PC $ .\candado.exe

============================================================
          SISTEMA DE ATAQUE - CANDADO INTELIGENTE
      Algoritmo de Fuerza Bruta con Listas Enlazadas
============================================================

[LOGIN EXITOSO]
  Usuario: admin
  Permisos: ADMINISTRADOR

[INICIALIZACION]
  Generando contraseña volátil...
  [+] Contraseña volátil generada exitosamente!
  Diccionario listo para usar...
  [+] Sistema listo para operaciones!

Presione ENTER para continuar...

============================================================
          SISTEMA DE ATAQUE - CANDADO INTELIGENTE
      Algoritmo de Fuerza Bruta con Listas Enlazadas
============================================================

[MENU PRINCIPAL]

  1. Generar nueva contraseña volátil
  2. Ejecutar ataque (DETALLADO)
  3. Ejecutar ataque (SILENCIOSO)
  4. Ver estadísticas del sistema
  5. Salir

Seleccione una opción (1-5): 2

============================================================
                 INICIANDO ATAQUE DE FUERZA BRUTA
============================================================

[PREPARACION]
  Cargando diccionario en lista enlazada...
  [+] Palabras cargadas: 147

[ATAQUE]
  Estado: FUERZA BRUTA
  Objetivo: [OCULTA - Contraseña Volátil]
  Modo: DETALLADO (cada 5 intentos)

  [Intento 5] Probando: letmein
  [Intento 10] Probando: monkey
  [Intento 15] Probando: basketball
  ... (continúa)

============================================================
       ¡¡ CANDADO ABIERTO EXITOSAMENTE !!
============================================================

[RESULTADOS]
  Contraseña encontrada: football
  Intentos realizados: 16 de 147
  Tiempo transcurrido: 0 segundo(s)
  Eficiencia: 10.8844%

============================================================

=== NOTAS IMPORTANTES ===

1. El programa siempre genera una contraseña NUEVA y ALEATORIA
   al iniciar. No está quemada en el código.

2. Usa LISTAS ENLAZADAS sin vectores ni arrays [], como fue solicitado.

3. La automatización es FUNDAMENTAL: el login es automático, la 
   contraseña se genera automáticamente, el diccionario se carga 
   automáticamente.

4. El menú interactivo permite control total del usuario sobre
   cuándo ejecutar ataques, generar nuevas contraseñas, etc.

5. Los colores funcionan en PowerShell de Windows (código Windows.h).

6. La memoria se libera automáticamente al salir.

=== COMPILACIÓN (si necesitas recompilar) ===

g++ -o candado.exe candado.cpp

=== CONTACTO Y AYUDA ===

Si tienes dudas sobre el funcionamiento, revisa:
- INSTRUCCIONES.txt (más detalles de uso)
- Código comentado en candado.cpp
- Ejecuta demo.exe para ver demostración automática

¡Disfruta el programa!
