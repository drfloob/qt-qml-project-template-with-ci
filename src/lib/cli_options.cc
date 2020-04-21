//
// Copyright (c) 2020, 219 Design, LLC (getstarted@219design.com)
// See LICENSE.txt
//
// 219design.com
//
#include "cli_options.h"

#include <QCommandLineParser>



namespace com
{

namespace two_one_nine
{

namespace my_project
{

constexpr char GUI_TEST_CLI_OPT[] = "guitest";

CliOptions::CliOptions( const QCoreApplication& app )
{
    QCommandLineParser parser;
    parser.addHelpOption();

    parser.addOptions( {
        {{"g", GUI_TEST_CLI_OPT}, "run automated gui tests (app will SHUT DOWN soon after launch)"},
    } );

    parser.process( app );

    m_guiTests = parser.isSet( GUI_TEST_CLI_OPT );
}

CliOptions::~CliOptions() = default;

bool CliOptions::RunningGuiTests() const
{
    return m_guiTests;
}

} // namespace com

} // namespace two_one_nine

} // namespace my_project

