PHP_ARG_ENABLE(
	wcl, 
	whether to enable wcl support,
dnl Make sure that the comment is aligned:
[  --enable-wcl           Enable wcl support])

if test "$PHP_WCL" != "no"; then
    PHP_NEW_EXTENSION(wcl, wcl.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
