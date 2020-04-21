//
// Copyright (c) 2020, 219 Design, LLC (getstarted@219design.com)
// See LICENSE.txt
//
// 219design.com
//
#include "resources.h"

#include <QDir>

#include "src/libstyles/resources.h"

// Q_INIT_RESOURCE cannot be called from inside a named namespace.  See:
// http://doc.qt.io/qt-5/qdir.html#Q_INIT_RESOURCE
static inline void init()
{
    Q_INIT_RESOURCE( libresources );
}



namespace com
{

namespace two_one_nine
{

namespace my_project
{

void initLibResources()
{
    init();
    com::two_one_nine::my_project::initLibStylesResources();

    // Any other qregister things we wish...
    // qRegisterMetaType<CustomType*>("CustomType*");
}


} // namespace com

} // namespace two_one_nine

} // namespace my_project

