/***************************************************************************
 *   Copyright (C) 2007 by Sindre Aam�s                                    *
 *   aamas@stud.ntnu.no                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation.                            *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License version 2 for more details.                *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   version 2 along with this program; if not, write to the               *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QApplication>
#include <QSize>
#include "mainwindow.h"
#include "gambattesource.h"
#include "gambattemenuhandler.h"

int main(int argc, char *argv[]) {
// 	Q_INIT_RESOURCE(application);
	QApplication app(argc, argv);
	QCoreApplication::setOrganizationName("gambatte");
	QCoreApplication::setApplicationName("gambatte_qt");
	GambatteSource source;
	MainWindow *mw = new MainWindow(&source,
	                                source.generateButtonInfos(),
	                                source.generateVideoSourceInfos(),
	                                MainWindow::tr("Video filter:"),
	                                QSize(160, 144),
	                                source.generateSampleRateInfo());
	GambatteMenuHandler mh(mw, &source, argc, argv);
	mw->show();
	return app.exec();
}
