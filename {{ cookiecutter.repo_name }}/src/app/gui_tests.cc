//
// Copyright (c) {{ cookiecutter.year }}, {{ cookiecutter.full_name }}
// {{ cookiecutter.website }}
// {{ cookiecutter.email }}
//
// See LICENSE.txt
//

#include "gui_tests.h"

#include <QCoreApplication>
#include <QTimer>

#include "util-assert.h"

{% for ns in cpp_namespace %}
namespace {{ ns }}
{
{% endfor %}
namespace
{
    // Don't let this discourage us from ever renaming our qml filenames. This
    // isn't for the purpose of enforcing the precise NAME. Rather, this is used
    // only to give confirmation that we understand what the
    // QQmlApplicationEngine creates/loads when the app is run.
    constexpr char EXPECTED_FIRST_LOADED_FILE[] = "homepage.qml";
} // namespace

GuiTests::GuiTests( const QQmlApplicationEngine& engine )
{
    connect( &engine, &QQmlApplicationEngine::objectCreated, [=]( QObject*, const QUrl& url ) {
        FASSERT( url.fileName() == QString( EXPECTED_FIRST_LOADED_FILE ), "something must have changed in loading behavior of QQmlApplicationEngine" );

        // quit during next event-loop cycle
        QTimer::singleShot( 1 /*milliseconds*/, QCoreApplication::instance(), QCoreApplication::quit );
    } );
}

GuiTests::~GuiTests() = default;

{% for ns in cpp_namespace|reverse %}
} // namespace {{ ns }}
{% endfor %}
