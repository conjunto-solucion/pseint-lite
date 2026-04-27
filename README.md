# PSeInt Lite

Este es una copia de https://pseint.sourceforge.net/index.php?page=descargas_old.php (la versión 20210609 de PSeInt)

## Objetivos

Esta fork tiene dos objetivos:

1. Modificar el símbolo utilizado en los diagramas de flujo para representar la salida de datos, haciendo que coincida con la forma "Hoja de papel impresa", que en muchos estándares se asocia a "documento". También eliminar las flechitas indicadoras para "entrada" y "salida".

2. Descartar algunas características. Se mantiene como mínimo el editor e intérprete, así como el editor y exportador de diagramas de flujo.


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


## Directorios

Módulos principales:
  * pseint: fuentes del interprete
  * wxPSeInt: fuentes de la nueva interfaz (editor de pseudocódigo, e interfaz principal)
  * psterm: fuentes de la terminal que se utiliza para ejecutar desde wxPSeInt
  * psdraw3: fuentes del editor de diagramas de flujo. Es de especial interés el archivo DClasico.cpp para modificar cómo se dibuja el diagrama.

Módulos secundarios:
  * psdrawE: fuentes del exportador de diagramas de flujo (genera imagenes png/jpg/bmp)
  * psexport: fuentes del exportador (convierte de pseudocodigo a codigo C++)
  * pseval: fuentes de la interfaz que genera y evalúa los ejercicios autocontenidos

Otros directorios:
  * dtl: biblioteca auxiliar para comparar texto simil diff
  * hoewrap: biblioteca auxiliar (hoedown) para convertir markdown a html
  * test: pseudocódigos con casos de prueba y scripts para correrlos de forma automática
  * bin: demás archivos necesarios para ejecutar wxPSeInt (imagenes, documentacion, ayuda, etc).
  * dist: archivos adicionales para generar paquetes e instaladores
  * configs: configuraciones de los distintos toolchains para compilar con los Makefiles


Puede encontrar más información de la función de cada módulo y de cómo se comunican entre
ellos en http://cucarachasracing.blogspot.com.ar/2012/12/destripando-pseint.html

   
Además, hay un archivo Makefile.pack que sirve para generar los paquetes e instaladores
de todo el software desde GNU/Linux. Para generar el instalador para Windows requiere 
wine+mingw+wxwidgets+inno o nsis. Para las versiones para macOS se utilizó osxcross
para generar versiones de clang adecuadas.


Enlaces externos:
* wxWidgets: http://www.wxwidgets.org
* ZinjaI: http://zinjai.sourceforge.net
* Hoedown: https://github.com/hoedown/hoedown.git
* Diff Template Library (dtl): https://github.com/cubicdaiya/dtl.git
* wine: http://winehq.org
* NSIS: https://nsis.sourceforge.io/Main_Page
* Inno Setup: https://jrsoftware.org/isinfo.php
* osxcross: https://github.com/tpoechtrager/osxcross
* Inconsolata: https://levien.com/type/myfonts/inconsolata.html
* Actualizaciones: http://pseint.sourceforge.net