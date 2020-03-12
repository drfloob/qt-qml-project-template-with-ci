//
// Copyright (c) {{ cookiecutter.year }}, {{ cookiecutter.full_name }}
// {{ cookiecutter.website }}
// {{ cookiecutter.email }}
//
// See LICENSE.txt
//

#ifndef PROJECT_APP_GUI_TESTS_H
#define PROJECT_APP_GUI_TESTS_H

#include <QQmlApplicationEngine>
#include <QtCore/QObject>

{% for ns in cpp_namespace %}
namespace {{ ns }}
{
{% endfor %}
class GuiTests : public QObject
{
    Q_OBJECT
public:
    explicit GuiTests( const QQmlApplicationEngine& qmlapp );
    ~GuiTests();

    GuiTests( const GuiTests& ) = delete;
    GuiTests& operator=( const GuiTests& ) = delete;
};
{% for ns in cpp_namespace|reverse %}
} // namespace {{ ns }}
{% endfor %}

#endif // PROJECT_APP_GUI_TESTS_H
