# PSeInt Lite

Este es una fork de https://github.com/miguelinux/pseint, que a su vez es una copia de https://pseint.sourceforge.net/index.php?page=descargas_old.php (la versión 20210609 de PSeInt)

## Objetivos

Esta fork tiene dos objetivos:

1. Modificar el símbolo utilizado en los diagramas de flujo para representar la salida de datos, haciendo que coincida con la forma "Hoja de papel impresa", que en muchos estándares se asocia a "documento".

2. Descartar dentro de lo posible, las características que no son necesarias (arbitrariamente). Se mantiene el editor e intérprete, así como el editor y exportador de diagramas de flujo.


## Cómo compilar

La build se genera dentro del directorio `/bin`. Este directorio también incluye ciertos archivos que no se generan al hacer build, por lo que no se recomienda borrar todo su contenido.

Primeramente es necesario instalar `wxwidgets 3.1`.
También es recomendable no tener múltiples versiones de `libpng` en el sistema, para evitar conflictos. Preferentemente tener sólo la versión 1.6 al momento de compilar wxwidgets.

Puede descargar wxWidgets 3.1.4 desde:
https://github.com/wxWidgets/wxWidgets/releases?page=3

Y compilar wxwidgets siguiendo las instrucciones descritas en el archivo `docs/gtk/install.md`. 

Resumen:
```bash
mkdir buildgtk
cd buildgtk
../configure --with-gtk
make
sudo make install
sudo ldconfig
```

Una vez hecho esto, dirigirse al directorio raíz de pseint-lite y ejecutar:
```bash
make ARCH=lnx
```

Esto generará una build en `/bin` para plataformas Linux. Por el momento no se han hecho las pruebas para compilar una versión para Windows, pero puedes intentarlo siguiendo las instrucciones oficiales descritas en `/fuentes.txt`


# Cómo desarrollar

Se recomienda el IDE ZinjaI, puesto que es el utilizado por los autores de PSeInt. No hay un proyecto general con todos los submódulos, sino que tendrá que trabajar en cada submódulo de manera separada, abriendo los archivos .zpr desde ZinjaI.

Puede descargar ZinjaI y el complemento wxWidgets 3.1.0 (archivo zcp) desde:
https://zinjai.sourceforge.net/index.php?page=descargas.php
