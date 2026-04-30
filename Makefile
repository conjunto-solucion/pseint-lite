ifdef ARCH

all: 
	${MAKE} -C pseint   -f Makefile ARCH=${ARCH}
	${MAKE} -C psexport -f Makefile ARCH=${ARCH}
	${MAKE} -C hoewrap  -f Makefile ARCH=${ARCH}
	${MAKE} -C wxPSeInt -f Makefile ARCH=${ARCH}
	${MAKE} -C pseval   -f Makefile ARCH=${ARCH}
	${MAKE} -C psterm   -f Makefile ARCH=${ARCH}
	${MAKE} -C psdraw3  -f Makefile ARCH=${ARCH}
	${MAKE} -C psdrawE  -f Makefile ARCH=${ARCH}

clean: 
	${MAKE} -C pseint   -f Makefile ARCH=${ARCH} clean
	${MAKE} -C psexport -f Makefile ARCH=${ARCH} clean
	${MAKE} -C hoewrap  -f Makefile ARCH=${ARCH} clean
	${MAKE} -C wxPSeInt -f Makefile ARCH=${ARCH} clean
	${MAKE} -C pseval   -f Makefile ARCH=${ARCH} clean
	${MAKE} -C psterm   -f Makefile ARCH=${ARCH} clean
	${MAKE} -C psdraw3  -f Makefile ARCH=${ARCH} clean
	${MAKE} -C psdrawE  -f Makefile ARCH=${ARCH} clean

endif