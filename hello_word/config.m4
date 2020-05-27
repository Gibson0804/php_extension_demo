    PHP_ARG_ENABLE(ukulele,
        [Whether to enable the "ukulele" extension],
        [  enable-ukulele        Enable "ukulele" extension support])

    if test $PHP_ukulele != "no"; then
        PHP_SUBST(ukulele_SHARED_LIBADD)
        PHP_NEW_EXTENSION(ukulele, ukulele.c, $ext_shared)
    fi
