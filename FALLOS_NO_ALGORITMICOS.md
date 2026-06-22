# Fallos no relacionados con algoritmos

Este documento recoge los fallos que no dependen de la lógica de ordenación interna.

## Resumen del tester

- El parsing de entrada ya pasa las pruebas de formato, duplicados y rangos.
- Las entradas ya ordenadas devuelven 0 operaciones.
- El modo `--bench` sigue apareciendo como incompleto en algunas ejecuciones, aunque la salida ya va por `fd 2`.
- En varias combinaciones de `--bench` el tester no consigue leer bien la estrategia o el porcentaje de desorden.

## Fallos detectados

- [ ] El reporte de `--bench` no se interpreta de forma consistente en el tester.
- [ ] En algunas ejecuciones de `--bench --simple`, `--bench --medium` y `--bench --complex` la estrategia aparece como ausente.
- [ ] El porcentaje de desorden reportado por benchmark no siempre se lee correctamente desde el tester.
- [ ] La salida del benchmark debe mantenerse estrictamente en `fd 2` y seguir el formato esperado por el tester.

## Lo que ya está bien

- [x] El parsing acepta valores válidos, incluidos `INT_MIN` e `INT_MAX`.
- [x] El parsing rechaza correctamente números inválidos y duplicados.
- [x] Las entradas ya ordenadas no generan movimientos.
- [x] La salida del benchmark ya se escribe en `fd 2`.
- [x] El benchmark ya diferencia la estrategia adaptativa interna cuando puede leerla.
- [x] La ruta sin flags ya quedó alineada con `--adaptive`.

## Hipótesis

- El problema ya no parece ser de parsing.
- El punto débil está en el reporte de benchmark y en cómo el tester interpreta esa salida.
- Puede haber un desajuste entre el formato exacto que imprime el programa y el patrón que espera el tester.

## Roadmap de corrección

### Fase 1: Verificar formato exacto

- [ ] Revisar el texto exacto que espera el tester para `--bench`.
- [ ] Comparar la salida real del programa con ese formato.
- [ ] Asegurar que `disorder` y `strategy` siempre salen en la misma estructura.

### Fase 2: Confirmar todos los modos de benchmark

- [ ] Probar `--bench --simple`.
- [ ] Probar `--bench --medium`.
- [ ] Probar `--bench --complex`.
- [ ] Probar `--bench --adaptive`.
- [ ] Verificar que el tester reconoce estrategia y desorden en todos ellos.

### Fase 3: Validación final

- [ ] Repetir el tester completo.
- [ ] Confirmar que benchmark deja de salir como aviso o incompleto.
- [ ] Mantener el resto del comportamiento sin cambios.
