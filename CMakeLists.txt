cmake_minimum_required (VERSION 2.8)
project (algorithm)

set(CMAKE_CXX_FLAGS_DEBUG "-g3")

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(EXECSUBDIRS "${PROJECT_SOURCE_DIR}/test")
FOREACH(execsubdir ${EXECSUBDIRS})
    FILE(GLOB MAINFILES RELATIVE "${PROJECT_SOURCE_DIR}/test/${execsubdir}" "${PROJECT_SOURCE_DIR}/test/${execsubdir}/*.cpp")
    include_directories("${PROJECT_SOURCE_DIR}/src/${execsubdir}")
    FOREACH(mainfile ${MAINFILES})
        LIST(APPEND SRC_LIST "${PROJECT_SOURCE_DIR}/test/${execsubdir}/${mainfile}")
        STRING(REPLACE "." " " NAMELIST ${mainfile})
        separate_arguments(NAMELIST)
        LIST(GET NAMELIST 0 NAME)
        add_executable(${NAME} ${SRC_LIST})
        LIST(REMOVE_ITEM SRC_LIST "${PROJECT_SOURCE_DIR}/test/${execsubdir}/${mainfile}")
    ENDFOREACH()
ENDFOREACH()
