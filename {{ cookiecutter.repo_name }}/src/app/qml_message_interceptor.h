//
// Copyright (c) 2020, 219 Design, LLC
// See LICENSE.txt
//
// https://www.219design.com
// Software | Electrical | Mechanical | Product Design
//
#ifndef PROJECT_APP_QML_MESSAGE_INTERCEPTOR_H
#define PROJECT_APP_QML_MESSAGE_INTERCEPTOR_H

#include <QObject>

{% set nslist = cookiecutter.cpp_namespace.split('.') %}
{% for ns in nslist %}
namespace {{ ns }}
{
{% endfor %}
class QmlMessageInterceptor
{
public:
    QmlMessageInterceptor();

    ~QmlMessageInterceptor();
};

{% for ns in nslist %}
} // namespace {{ ns }}
{% endfor %}

#endif // PROJECT_APP_QML_MESSAGE_INTERCEPTOR_H
