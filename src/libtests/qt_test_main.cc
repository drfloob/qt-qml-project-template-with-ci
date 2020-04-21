//
// Copyright (c) 2020, 219 Design, LLC (getstarted@219design.com)
// See LICENSE.txt
//
// 219design.com
//
#include <QCoreApplication>
#include <QTimer>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// This test runner implements the common setup for all googletest-based unit
// tests which require access to a QCoreApplication instance. (Note: _not_ all
// Qt-based code needs a QCoreApplication during its unit tests. Many tests of
// Qt code use test_main instead.)

int main( int argc, char* argv[] )
{
    // QCoreApplication will clean up qt resources when closed. Objects that use
    // qt plugins can show false positive memory leaks on ASAN without properly
    // quitting the active QCoreApplication.
    QCoreApplication a( argc, argv );

    testing::InitGoogleTest( &argc, argv );
    testing::InitGoogleMock( &argc, argv );

    int ret = RUN_ALL_TESTS();

    // Allows qt to process its exec loop
    QTimer exit_timer;
    QObject::connect( &exit_timer, &QTimer::timeout, &a, QCoreApplication::quit );
    exit_timer.start();

    a.exec();
    return ret;
}
