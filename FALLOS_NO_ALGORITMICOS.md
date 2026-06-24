# Fallos no relacionados con algoritmos

Este documento recoge los fallos que no dependen de la lógica de ordenación interna.

## Estado actual

- El parsing y la validación de entrada ya pasan.
- Los tests básicos y los casos límite están verdes.
- Quedan solo tareas de limpieza de warnings o de estabilidad del reporte del tester.

## Tareas pendientes

- [ ] .

## Lo que ya está bien

- [x] El parsing acepta valores válidos, incluidos `INT_MIN` e `INT_MAX`.
- [x] El parsing rechaza correctamente números inválidos y duplicados.
- [x] Las entradas ya ordenadas no generan movimientos.
- [x] La salida del benchmark se escribe en `fd 2`.
- [x] La ruta sin flags ya quedó alineada con `--adaptive`.
- [x] El checker recibe parámetros y libera correctamente.
- [X] Confirmado que el reporte de `--bench` es estable en todas las combinaciones.
- [X] El checker pasa todos los tests del checker y la norminette (checkear en 42 por si acaso).
- [X] Tras los cambios al bench todo sigue funcionando sin problemas.
