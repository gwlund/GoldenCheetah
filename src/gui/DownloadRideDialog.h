/* 
 * Copyright (c) 2006-2008 Sean C. Rhea (srhea@srhea.net)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_DownloadRideDialog_h
#define _GC_DownloadRideDialog_h 1

#include <QtGui>
#include "../pt/PowerTap.h"

class MainWindow;
class DownloadThread;

class DownloadRideDialog : public QDialog 
{
    Q_OBJECT

    public:
        DownloadRideDialog(MainWindow *mainWindow, const QDir &home);

        void downloadFinished();
        bool statusCallback(PowerTap::State state);

    private slots:
        void downloadClicked();
        void cancelClicked();
        void setReadyInstruct();
        void scanDevices();

    private:
 
        MainWindow *mainWindow;
        QDir home;
        QListWidget *listWidget;
        QPushButton *downloadButton, *rescanButton, *cancelButton;
        QLabel *label;

        QVector<DevicePtr> devList;
        bool cancelled, downloadInProgress;
        unsigned recInt;
        int endingOffset;
        QVector<unsigned char> records;
        QString filename, filepath;
};

#endif // _GC_DownloadRideDialog_h

