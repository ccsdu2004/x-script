cmake_minimum_required(VERSION 3.5)

project(xscript-porject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -pg")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(./include)
include_directories(./source)

add_library(
     xscript-core
     include/xscript/xdefs.h
     include/xscript/xfilereader.h
     source/xfilereader.cpp
     include/xscript/xlexer.h
     include/xscript/xtoken.h
     source/lexer/xtoken.cpp
     source/lexer/xlexer.cpp
     include/xscript/xvariabletable.h
     source/xvariabletable.cpp

     include/xscript/xprint.h
     source/xprint.cpp
     source/xerror.cpp

     include/xscript/xitemvisitor.h
     source/type/xitemvisitor.cpp

     include/xscript/xitem.h
     include/xscript/xitemtype.h
     include/xscript/xitemcontainer.h
     include/xscript/xitemsimpletype.h
     include/xscript/xitemundefined.h
     include/xscript/xitemboolean.h
     include/xscript/xitemstring.h
     include/xscript/xitemint32.h
     include/xscript/xitemint64.h
     include/xscript/xitemfloat.h
     include/xscript/xitemdouble.h
     include/xscript/xitemlist.h
     include/xscript/xitemdict.h
     include/xscript/xitemcontainer.h

     source/type/xitem.cpp
     source/type/xitemtype.cpp
     source/type/xitemundefined.cpp
     source/type/xitemboolean.cpp
     source/type/xitemstring.cpp
     source/type/xitemint32.cpp
     source/type/xitemint64.cpp
     source/type/xitemfloat.cpp
     source/type/xitemdouble.cpp
     source/type/xitemlist.cpp
     source/type/xitemdict.cpp
     source/type/xitemtoken.cpp
     source/type/xitemcontainer.cpp

     include/xscript/xcall.h
     source/call/xcall.cpp

     include/xscript/xcallblock.h
     source/call/xcallblock.cpp

     source/call/xitemcreator.h
     source/call/xitemcreator.cpp

     include/xscript/xstatecreator.h
     source/xstatecreator.cpp

     include/xscript/xscriptexecutor.h
     source/xscriptexecutor.cpp

     source/creator/xstatecreatorlet.h
     source/creator/xstatecreatorlet.cpp
     source/creator/xstatecreatorset.h
     source/creator/xstatecreatorset.cpp
     source/creator/xstatecreatorprint.h
     source/creator/xstatecreatorprint.cpp
     source/creator/xstatecreatorif.h
     source/creator/xstatecreatorif.cpp
     source/creator/xstatecreatorlist.h
     source/creator/xstatecreatorlist.cpp

     source/call/xcalllet.cpp
     source/call/xcalllet.h
     source/call/xcallset.cpp
     source/call/xcallset.h
     source/call/xcallboolean.cpp
     source/call/xcallboolean.h
     source/call/xcallprint.cpp
     source/call/xcallprint.h
     source/call/xcallif.cpp
     source/call/xcallif.h

     include/xscript/xmodule.h
     source/xmodule.cpp
)

#add_subdirectory(XScriptEditor)
add_subdirectory(demo)

