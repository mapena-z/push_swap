el desorden sea una propiedad del stack, se calcula siempre al inicio

hacer que el bench se calcule siempre y solo imprimirlo cuando se necesite (menos complejidad)
que la flag --bench no diga si imprimimos o no

por defecto sin flags, se selecciona el modo adaptive

el programa tiene que aceptar varias flags, probar --bench --medium, --medium -complex, --bench --medium --complex, etc

arreglar el algoritmo insertion

los algoritmos pequeños solo deberian funcionar sin flags, al forzar un algoritmo, este lo calcula con su algoritmo propio
