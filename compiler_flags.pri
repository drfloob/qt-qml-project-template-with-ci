#
# Copyright (c) 2020, 219 Design, LLC
# See LICENSE.txt
#
# https://www.219design.com
# Software | Electrical | Mechanical | Product Design
#

# the line below suppresses warnings generated by Qt's header files: we tell
# GCC to treat Qt's headers as "system headers" with the -isystem flag
QMAKE_CXXFLAGS += -isystem $$[QT_INSTALL_HEADERS]

unix:{
    # So the exe will launch if we put all our '*.so' dylibs side-by-side with it.
    # Based on https://stackoverflow.com/a/27393241/10278
    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
}

unix:{
    # some inspired by: https://kristerw.blogspot.com/2017/09/useful-gcc-warning-options-not-enabled.html
    # others inspired by: https://stackoverflow.com/questions/5088460/flags-to-enable-thorough-and-verbose-g-warnings
    QMAKE_CXXFLAGS += "\
         -Wall \
         -Wcast-align \
         -Wcast-qual \
         -Wconversion \
         -Wdisabled-optimization \
         -Wduplicated-branches \
         -Wduplicated-cond \
         -Werror \
         -Werror=switch \
         -Wextra \
         -Wfloat-equal \
         -Wformat-nonliteral \
         -Wformat-security \
         -Wformat=2 \
         -Wimport \
         -Winit-self \
         -Winline \
         -Wlogical-op \
         -Wmisleading-indentation \
         -Wmissing-declarations \
         -Wmissing-field-initializers \
         -Wmissing-format-attribute   \
         -Wmissing-include-dirs \
         -Wmissing-noreturn \
         -Wnon-virtual-dtor \
         -Wnull-dereference \
         -Wold-style-cast \
         -Wpedantic \
         -Wpointer-arith \
         -Wredundant-decls \
         -Wrestrict \
         -Wshadow \
         -Wshadow \
         -Wstack-protector \
         -Wswitch-default \
         -Wswitch-enum \
         -Wundef  \
         -Wuninitialized \
         -Wunreachable-code \
         -Wunused \
         -Wunused-but-set-parameter \
         -Wunused-parameter \
         -Wvariadic-macros \
         -Wwrite-strings \
         "
}

include($$top_srcdir/src/assert/assert.pri) # allows all code to include util-assert.h