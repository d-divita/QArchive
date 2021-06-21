---
title: Announcing QArchive v2.1.x
author: Antony J.r
authorURL: https://antonyjr.in
---

QArchive has come a long road. I would say that I never expected that it would actually live this long. In this **release** QArchive gets a very big upgrade.

When this library was first created the only scope was hard drive based extraction and compression and libarchive seems to have a lot of optimization like zero-copy. But for a long time I've wished to have in-memory extraction and compression but was **too lazy**(sorry folks).

In this release, **I present you with new classes to handle in-memory extraction and compression with ease**. Down below are the new classes which are added to the **QArchive namespace.**

   * [QArchive::MemoryExtractor](/QArchive/docs/QArchiveMemoryExtractor.html)

   * [QArchive::MemoryFile](/QArchive/docs/QArchiveMemoryFile.html)

   * [QArchive::MemoryExtractorOutput](/QArchive/docs/QArchiveExtractorOutput.html)

   * [QArchive::MemoryCompressor](/QArchive/docs/QArchiveMemoryCompressor.html)

Pleae see the documentation for detailed information on these classes.

### Bugfixes

  * Fixed memory leaks.

  * Fix pause/resume in extractor and compressor classes.
  
  * Fix addFiles for directory

### A Little Demo

Let me demonstrate you a small example where we compress and extract a **7Zip** archive in-memory and read the first file contents if it's text document.

```
#include <QCoreApplication>
#include <QDebug>
#include <QBuffer>
#include <QArchive/QArchive>
/* #include <QArchive> // if you use add_subdirectory with cmake */

int main(int argc, char **argv) {
   QCoreApplication app(argc, argv);

   // Let's write our text document.
   QString text = QString::fromUtf8("Thanks for using QArchive.");

   QBuffer document;
   document.open(QIODevice::WriteOnly);
   document.write(text.toLocal8Bit().constData());
   document.close();

   QArchive::MemoryCompressor compressor(QArchive::SevenZipFormat);
   compressor.addFiles("Readme.txt", (QIODevice*)&document);

   QIODevice *archive = nullptr;
   QArchive::MemoryExtractor extractor;

   QObject::connect(&compressor, &QArchive::MemoryCompressor::finished,
   [&](QBuffer *a) {
	archive = (QIODevice*)a;
	extractor.setArchive(archive);
	extractor.start();
   });

   QObject::connect(&extractor, &QArchive::MemoryExtractor::finished,
   [&](QArchive::MemoryExtractorOutput *output) {
	QVector<QArchive::MemoryFile> files = output->getFiles();

	for(auto iter = files.begin(),
		 end = files.end();
		 iter != end;
		 ++iter) {
	    QJsonObject fileInfo = (*iter).fileInformation();
	    QBuffer *buffer = (*iter).buffer();

	    // By default buffer is closed.
	    buffer->open(QIODevice::ReadOnly);

	    qDebug() << "Filename:: " << fileInfo.value("FileName").toString();
	    qDebug() << "Contents:: " << QString(buffer->readAll());
		
	    buffer->close();
	}

	// Only delete the output object and 
	// any other buffer you allocated.	
	output->deleteLater();
	archive->deleteLater();
	app.quit();
   });

   compressor.start(); 
   return app.exec();
}
```

