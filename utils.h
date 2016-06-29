#ifndef UTILS_H
#define UTILS_H

#include "QString"
#include "QFile"
#include "QDir"

QString loadWebDir(){
    //copy qrc index.html  to TempLocation
    QString tmploc = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    QDir tmpdir(tmploc + "/tmp");

    QDirIterator it(":", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QString tmpfile;
        tmpfile = it.next();

        if (QFileInfo(tmpfile).isFile()) {
                QFileInfo file = QFileInfo(tmpdir.absolutePath() + tmpfile.right(tmpfile.size()-1));
                file.dir().mkpath(".");                             // create full path if necessary

                QFile::remove(file.absoluteFilePath()); // remove previous file to make sure we have the latest version
                if ( tmpfile.endsWith("qml")) continue ;
                QFile::copy(tmpfile, file.absoluteFilePath()) ;
         }
    }

    return  tmpdir.absolutePath() ;
}

#endif // UTILS_H
