cmake_minimum_required(VERSION 3.5)

project(xscript-porject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -pg")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(source)

add_library(
     xscript-core
     include/xdefs.h
     include/xfactory.h
     include/xitem.h
     include/xcallerror.h
     include/xprint.h
     source/xitemtype.cpp
     source/xitem.cpp
     source/xcallerror.cpp
     include/xitemvisitor.h
     source/xitemvisitor.cpp
     include/xitemtype.h
     include/xitemsimpletype.h
     include/xitemcontainer.h
     include/xitemundefined.h
     source/xitemundefined.cpp
     include/xitemboolean.h
     source/xitemboolean.cpp
     include/xitemstring.h
     source/xitemstring.cpp
     include/xitemint32.h
     source/xitemint32.cpp
     include/xitemint64.h
     source/xitemint64.cpp
     include/xitemfloat.h
     source/xitemfloat.cpp
     include/xitemdouble.h
     source/xitemdouble.cpp
     include/xitemlist.h
     source/xitemlist.cpp
     include/xitemdict.h
     source/xitemdict.cpp
     include/xitemfunction.h
     source/xitemfunction.cpp
     include/xitemmodule.h
     source/xitemmodule.cpp
     include/xitemcontainer.h
     source/xitemcontainer.cpp
     source/xprint.cpp
     include/xitemfunctionproxy.h
     source/xitemfunctionproxy.cpp
     source/operator/xoperatorplus.h
     source/operator/xoperatorplus.cpp
     source/operator/xoperatorminus.h
     source/operator/xoperatorminus.cpp
     source/operator/xoperatormulti.h
     source/operator/xoperatormulti.cpp
     source/operator/xoperatordiv.h
     source/operator/xoperatordiv.cpp
     source/operator/xoperatorcompare.h
     source/operator/xoperatorcompare.cpp
     source/operator/xoperatorlogic.h
     source/operator/xoperatorlogic.cpp
     source/operator/xoperator.cpp
)

add_subdirectory(XScriptEditor)
add_subdirectory(demo)
