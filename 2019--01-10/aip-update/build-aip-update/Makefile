#############################################################################
# Makefile for building: aip-update
# Generated by qmake (2.01a) (Qt 4.8.5) on: Mon Jul 18 18:22:37 2016
# Project:  ../aip-update/aip-update.pro
# Template: app
# Command: /home/link/CrossTools/qt/bin/qmake -spec ../../../../CrossTools/qt/mkspecs/qws/linux-arm-gnueabi-g++ -o Makefile ../aip-update/aip-update.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-none-linux-gnueabi-gcc -lts
CXX           = arm-none-linux-gnueabi-g++ -lts
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../../../CrossTools/qt/mkspecs/qws/linux-arm-gnueabi-g++ -I../aip-update -I../../../../CrossTools/qt/include/QtCore -I../../../../CrossTools/qt/include/QtNetwork -I../../../../CrossTools/qt/include/QtGui -I../../../../CrossTools/qt/include -I. -I. -I../aip-update -I../../../../CrossTools/qt/include -I.
LINK          = arm-none-linux-gnueabi-g++ -lts
LFLAGS        = -Wl,-O1 -Wl,-rpath,/home/hl/qt/lib
LIBS          = $(SUBLIBS)  -L/home/link/CrossTools/qt/lib -lQtGui -L/home/hl/em9280/rootfs-qt4.7/lib -L/home/hl/qt/lib -lQtNetwork -lQtCore -lpthread 
AR            = arm-none-linux-gnueabi-ar cqs
RANLIB        = 
QMAKE         = /home/link/CrossTools/qt/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = arm-none-linux-gnueabi-strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ../aip-update/main.cpp \
		../aip-update/CMainScreen.cpp \
		../aip-update/MyCanThread.cpp moc_CMainScreen.cpp \
		moc_MyCanThread.cpp
OBJECTS       = main.o \
		CMainScreen.o \
		MyCanThread.o \
		moc_CMainScreen.o \
		moc_MyCanThread.o
DIST          = ../../../../CrossTools/qt/mkspecs/common/unix.conf \
		../../../../CrossTools/qt/mkspecs/common/linux.conf \
		../../../../CrossTools/qt/mkspecs/common/gcc-base.conf \
		../../../../CrossTools/qt/mkspecs/common/gcc-base-unix.conf \
		../../../../CrossTools/qt/mkspecs/common/g++-base.conf \
		../../../../CrossTools/qt/mkspecs/common/g++-unix.conf \
		../../../../CrossTools/qt/mkspecs/common/qws.conf \
		../../../../CrossTools/qt/mkspecs/qconfig.pri \
		../../../../CrossTools/qt/mkspecs/features/qt_functions.prf \
		../../../../CrossTools/qt/mkspecs/features/qt_config.prf \
		../../../../CrossTools/qt/mkspecs/features/exclusive_builds.prf \
		../../../../CrossTools/qt/mkspecs/features/default_pre.prf \
		../../../../CrossTools/qt/mkspecs/features/release.prf \
		../../../../CrossTools/qt/mkspecs/features/default_post.prf \
		../../../../CrossTools/qt/mkspecs/features/shared.prf \
		../../../../CrossTools/qt/mkspecs/features/warn_on.prf \
		../../../../CrossTools/qt/mkspecs/features/qt.prf \
		../../../../CrossTools/qt/mkspecs/features/unix/thread.prf \
		../../../../CrossTools/qt/mkspecs/features/moc.prf \
		../../../../CrossTools/qt/mkspecs/features/resources.prf \
		../../../../CrossTools/qt/mkspecs/features/uic.prf \
		../../../../CrossTools/qt/mkspecs/features/yacc.prf \
		../../../../CrossTools/qt/mkspecs/features/lex.prf \
		../../../../CrossTools/qt/mkspecs/features/include_source_dir.prf \
		../aip-update/aip-update.pro
QMAKE_TARGET  = aip-update
DESTDIR       = 
TARGET        = aip-update

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_CMainScreen.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ../aip-update/aip-update.pro  ../../../../CrossTools/qt/mkspecs/qws/linux-arm-gnueabi-g++/qmake.conf ../../../../CrossTools/qt/mkspecs/common/unix.conf \
		../../../../CrossTools/qt/mkspecs/common/linux.conf \
		../../../../CrossTools/qt/mkspecs/common/gcc-base.conf \
		../../../../CrossTools/qt/mkspecs/common/gcc-base-unix.conf \
		../../../../CrossTools/qt/mkspecs/common/g++-base.conf \
		../../../../CrossTools/qt/mkspecs/common/g++-unix.conf \
		../../../../CrossTools/qt/mkspecs/common/qws.conf \
		../../../../CrossTools/qt/mkspecs/qconfig.pri \
		../../../../CrossTools/qt/mkspecs/features/qt_functions.prf \
		../../../../CrossTools/qt/mkspecs/features/qt_config.prf \
		../../../../CrossTools/qt/mkspecs/features/exclusive_builds.prf \
		../../../../CrossTools/qt/mkspecs/features/default_pre.prf \
		../../../../CrossTools/qt/mkspecs/features/release.prf \
		../../../../CrossTools/qt/mkspecs/features/default_post.prf \
		../../../../CrossTools/qt/mkspecs/features/shared.prf \
		../../../../CrossTools/qt/mkspecs/features/warn_on.prf \
		../../../../CrossTools/qt/mkspecs/features/qt.prf \
		../../../../CrossTools/qt/mkspecs/features/unix/thread.prf \
		../../../../CrossTools/qt/mkspecs/features/moc.prf \
		../../../../CrossTools/qt/mkspecs/features/resources.prf \
		../../../../CrossTools/qt/mkspecs/features/uic.prf \
		../../../../CrossTools/qt/mkspecs/features/yacc.prf \
		../../../../CrossTools/qt/mkspecs/features/lex.prf \
		../../../../CrossTools/qt/mkspecs/features/include_source_dir.prf \
		/home/link/CrossTools/qt/lib/libQtGui.prl \
		/home/link/CrossTools/qt/lib/libQtNetwork.prl \
		/home/link/CrossTools/qt/lib/libQtCore.prl
	$(QMAKE) -spec ../../../../CrossTools/qt/mkspecs/qws/linux-arm-gnueabi-g++ -o Makefile ../aip-update/aip-update.pro
