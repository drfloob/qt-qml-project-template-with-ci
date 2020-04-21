//
// Copyright (c) 2020, 219 Design, LLC (getstarted@219design.com)
// See LICENSE.txt
//
// 219design.com
//

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "view_model_collection.h"

int main( int argc, char* argv[] )
{
    qSetMessagePattern(
        "[QT-%{type}][thr:%{threadid}]%{if-category}%{category}: %{endif}%{file}(%{line}): %{message}" );
    QGuiApplication app( argc, argv );

    // ViewModels must OUTLIVE the qml engine, so create them first:
    com::two_one_nine::my_project::ViewModelCollection vms( app );

    // Created after vms, so that we avoid null vm qml warnings upon vm dtors
    QQmlApplicationEngine engine;

    vms.ExportContextPropertiesToQml( &engine );

    engine.addImportPath( "qrc:///" ); // needed for finding qml in our plugins
    engine.load( QUrl( QStringLiteral( "qrc:///qml/main.qml" ) ) );

    return app.exec();
}
