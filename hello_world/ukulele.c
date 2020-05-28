//ukulele.c

#include "config.h"

#include "php.h"

ZEND_FUNCTION(u_hello)
{
    php_printf("Hello World!\n");
};

ZEND_FUNCTION(ukulele_hello)
{
    php_printf("Hello Ukulele!\n");
}

static zend_function_entry ukulele_functions[] = {
    ZEND_FE(u_hello,NULL)
    ZEND_FE(ukulele_hello,NULL)
    { NULL, NULL, NULL }
};

zend_module_entry ukulele_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
     STANDARD_MODULE_HEADER,
#endif
    "ukulele", //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    ukulele_functions, /* Functions */
    NULL, /* MINIT */
    NULL, /* MSHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    "2.1", //这个地方是我们扩展的版本
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_UKULELE
ZEND_GET_MODULE(ukulele)
#endif

