 CONFIG += qt debug
 HEADERS += 
 SOURCES += Qt.cpp
 SOURCES += 
 win32 {
     SOURCES += Qt.cpp
 }
 unix {
     SOURCES += hellounix.cpp
 }
 #!exists( main.cpp ) {
 #    error( "No main.cpp file found" )
 #}
 win32:debug {
     CONFIG += console
 }