#include <iostream>
#include "LangSettings.h"
#include <algorithm>
using namespace std;

LangSettings::aux_struct LangSettings::data[LS_COUNT];
bool LangSettings::init_done=false;

void LangSettings::init() {
	
	data[LS_FORCE_DEFINE_VARS		 ].Set("force_define_vars",			false,	
		"Obligar a definir los tipos de variables",
			"Si esta opci�n est� deshabilitada no se puede utilizar una variable sin previamente definir su tipo. "
			"Para esto se debe utilizar la palabra clave DEFINIR. Ej: \"DEFINIR X COMO REAL\". Los tipos posibles "
			"son ENTERO, NUMERICO/REAL, LOGICO, CARACTER/TEXTO."
		);
	data[LS_FORCE_INIT_VARS			 ].Set("force_init_vars",			false,
		"No permitir utilizar variables o posiciones de arreglos sin inicializar",
			"Si esta opci�n est� deshabilitada se puede utilizar variables sin incializar (que nunca fueron leidas o asignadas) "
			"en expresiones o para mostrar en pantalla. En este caso asumen el valor por defecto 0, \"\", o FALSO segun el tipo "
			"que corresponda. Si esta opci�n est� seleccionada escribir o evaluar una expresi�n que involucra una variable sin "
			"inicializar genera un error en tiempo de ejecuci�n."
		);
	data[LS_FORCE_SEMICOLON			 ].Set("force_semicolon",			false,
		"Controlar el uso de ; al final de sentencias secuenciales",
			"Si esta opci�n est� activada obliga a colocar punto y coma (;) al final de las instrucciones secuenciales, como se hace "
			"en lenguajes como C++ o Pascal (util para acostumbrarse antes de dar el salto desde el pseudoc�digo a un lenguaje real). "
			"si est� desactivada el uso del punto y coma es opcional."
		);
	data[LS_BASE_ZERO_ARRAYS		 ].Set("base_zero_arrays",			false,
		"Utilizar indices en arreglos y cadenas en base 0",
			"Si esta opci�n esta activada, el primer elemento de un arreglo de N elementos ser� el 0 y el �ltimo el N-1, mientras "
			"que en caso contrario el primero ser� el 1 y el �ltimo el N"
		);
	data[LS_ALLOW_CONCATENATION		 ].Set("allow_concatenation",		true,
		"Permitir concatenar variables de texto con el operador +",
			"Si esta opci�n esta activada se puede concatenar el contenido de dos variables de tipo caracter con el operador +. "
			"Por ejemplo: NombreCompleto <- Nombre+\" \"+Apellido;"
		);
	data[LS_USE_NASSI_SHNEIDERMAN	 ].Set("use_nassi_shneiderman",		false,
		"Usar diagramas de Nassi-Shneiderman",
			"Con esta opci�n activada, el editor de diagramas utilizar� el formato de Nassi-Shneiderman\n"
			"en lugar del formato cl�sico de diagrama de flujo."
		);
	data[LS_USE_ALTERNATIVE_IO_SHAPES].Set("use_alternative_io_shapes",	false,
		"Usar formas alternativas para Leer y Escribir en el diagrama",
			"Con esta opci�n activada, si se utiliza el diagrama de flujo cl�sico (no Nassi-Shneiderman), los bloques para las instrucciones"
			"Leer y Escribir ser�n diferentes entre s�, siguiendo una convenci�n alternativa"
		);
	data[LS_ALLOW_DINAMYC_DIMENSIONS ].Set("allow_dinamyc_dimensions",	true,
		"Permitir utilizar variables para dimensionar arreglos",
			"Si esta opci�n est� seleccionada se puede utilizar una variable o una expresi�n que involucre variables para dimensionar un "
			"arreglo (por ejemplo, se puede pedir al usuario del programa el tama�o leyendo un numero y utilizarlo luego para crear el "
			"arreglo). Este suele ser el caso de los lenguajes interpretados, mientras que los lenguajes compilados suelen exigir que el "
			"tama�o de los arreglos est�ticos sea una constante (por ejemplo, C y C++)."
		);
	data[LS_OVERLOAD_EQUAL			 ].Set("overload_equal",			false,
		"Permitir asignar con el signo igual (=)",
			"Esta opcion habilita la asignaci�n con el signo igual (Ej: x=0;). En muchos casos esta sintaxis de asignaci�n no se"
			"permite, ya que en muchos lenguajes no se utilia el mismo operador para asignar y comparar, como sucede al activar"
			"esta opci�n. En cualquier caso, las otras dos sintaxis de asignaci�n (con <- y con :=) siguen siendo v�lidas."
		);
	data[LS_COLOQUIAL_CONDITIONS	 ].Set("coloquial_conditions",		true,
		"Permitir condiciones en lenguaje coloquial",
			"Esta opcion permite expresar las condiciones en un lenguaje m�s coloquial con construcciones como \"X ES PAR\", "
			"\"X NO ES MULTIPLO DE 5\", \"X ES IGUAL A Y\", \"X ES ENTERO\", etc. Esta opci�n activa adem�s el uso de palabras "
			"clave para reemplazar operadores."
		);
	data[LS_LAZY_SYNTAX				 ].Set("lazy_syntax",				true,
		"Utilizar sintaxis flexible",
			"Esta opcion habilita variaciones opcionales en la sintaxis de ciertas instrucciones y estructuras de control. Por ejemplo, "
			"omitir la palabra HACER en un bucle MIENTRAS o PARA, utilizar la palabra DESDE para indicar el valor de inicio de un ciclo "
			"PARA, separar la expresiones/variables en una lectura/escritura con espacios en lugar de comas, escribir FinProceso como Fin "
			"Proceso, FinSi como Fin Si, etc."
		);
	data[LS_WORD_OPERATORS			 ].Set("word_operators",			true,
		"Permitir las palabras Y, O, NO y MOD para los operadores &&, |, ~ y %",
			"Con esta opci�n habilitada PSeInt acepta las palabras clave Y, O, NO, y MOD como sin�nimos de los operadores &&, |, ~ y % respectivamente. "
			"Notar que en este caso estas palabras ser�n palabras reservadas y no se podr�n utilizar como nombres de variables."
		);
	data[LS_ENABLE_USER_FUNCTIONS	 ].Set("enable_user_functions",		true,
		"Permitir definir funciones/subprocesos",
			"Con esta opci�n activada se permite definir subprocesos/funciones en pseudoc�digo para mediante la palabra clase SubProceso."
		);
	data[LS_ENABLE_STRING_FUNCTIONS	 ].Set("enable_string_functions",	true,
		"Habilitar funciones para el manejo de cadenas",
			"Esta opci�n habilita un conjunto de funciones predefinidas que sirven para operar sobre cadenas de "
			"caracteres. Las funciones son: Longitud, SubCadena, Mayusculas, Minusculas y Concatenar)."
		);
	data[LS_INTEGER_ONLY_SWITCH].Set("integer_only_switch",				false,
		"Limitar la estructura Seg�n a variables de control num�ricas",
			"Muchos lenguajes solo permiten utilizar n�meros enteros para las expresiones de control de la estructura de "
			"selecci�n m�ltiple (\"Seg�n\" en PSeInt). Si habilita esta opci�n, PSeInt aplicar� esta restricci�n. En caso "
			"contrario, podr� utilizar tambi�n variables de tipo caracter."
		);
	data[LS_DEDUCE_NEGATIVE_FOR_STEP].Set("deduce_negative_for_step",	true,
		"Permitir omitir el paso -1 en ciclos Para",
			"Con esta opci�n activa, si no se especifica el valor del \"paso\" en una estructura de tipo \"Para\", se utiliza +1 o -1 "
			"seg�n corresponda. Se determina comparando los valores iniciales y finales, si el primero es mayor al segundo +1, o -1 "
			"en caso contrario. Si se desactiva esta opci�n, se utilizar� siempre +1 como paso por defecto."
		);
	data[LS_ALLOW_ACCENTS].Set("allow_accents",							true,
		"Permitir utilizar acentos en nombres de variables",
			"Con esta opci�n activada, los identificadores de variables y funciones pueden incluir letras con "
			"acento, di�resis y/o la letra �. Si est� desactivada, el uso de estas letras generar� errores de "
			"\"identificador no v�lido\" y/o \"caracter no v�lido\"."
		);
	data[LS_PREFER_ALGORITMO].Set("prefer_algoritmo",					true,
		"Preferir las palabras clave \"Algoritmo\" y \"FinAlgoritmo\"",
			"Con esta opci�n activada, al insertar plantillas, generar o autocompletar el pseudoc�digo, "
			"se priorizar� el uso de las palabras claves \"Algoritmo\" y \"FinAlgoritmo\" frente a "
			"\"Proceso\" y \"FinProceso\" respectivamente. Si la opci�n est� desactivada se utilizar�n "
		    "por defecto las palabras clave \"Proceso\" y \"FinProceso\""
		);
	data[LS_PREFER_FUNCION].Set("prefer_funcion",						true,
		"Preferir las palabras clave \"Funci�n\" y \"FinFunci�n\"",
			"Con esta opci�n activada, al insertar plantillas, generar o autocompletar el pseudoc�digo, "
			"se priorizar� el uso de las palabras claves \"Funci�n\" y \"FinFunci�n\" frente a "
			"\"Proceso\" y \"FinProceso\" (o \"Algoritmo\" y \"FinAlgoritmo\") respectivamente."
		);
	data[LS_ALLOW_REPEAT_WHILE].Set("allow_repeat_while",					true,
		"Permitir la variaci�n \"Repetir ... Mientras Que...\"",
			"Habilita el uso de \"Mientras que <condici�n>\" en lugar de \"Hasta que <condici�n>\" "
			"para cerrar una estructura RepetirEsta construcci�n alternativa itera por verdadero "
			"en lugar de iterar por falso."
		);
	data[LS_PREFER_REPEAT_WHILE].Set("prefer_repeat_while",					false,
		"Preferir \"Repetir ... Mientras Que...\"",
			"Con esta opci�n activada, al seleccionar la estructura de control \"Repetir\" desde "
			"el panel de comandos (tanto del editor de pseudoc�digo como del editor de diagramas "
			"de flujo) se insertar� la versi�n \"Repetir ... Mientras que\" (que itera por "
			"verdadero); mientras que si est� desactivada se inserta la versi�n \"Repetir ... "
			"Hasta que\" (que itera por falso)."
		);
	data[LS_ALLOW_FOR_EACH].Set("allow_for_each",				true,
			"Habilitar estructura \"Para Cada...\"",
			"Con esta opci�n habilitada se puede utilizar la versi�n alternativa de la estructura "
			"repetitiva \"Para\" que permite recorrer los elementos de un arreglo de forma m�s "
			"simple. Ej: \"Para Cada Elemento de V Hacer ... FinPara\"."
		);
	data[LS_PROTECT_FOR_COUNTER].Set("protect_for_counter",				false,
			"Proteger contador del Para",
			"Con esta opci�n habilitada no se puede modificar la variable que se utiliza como "
			"contador dentro de un para, y adicionalmente la variable deja de estar inicializada "
			"una vez finalizado el bucle."
		);
#ifdef DEBUG
	for(int i=0;i<LS_COUNT;i++) { 
		if (!data[i].nombre) cerr<<"ERROR!!! campo no inicializado en LangSettings::data["<<i<<"]"<<endl;
	}
#endif
	init_done=true;
};


