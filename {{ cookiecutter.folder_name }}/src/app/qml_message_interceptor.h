//
// Copyright (c) {{ cookiecutter.year }}, {{ cookiecutter.who_am_I }} ({{ cookiecutter.email }})
// See LICENSE.txt
//
// {{ cookiecutter.website }}
//
#ifndef PROJECT_APP_QML_MESSAGE_INTERCEPTOR_H
#define PROJECT_APP_QML_MESSAGE_INTERCEPTOR_H

#include <QObject>

{% set nslist = cookiecutter.cpp_namespace.split('::') %}
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
