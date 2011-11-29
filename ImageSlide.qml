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
