INCLUDEPATH += $$PWD $$PWD/include $$PWD/libarchive
QT += core
LIBS += -L$$PWD/libarchive/ -larchive
SOURCES += $$PWD/src/qarchive_enums.cc \
	    $$PWD/src/qarchiveutils_p.cc \
	    $$PWD/src/qarchivememoryfile.cc \
	    $$PWD/src/qarchivememoryextractoroutput.cc \
	    $$PWD/src/qarchiveioreader_p.cc \
	    $$PWD/src/qarchiveextractor_p.cc \
	    $$PWD/src/qarchiveextractor.cc \
	    $$PWD/src/qarchivecompressor_p.cc \
	    $$PWD/src/qarchivecompressor.cc \
	    $$PWD/src/qarchivediskextractor.cc \
	    $$PWD/src/qarchivememoryextractor.cc \
	    $$PWD/src/qarchivediskcompressor.cc \
	    $$PWD/src/qarchivememorycompressor.cc

HEADERS += $$PWD/include/qarchive_enums.hpp \
	    $$PWD/include/qarchiveutils_p.hpp \
	    $$PWD/include/qarchivememoryfile.hpp \
	    $$PWD/include/qarchivememoryextractoroutput.hpp \
	    $$PWD/include/qarchiveioreader_p.hpp \
	    $$PWD/include/qarchiveextractor_p.hpp \
	    $$PWD/include/qarchiveextractor.hpp \
	    $$PWD/include/qarchivecompressor_p.hpp \
	    $$PWD/include/qarchivecompressor.hpp \
	    $$PWD/include/qarchivediskextractor.hpp \
	    $$PWD/include/qarchivememoryextractor.hpp \
	    $$PWD/include/qarchivediskcompressor.hpp \
	    $$PWD/include/qarchivememorycompressor.hpp
