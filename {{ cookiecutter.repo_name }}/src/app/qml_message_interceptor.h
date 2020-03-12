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

{% for ns in cpp_namespace %}
namespace {{ ns }}
{
{% endfor %}
class QmlMessageInterceptor
{
public:
    QmlMessageInterceptor();

    ~QmlMessageInterceptor();
};

{% for ns in cpp_namespace|reverse %}
} // namespace {{ ns }}
{% endfor %}

#endif // PROJECT_APP_QML_MESSAGE_INTERCEPTOR_H
