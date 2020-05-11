//
// Copyright (c) {{ cookiecutter.year }}, {{ cookiecutter.who_am_I }} ({{ cookiecutter.email }})
// See LICENSE.txt
//
// {{ cookiecutter.website }}
//
#include "cli_options.h"

#include <QCommandLineParser>

{% set nslist = cookiecutter.cpp_namespace.split('::') %}
{% for ns in nslist %}
namespace {{ ns }}
{
{% endfor %}
constexpr char GUI_TEST_CLI_OPT[] = "guitest";

CliOptions::CliOptions( const QCoreApplication& app )
{
    QCommandLineParser parser;
    parser.addHelpOption();

    parser.addOptions( {
        {{ '{{' }}"g", GUI_TEST_CLI_OPT}, "run automated gui tests (app will SHUT DOWN soon after launch)"},
    } );

    parser.process( app );

    m_guiTests = parser.isSet( GUI_TEST_CLI_OPT );
}

CliOptions::~CliOptions() = default;

bool CliOptions::RunningGuiTests() const
{
    return m_guiTests;
}
{% for ns in nslist %}
} // namespace {{ ns }}
{% endfor %}
