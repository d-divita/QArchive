#include <QMetaMethod>
#include <QMetaObject>

#include <qarchivediskextractor_p.hpp>
#include <qarchivediskextractor.hpp>

using namespace QArchive;

static QMetaMethod getMethod(DiskExtractorPrivate *o, const char *mId)
{
    auto metaObject = o->metaObject();
    return metaObject->method(metaObject->indexOfMethod(QMetaObject::normalizedSignature(mId)));
}

DiskExtractor::DiskExtractor(QObject *parent, bool singleThreaded )
    : QObject(parent)
{
    m_Extractor.reset(new DiskExtractorPrivate);
    if(!singleThreaded) {
        m_Thread.reset(new QThread);
        m_Extractor->moveToThread(m_Thread.data());
    }
    connect(m_Extractor.data(), &DiskExtractorPrivate::started,
            this, &DiskExtractor::started, Qt::DirectConnection);
    connect(m_Extractor.data(), &DiskExtractorPrivate::canceled,
            this, &DiskExtractor::canceled, Qt::DirectConnection);
    connect(m_Extractor.data(), &DiskExtractorPrivate::paused,
            this, &DiskExtractor::paused, Qt::DirectConnection);
    connect(m_Extractor.data(), &DiskExtractorPrivate::resumed,
            this, &DiskExtractor::resumed, Qt::DirectConnection);
    connect(m_Extractor.data(), &DiskExtractorPrivate::finished,
            this, &DiskExtractor::finished, Qt::DirectConnection);
    connect(m_Extractor.data(), &DiskExtractorPrivate::error,
            this, &DiskExtractor::error, Qt::DirectConnection);
    connect(m_Extractor.data(), &DiskExtractorPrivate::progress,
            this, &DiskExtractor::progress, Qt::DirectConnection);
    connect(m_Extractor.data(), &DiskExtractorPrivate::getInfoRequirePassword,
            this, &DiskExtractor::getInfoRequirePassword, Qt::DirectConnection);
    connect(m_Extractor.data(), &DiskExtractorPrivate::extractionRequirePassword,
            this, &DiskExtractor::extractionRequirePassword, Qt::DirectConnection);
    connect(m_Extractor.data(), &DiskExtractorPrivate::info,
            this, &DiskExtractor::info, Qt::DirectConnection);
}

DiskExtractor::DiskExtractor(QFile *archive, QObject *parent, bool singleThreaded)
    : DiskExtractor(parent, singleThreaded)
{
    setArchive(archive);
}

DiskExtractor::DiskExtractor(const QString &archivePath, QObject *parent, bool singleThreaded)
    : DiskExtractor(parent, singleThreaded)
{
    setArchive(archivePath);
}

DiskExtractor::DiskExtractor(const QString &archivePath, const QString &outputDirectory, QObject *parent, bool singleThreaded)
    : DiskExtractor(parent, singleThreaded)
{
    setArchive(archivePath);
    setOutputDirectory(outputDirectory);
}


DiskExtractor::~DiskExtractor()
{
    return;
}

void DiskExtractor::setArchive(QFile *archive)
{
    getMethod(m_Extractor.data(),
              "setArchive(QFile*)").invoke(m_Extractor.data(),
                                           Qt::QueuedConnection,
                                           Q_ARG(QFile*, archive));
    return;
}

void DiskExtractor::setArchive(const QString &archivePath)
{
    getMethod(m_Extractor.data(),
              "setArchive(const QString&)").invoke(m_Extractor.data(),
                      Qt::QueuedConnection,
                      Q_ARG(QString, archivePath));
    return;
}

void DiskExtractor::setArchive(const QString &archivePath, const QString &outputDirectory)
{
    setArchive(archivePath);
    setOutputDirectory(outputDirectory);
}

void DiskExtractor::setBlockSize(int n)
{
    getMethod(m_Extractor.data(),
              "setBlockSize(int)").invoke(m_Extractor.data(),
                                          Qt::QueuedConnection,
                                          Q_ARG(int, n));
    return;
}

void DiskExtractor::setShowProgress(bool choice)
{
    getMethod(m_Extractor.data(),
              "setShowProgress(bool)").invoke(m_Extractor.data(),
                      Qt::QueuedConnection,
                      Q_ARG(bool, choice));
    return;
}

void DiskExtractor::setOutputDirectory(const QString &dir)
{
    getMethod(m_Extractor.data(),
              "setOutputDirectory(const QString&)").invoke(m_Extractor.data(),
                      Qt::QueuedConnection,
                      Q_ARG(QString, dir));
    return;
}

void DiskExtractor::setPassword(const QString &passwd)
{
    getMethod(m_Extractor.data(),
              "setPassword(const QString&)").invoke(m_Extractor.data(),
                      Qt::QueuedConnection,
                      Q_ARG(QString, passwd));
    return;
}

void DiskExtractor::addFilter(const QString &filter)
{
    getMethod(m_Extractor.data(),
              "addFilter(const QString&)").invoke(m_Extractor.data(),
                      Qt::QueuedConnection,
                      Q_ARG(QString, filter));
    return;
}

void DiskExtractor::addFilter(const QStringList &filters)
{
    getMethod(m_Extractor.data(),
              "addFilter(const QStringList&)").invoke(m_Extractor.data(),
                      Qt::QueuedConnection,
                      Q_ARG(QStringList, filters));
    return;
}

void DiskExtractor::clear()
{
    getMethod(m_Extractor.data(), "clear()").invoke(m_Extractor.data(), Qt::QueuedConnection);
    return;
}

void DiskExtractor::getInfo()
{
    getMethod(m_Extractor.data(), "getInfo()").invoke(m_Extractor.data(), Qt::QueuedConnection);
    return;
}

void DiskExtractor::start()
{
    getMethod(m_Extractor.data(), "start()").invoke(m_Extractor.data(), Qt::QueuedConnection);
    return;
}

void DiskExtractor::cancel()
{
    getMethod(m_Extractor.data(), "cancel()").invoke(m_Extractor.data(), Qt::QueuedConnection);
    return;
}

void DiskExtractor::pause()
{
    getMethod(m_Extractor.data(), "pause()").invoke(m_Extractor.data(), Qt::QueuedConnection);
    return;
}

void DiskExtractor::resume()
{
    getMethod(m_Extractor.data(), "resume()").invoke(m_Extractor.data(), Qt::QueuedConnection);
    return;
}

