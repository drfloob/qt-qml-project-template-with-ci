//
// Copyright (c) 2020, 219 Design, LLC (getstarted@219design.com)
// See LICENSE.txt
//
// 219design.com
//
#ifndef PROJECT_APP_CLI_OPTIONS_H
#define PROJECT_APP_CLI_OPTIONS_H

#include <QCoreApplication>



namespace com
{

namespace two_one_nine
{

namespace my_project
{

class CliOptions
{
public:
    explicit CliOptions( const QCoreApplication& app );
    ~CliOptions();

    CliOptions( const CliOptions& ) = delete;
    CliOptions& operator=( const CliOptions& ) = delete;

    bool RunningGuiTests() const;

private:
    bool m_guiTests = false;
};

} // namespace com

} // namespace two_one_nine

} // namespace my_project


#endif // PROJECT_APP_CLI_OPTIONS_H