#ifdef FOR_WXPSEINT
#include <wx/string.h>
#include <wx/textfile.h>
#include <wx/filename.h>
#include "../wxPSeInt/string_conversions.h"
#include "../wxPSeInt/Logger.h"
#include "../wxPSeInt/version.h"


//static std::string get_filename(const std::string &fname) {
//	for(int i=fname.size()-1;i>0;i--) {
//		if (fname[i]=='\\'||fname[i]=='/') return fname.substr(i+1);
//	}
//	return fname;
//}

bool LangSettings::Load (const wxString &fname, bool from_list) {
	_LOG("LangSettings::Load "<<fname);
	if (!Load(std::string(_W2S(fname)))) return false;
	source = from_list ? LS_LIST : LS_FILE;
	name = wxFileName(fname).GetName();
	return true;
}

bool LangSettings::Save (const wxString &fname)  const {
	return Save(std::string(_W2S(fname)));
}

void LangSettings::Log ( ) const {
	_LOG("Profile: "<<VERSION<<" "<<GetAsSingleString().c_str());
}
#endif // FOR_WXPSEINT
#include <fstream>
bool LangSettings::Load(const std::string &fname) {
//	name = get_filename(fname);
	ifstream fil(fname.c_str());
	if (!fil.is_open()) return false; 
	Reset(0); string str; // reset va despues de los "return false" para evitar resetear el perfil personalizado cuando se llama desde el ConfigManager
	while (getline(fil,str)) ProcessConfigLine(str);
	Fix();
	return true;
}

