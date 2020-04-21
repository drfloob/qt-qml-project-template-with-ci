//
// Copyright (c) 2020, 219 Design, LLC (getstarted@219design.com)
// See LICENSE.txt
//
// 219design.com
//
#ifndef PROJECT_APP_GUI_TESTS_H
#define PROJECT_APP_GUI_TESTS_H

#include <QQmlApplicationEngine>
#include <QtCore/QObject>



namespace com
{

namespace two_one_nine
{

namespace my_project
{

class GuiTests : public QObject
{
    Q_OBJECT
public:
    explicit GuiTests( const QQmlApplicationEngine& qmlapp );
    ~GuiTests();

    GuiTests( const GuiTests& ) = delete;
    GuiTests& operator=( const GuiTests& ) = delete;
};

} // namespace com

} // namespace two_one_nine

} // namespace my_project


#endif // PROJECT_APP_GUI_TESTS_H
