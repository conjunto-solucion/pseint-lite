# PSeInt Lite

Este es una copia de https://pseint.sourceforge.net/index.php?page=descargas_old.php (la versión 20210609 de PSeInt, por Pablo Novara)


## Objetivos

Este fork tiene como objetivo modificar algunos aspectos visuales:

1. Modificar algunos símbolos utilizados en los diagramas de flujo.
  * Salida de datos: haciendo que coincida con la forma "Hoja de papel impresa".
  * Entrada de datos: paralelogramo, pero sin la flecha indicadora en la esquina superior derecha.
  * Bucle "Para": rombo, con línea doble en el lado superior izquierdo.
  * Selección múltiple: hexágono ancho.

2. Modificar colores de la interfaz gráfica.

3. Descartar algunas características menores que aparecen en la GUI.


## Cómo compilar

### **Compilar para Linux**

La build se genera dentro del directorio `/bin`. Este directorio también incluye ciertos archivos que no se generan al hacer build, por lo que no se recomienda borrar su contenido. Los submódulos ejecutables se generan dentro de `/bin/bin`.

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

Esto generará una build en `/bin` para plataformas Linux.


### **Compilar para Windows con Wine**

Si no lo tiene, instale wine:

```
sudo apt update
sudo apt install wine
```

Luego necesitará contar con dos instalaciones dentro del directorio `drive_c/` que se genera en `.wine/`.
Una es mingw32, y la otra es wxwidgets.

Primero, descarga e instala mingw32. Desconozco si funciona con mingw64 (el cual se encuentra más fácilemente), pero yo lo descargué desde:
https://sourceforge.net/projects/mingw/files/MinGW/Extension/make/mingw32-make-3.80-3/mingw32-make-3.80.0-3.exe/download

El ejecutable de mingw-make debe quedar en (dentro de wine): `drive_c/MinGW/bin/mingw32-make.exe`. Puede agregar esta dirección al PATH de wine si desea usarlo más fácilmente.

A continuación debe descargar wxwidgets 3.1. Puede descargar wxWidgets 3.1.4 desde:
https://github.com/wxWidgets/wxWidgets/releases?page=3

Luego, para compilarlo para Windows, use:

```cmd
wine cmd
cd ruta\a\wxWidgets-3.1\build\msw
mingw32-make -f makefile.gcc SHARED=1 UNICODE=1 BUILD=release clean
mingw32-make -f makefile.gcc SHARED=1 UNICODE=1 BUILD=release
```

Una vez que se ha compilado correctamente, debes mover la compilación a mingw. Para ello, crea un directorio `drive_c/MinGW/wx3`. Dentro de wx3, copia los directorios `include` y `lib` de wxwidgets. Debe quedar así:

```
C:\mingw\wx3\
 ├── include\
 └── lib\
      └── gcc_dll\
           └── mswu\
```

Una vez completada esta configuración previa, ya puedes compilar el proyecto:

```bash
export WINEPATH='C:\mingw\bin'
make ARCH=wine
```

Se generarán múltiples .exe dentro de `/bin`. El principal, que sirve para iniciar la aplicación es `bin/wxPSeInt.exe`.

A partir de aquí, tiene la opción de crear un instalador. Para ello, ejecute:
```
make -f Makefile.pack w32
```
Para que esto se ejecute correctamente, debe disponer de innosetup. Puede descargar innosetup desde https://jrsoftware.org/isinfo.php, instalarlo y ejecutarlo con wine. Debe estar instalado en `drive_c/Inno/`.

En el mismo directorio `/dist` se generará el instalador en formato .exe.

**Nota**: que no se produzca ningún error al ejecutar con Wine, no asegura que se ejecutará correctamente en Windows. Tenga cuidado al eliminar archivos o cambiar configuraciones.


## Directorios

Módulos principales:
  * pseint: fuentes del interprete
  * wxPSeInt: editor de pseudocódigo e interfaz principal
  * psterm: terminal que se utiliza para ejecutar desde wxPSeInt
  * psdraw3: editor de diagramas de flujo. Es de especial interés el archivo DClasico.cpp para modificar cómo se dibuja el diagrama.

Módulos secundarios:
  * psdrawE: exportador de diagramas de flujo (genera imagenes png/jpg/bmp)
  * psexport: convierte de pseudocodigo a codigo C++
  * pseval: genera y evalúa los ejercicios autocontenidos

Otros directorios:
  * bin: archivos necesarios para ejecutar wxPSeInt
  * dist: archivos adicionales para generar paquetes e instaladores
  * configs: configuraciones para compilar con los Makefiles

Bibliotecas auxiliares:
  * dtl: biblioteca auxiliar para comparar texto simil diff
  * hoewrap: biblioteca auxiliar (hoedown) para convertir markdown a html
