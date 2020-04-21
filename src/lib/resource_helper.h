//
// Copyright (c) 2020, 219 Design, LLC (getstarted@219design.com)
// See LICENSE.txt
//
// 219design.com
//
#ifndef PROJ_LIB_RESOURCE_HELPER_H
#define PROJ_LIB_RESOURCE_HELPER_H

#include <QtCore/QObject>
#include <QtQml/QQmlEngine>



namespace com
{

namespace two_one_nine
{

namespace my_project
{

class ResourceHelper : public QObject
{
    Q_OBJECT

    // Should correspond to content in qml/dummydata/resourceHelper.qml
    Q_PROPERTY( QString imageSourcePrefix MEMBER imageSourcePrefix CONSTANT )

public:
    ResourceHelper() = default;
    ~ResourceHelper() override = default;

    ResourceHelper( const ResourceHelper& ) = delete;
    ResourceHelper& operator=( const ResourceHelper& ) = delete;

    static void ExportContextPropertiesToQml( QQmlEngine* engine );

    // Should correspond to content in qml/dummydata/resourceHelper.qml
    const QString imageSourcePrefix = "qrc:///libstyles/";
};


} // namespace com

} // namespace two_one_nine

} // namespace my_project


#endif // PROJ_LIB_RESOURCE_HELPER_H
