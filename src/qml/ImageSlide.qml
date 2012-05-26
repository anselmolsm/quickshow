/* === This file is part of Quickshow ===
 *
 *   Copyright 2011-2012, Anselmo L. S. Melo <anselmolsm@gmail.com>
 *
 *   Quickshow is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Quickshow is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Quickshow. If not, see <http://www.gnu.org/licenses/>.
 */


import QtQuick 1.1

Image {
    id: root
    width: parent.width
    height: parent.height

    property bool isSlide: true;

    property alias title: title.text
    property alias authors: authors.text
    property alias date: date.text

    visible: false

    // ### Placeholder color, to avoid a bug in Presentation caused by
    // the lack of "color" property in ImageSlide.
    property color color: "white"

//    property real fontSize: 42
//    property real fontScale: 1

//    property real baseFontSize: fontSize * fontScale
//    property real titleFontSize: fontSize * 1.2 * fontScale

    Text {
        id: title
        font.pixelSize: 42
        font.bold: true
        anchors {
            left: parent.left
            leftMargin: 30
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: root.height/4
        }
    }
    Text {
        id: authors
        font.pixelSize: 30
        anchors {
            top: title.bottom
            topMargin: 30
            left: title.left
        }
    }
    Text {
        id: date
        font.pixelSize: 24
        anchors {
            top: authors.bottom
            topMargin: 5
            left: authors.left
        }
    }
}
