#ifndef QARCHIVE_GLOBAL_HPP_INCLUDED
#define QARCHIVE_GLOBAL_HPP_INCLUDED
#include <QtCore/QtGlobal>

#ifdef QARCHIVE_BUILD
# define QARCHIVE_EXPORT Q_DECL_EXPORT
#else
# define QARCHIVE_EXPORT Q_DECL_IMPORT
#endif // QARCHIVE_BUILD

#endif // QARCHIVE_GLOBAL_HPP_INCLUDED