static void replace(string  &s, string from, string to) {
	size_t p = s.find(from);
	while(p!=string::npos) {
		s.replace(p,from.size(),to);
		p = s.find(from,p+to.size());
	}
}

bool LangSettings::Save (const string &fname) const {
	ofstream fil(fname.c_str(),ios::trunc);
	if (!fil.is_open()) return false;
	
//	fil << "name=" << name << endl;
//	if (source==LS_DEFAULT)   fil << "source=defaul" << endl;
//	else if (source==LS_FILE) fil << "source=file" << endl;
//	else if (source==LS_LIST) fil << "source=list" << endl;
//	else                      fil << "source=custom" << endl;
	string tmp = descripcion.c_str(); 
	replace(tmp,"\r",""); replace(tmp,"\n","\ndesc=");
	fil << "desc=" << tmp << endl;
	fil << "version=" <<LS_VERSION << endl;
	for(int i=0;i<LS_COUNT;i++) 
		fil << GetConfigLine(i) << endl;
	fil.close();
	return true;
}

std::string LangSettings::GetAsSingleString() const {
	std::string retval(LS_COUNT,'?');
	for(int i=0;i<LS_COUNT;i++) retval[i]=settings[i]?'1':'0';
	return retval;
}


void LangSettings::Fix ( ) {
	if (version<20210609) { 
		settings[LS_ALLOW_FOR_EACH]=settings[LS_LAZY_SYNTAX]; // LS_ALLOW_FOR_EACH era parte de LS_LAZY_SYNTAX
	}
	if (version<20210407) { 
		settings[LS_ALLOW_REPEAT_WHILE]=settings[LS_LAZY_SYNTAX]; // LS_ALLOW_REPEAT_WHILE era parte de LS_LAZY_SYNTAX
	}
	if (version<20160321) { 
		settings[LS_ALLOW_ACCENTS]=settings[LS_LAZY_SYNTAX]; // LS_ALLOW_ACCENTS era parte de LS_LAZY_SYNTAX
		settings[LS_PREFER_ALGORITMO]=settings[LS_PREFER_FUNCION] = false; // LS_PREFER_ALGORITMO y LS_PREFER_FUNCION no exist�an
	}
	if (version<20150304) { // LS_INTEGER_ONLY_SWITCH y LS_DEDUCE_NEGATIVE_FOR_STEP eran parte de LS_LAZY_SYNTAX
		settings[LS_INTEGER_ONLY_SWITCH]=!settings[LS_LAZY_SYNTAX];
		settings[LS_DEDUCE_NEGATIVE_FOR_STEP]=settings[LS_LAZY_SYNTAX];
	}
	if (settings[LS_COLOQUIAL_CONDITIONS]) settings[LS_WORD_OPERATORS]=true; // no se puede usar LS_COLOQUIAL_CONDITIONS sin LS_WORD_OPERATORS
	if (!settings[LS_ALLOW_REPEAT_WHILE]) settings[LS_PREFER_REPEAT_WHILE] = false; // no tiene sentido LS_PREFER_REPEAT_WHILE sin LS_ALLOW_REPEAT_WHILE
	version=LS_VERSION; // colocar version nueva, para que el fix ya no actualice el perfil en la pr�xima carga
}

