# Problemas conocidos

## Diagrama de bucle for
Es posible transformar un bucle PARA de pseudocódigo a diagrama, pero
actualmente no es posible hacer el proceso inverso de manera correcta.
Al crear un bucle PARA desde el editor de diagramas de flujo, el programa no permite
editar el valor inicial, el valor final y el paso, tan solo el nombre del la variable
iteradora. El resto, necesariamente debe editarse desde el pseudocódigo.


## Acentos y Ñ
En algunos casos se observa que las letras con acentos no se procesan correctamente en formato Unicode.
Se ha observado esto por lo menos en: los mensajes de información en el panel inferior del editor de código.


## Automatización en los Makefiles
Hay ciertas tareas que se deberían incorporar en el Makefile:
* Cuando se está compilando para ARCH=lnx, se debería crear el directorio bin/bin automáticamente si no existiese
* Cuando se usa el Makefile.pack con la opción w32, se debería eliminar los archivos pseint y wxPSeInt propios de Linux, o en su defecto, no copiarlos, para evitar que terminen en el instalador generado.
* Cuando se usa el Makefile.pack con la opción w32, se debería realizar la compilación con ARCH=wine de manera automática antes de copiar los archivos, para evitar generar accidentalmente el instalador con una versión desactualizada.