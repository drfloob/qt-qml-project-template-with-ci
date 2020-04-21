//
// Copyright (c) 2020, 219 Design, LLC (getstarted@219design.com)
// See LICENSE.txt
//
// 219design.com
//
#ifndef PROJECT_APP_VIEW_MODEL_COLLECTION_H
#define PROJECT_APP_VIEW_MODEL_COLLECTION_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>

#include <memory>



namespace com
{

namespace two_one_nine
{

namespace my_project
{

class CliOptions;
class GuiTests;
class LoggingTags;
class QmlMessageInterceptor;

class ViewModelCollection
{
public:
    explicit ViewModelCollection( const QGuiApplication& app );
    ~ViewModelCollection();

    ViewModelCollection( const ViewModelCollection& ) = delete;
    ViewModelCollection& operator=( const ViewModelCollection& ) = delete;

    void ExportContextPropertiesToQml( QQmlApplicationEngine* engine );

private:
    const std::unique_ptr<const CliOptions> m_opts;
    std::unique_ptr<QmlMessageInterceptor> m_qmlLogger;
    std::unique_ptr<LoggingTags> m_logging;

    std::unique_ptr<GuiTests> m_guiTests;
};

} // namespace com

} // namespace two_one_nine

} // namespace my_project


#endif // PROJECT_APP_VIEW_MODEL_COLLECTION_H