bool LangSettings::SetFromSingleString (const std::string & str) {
	if (str.size()!=LS_COUNT) return false;
	for(int i=0;i<LS_COUNT;i++) settings[i] = str[i]=='1';
	return true;
}


// IMPORTANTE, todos los char* de abajo con las keywords tienen que terminar con un espacio por si se concatenan entre si

static const char *mxSourceWords1 =
	"leer proceso definir como dimension si entonces sino segun hacer hasta que para con paso "
	"repetir mientras de otro modo escribir finpara "
	"fin finproceso finsi finmientras finsegun "
	"verdadero falso algoritmo finalgoritmo "
	"numero n�mero numeros n�meros numerico num�rico numerica num�rica numericas num�ricas numericos num�ricos "
	"entero entera enteros enteras real reales "
	"caracter car�cter caracteres texto cadena cadenas "
	"logico l�gico logica l�gica logicos l�gicos logicas l�gicas "
	"borrar limpiar pantalla borrarpantalla limpiarpantalla esperar tecla esperartecla segundos milisegundos segundo milisegundo sinsaltar sin saltar sinbajar bajar "
	"seg�n finseg�n dimensi�n ";

static const char *mxSourceWords1_op =
	"y no o mod ";

static const char *mxSourceWords1_extra =
	"es sies opcion caso desde imprimir cada mostrar opci�n son ";

static const char *mxSourceWords1_conds =
	"es par impar igual divisible multiplo distinto distinta de por cero positivo negativo negativa positiva entero mayor menor ";

static const char *mxSourceWords1_funcs =
	"subproceso finsubproceso funci�n funcion finfunci�n finfuncion por referencia valor copia subalgoritmo finsubalgoritmo ";

static const char* mxSourceWords2_math =
	"cos sen tan acos asen atan raiz rc ln abs exp aleatorio azar trunc redon pi euler ";

static const char* mxSourceWords2_string =
	"concatenar longitud mayusculas minusculas subcadena may�sculas min�sculas convertiranumero convertiratexto ";


std::string LangSettings::GetKeywords ( ) const {
	std::string ks = mxSourceWords1;
	if (settings[LS_ENABLE_USER_FUNCTIONS]) ks += mxSourceWords1_funcs;
	if (settings[LS_WORD_OPERATORS]) ks += mxSourceWords1_op;
	if (settings[LS_LAZY_SYNTAX]) ks += mxSourceWords1_extra;
	if (settings[LS_COLOQUIAL_CONDITIONS]) ks += mxSourceWords1_conds;
	return ks;
}

std::string LangSettings::GetFunctions ( ) const {
	std::string ks = mxSourceWords2_math;
	if (settings[LS_ENABLE_STRING_FUNCTIONS]) ks += mxSourceWords2_string;
	return ks;
}