../../../../CrossTools/qt/mkspecs/common/unix.conf:
../../../../CrossTools/qt/mkspecs/common/linux.conf:
../../../../CrossTools/qt/mkspecs/common/gcc-base.conf:
../../../../CrossTools/qt/mkspecs/common/gcc-base-unix.conf:
../../../../CrossTools/qt/mkspecs/common/g++-base.conf:
../../../../CrossTools/qt/mkspecs/common/g++-unix.conf:
../../../../CrossTools/qt/mkspecs/common/qws.conf:
../../../../CrossTools/qt/mkspecs/qconfig.pri:
../../../../CrossTools/qt/mkspecs/features/qt_functions.prf:
../../../../CrossTools/qt/mkspecs/features/qt_config.prf:
../../../../CrossTools/qt/mkspecs/features/exclusive_builds.prf:
../../../../CrossTools/qt/mkspecs/features/default_pre.prf:
../../../../CrossTools/qt/mkspecs/features/release.prf:
../../../../CrossTools/qt/mkspecs/features/default_post.prf:
../../../../CrossTools/qt/mkspecs/features/shared.prf:
../../../../CrossTools/qt/mkspecs/features/warn_on.prf:
../../../../CrossTools/qt/mkspecs/features/qt.prf:
../../../../CrossTools/qt/mkspecs/features/unix/thread.prf:
../../../../CrossTools/qt/mkspecs/features/moc.prf:
../../../../CrossTools/qt/mkspecs/features/resources.prf:
../../../../CrossTools/qt/mkspecs/features/uic.prf:
../../../../CrossTools/qt/mkspecs/features/yacc.prf:
../../../../CrossTools/qt/mkspecs/features/lex.prf:
../../../../CrossTools/qt/mkspecs/features/include_source_dir.prf:
/home/link/CrossTools/qt/lib/libQtGui.prl:
/home/link/CrossTools/qt/lib/libQtNetwork.prl:
/home/link/CrossTools/qt/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../../../CrossTools/qt/mkspecs/qws/linux-arm-gnueabi-g++ -o Makefile ../aip-update/aip-update.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/aip-update1.0.0 || $(MKDIR) .tmp/aip-update1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/aip-update1.0.0/ && $(COPY_FILE) --parents ../aip-update/CMainScreen.h ../aip-update/MyCanThread.h .tmp/aip-update1.0.0/ && $(COPY_FILE) --parents ../aip-update/main.cpp ../aip-update/CMainScreen.cpp ../aip-update/MyCanThread.cpp .tmp/aip-update1.0.0/ && $(COPY_FILE) --parents ../aip-update/CMainScreen.ui .tmp/aip-update1.0.0/ && (cd `dirname .tmp/aip-update1.0.0` && $(TAR) aip-update1.0.0.tar aip-update1.0.0 && $(COMPRESS) aip-update1.0.0.tar) && $(MOVE) `dirname .tmp/aip-update1.0.0`/aip-update1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/aip-update1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_CMainScreen.cpp moc_MyCanThread.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_CMainScreen.cpp moc_MyCanThread.cpp
moc_CMainScreen.cpp: ../aip-update/MyCanThread.h \
		../aip-update/CMainScreen.h
	/home/link/CrossTools/qt/bin/moc $(DEFINES) $(INCPATH) ../aip-update/CMainScreen.h -o moc_CMainScreen.cpp

moc_MyCanThread.cpp: ../aip-update/MyCanThread.h
	/home/link/CrossTools/qt/bin/moc $(DEFINES) $(INCPATH) ../aip-update/MyCanThread.h -o moc_MyCanThread.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_CMainScreen.h
compiler_uic_clean:
	-$(DEL_FILE) ui_CMainScreen.h
ui_CMainScreen.h: ../aip-update/CMainScreen.ui
	/home/link/CrossTools/qt/bin/uic ../aip-update/CMainScreen.ui -o ui_CMainScreen.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: ../aip-update/main.cpp ../aip-update/CMainScreen.h \
		../aip-update/MyCanThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../aip-update/main.cpp

CMainScreen.o: ../aip-update/CMainScreen.cpp ../aip-update/CMainScreen.h \
		../aip-update/MyCanThread.h \
		ui_CMainScreen.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CMainScreen.o ../aip-update/CMainScreen.cpp

MyCanThread.o: ../aip-update/MyCanThread.cpp ../aip-update/MyCanThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MyCanThread.o ../aip-update/MyCanThread.cpp

moc_CMainScreen.o: moc_CMainScreen.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_CMainScreen.o moc_CMainScreen.cpp

moc_MyCanThread.o: moc_MyCanThread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MyCanThread.o moc_MyCanThread.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

