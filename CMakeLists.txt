AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/mod_promotion.cpp")
AC_ADD_SCRIPT_LOADER("Promotion" "${CMAKE_CURRENT_LIST_DIR}/src/loader.h")

AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/mod_promotion.conf.dist")