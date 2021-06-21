#ifndef QARCHIVE_DISK_EXTRACTOR_HPP_INCLUDED
#define QARCHIVE_DISK_EXTRACTOR_HPP_INCLUDED
#include <QScopedPointer>
#include <QIODevice>
#include <QString>
#include <QObject>
#include <QThread>
#include <QJsonObject>

#include "qarchiveextractor.hpp"

namespace QArchive {
class DiskExtractorPrivate;
class DiskExtractor : public QObject {
    Q_OBJECT
  public:
    DiskExtractor(QObject *parent = nullptr, bool singleThreaded = true);
    DiskExtractor(QIODevice*, QObject *parent = nullptr, bool singleThreaded = true);
    DiskExtractor(const QString&, QObject *parent = nullptr, bool singleThreaded = true);
    DiskExtractor(const QString&, const QString&, QObject *parent = nullptr, bool singleThreaded = true);
    ~DiskExtractor();
  Q_SIGNALS:
    void finished();
};
}
#endif // QARCHIVE_DISK_EXTRACTOR_HPP_INCLUDED
