
#include "config.h"

#include "php.h"


// ZEND_BEGIN_MODULE_GLOBALS(wcl)
    // zend_long filter_blank;
// ZEND_END_MODULE_GLOBALS(wcl)


// ZEND_DECLARE_MODULE_GLOBALS(wcl)

PHP_FUNCTION(wcl)
{
    php_printf("Hello World!\n");

    char *filepath = NULL;
    int argc = ZEND_NUM_ARGS();
    size_t filepath_len;
    char ch, pre = '\n';
    FILE *fp;
    zend_long lcount = 0;


    // if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filepath, &filepath_len) == FAILURE) 
    if (zend_parse_parameters(argc, "s", &filepath, &filepath_len) == FAILURE) 
    {
        return;
    }

    zend_printf(filepath);
    zend_printf("%i\n",filepath_len);
    php_printf("ab\n");

        php_printf("biao hahahh!\n");

    //  //php_error(E_WARNING, "wcl: not yet implemented"); 

    if ((fp = fopen(filepath, "r")) == NULL) {
        RETURN_FALSE;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lcount++;
        }
        pre = ch;
    }
    fclose(fp);

    RETURN_LONG(lcount);
}


static zend_function_entry wcl_functions[] = {
    ZEND_FE(wcl,NULL)
    { NULL, NULL, NULL }
};

/* {{{ wcl_module_entry
 */
zend_module_entry wcl_module_entry = {
    STANDARD_MODULE_HEADER,
    "wcl",
    wcl_functions,
    NULL, /* MINIT */
    NULL, /* MSHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    "2.1",
    STANDARD_MODULE_PROPERTIES
};
/* }}} */


#ifdef COMPILE_DL_WCL
ZEND_GET_MODULE(wcl)
#endif

