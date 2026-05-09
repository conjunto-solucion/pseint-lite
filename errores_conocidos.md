# Errores conocidos

## Diagrama de bucle for
El contexto de este error es dentro de `Entity::DrawText()`, del archivo `/psdraw3/Entity.cpp`
La representación en diagrama del bucle "para" asume indebidamente que los valores extremos (valor inicial, valor final)
son constantes inmediatas. Esto se realiza porque el diagrama espera calcular cuál debe ser el símbolo de comparación apropidado
a usar en la condición (i<10, i>10, etc.). Si resulta que uno de esos valores es variable o desconocido, no es posible determinar el
símbolo de comparación, de modo que el programa no puede dibujar el diagrama.

## Acentos y Ñ
En algunos casos se observa que las letras con acentos no se procesan correctamente en formato Unicode.
Se ha observado esto por lo menos en: los mensajes de información en el panel inferior del editor de código.
